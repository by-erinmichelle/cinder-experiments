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

typedef std::shared_ptr<class MainController> MainControllerRef;

class MainController : public bluecadet::views::BaseView {
public:
	MainController();
	~MainController();

	void setup();
	void postLoadingSetup();
private:
	ButtonControllerRef mButtonController;
};