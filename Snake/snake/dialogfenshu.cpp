// dialogfenshu.cpp : 实现文件
//

#include "stdafx.h"
#include "snake.h"
#include "dialogfenshu.h"
#include "afxdialogex.h"


// dialogfenshu 对话框

IMPLEMENT_DYNAMIC(dialogfenshu, CDialogEx)

dialogfenshu::dialogfenshu(CWnd* pParent /*=NULL*/)
	: CDialogEx(dialogfenshu::IDD, pParent)
{

	m_fenshu = 0;
}

dialogfenshu::~dialogfenshu()
{
}

void dialogfenshu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_fenshu, m_fenshu);
}


BEGIN_MESSAGE_MAP(dialogfenshu, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &dialogfenshu::OnEnChangeEdit1)
END_MESSAGE_MAP()


// dialogfenshu 消息处理程序


void dialogfenshu::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
