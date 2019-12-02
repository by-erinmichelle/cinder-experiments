#include "MainController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::text;

MainController::MainController() : BaseView() { }

MainController::~MainController() { }

void MainController::setup() {
	setSize(ScreenLayout::getInstance()->getAppSize());
	setBackgroundColor(Color(1, 1, 1));

	// Setup styles
	StyleManager::getInstance()->setup(getAssetPath("fonts/styles.json"), "styles");

	//Setup StyledTextParser
	StyledTextParser::getInstance()->setDefaultOptions(
		StyledTextParser::OptionFlags::INVERT_NESTED_ITALICS |
		StyledTextParser::OptionFlags::TRIM_WHITESPACE |
		StyledTextParser::OptionFlags::TRIM_LEADING_BREAKS |
		StyledTextParser::OptionFlags::TRIM_TRAILING_BREAKS
	);

	mControllerSize = (getSize() - vec2(200));
	mControllerButtonSize = vec2(getSize().x / (4 * 2), 70);

	// setup buttons
	mButtonContainer = make_shared<BaseView>();
	setupButtons();
	mBackToMain = make_shared<TouchView>();
	mBackToMain->setAlpha(0);
	mBackToMain->setSize(mControllerButtonSize);
	mBackToMain->setPosition(mControllerButtonSize.x / 2, getHeight() - mControllerButtonSize.y - 50.0f);
	mBackToMain->setBackgroundColor(Color(0, 0, 0));
	auto backText = make_shared<TextView>();
	backText->setup("Back", "menuButton");
	backText->setTextColor(Color(1, 1, 1));
	backText->setCenter(mControllerButtonSize / vec2(2));
	mBackToMain->addChild(backText);

	// setup controllers
	mButtonController = make_shared<ButtonController>();
	mButtonController->setup(mControllerSize, mControllerPosition);
	mImageController = make_shared<ImageController>();
	mImageController->setup(mControllerSize, mControllerPosition);
	mLineController = make_shared<LineController>();
	mLineController->setup(mControllerSize, mControllerPosition);
	mTextController = make_shared<TextController>();
	mTextController->setup(mControllerSize, mControllerPosition);

	// add children
	addChild(mButtonController);
	addChild(mImageController);
	addChild(mLineController);
	addChild(mTextController);
	addChild(mButtonContainer);
	addChild(mBackToMain);
}

void MainController::setupButtons()
{
	// buttons
	mShowButtonController = make_shared<TouchView>();
	auto showButtonText = make_shared<TextView>();
	showButtonText->setup("Buttons", "menuButton");
	showButtonText->setCenter(mControllerButtonSize / vec2(2));
	mShowButtonController->addChild(showButtonText);
	mShowButtonController->getSignalTapped().connect([=](auto touch) {
		setState(BUTTONS);
	});
	mButtons.push_back(mShowButtonController);

	// images
	mShowImageController = make_shared<TouchView>();
	auto showImageText = make_shared<TextView>();
	showImageText->setup("Images", "menuButton");
	showImageText->setCenter(mControllerButtonSize / vec2(2));
	mShowImageController->addChild(showImageText);
	mShowImageController->getSignalTapped().connect([=](auto touch) {
		setState(IMAGES);
	});
	mButtons.push_back(mShowImageController);

	// lines
	mShowLineController = make_shared<TouchView>();
	auto showLineText = make_shared<TextView>();
	showLineText->setup("Lines", "menuButton");
	showLineText->setCenter(mControllerButtonSize / vec2(2));
	mShowLineController->addChild(showLineText);
	mShowLineController->getSignalTapped().connect([=](auto touch) {
		setState(LINES);
	});
	mButtons.push_back(mShowLineController);

	// text
	mShowTextController = make_shared<TouchView>();
	auto showTextText = make_shared<TextView>();
	showTextText->setup("Text", "menuButton");
	showTextText->setCenter(mControllerButtonSize / vec2(2));
	mShowTextController->addChild(showTextText);
	mShowTextController->getSignalTapped().connect([=](auto touch) {
		setState(TEXT);
	});
	mButtons.push_back(mShowTextController);

	for (int i = 0; i < mButtons.size(); i++) {
		mButtons[i]->setSize(mControllerButtonSize);

		auto stroke = make_shared<StrokedRectView>();
		stroke->setStrokeWidth(2.5f);
		stroke->setStrokeColor(Color(0, 0, 0));
		stroke->setSize(mButtons[i]->getSize());
		stroke->setSmoothness(0.0f);
		mButtons[i]->addChild(stroke);

		if (i >= 1) {
			int j = i - 1;
			mButtons[i]->setPosition(mButtons[j]->getPosition() + vec2(mControllerButtonSize.x * 2, 0));
		}

		mButtons[i]->getSignalTouchBegan().connect([=](auto touch) {
			mButtons[i]->getTimeline()->apply(&mButtons[i]->getScale(), vec2(.94f), .1f, EaseInOutSine());
		});
		mButtons[i]->getSignalTouchEnded().connect([=](auto touch) {
			mButtons[i]->getTimeline()->apply(&mButtons[i]->getScale(), vec2(1.0f), .1f, EaseInOutSine());
		});

		mButtons[i]->setTransformOrigin(mButtons[i]->getSize() / vec2(2));
	}

	// add children
	mButtonContainer->addChild(mShowButtonController);
	mButtonContainer->addChild(mShowImageController);
	mButtonContainer->addChild(mShowLineController);
	mButtonContainer->addChild(mShowTextController);

	mButtonContainer->setPosition(mControllerButtonSize.x / 2, getHeight() - mControllerButtonSize.y - 50.0f);
}

void MainController::postLoadingSetup() {

}

void MainController::setState(State newState)
{
	switch (newState) {
	case BUTTONS:
		hideButtons();
		mButtonController->setAlpha(1.0);
		//hide
		mLineController->setAlpha(0.0);
		mImageController->setAlpha(0.0);
		mTextController->setAlpha(0.0);
		break;
	case LINES:
		hideButtons();
		mLineController->setAlpha(1.0);
		//hide
		mButtonController->setAlpha(0.0);
		mImageController->setAlpha(0.0);
		mTextController->setAlpha(0.0);
		break;
	case IMAGES:
		hideButtons();
		mImageController->setAlpha(1.0);
		//hide
		mButtonController->setAlpha(0.0);
		mLineController->setAlpha(0.0);
		mTextController->setAlpha(0.0);
		break;
	case TEXT:
		hideButtons();
		mTextController->setAlpha(1.0);
		//hide
		mButtonController->setAlpha(0.0);
		mImageController->setAlpha(0.0);
		mLineController->setAlpha(0.0);
		break;
	case MAIN:
		showButtons();
		//hide
		mButtonController->setAlpha(0.0);
		mImageController->setAlpha(0.0);
		mTextController->setAlpha(0.0);
		mLineController->setAlpha(0.0);
		break;
	}
}

void MainController::hideButtons()
{
	mButtonContainer->setAlpha(0);
	mBackToMain->setAlpha(1);
	mBackToMain->getSignalTapped().connect([=](auto touch) {
		setState(MAIN);
	});
}

void MainController::showButtons()
{
	mButtonContainer->setAlpha(1);
	mBackToMain->setAlpha(0);
}
