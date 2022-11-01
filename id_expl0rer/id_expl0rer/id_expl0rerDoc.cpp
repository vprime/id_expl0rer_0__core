// id_expl0rerDoc.cpp : implementation of the Cid_expl0rerDoc class
//

#include "stdafx.h"
#include "id_expl0rer.h"

#include "id_expl0rerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cid_expl0rerDoc

IMPLEMENT_DYNCREATE(Cid_expl0rerDoc, CDocument)

BEGIN_MESSAGE_MAP(Cid_expl0rerDoc, CDocument)
END_MESSAGE_MAP()

// Cid_expl0rerDoc construction/destruction

Cid_expl0rerDoc::Cid_expl0rerDoc()
{
	// TODO: add one-time construction code here

}

Cid_expl0rerDoc::~Cid_expl0rerDoc()
{
}

BOOL Cid_expl0rerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// Cid_expl0rerDoc serialization


void Cid_expl0rerDoc::Serialize(CArchive& ar)
{
	(ar);
}



// Cid_expl0rerDoc diagnostics

#ifdef _DEBUG
void Cid_expl0rerDoc::AssertValid() const
{
	CDocument::AssertValid();
}
#endif //_DEBUG


// Cid_expl0rerDoc commands

