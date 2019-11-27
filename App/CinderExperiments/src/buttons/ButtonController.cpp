#include "ButtonController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::views;

void ButtonController::setup(ci::vec2 size)
{
	setSize(size);
	setPosition(vec2(100));
	setAlpha(0.0f);

	mSize = vec2(size.x / (6 * kPadding), 50);

	for (int i = 0; i < 16; i++) {
		auto mButton = make_shared<TouchView>();
		mButton->setSize(mSize);
		mButton->setBackgroundColor(Color(1, 1, 0));
		if (i <= 5)
			mButton->setPosition(kPosition + vec2(i * mSize.x * kPadding, 0));
		if (i > 5 && i <= 10)
			mButton->setPosition(mButton->getPosition() + vec2((i - 6) * mSize.x * kPadding, 100));
		if (i > 10)
			mButton->setPosition(mButton->getPosition() + vec2((i - 11) * mSize.x * kPadding, 200));

		addChild(mButton);

		auto mText = make_shared<TextView>();
		mText->setPosition(vec2(15));
		mButton->addChild(mText);

		mButtons.push_back(mButton);

		switch (i) {
			case 0: {
				handleHitState(EaseInAtan(), i);
				mText->setText("ease in atan");
				break;
			}
			case 1: {
				handleHitState(EaseInBack(), i);
				mText->setText("ease in back");
				break;
			}
			case 2: {
				handleHitState(EaseInBounce(), i);
				mText->setText("ease in bounce");
				break;
			}
			case 3: {
				handleHitState(EaseInCirc(), i);
				mText->setText("ease in circ");
				break;
			}
			case 4: {
				handleHitState(EaseInCubic(), i);
				mText->setText("ease in cubic");
				break;
			}
			case 5: {
				handleHitState(EaseInExpo(), i);
				mText->setText("ease in expo");
				break;
			}
			case 6: {
				handleHitState(EaseInOutAtan(), i);
				mText->setText("ease in out atan");
				break;
			}
			case 7: {
				handleHitState(EaseInOutBack(), i);
				mText->setText("ease in out back");
				break;
			}
			case 8: {
				handleHitState(EaseInOutBounce(), i);
				mText->setText("ease in out bounce");
				break;
			}
			case 9: {
				handleHitState(EaseInOutCirc(), i);
				mText->setText("ease in out circ");
				break;
			}
			case 10: {
				handleHitState(EaseInOutCubic(), i);
				mText->setText("ease in out cubic");
				break;
			}
			case 11: {
				handleHitState(EaseInOutExpo(), i);
				mText->setText("ease in out expo");
				break;
			}
			case 12: {
				handleHitState(EaseInOutQuad(), i);
				mText->setText("ease in out quad");
				break;
			}
			case 13: {
				handleHitState(EaseInOutQuart(), i);
				mText->setText("ease in out quart");
				break;
			}
			case 14: {
				handleHitState(EaseInOutQuint(), i);
				mText->setText("ease in out quint");
				break;
			}
			case 15: {
				handleHitState(EaseInOutSine(), i);
				mText->setText("ease in out sine");
				break;
			}
		}

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
