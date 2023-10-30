
// RFIDDlg.cpp: 구현 파일
//
#include "is_d2xx.h"
#include "pch.h"
#include "framework.h"
#include "RFID.h"
#include "RFIDDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




MYSQL* conn;
MYSQL* conn_result;
unsigned int timeout_sec = 1;
//char query[1024];
MYSQL_RES* result;
MYSQL_ROW row;
CString query;
char query1[44] = { 0 };
CString temp2 = _T("");
//unsigned char uid[1024] = { 0 };

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRFIDDlg 대화 상자



CRFIDDlg::CRFIDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RFID_DIALOG, pParent)
	, m_strRfid(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CRFIDDlg::~CRFIDDlg()
{
	//연결 해제 추가
}

void CRFIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strRfid);
	DDX_Control(pDX, IDC_BUTTON1, ㅇ);
}

BEGIN_MESSAGE_MAP(CRFIDDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRFIDDlg::OnConnect)
	ON_BN_CLICKED(IDC_BUTTON3, &CRFIDDlg::OnReadOnce)
	ON_BN_CLICKED(IDC_BUTTON4, &CRFIDDlg::OnSQLSelect)
	ON_BN_CLICKED(IDC_BUTTON2, &CRFIDDlg::OnSQLConnect)
END_MESSAGE_MAP()


// CRFIDDlg 메시지 처리기

BOOL CRFIDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRFIDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRFIDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRFIDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRFIDDlg::OnConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		//열린 포트번호 찾기
	if (is_GetDeviceNumber(&usbnumber) == IS_OK)
	{
		printf("FTDI USB To Serial 연결된 개수 : %d\n", usbnumber);
		if (is_GetSerialNumber(0, readSerialNumber) == IS_OK)
		{
			if (memcmp(changeSerialNumber, readSerialNumber, sizeof(changeSerialNumber) != 0))
			{
				if (is_SetSerialNumber(0, changeSerialNumber) == IS_OK)
				{
					printf(" USB To Serial Number 를 변경 하였습니다.\n");
					printf(" FTDI SerialNumber :  %s \n", changeSerialNumber);
				}
			}
			else
				printf(" FTDI SerialNumber :  %s \n", changeSerialNumber);
		}
	}

	//열린 포트번호로 연결
	unsigned long portNumber;
	if (is_GetCOMPort_NoConnect(0, &portNumber) == IS_OK)
	{
		printf("COM Port : %d\n", portNumber);
	}
	if (is_OpenSerialNumber(&ftHandle, readSerialNumber, 115200) != IS_OK)
	{
		printf("USB To Serial과 통신 연결 실패\n");
		//return -1;
	}
	else {
		printf("Serial포트 %d와 통신 연결성공!! \n", portNumber);
	}
	Sleep(100);
	flag_r = 0;
	conn = mysql_init(NULL);
	mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
	conn_result = mysql_real_connect(conn, "127.0.0.1", "root", "dnckdals1!", "mysql", 3306, NULL, 0);
	//비밀번호 바꿔주세요!!

	if (NULL == conn_result)
	{
		printf("DB Connection Fail");
		//cout << "DB Connection Fail" << endl;
	}
	else
	{
		printf("DB Connection Success\n");
		//cout << "DB Connection Success" << endl;

	}
}


