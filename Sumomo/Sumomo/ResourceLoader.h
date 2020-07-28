#pragma once
#include <windows.h>
#include <gdiplus.h>
#include <vector>
using namespace Gdiplus;
using namespace std;
#pragma comment(lib, "Gdiplus.lib")

class ResourceLoader
{
public:
	Bitmap* loadImage(const WCHAR* filePath);
	ResourceLoader();
	~ResourceLoader();
private:
	Bitmap* findImage(const WCHAR* filePath);
	vector<Bitmap*>		imageRes;
	vector<const WCHAR*> imageResPaths;

};

