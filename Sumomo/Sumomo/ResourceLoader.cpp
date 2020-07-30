#include "ResourceLoader.h"
#include <iostream>
#include "SumomoGame.h"

using namespace std;
using namespace Sumomo;

ResourceLoader::ResourceLoader() {
}

ResourceLoader::~ResourceLoader() {
	imageResPaths.clear();
	for (unsigned int i = 0; i < imageRes.size(); i++) {
		delete imageRes[i];
	}
	imageRes.clear();
	Gdiplus::GdiplusShutdown(m_pGdiToken);
}

Bitmap * ResourceLoader::findImage(const WCHAR* filePath)
{
	for (unsigned int i = 0; i < imageResPaths.size(); i++) {
		if (wcscmp(filePath, imageResPaths[i])) {
			//cout << "found" << endl;
			return imageRes[i];
		}
	}
	//cout << "not found" << endl;
	return nullptr;
}

Bitmap * ResourceLoader::loadImage(const WCHAR* filePath)
{
	Bitmap* old = findImage(filePath);
	if (old != nullptr) {
		return old;
	}

	Bitmap* new_image;
	new_image = new Bitmap((WCHAR*)filePath);
	imageRes.push_back(new_image);
	imageResPaths.push_back(filePath);
	return new_image;
}