void CRFIDDlg::OnReadOnce()
{
	CString temp, temp1=_T("");
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ISO15693모드로 읽기( 싱글모드 읽기 )
	if (flag_r == 0)
	{
		if (is_WriteReadCommand(ftHandle, CM1_ISO15693, CM2_ISO15693_ACTIVE + BUZZER_ON,
			writeLength, wirteData, &readLength, readData) == IS_OK) {
			int i;
			if (readLength == 8)
			{
				printf("ISO 15693 UID : ");

				query.Format(_T("INSERT INTO rfid VALUES('"));

				for (i = 0; i < readLength; i++)
				{
					temp.Format(_T("%02x"), readData[i]);

					//query.Append(_T("%02x"), readData[i]);
					//temp.Format(_T("%02x "), uid[i]);
					//uid[i] = readData[i];
					temp1 += temp;//temp1이 for문 끝나면 uid 전체를 갖고있게됨.

					printf("%02x", readData[i]);
				}
				query.Insert(25, temp1);//uid 전체 넘겨주기
				m_strRfid = temp1;
				UpdateData(FALSE);
				CString temp2 = _T("')");
				//temp2.Format(_T("');"));
				//query += temp2;
				query.Insert(25 + readLength * 2, temp2);
				printf("\n");

				for (i = 0; i < 44; i++)
				{
					query1[i] = query[i];
					printf("%c", query1[i]);//(char*)(LPCTSTR)

				}

				//(char*)(LPCTSTR)query[43] = '\0';
				printf("\n");
				printf("\n");
			}
		}
		else if (is_WriteReadCommand(ftHandle, CM1_ISO14443AB, CM2_ISO14443A_ACTIVE + BUZZER_ON,
				writeLength, wirteData, &readLength, readData) == IS_OK) 
		{



			if (readLength == 4)
			{
				printf("ISO 14443AB UID : ");

				query.Format(_T("INSERT INTO rfid VALUES('"));

				for (int i = 0; i < readLength; i++)
				{
					temp.Format(_T("%02x"), readData[i]);

					//query.Append(_T("%02x"), readData[i]);
					//temp.Format(_T("%02x "), uid[i]);
					//uid[i] = readData[i];
					temp1 += temp;

					printf("%02x", readData[i]);
				}
				query.Insert(25, temp1);
				m_strRfid = temp1;
				UpdateData(FALSE);
				temp2 = _T("')");
				//temp2.Format(_T("');"));
				query += temp2;
				//query.Insert(25 + readLength * 2, temp2);
				printf("\n");
				for (int i = 0; i < 36; i++)
				{
					query1[i] = query[i];
					printf("%c", query1[i]);//(char*)(LPCTSTR)
				}

			}

				//(char*)(LPCTSTR)query[43] = '\0';
				printf("\n");
				printf("\n");
		}















		
			//sprintf_s(query, 1024, "INSERT INTO rfid() VALUES('%02x')", uid);//아까전에 만들어줬던 db 내 테이블 이름

			// Send Query
			if (mysql_query(conn, query1))//(const char*)(LPCTSTR)query)
			{
				printf("SELECT Fail");
					//cout << "SELECT Fail" << endl;
			}
			// Get Response
			result = mysql_store_result(conn);

		
	
	}
}
	/*
	//ISO14443A모드로 읽기
	if (is_WriteReadCommand(ftHandle, CM1_ISO14443AB, CM2_ISO14443A_ACTIVE + BUZZER_ON,
		writeLength, wirteData, &readLength, readData) == IS_OK)
	{
		int i;
		printf("ISO 14443AB UID : ");
		for (i = 0; i < readLength; i++)
		{
			printf("%02x ", readData[i]);
		}
		printf("\n");
	}
	*/



void CRFIDDlg::OnSQLSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*
	printf("%s", uid);
	sprintf_s(query, 1024, "INSERT INTO rfid(uid)VALUES('%s')",uid);//아까전에 만들어줬던 db 내 테이블 이름

	// Send Query
	if (mysql_query(conn, query))
	{
		printf("SELECT Fail");
		//cout << "SELECT Fail" << endl;
	}

	// Get Response
	result = mysql_store_result(conn);
*/
}



void CRFIDDlg::OnSQLConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	/*
		printf("ISO 15693 UID : ");
			for (i = 0; i < readLength; i++)
			{
				temp.Format(_T("%02x "), readData[i]);
				temp1 += temp;

	*/

		//sprintf_s(query, 1024, "SELECT * FROM rfid");//아까전에 만들어줬던 db 내 테이블 이름
		query.Format(_T("SELECT * FROM rfid"));
		// Send Query
		if (mysql_query(conn, (char*)(LPCTSTR)query))
		{
			printf("SELECT Fail");
			//cout << "SELECT Fail" << endl;
		}

		// Get Response
		result = mysql_store_result(conn);

		int fields = mysql_num_fields(result);    // 필드 갯수 구함

		while (row = mysql_fetch_row(result))     // 모든 레코드 탐색
		{
			for (int i = 0; i < fields; i++)    // 각각의 레코드에서 모든 필드 값 출력
			{
				printf("%s ", row[i]);
				//cout << row[i] << "   ";
			}
			printf("\n");
			//cout << endl;
		}







		/*

		// 무선파워를 끊어요.
	is_RfOff(ftHandle);


	//USB 포트를 Close
	if (is_Close(ftHandle) == IS_OK)
	{
		printf("연결을 닫습니다. ");
	}
	*/
	
}
