
#include "SdlTargetDisplay.hpp"

SdlTargetDisplay::SdlTargetDisplay(void) {
	return;
}
SdlTargetDisplay::SdlTargetDisplay(const SdlTargetDisplay & obj) {

}
SdlTargetDisplay::~SdlTargetDisplay(void) {

}
SdlTargetDisplay & SdlTargetDisplay::operator=(SdlTargetDisplay const & src) {
	return *this;
}

void SdlTargetDisplay::init(SDL_Renderer *renderer, int width, int height) throw(const char*) {
	_renderer = renderer;
	_width = width;
	_height = height;

	x = 0;
	y = 0;
	speed = 0;
	//	speed = std::rand() % 3;
}


void SdlTargetDisplay::close(void) {

}

void SdlTargetDisplay::handleEventH(SDL_Event& e)
{

}

void SdlTargetDisplay::handleMovement(SDL_Event& e)
{
	x = e.motion.x;
	y = e.motion.y;
}

void SdlTargetDisplay::draw(void) {
	SDL_Rect EnemyDest;

	texture = IMG_LoadTexture(_renderer, "../data/circle.tga");
	SDL_QueryTexture(texture, NULL, NULL, &frameW, &frameH);
	EnemyDest.x = x;
	EnemyDest.y = y;
	EnemyDest.w = frameW;
	EnemyDest.h = frameH;
	SDL_RenderCopy(_renderer, texture, NULL, &EnemyDest);
	SDL_DestroyTexture(texture);

	return;
}

std::ostream & operator<<(std::ostream & o, SdlTargetDisplay const & rhs);
