#pragma once


// Dialogsudo �Ի���

class Dialogsudo : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogsudo)

public:
	Dialogsudo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialogsudo();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangesudu();
	int m_sudu;
};
