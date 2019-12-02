#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/TouchView.h"
#include "bluecadet/views/TextView.h"
#include "bluecadet/views/LineView.h"


typedef std::shared_ptr<class LineController> LineControllerRef;

class LineController : public bluecadet::views::BaseView {
public:
	void setup(ci::vec2 size, ci::vec2 position);
	void drawFromCenter();
	void animateLines();
	void animateText();

private:

	// Views
	bluecadet::views::LineViewRef mLine;
	bluecadet::views::TouchViewRef mButton;
	bluecadet::views::TextViewRef mButtonText;
	
	// Props
	ci::vec2 mSize;
	ci::Anim<float> mLineWidth;
	ci::Anim<float> mLinePosition;
	ci::Anim<ci::Color> mButtonTextColor;
	bool hasAnimated = false;
	// Consts
};