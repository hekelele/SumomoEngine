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
	Image* loadImage(const char* filePath);
	ResourceLoader();
	~ResourceLoader();
private:
	Image* findImage(const char* filePath);
	int equal_char_array(const char* chara1, const char* chara2);
	vector<Image*>		imageRes;
	vector<const char*> imageResPaths;

};

