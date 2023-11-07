
// RFIDDlg.h: 헤더 파일
//

#pragma once
#include "is_d2xx.h"
#include <afxwin.h>





// CRFIDDlg 대화 상자
class CRFIDDlg : public CDialogEx
{
// 생성입니다.
public:
	CRFIDDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CRFIDDlg();



	IS_HANDLE ftHandle = 0;
	char readSerialNumber[100] = "COM07";
	char changeSerialNumber[100] = "RFID01";
	short usbnumber;
	unsigned char wirteData[1024];
	unsigned short writeLength = 2;
	unsigned char readData[1024];
	unsigned short readLength = 2;
	unsigned char cmd1=0;
	unsigned char cmd2=0;
	BOOL flag_r=0;


	CWinThread* m_pThread;
	bool m_isWorkingThread;
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RFID_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDBSelect();
	afx_msg void OnReadOnce();
	afx_msg void OnDBUpdate();
	afx_msg void OnDataInput();
	afx_msg void OnReadManyTime();

	CStatic m_picture_control;
	CEdit m_ctrl_DBStatus;
	CEdit m_ctrl_UID;
	CEdit m_ctrl_select_result;
	CEdit m_ctrl_Index;
	CEdit m_ctrl_pic_name;
	CEdit m_ctrl_Name;
	/*
	void Set_str_Name(CString str_Name)
	{
		
		//m_str_Name = str_Name;
		//char* temp;
		//strcpy(temp, (char*)(LPCTSTR)str_Name);
		//다시 CHAR -> CSTRING

	}
	void Set_str_Pic_name(CString Pic_name)
	{
		//m_str_pic_path = Pic_name;
	}
	*/
};
