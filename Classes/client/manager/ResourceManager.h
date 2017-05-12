#pragma once

#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "cocos2d.h"
using namespace std;

USING_NS_CC;

class ResourceManager
{
public:
	static ResourceManager* getInstance();
	void loadPlistResource(string plistName);
	void unloadPlistResource(string plistName);
	void unloadImageResource(string imageName);
	void addToCache(string plistName);
	string getImageFullPath(string imageName);
	void pvrPlistImageAsyncCallback(Texture2D* texture);

private:
	map<string, int> s_plistsRefCount;
};

#endif	