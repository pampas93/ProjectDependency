#pragma once

/////////////////////////////////////////////////////////////////////
//  bridger.h												       //
//																   //
//  Language:      Visual C++ 2015                                 //
//  Platform:      Dell Inspiron, Windows 8.1			           //
//  Application:   ProjectDependency- PempPassionProjects	       //
//  Author:        Abhijit Srikanth SUID:864888072			       //
/////////////////////////////////////////////////////////////////////
/*
Module Operations :
== == == == == == == == ==

This module defines a Bridger for Connecting the GUI class with CodeExecutive
Bridger class (bridger.cpp) implements IBridger
> Connects GUI with CodeExecutive
> Opens the Browser to display dependencies.

*/

#define DLL_DECL __declspec(dllexport)


struct IBridger
{
public:
	virtual void start(char* path) = 0;
	virtual void open()= 0;
	virtual void stop() = 0;
};

extern "C" {
	struct ObjectFactory
	{
		DLL_DECL IBridger* createBridger();
	};
}
