#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/core/BaseApp.h"
#include "bluecadet/text/FontManager.h"
#include "bluecadet/text/StyledTextParser.h"
#include "MainController.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet::core;
using namespace bluecadet::text;


class CinderExperimentsApp : public BaseApp {
  public:
	static void prepareSettings(ci::app::App::Settings* settings);
	void setup() override;
	void update() override;
	void draw() override;
	MainControllerRef mMainController;
};

void CinderExperimentsApp::setup()
{
	BaseApp::setup();

	// Setting up fonts
	FontManager::getInstance()->setFontScale(1.0f / getDisplay()->getContentScale());
	FontManager::getInstance()->setup(getAssetPath("fonts/fonts.json"));
	StyleManager::getInstance()->setup(getAssetPath("fonts/styles.json"), "styles");
	StyledTextParser::getInstance()->setDefaultOptions(
		StyledTextParser::OptionFlags::INVERT_NESTED_ITALICS | StyledTextParser::OptionFlags::TRIM_WHITESPACE |
		StyledTextParser::OptionFlags::TRIM_LEADING_BREAKS | StyledTextParser::OptionFlags::TRIM_TRAILING_BREAKS
		| StyledTextParser::OptionFlags::STRIP_PARAGRAPH_TAG);

	mMainController = make_shared<MainController>();
	mMainController->setup();
	getRootView()->addChild(mMainController);
}

void CinderExperimentsApp::prepareSettings(ci::app::App::Settings* settings) {
	SettingsManager::getInstance()->setup(settings, ci::app::getAssetPath("settings.json"));
}

void CinderExperimentsApp::update()
{
	BaseApp::update();
}

void CinderExperimentsApp::draw()
{
	BaseApp::draw();
}

CINDER_APP(CinderExperimentsApp, RendererGl(RendererGl::Options().msaa(4).stencil(true)), CinderExperimentsApp::prepareSettings);
