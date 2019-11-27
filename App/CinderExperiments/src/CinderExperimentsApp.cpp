#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/core/BaseApp.h"
#include "bluecadet/text/FontManager.h"
#include "bluecadet/text/StyledTextParser.h"

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
};

void CinderExperimentsApp::setup()
{
	BaseApp::setup();
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
