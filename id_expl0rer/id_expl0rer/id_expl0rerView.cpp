// id_expl0rerView.cpp : implementation of the Cid_expl0rerView class
//

#include "stdafx.h"
#include "id_expl0rer.h"

#include "id_expl0rerDoc.h"
#include "id_expl0rerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cid_expl0rerView

IMPLEMENT_DYNCREATE(Cid_expl0rerView, CView)

BEGIN_MESSAGE_MAP(Cid_expl0rerView, CView)
END_MESSAGE_MAP()

// Cid_expl0rerView construction/destruction

Cid_expl0rerView::Cid_expl0rerView()
{
	// TODO: add construction code here

}

Cid_expl0rerView::~Cid_expl0rerView()
{
}

BOOL Cid_expl0rerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}


// Cid_expl0rerView drawing
void Cid_expl0rerView::OnDraw(CDC* /*pDC*/)
{
	Cid_expl0rerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}



// Cid_expl0rerView diagnostics

#ifdef _DEBUG
void Cid_expl0rerView::AssertValid() const
{
	CView::AssertValid();
}

Cid_expl0rerDoc* Cid_expl0rerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cid_expl0rerDoc)));
	return (Cid_expl0rerDoc*)m_pDocument;
}
#endif //_DEBUG


// Cid_expl0rerView message handlers
