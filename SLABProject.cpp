//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit8.cpp", Form8);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	if(GetEnvironmentVariable("Path").Pos("cygwin")==0)
	{
		TStringList *list = new TStringList;
		list->Add("@echo off");
		list->Add("pushd %~dp0");
		list->Add("set PATH=%PATH%;%APPDATA%\\cygwin-x86\\cygwin\\bin");
		list->Add("start \"\" \""+ParamStr(0)+"\"");
		list->Add("exit");
		list->SaveToFile("launcher.bat",TEncoding::ANSI);
		system("start launcher.bat");
		return 0;
	}
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
