#pragma once
#include "Resource.h"

// CPA_8955L_Select_Dlg 对话框

class CPA_8955L_Select_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPA_8955L_Select_Dlg)

public:
	CPA_8955L_Select_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPA_8955L_Select_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_i_PA_Index;
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
};
