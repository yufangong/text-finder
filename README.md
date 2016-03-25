# text-finder

1. Interfaces in Windows and Linux

Window:
TextSearch.h

	STDMETHOD(SetSearchPath)(BSTR path);
	STDMETHOD(SetSearchKeywords)(SAFEARRAY* keywords);
	STDMETHOD(SetSearchOption)(VARIANT_BOOL searchAll);
	STDMETHOD(GetResults)(SAFEARRAY ** files);

Linux:
ITFService

    virtual void SetSearchPath(std::string path) = 0;
    virtual void SetSearchKeywords(std::vector<std::string> keywords) = 0;
    virtual void SetSearchOption(bool searchAll) = 0;
    virtual std::vector<std::string> GetResults() = 0; 

    virtual void* AddRef() = 0;
    virtual void Release() = 0;
    virtual void Verbose(bool pred=true) = 0;

2. In Linux, factory TFObjectFactory creates the new instances of TextFinder, which is inherited from ITFService(interface).

3. Implement AddRef() and Release() in AbstractRefCount, which is wrapped in ITFService.

4. Each file will be analyzed by its own thread. (implement in Search class 
	void StartThreads(std::vector<std::string> keywords, bool searchAll);

Thank you for reading!
