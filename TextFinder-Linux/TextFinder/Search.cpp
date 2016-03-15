///////////////////////////////////////////////////////////////////////////////
// Search.cpp - Implement text search function                           //
// ver 1.0                                                                   //
// Language:        Visual C++, Visual Studio 2013                           //
// platform:        Macbook pro, Parallels Desktop, Windows 7 profession     //
// Application:     spring 2014 Projects                                     //
// student:         Yufan Gong, Syracuse University                          //
//                  (315) 247-3777, ygong01@syr.edu                          //
///////////////////////////////////////////////////////////////////////////////
#include "Search.h"

//----< put filenames in queue and start text search threads >-------------------

std::vector<std::string>& Search::getFiles(const Path& path)
{
	std::vector<std::string> temp = FileSystem::Directory::getFiles(path, "*.*");
	for (auto file : temp)
	{
		file = FileSystem::Path::fileSpec(path, file);
		files.push_back(file);
	}
	// analyze options of command line to decide recursion


	Paths dirs = FileSystem::Directory::getDirectories(path, "*.*");
	for (size_t i = 0; i < dirs.size(); i++)
	{
		if (dirs[i] != "." &&  dirs[i] != "..")
		{
			std::string subdir = dirs[i];
			std::string fullpath = path + subdir + "/";
			getFiles(fullpath);
		}
	}

	return files;
}


std::vector<std::string> Search::StartTextSearch(std::vector<std::string> keywords, std::string path, bool searchAll)
{
	std::vector<std::string> files = getFiles(path);
	for (auto file : files)
	{
		PostFile(file);
	}
	StartThreads(keywords, searchAll);
	if (OutPutQsize() == 0)
	{
		Result.push_back("No items match your search.");
	}
	else
	{
		while (OutQ.size() > 0)
		{
			Result.push_back(GetFile());
		}
	}
	return Result;
}

//----< start threads >-------------------

void Search::StartThreads(std::vector<std::string> keywords, bool searchAll)
{
	//std::vector<std::thread*> threadvector;
    	std::cout << "  #File number in specified directory and its subdirectories : " << InQ.size() << std::endl;
	int threadNumber = InQ.size();
        std::cout << "  #Thread number : " << threadNumber << std::endl;

	if (searchAll)
	{
		for (int i = 0; i < threadNumber; i++)
		{
			std::thread* t = new std::thread(&Search::textSearchAll, this, keywords);
			t->join();
		}
	}
	else
	{
		for (int i = 0; i < threadNumber; i++)
		{
			std::thread* t = new std::thread(&Search::textSearch, this, keywords);
			t->join();
			//threadvector.push_back(t);
		}
	}

}

//----< each thread gets files and search in it, put result in outQ >-------------------

void Search::textSearch(std::vector<std::string> keywords)
{
	
		std::string filecontent;
		std::string filename = InQ.deQ();
		file = new File(filename);

		file->open(File::in);
		while (file->isGood())
		{
			filecontent += file->getLine();
		}

			for (auto keyword : keywords)
			{
				size_t found = filecontent.find(keyword);

				if (found != std::string::npos)
				{
					OutQ.enQ(filename);
					break;
				}
			}
	
}

//----< each thread gets files and search in it, put result in outQ >-------------------

void Search::textSearchAll(std::vector<std::string> keywords)
{
	
		std::string filecontent;
		std::string filename = InQ.deQ();
		file = new File(filename);

		file->open(File::in);
		while (file->isGood())
		{
			filecontent += file->getLine();
		}
		
			bool allMatch = false;
			for (auto keyword : keywords)
			{
				size_t found = filecontent.find(keyword);
				if (found != std::string::npos)
				{
					allMatch = true;
					continue;
				}
				else
				{
					allMatch = false;
					break;
				}
			}
			if (allMatch)
				OutQ.enQ(filename);
	
}

//----< put filename in pre-process queue >-------------------

void Search::PostFile(std::string filename)
{ 
	InQ.enQ(filename); 
}
//----< get result from after-process queue >-------------------

std::string Search::GetFile()
{
	return OutQ.deQ();
}



#ifdef TEST_SEARCH
//-------<test stub>------------
#include <iostream>
int main()
{
	Search* ts = new Search();
	ts->PostFile("TextSearch.cpp");
	ts->StartThreads(3,"text");
	std::string filenames;
	while (ts->OutPutQsize() > 0)
	{
		filenames += ts->GetFile();
	}
	std::cout << filenames;
}
#endif