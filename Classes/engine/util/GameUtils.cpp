#include "GameUtils.h"
#include <stdlib.h>

Sprite* getSprite(string filename, float x, float y, Vec2 anchorPoint)
{
	Sprite *psprite = Sprite::create();

	// Search in the cache, first
	SpriteFrameCache *sfc = SpriteFrameCache::getInstance();
	SpriteFrame *psf = sfc->getSpriteFrameByName(filename.c_str());

	string::size_type pos;
	if (!psf && (pos = filename.find_last_of('/')) != filename.npos)
	{
		string lastPart(filename.begin() + pos + 1, filename.end());
		psf = sfc->getSpriteFrameByName(lastPart.c_str());
	}

	if (psf)
	{
		psprite->initWithSpriteFrame(psf);
	}
	else
	{
		log("WARNING : %s not in a PACK!", filename.c_str() );
		if (!psprite->initWithFile(filename.c_str()))
		{
			log("ERROR: %s is not in resources", filename.c_str());
			return NULL;
		}
	}

	psprite->setPosition(x, y);
	psprite->setAnchorPoint(anchorPoint);
	return psprite;
}

SpriteFrame* getSpriteFrameByName(const string spriteName)
{
	return SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteName);
}

bool resourcePresentForLoading(string filename)
{
	return FileUtils::getInstance()->isFileExist(filename);
}

Button* createButton(const float x, const float y, 
				     const std::string &imagePattern, 
					 const Widget::ccWidgetClickCallback &clickEvent,
					 const bool bright,
					 const std::string joiner,
					 const string imageExt, 
					 const int start)
{
	return createButton(x, y,
					    imagePattern + joiner + to_string(start) + imageExt,
						imagePattern + joiner + to_string(start + 1) + imageExt,
						imagePattern + joiner + to_string(start + 2) + imageExt,
						imagePattern + joiner + to_string(start + 3) + imageExt, 
						clickEvent, 
						bright);
}

Button* createButton(const float x, const float y, 
					 const std::string &normalImage,
					 const std::string &hoverImage,
					 const std::string &pressedImage,
					 const std::string &disableImage,
				     const Widget::ccWidgetClickCallback &clickEvent,
					 const bool bright,
					 Vec2 anchorPoint,
					 Widget::TextureResType texType)
{
	auto button = Button::create(normalImage, hoverImage, pressedImage, disableImage, texType);
	button->setPosition(Vec2(x, y));
	button->setAnchorPoint(anchorPoint);
	button->addClickEventListener(clickEvent);
	button->setBright(bright);
	return button;
}

const char* gbk2UTF8(const char* gb2312)
{
	int len = MultiByteToWideChar(0, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(0, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(65001, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(65001, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}


Animation* createAnimation(const std::string &spriteName, int frames, float delay, bool loop, bool restoreOriginalFrame, bool isPattern)
{
	std::string pattern = "{n}";
	Vector<SpriteFrame*> spriteFrames;
	for (int i = 1; i <= frames; i++)
	{
		if (!isPattern)
		{
			spriteFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteName + "-" + to_string(i) + ".png"));
		}
		else
		{
			string::size_type pos = spriteName.find(pattern);
			std::string resource = spriteName;
			resource.replace(pos, pattern.length(), to_string(i));

			spriteFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(resource));
		}
	}

	Animation *animation = Animation::createWithSpriteFrames(spriteFrames);
	if (loop)
	{
		animation->setLoops(-1);
	}

	animation->setRestoreOriginalFrame(restoreOriginalFrame);
	animation->setDelayPerUnit(delay);

	return animation;
}

void preLoadResources(const vector<std::string> resources)
{
	for (int i = 0; i < resources.size(); i++)
	{
		preLoadResource(resources[i]);
	}
}

void preLoadResources(const std::string resourcePattern, int start, int end, const std::string pattern)
{
	string::size_type pos = resourcePattern.find(pattern);
	if (pos)
	{
		for (int i = start; i <= end; i++)
		{
			std::string resource = resourcePattern;
			resource.replace(pos, pattern.length(), to_string(i));
			preLoadResource(resource);
		}
	}
}

void preLoadResource(const std::string resource)
{
	if (FileUtils::getInstance()->isFileExist(resource))
	{
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(resource);
	}
}

void asyncLoadResources(const std::string resourcePattern, int start, int end, 
	const std::function<void(Texture2D*)>& callback, const std::string pattern)
{
	string::size_type pos = resourcePattern.find(pattern);
	if (pos)
	{
		for (int i = start; i <= end; i++)
		{
			std::string resource = resourcePattern;
			resource.replace(pos, pattern.length(), to_string(i));
			Director::getInstance()->getTextureCache()->addImageAsync(resource, callback);
		}
	}
}