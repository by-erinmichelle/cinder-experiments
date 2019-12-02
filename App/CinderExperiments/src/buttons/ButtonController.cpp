#include "ButtonController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::views;

void ButtonController::setup(ci::vec2 size, ci::vec2 position)
{
	setSize(size);
	setPosition(position);
	setAlpha(0.0f);

	mSize = vec2(size.x / (6 * kPadding), 70);

	for (int i = 0; i < 16; i++) {
		auto mButton = make_shared<TouchView>();
		mButton->setSize(mSize);
		mButton->setBackgroundColor(Color(0, 0, 1));
		if (i <= 5)
			mButton->setPosition(kPosition + vec2(i * mSize.x * kPadding, 0));
		if (i > 5 && i <= 10)
			mButton->setPosition(mButton->getPosition() + vec2((i - 6) * mSize.x * kPadding, 100));
		if (i > 10)
			mButton->setPosition(mButton->getPosition() + vec2((i - 11) * mSize.x * kPadding, 200));

		addChild(mButton);

		auto text = make_shared<TextView>();
		mButton->addChild(text);

		mButtons.push_back(mButton);

		switch (i) {
			case 0: {
				handleHitState(EaseInAtan(), i);
				text->setup("ease in atan", "buttonDemo.easing");
				break;
			}
			case 1: {
				handleHitState(EaseInBack(), i);
				text->setup("ease in back", "buttonDemo.easing");
				break;
			}
			case 2: {
				handleHitState(EaseInBounce(), i);
				text->setup("ease in bounce", "buttonDemo.easing");
				break;
			}
			case 3: {
				handleHitState(EaseInCirc(), i);
				text->setup("ease in circ", "buttonDemo.easing");
				break;
			}
			case 4: {
				handleHitState(EaseInCubic(), i);
				text->setup("ease in cubic", "buttonDemo.easing");
				break;
			}
			case 5: {
				handleHitState(EaseInExpo(), i);
				text->setup("ease in expo", "buttonDemo.easing");
				break;
			}
			case 6: {
				handleHitState(EaseInOutAtan(), i);
				text->setup("ease in out atan", "buttonDemo.easing");
				break;
			}
			case 7: {
				handleHitState(EaseInOutBack(), i);
				text->setup("ease in out back", "buttonDemo.easing");
				break;
			}
			case 8: {
				handleHitState(EaseInOutBounce(), i);
				text->setup("ease in out bounce", "buttonDemo.easing");
				break;
			}
			case 9: {
				handleHitState(EaseInOutCirc(), i);
				text->setup("ease in out circ", "buttonDemo.easing");
				break;
			}
			case 10: {
				handleHitState(EaseInOutCubic(), i);
				text->setup("ease in out cubic", "buttonDemo.easing");
				break;
			}
			case 11: {
				handleHitState(EaseInOutExpo(), i);
				text->setup("ease in out expo", "buttonDemo.easing");
				break;
			}
			case 12: {
				handleHitState(EaseInOutQuad(), i);
				text->setup("ease in out quad", "buttonDemo.easing");
				break;
			}
			case 13: {
				handleHitState(EaseInOutQuart(), i);
				text->setup("ease in out quart", "buttonDemo.easing");
				break;
			}
			case 14: {
				handleHitState(EaseInOutQuint(), i);
				text->setup("ease in out quint", "buttonDemo.easing");
				break;
			}
			case 15: {
				handleHitState(EaseInOutSine(), i);
				text->setup("ease in out sine", "buttonDemo.easing");
				break;
			}

		}

		text->setCenter(mButton->getSize() / vec2(2));

		mButton->setTransformOrigin(mButton->getSize() / vec2(2));
	}

}

void ButtonController::handleHitState(cinder::EaseFn easing, int i) {
	mButtons[i]->getSignalTouchBegan().connect([=](auto e) {
		mButtons[i]->getTimeline()->apply(&mButtons[i]->getScale(), vec2(0.7f), .5f, easing);
	});
	mButtons[i]->getSignalTouchEnded().connect([=](auto e) {
		mButtons[i]->getTimeline()->apply(&mButtons[i]->getScale(), vec2(1.0f), .5f, easing);
	});
}
