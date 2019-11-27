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

	mButtonController = make_shared<ButtonController>();
	mButtonController->setup(getSize() - vec2(200));
	addChild(mButtonController);
}

void MainController::postLoadingSetup() {

}