#include "ShaderController.h"
#include "cinder/Log.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::views;
using namespace bluecadet::utils;

void ShaderController::setup()
{
	setAlpha(0.0f);

	//auto lambert = gl::ShaderDef().lambert().color();
	//gl::GlslProgRef shader = gl::getStockShader(lambert);
	//mBox = gl::Batch::create(geom::Cube(), shader);

	//mCam.lookAt(vec3(3, 10, 3.5), vec3(0, 1, 0)); // where to look at the shape
}

void ShaderController::draw() {
	gl::clear();

	//!!--- one circle
	//gl::drawSolidCircle(getWindowCenter(), 200); //offset and radius
	
	//!!--- 3 multi color circles
	//vec2 center = getWindowCenter();
	//float r = 100;
	//gl::color(Color(1, 0, 0)); // sets a global current color
	//gl::drawSolidCircle(center + vec2(-r, r), r);
	//gl::color(Color(0, 1, 0)); // green
	//gl::drawSolidCircle(center + vec2(r, r), r);
	//gl::color(Color(0, 0, 1)); // blue
	//gl::drawSolidCircle(center + vec2(0, -.73 * r), r);

	//!!--- transforms





	//gl::enableDepthRead();
	//gl::enableDepthWrite();

	//gl::setMatrices(mCam); // reset model and projection matrices

	//int numSpheres = 64;
	//float maxAngle = M_PI * 7;
	//float spiralRadius = 1;
	//float height = 2;
	//float boxSize = 0.05f;
	//float anim = getElapsedFrames() / 100.0f;

	//for (int s = 0; s < numSpheres; ++s) {
	//	float rel = s / (float)numSpheres;
	//	float angle = rel * maxAngle;
	//	float y = fabs(cos(rel * M_PI + anim)) * height;
	//	float r = rel * spiralRadius;
	//	vec3 offset(r * cos(angle), y / 2, r * sin(angle));

	//	gl::pushModelMatrix();
	//	gl::translate(offset);
	//	gl::scale(vec3(boxSize, y, boxSize));
	//	gl::color(Color(CM_HSV, rel, 1, 1));
	//	mBox->draw();
	//	gl::popModelMatrix();
	//}
}
