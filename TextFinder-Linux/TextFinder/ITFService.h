
#ifndef ITFSERVICE_H
#define	ITFSERVICE_H
#include <vector>
#include <stdlib.h>
#include <string>
#include <atomic> 
#include <iostream>
//#include "Search.h"

class ITFService {
public:
    virtual void SetSearchPath(std::string path) = 0;
    virtual void SetSearchKeywords(std::vector<std::string> keywords) = 0;
    virtual void SetSearchOption(bool searchAll) = 0;
    virtual std::vector<std::string> GetResults() = 0; 
    virtual void* AddRef() = 0;
    virtual void Release() = 0;
    virtual void Verbose(bool pred=true) = 0;
    virtual ~ITFService(){};
};


class AbstractRefCount : public ITFService
{
public:
  AbstractRefCount() { 
    refCnt = 1; 
  }
   
  void* AddRef() { ++refCnt; }

  void Release() {
    if (--refCnt == 0)
      delete this;
  }
  ~AbstractRefCount() { 
    if (verbose_)
      std::cout << "\n  destroying Reference Counted Instance"; 
  }
protected:
  bool verbose_ = false;
private:
  std::atomic<size_t> refCnt;// Reference Counting will be thread safe
};
#endif	

