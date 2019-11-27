#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/TouchView.h"
#include "bluecadet/views/TextView.h"


typedef std::shared_ptr<class ImageController> ImageControllerRef;

class ImageController : public bluecadet::views::BaseView {
public:
	void setup(ci::vec2 size);

private:

	// Props
	ci::vec2 mSize;

	// Consts
};