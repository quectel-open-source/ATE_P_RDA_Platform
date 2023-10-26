// PA_8955L_Select_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "rf_cal_ft_rda.h"
#include "PA_8955L_Select_Dlg.h"
#include "afxdialogex.h"


// CPA_8955L_Select_Dlg 对话框

IMPLEMENT_DYNAMIC(CPA_8955L_Select_Dlg, CDialogEx)

CPA_8955L_Select_Dlg::CPA_8955L_Select_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPA_8955L_Select_Dlg::IDD, pParent)
	, m_i_PA_Index(0)
{

}

CPA_8955L_Select_Dlg::~CPA_8955L_Select_Dlg()
{
}

void CPA_8955L_Select_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_i_PA_Index);
}


BEGIN_MESSAGE_MAP(CPA_8955L_Select_Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPA_8955L_Select_Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPA_8955L_Select_Dlg 消息处理程序


void CPA_8955L_Select_Dlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void CPA_8955L_Select_Dlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}


BOOL CPA_8955L_Select_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
