// TextSearch.h : Declaration of the CTextSearch

#pragma once
#include "resource.h"       // main symbols

#include <atlbase.h>
#include <atlsafe.h>

#include "TextSearchCompt_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CTextSearch

class ATL_NO_VTABLE CTextSearch :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTextSearch, &CLSID_TextSearch>,
	public IDispatchImpl<ITextSearch, &IID_ITextSearch, &LIBID_TextSearchComptLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTextSearch()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TEXTSEARCH)


BEGIN_COM_MAP(CTextSearch)
	COM_INTERFACE_ENTRY(ITextSearch)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	
	STDMETHOD(SetSearchPath)(BSTR path);
	STDMETHOD(SetSearchKeywords)(SAFEARRAY* keywords);
	STDMETHOD(SetSearchOption)(VARIANT_BOOL searchAll);
	STDMETHOD(GetResults)(SAFEARRAY ** files);

private:
	CComBSTR _searchPath;
	CComSafeArray<BSTR> _searchKeywords; 
	VARIANT_BOOL _searchAll;
};

OBJECT_ENTRY_AUTO(__uuidof(TextSearch), CTextSearch)
