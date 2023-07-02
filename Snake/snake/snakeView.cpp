
// snakeView.cpp : CsnakeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "snake.h"
#endif

#include "snakeDoc.h"
#include "snakeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsnakeView

IMPLEMENT_DYNCREATE(CsnakeView, CView)

BEGIN_MESSAGE_MAP(CsnakeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsnakeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_start, &CsnakeView::OnStart)
	ON_COMMAND(ID_end, &CsnakeView::OnEnd)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
//	ON_COMMAND(IDOK, &CsnakeView::OnIdok)
ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_jixu, &CsnakeView::OnJixu)
ON_COMMAND(ID_shuo, &CsnakeView::OnShuo)
ON_COMMAND(ID_bofang, &CsnakeView::OnBofang)
ON_COMMAND(ID_tingzhi, &CsnakeView::OnTingzhi)
END_MESSAGE_MAP()

// CsnakeView ����/����

CsnakeView::CsnakeView()
{
	// TODO: �ڴ˴���ӹ������
	Snake.SetSize(1);
	Snake.SetAt(0,CPoint(300,50));
	Snake.Add(CPoint(250,50));
	Snake.Add(CPoint(200,50));
	Snake.Add(CPoint(150,50));
	Snake.Add(CPoint(100,50));
	Food.x=800;
	Food.y=50;
	dir=VK_RIGHT;
	BITMAP BM;
	m_Bitmap_snakeheadright.LoadBitmap(IDB_BITright);
	m_Bitmap_snakeheadright.GetBitmap(&BM);
	m_nWidth_snakeheadright=BM.bmWidth;
	m_nHeight_snakeheadright=BM.bmHeight;
	m_Bitmap_snakeheadleft.LoadBitmap(IDB_BITleft);
	m_Bitmap_snakeheadleft.GetBitmap(&BM);
	m_nWidth_snakeheadleft=BM.bmWidth;
	m_nHeight_snakeheadleft=BM.bmHeight;
	m_Bitmap_snakeheadtop.LoadBitmap(IDB_BITtop);
	m_Bitmap_snakeheadtop.GetBitmap(&BM);
	m_nWidth_snakeheadtop=BM.bmWidth;
	m_nHeight_snakeheadtop=BM.bmHeight;
	m_Bitmap_snakeheadbottom.LoadBitmap(IDB_BITbottom);
	m_Bitmap_snakeheadbottom.GetBitmap(&BM);
	m_nWidth_snakeheadbottom=BM.bmWidth;
	m_nHeight_snakeheadbottom=BM.bmHeight;
	m_Bitmap_snakebody.LoadBitmap(IDB_BITMAP2);
	m_Bitmap_snakebody.GetBitmap(&BM);
	m_nWidth_snakebody=BM.bmWidth;
	m_nHeight_snakebody=BM.bmHeight;
	m_Bitmap_food.LoadBitmap(IDB_BITMAP3);
	m_Bitmap_food.GetBitmap(&BM);
	m_nWidth_food=BM.bmWidth;
	m_nHeight_food=BM.bmHeight;
	m_Bitmap_background.LoadBitmap(IDB_BITmap);
	m_Bitmap_background.GetBitmap(&BM);
	m_nWidth_background=BM.bmWidth;
	m_nHeight_background=BM.bmHeight;
	m_sudo=1;
	fenshu=0;
	zan=0;
}
int CsnakeView::Getrand(int min, int max)//���������
{
	int Max;
    Max=RAND_MAX;//rand()��������������ֵ
    return (int)(rand()*(max-min)/Max+min);
}
CsnakeView::~CsnakeView()
{
}

BOOL CsnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsnakeView ����

