// Dialogsudo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "snake.h"
#include "Dialogsudo.h"
#include "afxdialogex.h"


// Dialogsudo �Ի���

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


// Dialogsudo ��Ϣ�������


void Dialogsudo::OnEnChangesudu()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
