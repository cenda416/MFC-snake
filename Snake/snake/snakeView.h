
// snakeView.h : CsnakeView 类的接口
//

#pragma once
#include<afxtempl.h>
#include "resource.h"
#include"dialogfenshu.h"
#include"Dialog1.h"
#include"Dialogsudo.h"
#include <stdlib.h>
#include <time.h> 
#include"mmsystem.h"
class CsnakeView : public CView
{
protected: // 仅从序列化创建
	CsnakeView();
	DECLARE_DYNCREATE(CsnakeView)

// 特性
public:
	CsnakeDoc* GetDocument() const;

// 操作
public:
	CArray<CPoint,CPoint&> Snake;
	CPoint Food;
	int dir;
	CBitmap m_Bitmap_snakeheadleft,m_Bitmap_snakeheadright,m_Bitmap_snakeheadtop,m_Bitmap_snakeheadbottom;
	CBitmap m_Bitmap_food,m_Bitmap_snakebody;
	CBitmap m_Bitmap_background;
	int m_nHeight_snakeheadleft,m_nHeight_snakeheadright,m_nHeight_snakeheadtop,m_nHeight_snakeheadbottom;
	int m_nHeight_food,m_nHeight_snakebody;
	int m_nHeight_background;
	int m_nWidth_snakeheadleft,m_nWidth_snakeheadright,m_nWidth_snakeheadtop,m_nWidth_snakeheadbottom;
	int m_nWidth_food,m_nWidth_snakebody;
	int m_nWidth_background;
	int m_sudo;
	int fenshu;
	int zan;//暂停判断
	int Getrand(int min,int max);
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CsnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStart();
	afx_msg void OnEnd();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnIdok();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnJixu();
	afx_msg void OnShuo();
	afx_msg void OnBofang();
	afx_msg void OnTingzhi();
};

#ifndef _DEBUG  // snakeView.cpp 中的调试版本
inline CsnakeDoc* CsnakeView::GetDocument() const
   { return reinterpret_cast<CsnakeDoc*>(m_pDocument); }
#endif

