
#include "SdlEnemyDisplay.hpp"

SdlEnemyDisplay::SdlEnemyDisplay(void) {
	return;
}
SdlEnemyDisplay::SdlEnemyDisplay(const SdlEnemyDisplay & obj) {

}
SdlEnemyDisplay::~SdlEnemyDisplay(void) {

}
SdlEnemyDisplay & SdlEnemyDisplay::operator=(SdlEnemyDisplay const & src) {
	return *this;
}

void SdlEnemyDisplay::init(SDL_Renderer *renderer, int width, int height) throw(const char*) {
	running = 1;
	_renderer = renderer;
	_width = width;
	_height = height;
	x = std::rand() % (width - 30);
	y = std::rand() % (height - 30);
	speed = 0;
	speed = std::rand() % 5 + 2;
}


void SdlEnemyDisplay::close(void) {

}

void SdlEnemyDisplay::handleEventH(SDL_Event& e)
{

}

void SdlEnemyDisplay::handleMovement(SDL_Event& e, int offsetX, int offsetY)
{
	static int counter = 0;

	double length;
	int x_velocity;
	int y_velocity;


	counter++;
	if (counter % 15 == 0)
	{
		x_velocity = x - _width / 2;
		y_velocity = y - _height / 2;
		length = std::sqrt((x_velocity * x_velocity) + (y_velocity * y_velocity));
		velocity[0] = x_velocity / length;
		velocity[1] = y_velocity / length;

		x -= (velocity[0] * speed) + offsetX;
		y -= (velocity[1] * speed) + offsetY;
		if (y >= _height || x >= _width || y <= 0 || x <= 0)
			running = 0;
	}
	x += offsetX;
	y += offsetY;
	if (std::abs(x - _width / 2) <= 20&& std::abs(y - _height / 2) <= 20)
	{
		SDL_DestroyTexture(texture);
		texture = IMG_LoadTexture(_renderer, "../data/end.png");
		SDL_RenderCopy(_renderer, texture, NULL, NULL);
		SDL_RenderPresent(_renderer);
		SDL_Delay(3000);
		SDL_Quit();
	}

}

void SdlEnemyDisplay::draw(void) {
	SDL_Rect EnemyDest;

	if (!running)
		return;
	texture = IMG_LoadTexture(_renderer, "../data/enemy.png");
	SDL_QueryTexture(texture, NULL, NULL, &frameW, &frameH);
	EnemyDest.x = x;
	EnemyDest.y = y;
	EnemyDest.w = frameW;
	EnemyDest.h = frameH;
	SDL_RenderCopy(_renderer, texture, NULL, &EnemyDest);
	SDL_DestroyTexture(texture);
}

std::ostream & operator<<(std::ostream & o, SdlEnemyDisplay const & rhs);
