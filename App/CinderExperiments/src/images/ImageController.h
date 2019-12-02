#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/TouchView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/utils/ImageManager.h"
#include "bluecadet/views/MaskView.h"
#include "bluecadet/views/EllipseView.h"


typedef std::shared_ptr<class ImageController> ImageControllerRef;

class ImageController : public bluecadet::views::BaseView {
public:
	void setup(ci::vec2 size, ci::vec2 position);
	void createEllipseMaskImage();

private:

	// Views
	bluecadet::views::ImageViewRef mImage;
	bluecadet::views::EllipseViewRef  mEllipseMask;
	bluecadet::views::MaskViewRef	mMask;

	// Props
	ci::vec2 mSize;
	ci::vec2 mPosition;


	// Consts
};