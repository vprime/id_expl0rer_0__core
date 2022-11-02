// id_expl0rerDoc.h : interface of the Cid_expl0rerDoc class
//


#pragma once

class Cid_expl0rerDoc : public CDocument
{
protected: // create from serialization only
	Cid_expl0rerDoc();
	DECLARE_DYNCREATE(Cid_expl0rerDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();

	virtual void Serialize(CArchive& ar);


// Implementation
public:
	virtual ~Cid_expl0rerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


