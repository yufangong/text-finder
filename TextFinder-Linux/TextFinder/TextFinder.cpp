/* 
 * File:   TextFinder.cpp
 * Author: browneyes
 * 
 * Created on March 16, 2015, 9:01 PM
 */

#include "TextFinder.h"
TextFinder::~TextFinder(){
    if (verbose_)
    std::cout << "\n  destroying TextComp instance";
}

void TextFinder::SetSearchPath(std::string path)
{
    _searchPath = path;
}
void TextFinder::SetSearchKeywords(std::vector<std::string> keywords)
{
    _searchKeywords = keywords;
}

void TextFinder::SetSearchOption(bool searchAll)
{
    _searchAll = searchAll;
}

std::vector<std::string> TextFinder::GetResults()
{
    Search searchService;

    std::vector<std::string> results = searchService.StartTextSearch(_searchKeywords, _searchPath, _searchAll);
	
    return results;

}

