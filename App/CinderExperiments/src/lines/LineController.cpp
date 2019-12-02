#include "LineController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::views;

void LineController::setup(ci::vec2 size, ci::vec2 position)
{
	setSize(size);
	setPosition(position);
	setAlpha(0.0f);

	mSize = vec2(200, 0);

	mButton = make_shared<TouchView>();
	mButton->setSize(300, 70);
	mButton->setPosition(size - mButton->getSize());
	addChild(mButton);
	mButtonText = make_shared<TextView>();
	mButtonText->setup("Animate Lines", "menuButton");
	mButtonText->setCenter(mButton->getSize() / vec2(2));
	mButton->addChild(mButtonText);

	mButton->getSignalTapped().connect([=](auto touch) {
		if (!hasAnimated) {
			animateText();
			animateLines();
		}
	});
}

void LineController::drawFromCenter()
{
	mLine = make_shared<LineView>();
	mLineWidth = 0.0f;
	mLinePosition = mSize.x / 2;
	mLine->setup(vec2(0), Color(0, 0, 0), 5.0f);
	mLine->setPosition(mLinePosition, mSize.y);

	//animate line out (end point)
	mLine->getTimeline()->apply(&mLineWidth, mSize.x, 1.5f, EaseInOutSine()).updateFn([=] {
		mLine->setEndPoint(vec2(mLineWidth, 0));
		});
	//animate line out (start point)
	mLine->getTimeline()->apply(&mLinePosition, 0.0f, 1.5f, EaseInOutSine()).updateFn([=] {
		mLine->setPosition(vec2(mLinePosition, mSize.y));
		});

	dispatchAfter([=] {
		//animate line in (end point)
		mLine->getTimeline()->apply(&mLineWidth, 0.0f, 1.5f, EaseInOutSine()).updateFn([=] {
			mLine->setEndPoint(vec2(mLineWidth, 0));
			});
		//animate line in (start point)
		mLine->getTimeline()->apply(&mLinePosition, mSize.x / 2, 1.5f, EaseInOutSine()).updateFn([=] {
			mLine->setPosition(vec2(mLinePosition, mSize.y));
			hasAnimated = false;
			});
	}, 2.0f );

	addChild(mLine);
}

void LineController::animateLines()
{
	drawFromCenter();
}

void LineController::animateText()
{
	hasAnimated = true;
	mButtonTextColor = Color(0, 0, 0);
	mButtonText->getTimeline()->apply(&mButtonTextColor, Color(.5, .5, .5), .35, EaseInOutSine()).updateFn([=] {
		mButtonText->setTextColor(mButtonTextColor);
	});

	dispatchAfter([=] {
		mButtonText->getTimeline()->apply(&mButtonTextColor, Color(0, 0, 0), .35, EaseInOutSine()).updateFn([=] {
			mButtonText->setTextColor(mButtonTextColor);
		});		
	}, 5.0f);
}
