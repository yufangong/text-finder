// dllmain.h : Declaration of module class.

class CTextSearchComptModule : public ATL::CAtlDllModuleT< CTextSearchComptModule >
{
public :
	DECLARE_LIBID(LIBID_TextSearchComptLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEXTSEARCHCOMPT, "{B976A375-D706-4302-B204-A96A59212267}")
};

extern class CTextSearchComptModule _AtlModule;
