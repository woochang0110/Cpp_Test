#pragma once
#include "afxdialogex.h"


// SELRes 대화 상자

class SELRes : public CDialog
{
	DECLARE_DYNAMIC(SELRes)

public:
	SELRes(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SELRes();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_RESULT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_ctrl_SR;
};
