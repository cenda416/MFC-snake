#pragma once


// Dialogsudo 对话框

class Dialogsudo : public CDialogEx
{
	DECLARE_DYNAMIC(Dialogsudo)

public:
	Dialogsudo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialogsudo();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangesudu();
	int m_sudu;
};