void CsnakeView::OnDraw(CDC* pDC)
{
	CsnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rect;
		GetClientRect(&rect);	
		CDC memCDC;
		CBitmap memBitmap;
		memCDC.CreateCompatibleDC(pDC);
		memBitmap.CreateCompatibleBitmap(pDC, rect.Width(),rect.Height());
		CBitmap *pOldBit = memCDC.SelectObject(&memBitmap);
		memCDC.SelectObject(&memBitmap);
		memCDC.FillSolidRect(0,0,rect.Width(),rect.Height(),RGB(255,255,255)); 
		CDC DC_background;
		DC_background.CreateCompatibleDC(NULL);
		DC_background.SelectObject(&m_Bitmap_background);
		memCDC.StretchBlt(0,0,rect.Width(),rect.Height(),&DC_background,0,0,m_nWidth_background,m_nHeight_background,SRCCOPY);
		for(int i=0;i<Snake.GetSize();i++){
		if(i==0)
		{
		switch(dir){
		case VK_RIGHT:
		{
		CDC DC_snakehead;
		DC_snakehead.CreateCompatibleDC(NULL);
		DC_snakehead.SelectObject(&m_Bitmap_snakeheadright);
		memCDC.StretchBlt(Snake[i].x-25,Snake[i].y-25,50,50,&DC_snakehead,0,0,m_nWidth_snakeheadright,m_nHeight_snakeheadright,SRCCOPY);
		break;
		}
	case VK_LEFT:
		{
		CDC DC_snakehead;
		DC_snakehead.CreateCompatibleDC(NULL);
		DC_snakehead.SelectObject(&m_Bitmap_snakeheadleft);
		memCDC.StretchBlt(Snake[i].x-25,Snake[i].y-25,50,50,&DC_snakehead,0,0,m_nWidth_snakeheadleft,m_nHeight_snakeheadleft,SRCCOPY);
		break;
		}
	case VK_UP:
		{
		
		CDC DC_snakehead;
		DC_snakehead.CreateCompatibleDC(NULL);
		DC_snakehead.SelectObject(&m_Bitmap_snakeheadtop);
		memCDC.StretchBlt(Snake[i].x-25,Snake[i].y-25,50,50,&DC_snakehead,0,0,m_nWidth_snakeheadtop,m_nHeight_snakeheadtop,SRCCOPY);
		break;}
	case VK_DOWN:
		{
		
		CDC DC_snakehead;
		DC_snakehead.CreateCompatibleDC(NULL);
		DC_snakehead.SelectObject(&m_Bitmap_snakeheadbottom);
		memCDC.StretchBlt(Snake[i].x-25,Snake[i].y-25,50,50,&DC_snakehead,0,0,m_nWidth_snakeheadbottom,m_nHeight_snakeheadbottom,SRCCOPY);
		break;}
		}
	}
	
	else
	{
		CDC DC_snakebody;
		DC_snakebody.CreateCompatibleDC(NULL);
		DC_snakebody.SelectObject(&m_Bitmap_snakebody);
		memCDC.StretchBlt(Snake[i].x-25,Snake[i].y-25,50,50,&DC_snakebody,0,0,m_nWidth_snakebody,m_nHeight_snakebody,SRCCOPY);
	}
	}
	/*pDC->Ellipse(Food.x-25,Food.y-25,Food.x+25,Food.y+25);*/
		CDC DC_food;
		DC_food.CreateCompatibleDC(NULL);
		DC_food.SelectObject(&m_Bitmap_food);
		memCDC.StretchBlt(Food.x-25,Food.y-25,50,50,&DC_food,0,0,m_nWidth_food,m_nHeight_food,SRCCOPY);
		/*pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&memCDC,0,0,m_nWidth_background,m_nHeight_background,SRCCOPY);*/
		pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memCDC,0,0,SRCCOPY);
		memCDC.SelectObject(pOldBit);
		memBitmap.DeleteObject();
}


// CsnakeView ��ӡ


void CsnakeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CsnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CsnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CsnakeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsnakeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsnakeView ���

