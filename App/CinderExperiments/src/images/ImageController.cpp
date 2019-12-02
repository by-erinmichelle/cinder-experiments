#include "ImageController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::views;
using namespace bluecadet::utils;

void ImageController::setup(ci::vec2 size, ci::vec2 position)
{
	setSize(size);
	setPosition(position);
	setAlpha(0.0f);

	mSize = vec2(300);
	mPosition = vec2(0);

	ImageManager::getInstance()->loadAllFromDir(getAssetPath("images"));

	createEllipseMaskImage();
	createDuotoneImage();
}

void ImageController::createEllipseMaskImage()
{
	// ellipse mask
	mMask = make_shared<MaskView>();
	mMask->setSize(mSize);
	mMask->setPosition(mPosition);

	mEllipseMask = make_shared<EllipseView>();
	mEllipseMask->setup(mSize, ColorA(1, 1, 1, 0));
	mEllipseMask->setPosition(mSize / vec2(2)); // by default ellipse will position from it's center
	mMask->setMask(mEllipseMask); // set the mask for the mask view. this will mask all of the mask view's content & children

	mImage = make_shared<ImageView>();
	mImage->setTexture(ImageManager::getInstance()->getTexture("pekingnese.jpg"));
	mImage->setScaleMode(ImageView::ScaleMode::COVER);
	mImage->setSize(mSize);

	// add children
	addChild(mMask);
	mMask->addChild(mImage);
	mMask->addChild(mEllipseMask);
}

void ImageController::createDuotoneImage()
{
	mDuotoneImage = make_shared<ImageView>();
	mDuotoneImage->setTexture(ImageManager::getInstance()->getTexture("komondor.jpg"));
	mDuotoneImage->setScaleMode(ImageView::ScaleMode::COVER);
	mDuotoneImage->setSize(mSize);
	mDuotoneImage->setPosition(mPosition + vec2(mSize.x + 100, 0));
	mDuotoneImage->setTint(Color(1, 0, 1));
	addChild(mDuotoneImage);
}
