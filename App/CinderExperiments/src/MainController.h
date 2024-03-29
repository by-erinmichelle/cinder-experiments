#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/views/BaseView.h"
#include "bluecadet/text/FontManager.h"
#include "bluecadet/text/StyleManager.h"
#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"
#include "bluecadet/text/StyledTextParser.h"
#include "buttons/ButtonController.h"
#include "images/ImageController.h"
#include "lines/LineController.h"
#include "text/TextController.h"
#include "shaders/ShaderController.h"
#include "bluecadet/views/StrokedRectView.h"

typedef std::shared_ptr<class MainController> MainControllerRef;

class MainController : public bluecadet::views::BaseView {
public:
	MainController();
	~MainController();

	enum State { BUTTONS, IMAGES, LINES, TEXT, MAIN };

	void setup();
	void setupButtons();
	void postLoadingSetup();
	void setState(State newState);
	void hideMenu();
	void showMenu();

private:

	// Views
	ButtonControllerRef mButtonController;
	ImageControllerRef mImageController;
	LineControllerRef mLineController;
	TextControllerRef mTextController;
	ShaderControllerRef mShaderController;

	bluecadet::views::BaseViewRef mButtonContainer;
	bluecadet::views::TouchViewRef mShowButtonController;
	bluecadet::views::TouchViewRef mShowImageController;
	bluecadet::views::TouchViewRef mShowLineController;
	bluecadet::views::TouchViewRef mShowTextController;
	bluecadet::views::TouchViewRef mBackToMain;
	bluecadet::views::TextViewRef mTitle;


	ci::vec2 mControllerButtonSize;
	ci::vec2 mControllerSize;
	ci::vec2 mControllerPosition;
	std::vector<bluecadet::views::TouchViewRef> mButtons;

};