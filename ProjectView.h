
// ProjectView.h: CProjectView 클래스의 인터페이스
//

#pragma once
#include"Board.h"

class CProjectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CProjectView() noexcept;
	DECLARE_DYNCREATE(CProjectView)

// 특성입니다.
public:
	CProjectDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	Board MyBoard;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	int DownButtonX = 0;
	int UpButtonX = 0;
	CFile myFile;
	bool OutputMenu=TRUE;
	bool LogMenu = FALSE;
	int LogNum = 1;

	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void OnUpdate32774(CCmdUI* pCmdUI);
	afx_msg void OnUpdate32775(CCmdUI* pCmdUI);
	afx_msg void On32772();
	afx_msg void OnUpdate32772(CCmdUI* pCmdUI);
	
	void WriteFile();
};

#ifndef _DEBUG  // ProjectView.cpp의 디버그 버전
inline CProjectDoc* CProjectView::GetDocument() const
   { return reinterpret_cast<CProjectDoc*>(m_pDocument); }
#endif

