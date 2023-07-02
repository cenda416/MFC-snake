// Dialogsudo.cpp : 实现文件
//

#include "stdafx.h"
#include "snake.h"
#include "Dialogsudo.h"
#include "afxdialogex.h"


// Dialogsudo 对话框

IMPLEMENT_DYNAMIC(Dialogsudo, CDialogEx)

Dialogsudo::Dialogsudo(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dialogsudo::IDD, pParent)
{

	m_sudu = 0;
}

Dialogsudo::~Dialogsudo()
{
}

void Dialogsudo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_sudu, m_sudu);
}


BEGIN_MESSAGE_MAP(Dialogsudo, CDialogEx)
	ON_EN_CHANGE(IDC_sudu, &Dialogsudo::OnEnChangesudu)
END_MESSAGE_MAP()


// Dialogsudo 消息处理程序


void Dialogsudo::OnEnChangesudu()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
