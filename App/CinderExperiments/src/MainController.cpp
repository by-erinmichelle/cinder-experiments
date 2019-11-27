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
	mControllerButtonSize = vec2(getSize().x / (4 * 1.25), 50);

	// setup buttons
	mButtonContainer = make_shared<BaseView>();
	setupButtons();
	mBackToMain = make_shared<TouchView>();
	mBackToMain->setAlpha(0);
	mBackToMain->setSize(getWidth() - 300, 50);
	mBackToMain->setBackgroundColor(Color(1, 0, 0));
	auto backText = make_shared<TextView>();
	backText->setText("Back");
	mBackToMain->addChild(backText);


	mButtonController = make_shared<ButtonController>();
	mButtonController->setup(getSize() - vec2(200));

	// add children
	addChild(mButtonController);
	addChild(mButtonContainer);
	addChild(mBackToMain);


}

void MainController::setupButtons()
{
	// buttons
	mShowButtonController = make_shared<TouchView>();
	mShowButtonController->setSize(mControllerButtonSize);
	mShowButtonController->setBackgroundColor(Color(1, 0, 0));
	auto showButtonText = make_shared<TextView>();
	showButtonText->setText("Buttons");
	mShowButtonController->addChild(showButtonText);
	mShowButtonController->getSignalTapped().connect([=](auto touch) {
		setState(BUTTONS);
	});

	// images
	mShowImageController = make_shared<TouchView>();
	mShowImageController->setSize(mControllerButtonSize);
	mShowImageController->setBackgroundColor(Color(0, 1, 0));
	mShowImageController->setPosition(mShowButtonController->getPosition() + vec2(mControllerButtonSize.x * 1.25, 0));
	auto showImageText = make_shared<TextView>();
	showImageText->setText("Images");
	mShowImageController->addChild(showImageText);
	mShowImageController->getSignalTapped().connect([=](auto touch) {
		setState(IMAGES);
	});

	// lines
	mShowLineController = make_shared<TouchView>();
	mShowLineController->setSize(mControllerButtonSize);
	mShowLineController->setBackgroundColor(Color(1, 0, 1));
	mShowLineController->setPosition(mShowImageController->getPosition() + vec2(mControllerButtonSize.x * 1.25, 0));
	auto showLineText = make_shared<TextView>();
	showLineText->setText("Lines");
	mShowLineController->addChild(showLineText);
	mShowLineController->getSignalTapped().connect([=](auto touch) {
		setState(LINES);
	});

	// text
	mShowTextController = make_shared<TouchView>();
	mShowTextController->setSize(mControllerButtonSize);
	mShowTextController->setBackgroundColor(Color(1, 1, 0));
	mShowTextController->setPosition(mShowLineController->getPosition() + vec2(mControllerButtonSize.x * 1.25, 0));
	auto showTextText = make_shared<TextView>();
	showTextText->setText("Text");
	mShowTextController->addChild(showTextText);
	mShowTextController->getSignalTapped().connect([=](auto touch) {
		setState(TEXT);
	});

	// add children
	mButtonContainer->addChild(mShowButtonController);
	mButtonContainer->addChild(mShowImageController);
	mButtonContainer->addChild(mShowLineController);
	mButtonContainer->addChild(mShowTextController);
}

void MainController::postLoadingSetup() {

}

void MainController::setState(State newState)
{
	switch (newState) {
	case BUTTONS:
		hideButtons();

		mButtonController->setAlpha(1.0);
		break;
	case LINES:
		hideButtons();

		break;

	case IMAGES:
		hideButtons();

		break;

	case TEXT:
		hideButtons();

		break;
	case MAIN:
		showButtons();
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
