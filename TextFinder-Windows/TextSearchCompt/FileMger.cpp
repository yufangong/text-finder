///////////////////////////////////////////////////////////////////////////////
//// FileMgr.cpp - Search files with specific patterns and options           //
////                                                                         //
//// ----------------------------------------------------------------------- //
//// Version:      1.1													   //   
//// Language:     Visual C++, Visual Studio 2013                            //
//// Platform:     Macbook Pro, Parallels Desktop 9, Windows 7 Professional  //
//// Application:  Spring Projects, 2014                                     //
//// student:      Yufan Gong, Syracuse University                           //
////               (315) 247-3777, ygong01@syr.edu                           //
///////////////////////////////////////////////////////////////////////////////
//#include "stdafx.h"
//#include "FileMger.h"
//#include <iostream>
//#include "stdafx.h"
////----< search for specific files >-------------------
//
////Files FileMger::FindFiles(CommandLine cl_)
////{
////	path = std::get<0>(cl_);
////	options = std::get<1>(cl_);
////	for (auto opt : options)
////	//{
////	//	if (opt == "/s" || opt == "/S")
////	//		recursive = true;
////	//}
////	files = search(path);
////	return files;
////}
//
//
////----< search for specific files >-------------------
//
//Files& FileMger::search(const Path& path)
//{
//	Files temp = FileSystem::Directory::getFiles(path, "*.*");
//	for (auto file : temp)
//	{
//		file = FileSystem::Path::fileSpec(path, file);
//		files.push_back(file);
//	}
//	// analyze options of command line to decide recursion
//
//
//	Paths dirs = FileSystem::Directory::getDirectories(path, "*.*");
//	for (size_t i = 0; i < dirs.size(); i++)
//	{
//		if (dirs[i] != "." &&  dirs[i] != "..")
//		{
//			std::string subdir = dirs[i];
//			std::string fullpath = path + "\\" + subdir;
//			search(fullpath);
//		}
//	}
//
//	return files;
//}
//#ifdef TEST_FILEMGR
//
//int main(int argc, char* argv[])
//{
//	for (int i = 0; i < argc; ++i)
//		std::cout << "\n  " << argv[i];
//	std::vector<std::string> foundFiles;
//	std::vector<std::string> patterns;
//	patterns.push_back("*.cpp");
//	FileMgr fm;
//	foundFiles = fm.search(".", patterns, true);
//	for (auto file : foundFiles)
//		std::cout << "\n  " << file;
//	std::cout << "\n\n";
//}
//#endif
#include "stdafx.h"