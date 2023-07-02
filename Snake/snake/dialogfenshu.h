#pragma once


// dialogfenshu 对话框

class dialogfenshu : public CDialogEx
{
	DECLARE_DYNAMIC(dialogfenshu)

public:
	dialogfenshu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dialogfenshu();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	int m_fenshu;
};
