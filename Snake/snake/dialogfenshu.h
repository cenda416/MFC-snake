#pragma once


// dialogfenshu �Ի���

class dialogfenshu : public CDialogEx
{
	DECLARE_DYNAMIC(dialogfenshu)

public:
	dialogfenshu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dialogfenshu();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	int m_fenshu;
};
