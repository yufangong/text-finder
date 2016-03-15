///////////////////////////////////////////////////////////////
// cppClient.cpp											 //
//                                                           //
///////////////////////////////////////////////////////////////

///////commandline commmand path keywords /O


#include "stdafx.h"
#include "../TextSearchCompt/TextSearchCompt_i.h"
#include <iostream>
#include <atlbase.h>
#include <atlsafe.h>
#include <chrono>

int _tmain(int argc, _TCHAR* argv[])
{
  std::wcout << L"\n  ==============================================================";
  std::wcout << L"\n     Text Finder Service Start";
  std::wcout << L"\n  ==============================================================\n";

  if (argc < 4)
  {
	  std::wcout << L"\n  This Application only provide search service.\n ";
	  std::wcout << L"\n  CommandLine format:Command(search) path keywords(use space to separate) option";
	  std::wcout << L"\n  For example: search ../ keyword1 keyword2 /O \n";
	  return -1;
  }

  std::wstring command = argv[1];
  if (command != L"search")
  {
	  std::wcout << L"\n  This Application only provide search service.\n ";
	  std::wcout << L"\n  CommandLine format: Command(search) path keywords(use space to separate) option";
	  std::wcout << L"\n  For example: search ../ keyword1 keyword2 /O \n";
	  return -1;

  }
  CComBSTR path(argv[2]);
  VARIANT_BOOL searchAll;
  int keywordsEnd;
  std::wstring temp = argv[argc - 1];
  if (temp == L"/O" || temp == L"/o")
  {
	  searchAll = false;
	  keywordsEnd = argc - 1;
  }
  else{
	  searchAll = true;
	  keywordsEnd = argc;
  }

  CComSafeArray<BSTR> keywords;
  for (int i = 3; i < keywordsEnd; i++)
  {
	  keywords.Add(argv[i]);
  }


  std::wcout << L"\n  Set Search Path: " << path.Copy();
  std::wcout << L"\n  Set Search Keywords: ";
  for (int i = 0; i < (int)keywords.GetCount(); i++)
  {
	  std::wcout << keywords[i].Copy() << "  ";
  }
  std::wcout << L"\n  Set Search Option:";
  if (searchAll)
	  std::wcout << L"files contain all keywords\n\n";
  else
	  std::wcout << L"files contain any keyword\n\n";




  HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  if(!SUCCEEDED(hr))
  {
    std::wcout << L"\n  could not initialize COM\n\n";
    return 1;
  }

  using HRclock = std::chrono::high_resolution_clock;  // C++11 alias
  HRclock::time_point tstart = HRclock::now();
  try
  {
	  CComQIPtr<ITextSearch> pTextFinder;
	  pTextFinder.CoCreateInstance(CLSID_TextSearch);

	  if (pTextFinder != 0)
	  {
		  pTextFinder->SetSearchPath(path);
		  pTextFinder->SetSearchKeywords(keywords);
		  pTextFinder->SetSearchOption(searchAll);

		  SAFEARRAY files;
		  SAFEARRAY* pFiles = &files;
		  pTextFinder->GetResults(&pFiles);
		  CComSafeArray<BSTR> Files;
		  Files.Attach(pFiles);

		  HRclock::time_point tend = HRclock::now();

		  std::chrono::duration<double> time_span
			  = std::chrono::duration_cast<std::chrono::duration<double>>(tend - tstart);

		  std::wcout << L"\n  =====Execution time : " << time_span.count() << " seconds=====" << L"\n\n";
		  std::wcout << L"  *****************\n";
		  std::wcout << L"  *Search Result: *\n";
		  std::wcout << L"  *****************\n";
		  for (int i = 0; i<(int)Files.GetCount(); ++i)
		  {
			  std::wcout << L"\n  " << Files[i].Copy();
		  }
	  }
  }
  catch (std::exception& ex)
  {
	  std::wcout << L"\n  " << ex.what() << L"\n\n";
	  return 1;
  }
  std::wcout << L"\n\n";
  CoUninitialize();
  return 0;
}

