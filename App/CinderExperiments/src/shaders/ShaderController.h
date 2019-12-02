#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/TouchView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/utils/ImageManager.h"


typedef std::shared_ptr<class ShaderController> ShaderControllerRef;

class ShaderController : public bluecadet::views::BaseView {
public:
	void setup();
	void draw() override;

private:

	// Views

	ci::CameraPersp		mCam;
	ci::gl::BatchRef	mBox;


	// Props


	// Consts
};