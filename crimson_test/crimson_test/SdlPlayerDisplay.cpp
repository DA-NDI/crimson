
#include "SdlPlayerDisplay.hpp"
#include <string.h>

SdlPlayerDisplay::SdlPlayerDisplay(void) {
	return ;
}
SdlPlayerDisplay::SdlPlayerDisplay(const SdlPlayerDisplay & obj) {

}
SdlPlayerDisplay::~SdlPlayerDisplay(void) {

}
SdlPlayerDisplay & SdlPlayerDisplay::operator=(SdlPlayerDisplay const & src) {
	return *this;
}
void SdlPlayerDisplay::init(int width, int height) throw(const char*){
	this->_width = width;
	this->_height = height;
bool running = true;
window = SDL_CreateWindow("crimson",
0, 500, width, height, SDL_WINDOW_RESIZABLE);
renderer = SDL_CreateRenderer(window, -1, 0);
font = TTF_OpenFont("./src/font.ttf", 25);
color.r = 255;
color.g = 255;
color.b = 255;
SDL_SetRenderDrawColor(renderer, 55, 55, 55, 55);
}

void SdlPlayerDisplay::close(void) {
TTF_CloseFont(font);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
}

void SdlPlayerDisplay::handleEventH( SDL_Event& e )
{
	if( e.type == SDL_WINDOWEVENT && e.window.windowID == windowID )
	{
		switch( e.window.event )
		{
			case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow( window );
			break;
		}
	}
}

void SdlPlayerDisplay::handleMovement(SDL_Event& e)
{
	if (e.type == SDL_WINDOWEVENT && e.window.windowID == windowID)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow(window);
			break;
		}
	}
}

void SdlPlayerDisplay::draw(void) {
SDL_RenderClear(renderer);
int FPS = 60;
static int frameTime = 0;
SDL_Rect PlayerRectDest;
int texW = 0;
int texH = 0;
texture = IMG_LoadTexture(renderer, "../data/avatar.jpg");
SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
frameW = texW;
frameH = texH;
PlayerRectDest.x = _width / 2 - texW / 2;
PlayerRectDest.y = _height / 2 - texH / 2;
PlayerRectDest.w = frameW;
PlayerRectDest.h = frameH;
SDL_RenderCopy(renderer, texture, NULL, &PlayerRectDest);
SDL_DestroyTexture(texture);
SDL_RenderPresent(renderer);
return ;
}

std::ostream & operator<<(std::ostream & o, SdlPlayerDisplay const & rhs);
