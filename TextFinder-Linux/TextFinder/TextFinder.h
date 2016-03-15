/* 
 * File:   TextFinder.h
 * Author: browneyes
 *
 * Created on March 16, 2015, 9:01 PM
 */

#ifndef TEXTFINDER_H
#define	TEXTFINDER_H

#include "ITFService.h"
#include "Search.h"
class TextFinder : public AbstractRefCount
{
public:
    TextFinder() : AbstractRefCount(){}
    void SetSearchPath(std::string path);
    void SetSearchKeywords(std::vector<std::string> keywords);
    void SetSearchOption(bool searchAll);
    std::vector<std::string> GetResults();
    void Verbose(bool pred=true) { verbose_ = pred;  }
    ~TextFinder();
private:
    std::string _searchPath;
    std::vector<std::string> _searchKeywords;
    bool _searchAll;
};

#endif	/* TEXTFINDER_H */

