//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit4.cpp", Form4);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
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
		Application->MainFormOnTaskBar = true;
        Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
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