#ifdef _DEBUG
void CsnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CsnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsnakeDoc* CsnakeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsnakeDoc)));
	return (CsnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CsnakeView ��Ϣ�������


void CsnakeView::OnStart()
{
	// TODO: �ڴ���������������
	Dialogsudo dlg;
	

	if(dlg.DoModal()==IDOK){
		m_sudo=dlg.m_sudu;
		Invalidate();
	}
	if(m_sudo<=0){
		AfxMessageBox(L"����������");
		return;
	}
	zan=1;
	SetTimer(1,500.0/m_sudo,NULL);
	sndPlaySound(L"res\\1.wav",SND_ASYNC|SND_LOOP);

}


void CsnakeView::OnEnd()
{
	// TODO: �ڴ���������������
	sndPlaySound(NULL,SND_SYNC);
	KillTimer(1);
	dialogfenshu dlg1;
	dlg1.m_fenshu=fenshu;
	dlg1.DoModal();
	Snake.RemoveAll();
	Snake.SetSize(1);
	Snake.SetAt(0,CPoint(300,50));
	Snake.Add(CPoint(250,50));
	Snake.Add(CPoint(200,50));
	Snake.Add(CPoint(150,50));
	Snake.Add(CPoint(100,50));
	Food.x=800;
	Food.y=50;
	dir=VK_RIGHT;
	m_sudo=1;
	fenshu=0;
	Invalidate();
}


void CsnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPoint newhead;
	switch(dir){
	case VK_RIGHT:
		newhead=Snake.GetAt(0)+CPoint(50,0);
		break;
	case VK_LEFT:
		newhead=Snake.GetAt(0)+CPoint(-50,0);
		break;
	case VK_UP:
		newhead=Snake.GetAt(0)+CPoint(0,-50);
		break;
	case VK_DOWN:
		newhead=Snake.GetAt(0)+CPoint(0,50);
		break;
	}
	if(Snake[0].x==Food.x&&Snake[0].y==Food.y)
	{
		Snake.InsertAt(0,newhead);
		CRect rect;
		GetClientRect(&rect);
		Food.x=50*Getrand(1,rect.Width()/50.0);
		Food.y=50*Getrand(1,rect.Height()/50.0);
		fenshu++;
	}
	else{
	Snake.InsertAt(0,newhead);
	Snake.RemoveAt(Snake.GetSize()-1);
	}

	for(int i=1;i<Snake.GetSize();i++){
		if(Snake[i].x==Snake[0].x&&Snake[i].y==Snake[0].y){
			sndPlaySound(NULL,SND_SYNC);
			KillTimer(1);
			Dialog1 dlg2;
			dlg2.m_fenshu=fenshu;
			dlg2.DoModal();
			Snake.RemoveAll();
			Snake.SetSize(1);
			Snake.SetAt(0,CPoint(300,50));
			Snake.Add(CPoint(250,50));
			Snake.Add(CPoint(200,50));
			Snake.Add(CPoint(150,50));
			Snake.Add(CPoint(100,50));
			Food.x=800;
			Food.y=50;
			dir=VK_RIGHT;
			m_sudo=1;
			fenshu=0;
		}
	}
	CRect rect;
	GetClientRect(&rect);
	if(Snake[0].x<0||Snake[0].x>rect.Width()||Snake[0].y<0||Snake[0].y>rect.Height()){
	sndPlaySound(NULL,SND_SYNC);
	dialogfenshu dlg1;
	KillTimer(1);
	dlg1.m_fenshu=fenshu;
	dlg1.DoModal();
	Snake.RemoveAll();
	Snake.SetSize(1);
	Snake.SetAt(0,CPoint(300,50));
	Snake.Add(CPoint(250,50));
	Snake.Add(CPoint(200,50));
	Snake.Add(CPoint(150,50));
	Snake.Add(CPoint(100,50));
	Food.x=800;
	Food.y=50;
	dir=VK_RIGHT;
	m_sudo=1;
	fenshu=0;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


BOOL CsnakeView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return true;
	/*return CView::OnEraseBkgnd(pDC);*/
}


void CsnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nChar){
	case VK_RIGHT:
		if(dir!=VK_LEFT)dir=VK_RIGHT;
		break;
	case VK_LEFT:
		if(dir!=VK_RIGHT)dir=VK_LEFT;
		break;
	case VK_UP:
		if(dir!=VK_DOWN)dir=VK_UP;
		break;
	case VK_DOWN:
		if(dir!=VK_UP)dir=VK_DOWN;
		break;
		/*case 0x44:
		if(dir!=0x41)dir=0x44;
		break;
	case VK_LEFT:
		if(dir!=VK_RIGHT)dir=VK_LEFT;
		break;
	case VK_UP:
		if(dir!=VK_DOWN)dir=VK_UP;
		break;
	case VK_DOWN:
		if(dir!=VK_UP)dir=VK_DOWN;
		break;*/
	case VK_SPACE:
		if(zan==1){sndPlaySound(NULL,SND_SYNC);KillTimer(1);}
		break;
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


//void CsnakeView::OnIdok()
//{
//	// TODO: �ڴ���������������
//
//}


void CsnakeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(zan==1){
	sndPlaySound(NULL,SND_SYNC);
	KillTimer(1);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CsnakeView::OnJixu()
{
	// TODO: �ڴ���������������
	zan=1;
	SetTimer(1,500.0/m_sudo,NULL);
	sndPlaySound(L"res\\1.wav",SND_ASYNC|SND_LOOP);
}


void CsnakeView::OnShuo()
{
	// TODO: �ڴ���������������
	AfxMessageBox(L"������Ϸ��һ��̰������Ϸ����Ϸ������'��ʼ'�˵�����ʼ��Ϸ�����������ҿ��Կ��Ʒ����������Ϳո������ͣ���ɵ���˵�'����'������Ϸ���˵�'����'����ֱ�ӽ�����Ϸ���˵������֡�����ѡ�񲥷źͲ���������");
}


void CsnakeView::OnBofang()
{
	// TODO: �ڴ���������������
	sndPlaySound(L"res\\1.wav",SND_ASYNC|SND_LOOP);
}


void CsnakeView::OnTingzhi()
{
	// TODO: �ڴ���������������
	sndPlaySound(NULL,SND_SYNC);
}
