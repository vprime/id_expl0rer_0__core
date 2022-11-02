// id_expl0rerView.h : interface of the Cid_expl0rerView class
//


#pragma once

class Cid_expl0rerView : public CView
{
protected: // create from serialization only
	Cid_expl0rerView();
	DECLARE_DYNCREATE(Cid_expl0rerView)

// Attributes
public:
	Cid_expl0rerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:

// Implementation
public:
	virtual ~Cid_expl0rerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in id_expl0rerView.cpp
inline Cid_expl0rerDoc* Cid_expl0rerView::GetDocument() const
   { return reinterpret_cast<Cid_expl0rerDoc*>(m_pDocument); }
#endif

