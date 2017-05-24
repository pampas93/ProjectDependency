#pragma once
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
