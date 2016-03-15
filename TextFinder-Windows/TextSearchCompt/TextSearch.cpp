// TextSearch.cpp : Implementation of CTextSearch

#include "stdafx.h"
#include "TextSearch.h"
#include <atlsafe.h>
#include <iostream>
#include "Search.h"
#include <vector>

// CTextSearch




STDMETHODIMP CTextSearch::SetSearchPath(BSTR path)
{
	// TODO: Add your implementation code here
	_searchPath = path;
	return S_OK;
}


STDMETHODIMP CTextSearch::SetSearchKeywords(SAFEARRAY* keywords)
{
	// TODO: Add your implementation code here
	_searchKeywords = keywords;
	return S_OK;
}


STDMETHODIMP CTextSearch::SetSearchOption(VARIANT_BOOL searchAll)
{
	// TODO: Add your implementation code here
	_searchAll = searchAll;
	return S_OK;
}


STDMETHODIMP CTextSearch::GetResults(SAFEARRAY ** files)
{
	// TODO: Add your implementation code here
	Search searchService;
	std::string path = searchService.ConvertBSTRToMBS(_searchPath);
	//std::string keyword = searchService.ConvertBSTRToMBS(_searchKeyword);
	std::vector<std::string> keywords;

	for (int i = 0; i < (int)_searchKeywords.GetCount(); ++i)
		keywords.push_back(searchService.ConvertBSTRToMBS(_searchKeywords[i].Copy()));

	std::vector<std::string> results = searchService.StartTextSearch(keywords, path, _searchAll);
	CComSafeArray<BSTR> temp;
	
	for (auto result : results)
		temp.Add(CComBSTR(result.c_str()));

	*files = temp.Detach();

	return S_OK;
}



