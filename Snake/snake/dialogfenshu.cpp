// dialogfenshu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "snake.h"
#include "dialogfenshu.h"
#include "afxdialogex.h"


// dialogfenshu �Ի���

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


// dialogfenshu ��Ϣ�������


void dialogfenshu::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
