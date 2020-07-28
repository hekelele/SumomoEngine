#include "ResourceLoader.h"
#include <iostream>

using namespace std;

ResourceLoader::ResourceLoader() {
}

ResourceLoader::~ResourceLoader() {
}

Image * ResourceLoader::findImage(const char * filePath)
{

	return nullptr;
}

Image * ResourceLoader::loadImage(const char * filePath)
{
	return nullptr;
}


int ResourceLoader::equal_char_array(const char * chara1, const char * chara2)
{
	if (chara1 == nullptr || chara2 == nullptr) {
		return 0;
	}

	char pt1, pt2;
	int offset1 = 0, offset2 = 0;
	pt1 = chara1[offset1];
	pt2 = chara2[offset2];
	while (pt1!='\0')
	{
		if (pt1 != pt2) {
			return 0;
		}
		offset1++;
		offset2++;
		pt1 = chara1[offset1];
		pt2 = chara2[offset2];
	}

	if (pt2!='\0')
	{
		return 0;
	}

	return 1;
}



