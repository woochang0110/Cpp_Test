// SELRes.cpp: 구현 파일
//

#include "pch.h"
#include "RFID.h"
#include "afxdialogex.h"
#include "SELRes.h"

extern CString db_select_result;
// SELRes 대화 상자

IMPLEMENT_DYNAMIC(SELRes, CDialog)

SELRes::SELRes(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECT_RESULT, pParent)
{

}

SELRes::~SELRes()
{
}

void SELRes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrl_SR);
}


BEGIN_MESSAGE_MAP(SELRes, CDialog)
END_MESSAGE_MAP()


// SELRes 메시지 처리기


BOOL SELRes::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_ctrl_SR.SetWindowTextA(db_select_result);

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
