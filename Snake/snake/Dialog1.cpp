// Dialog1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "snake.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// Dialog1 �Ի���

IMPLEMENT_DYNAMIC(Dialog1, CDialogEx)

Dialog1::Dialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dialog1::IDD, pParent)
{

	m_fenshu = 0;
}

Dialog1::~Dialog1()
{
}

void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_fenshu);
}


BEGIN_MESSAGE_MAP(Dialog1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Dialog1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Dialog1 ��Ϣ�������


void Dialog1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
