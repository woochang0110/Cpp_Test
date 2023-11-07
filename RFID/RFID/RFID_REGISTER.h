#pragma once
#include "afxdialogex.h"
#include "RFIDDlg.h"


// RFID_REGISTER 대화 상자

class RFID_REGISTER : public CDialog
{
	DECLARE_DYNAMIC(RFID_REGISTER)

public:
	RFID_REGISTER(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~RFID_REGISTER();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RFID_REGISTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_Edit_Name;
//	CEdit m_Edit_UID;
	afx_msg void OnBnClickedOk();
	// Name for User Input
// Name for User Input
	CEdit m_ctrl_RName;
	// Picture Path for User Input
	CEdit m_ctrl_Rpic_path;
	CEdit m_ctrl_Guideline;
	virtual BOOL OnInitDialog();
};
