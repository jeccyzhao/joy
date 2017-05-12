#include "ResourceManager.h"

#include "cocos2d.h"

static ResourceManager* _instance = NULL;
string _plistName = "";
ResourceManager* ResourceManager::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ResourceManager();
	}

	return _instance;
};

void ResourceManager::loadPlistResource(string plistName)
{
	if (FileUtils::getInstance()->isFileExist(plistName + string(".plist")))
	{
		if (s_plistsRefCount[plistName] == 0)
		{
			_plistName = plistName;

			SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(_plistName + string(".plist"));

			//Director::getInstance()->getTextureCache()->addImageAsync(
			//	string(plistName) + string(".pvr.ccz"),
			//	CC_CALLBACK_1(ResourceManager::pvrPlistImageAsyncCallback, this));
		}
	}
	else
	{
		log("plist file %s does not exist", plistName);
	}
}

void ResourceManager::pvrPlistImageAsyncCallback(Texture2D* texture)
{
	if (_plistName != "")
	{
		SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(_plistName + string(".plist"), texture);
		log("Plist resource %s loaded and cached", _plistName.c_str());
		log("%s", Director::getInstance()->getTextureCache()->getCachedTextureInfo());
		log("Plist resource %s loaded and cached", _plistName);
		++s_plistsRefCount[_plistName];
	}
};

void ResourceManager::addToCache(string plistName)
{
	if (s_plistsRefCount[plistName] == 0)
	{
		log("Plist resource %s loaded and cached", plistName);
	}
};

void ResourceManager::unloadPlistResource(string plistName)
{
	assert(s_plistsRefCount.find(plistName) != s_plistsRefCount.end(), "Remove plist not found!");
	assert(s_plistsRefCount[plistName] > 0, "Reference count can not be zero!");

	--s_plistsRefCount[plistName];
	if (s_plistsRefCount[plistName] == 0)
	{
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile(plistName);
		TextureCache::getInstance()->removeTextureForKey(string(plistName) + string(".pvr.gz"));
		log("Plist resource %s unloaded and erased from cache", plistName);

		s_plistsRefCount.erase(plistName);
	}
}