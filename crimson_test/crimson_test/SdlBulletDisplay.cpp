
#include "SdlBulletDisplay.hpp"

SdlBulletDisplay::SdlBulletDisplay(void) {
	return;
}
SdlBulletDisplay::SdlBulletDisplay(const SdlBulletDisplay & obj) {

}
SdlBulletDisplay::~SdlBulletDisplay(void) {

}
SdlBulletDisplay & SdlBulletDisplay::operator=(SdlBulletDisplay const & src) {
	return *this;
}

void SdlBulletDisplay::init(SDL_Renderer *renderer, int width, int height) throw(const char*) {
	running = 0;
	_renderer = renderer;
	_width = width;
	_height = height;

	x = _width / 2;
	y = _height / 2;
	speed = 0;
	velocity[0] = 0;
	velocity[1] = 0;
}


void SdlBulletDisplay::close(void) {

}

void SdlBulletDisplay::handleEventH(SDL_Event& e)
{

}

void SdlBulletDisplay::handleMovement(SDL_Event& e)
{
	static int i = 0;

	i++;
	if (i % 3 == 0)
	{
		x += (velocity[0] * 10);
		y += (velocity[1] * 10);
	}
	if (y >=_height || x >= _width || y <= 0 || x <= 0)
	{
		y = _height / 2;
		x = _width / 2;
		running = 0;
	}
}

void SdlBulletDisplay::draw(void) {
	SDL_Rect EnemyDest;
	
	if (!running)
		return;
	texture = IMG_LoadTexture(_renderer, "../data/bullet.png");
	SDL_QueryTexture(texture, NULL, NULL, &frameW, &frameH);
	EnemyDest.x = x;
	EnemyDest.y = y;
	EnemyDest.w = frameW;
	EnemyDest.h = frameH;
	SDL_RenderCopy(_renderer, texture, NULL, &EnemyDest);
	SDL_DestroyTexture(texture);

	return;
}

std::ostream & operator<<(std::ostream & o, SdlBulletDisplay const & rhs);
