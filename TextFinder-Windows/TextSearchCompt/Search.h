#ifndef SEARCH_H
#define SEARCH_H
///////////////////////////////////////////////////////////////////////////////
// Search.h -   Implement text search function                           //
// ver 1.0                                                                   //
// Language:        Visual C++, Visual Studio 2013                           //
// platform:        Macbook pro, Parallels Desktop, Windows 7 profession     //
// Application:     spring 2014 Projects                                     //
// student:         Yufan Gong, Syracuse University                          //
//                  (315) 247-3777, ygong01@syr.edu                          //
///////////////////////////////////////////////////////////////////////////////
/*/
*
* Package Operations:
* ===================
* This package contains one class: TextSearch. This class used to implement text search in Server
* Repository(default now) directory.
*
* Public Interface:
* =================
* std::string StartTextSearch(int threadNum, std::string keyword, CommandLine cl);
*
* Build Command:
* ==============
* devenv SocketDemo2.sln /rebuild debug
*
* Maintenance History:
* ====================
* ver 1.0 : 29 Apr 14
* - first release
*/

#include "Cpp11-BlockingQueue.h"
#include "FileSystem.h"


///////////////////////////////////////////////////////
// Search

//using Files = std::vector<std::string>;
using Path = std::string;
using Options = std::vector<std::string>;
using Paths = std::vector<std::string>;
using KeyWords = std::vector<std::string>;
using CommandLine = std::tuple<Path, KeyWords, Options>;

class Search
{
public:
	using File = FileSystem::File;
	std::vector<std::string> StartTextSearch(std::vector<std::string> keywords, std::string path, bool searchAll);
	std::string ConvertBSTRToMBS(BSTR bstr);

private:
	void StartThreads(std::vector<std::string> keywords, bool searchAll);

	void textSearch(std::vector<std::string> keywords);
	void textSearchAll(std::vector<std::string> keywords);

	void PostFile(std::string filename);
	std::vector<std::string>& getFiles(const Path& path);
	BSTR ConvertMBSToBSTR(const std::string& str);
	std::string GetFile();
	size_t OutPutQsize(){ return OutQ.size(); }
	BlockingQueue<std::string> InQ;
	BlockingQueue<std::string> OutQ;
	std::vector<std::string> files;
	File* file;
	std::vector<std::string> Result;
};
#endif
