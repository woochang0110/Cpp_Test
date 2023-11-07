// RFID_REGISTER.cpp: 구현 파일
//

#include "pch.h"
#include "RFID.h"
#include "afxdialogex.h"
#include "RFID_REGISTER.h"

extern CString m_str_Name;
extern CString m_str_pic_path;

// RFID_REGISTER 대화 상자

IMPLEMENT_DYNAMIC(RFID_REGISTER, CDialog)

RFID_REGISTER::RFID_REGISTER(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RFID_REGISTER, pParent)
{

}

RFID_REGISTER::~RFID_REGISTER()
{
}

void RFID_REGISTER::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrl_RName);
	DDX_Control(pDX, IDC_EDIT2, m_ctrl_Rpic_path);
	DDX_Control(pDX, IDC_EDIT3, m_ctrl_Guideline);
}


BEGIN_MESSAGE_MAP(RFID_REGISTER, CDialog)
	ON_BN_CLICKED(IDOK, &RFID_REGISTER::OnBnClickedOk)
END_MESSAGE_MAP()


// RFID_REGISTER 메시지 처리기




void RFID_REGISTER::OnBnClickedOk()
{
	CString t_Name = _T("");
	CString t_Pic_Path = _T("");
	//
	
	m_ctrl_RName.GetWindowTextA(m_str_Name);
	m_ctrl_Rpic_path.GetWindowTextA(m_str_pic_path);

	CDialog::OnOK();
}




BOOL RFID_REGISTER::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrl_Guideline.SetWindowTextA(_T("Enter the information and Press OK"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
