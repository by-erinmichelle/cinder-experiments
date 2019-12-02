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

	mSize = vec2(100, 0);

	mButton = make_shared<TouchView>();
	mButton->setSize(100, 50);
	mButton->setPosition(size - mButton->getSize());
	mButton->setBackgroundColor(Color(1, 1, 0));
	addChild(mButton);

	mButton->getSignalTapped().connect([=](auto touch) {
		animateLines();
	});

}

void LineController::drawFromCenter()
{
	mLine = make_shared<LineView>();
	mLineWidth = 0.0f;
	mLinePosition = mSize.x / 2;
	mLine->setup(vec2(0), Color(1, 1, 1), 3.0f);
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
			});
	}, 2.0f );

	addChild(mLine);
}

void LineController::animateLines()
{
	drawFromCenter();
}
