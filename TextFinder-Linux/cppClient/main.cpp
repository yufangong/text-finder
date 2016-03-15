/* 
 * File:   main.cpp
 * Author: browneyes
 *
 * Created on March 16, 2015, 9:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include "../TextFinder/TFObjectFactory.h"
#include "../TextFinder/ITFService.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    std::cout << "\n  ==============================================================";
    std::cout << "\n     Text Finder Service Start";
    std::cout << "\n  ==============================================================";
    if (argc < 4)
    {
        std::cout << "\n This Application only provide search service.\n ";
        std::cout << "\n CommandLine format:Command(search) path keywords(use space to separate) option";
        std::cout << "\n For example: search ../ keyword1 keyword2 /O\n\n";
        return 0;
    }

    std::string command = argv[1];
    if (command != "search")
    {
        std::cout << "\n This Application only provide search service.\n ";
	std::cout << "\n CommandLine format: Command(search) path keywords(use space to separate) option";
	std::cout << "\n For example: search ../ keyword1 keyword2 /O\n\n";
        return 0;
    }
    std::string path = argv[2];
    bool searchAll;
    int keywordsEnd;
    std::string temp = argv[argc - 1];
    if (temp == "/O" || temp == "/o")
    {
	searchAll = false;
        keywordsEnd = argc - 1;
    }
    else{
	searchAll = true;
        keywordsEnd = argc;
    }

    std::vector<std::string> keywords;
    for (int i = 3; i < keywordsEnd; i++)
    {
        keywords.push_back(argv[i]);
    }
    
    std::cout << "\n  Set Search Path: " << path;
    std::cout << "\n  Set Search Keywords: ";
    for (int i = 0; i < keywords.size(); i++)
    {
	std::cout << keywords[i] << "  ";
    }
    std::wcout << "\n  Set Search Option:";
    if (searchAll)
	std::cout << "files contain all keywords\n\n";
    else
	std::cout << "files contain any keyword\n\n";
    
    
    using HRclock = std::chrono::high_resolution_clock;  // C++11 alias
    HRclock::time_point tstart = HRclock::now();
    try{   
        ITFService* pTextFinder = TFObjectFactory::create(); //AddRef here
        
        pTextFinder->SetSearchPath(path);
        pTextFinder->SetSearchKeywords(keywords);
        pTextFinder->SetSearchOption(searchAll);
        std::vector<std::string> files = pTextFinder->GetResults();
        
        
        HRclock::time_point tend = HRclock::now();
        std::chrono::duration<double> time_span = 
        std::chrono::duration_cast<std::chrono::duration<double>>(tend - tstart);
        std::cout << "\n  ====Execution time : " << time_span.count() << " seconds====\n" << std::endl;

        std::cout << "  *****************\n";
        std::cout << "  *Search Result: *\n";
        std::cout << "  *****************\n"; 
        for(auto file : files)
        {
            std::cout << "  " << file << std::endl;
        }
         
         //TFObjectFactory::destory(pTextFinder);
        pTextFinder->Release();
    }
  catch (std::exception& ex)
  {
	  std::cout << "\n  " << ex.what() << "\n\n";
	  return 1;
  }
    std::cout << "\n\n";

    return 0;
}

