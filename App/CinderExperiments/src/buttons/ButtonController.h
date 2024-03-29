#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/TouchView.h"
#include "bluecadet/views/TextView.h"
#include "bluecadet/views/StrokedRectView.h"


typedef std::shared_ptr<class ButtonController> ButtonControllerRef;
 
class ButtonController : public bluecadet::views::BaseView {
public:
	void setup(ci::vec2 size, ci::vec2 position);
	void handleHitState(cinder::EaseFn easing, int i);

private:

	// Props
	std::vector<bluecadet::views::TouchViewRef> mButtons;
	ci::vec2 mSize;

	// Consts
	const ci::vec2 kPosition = ci::vec2(0, 0);
	const float kPadding = 1.25;

};