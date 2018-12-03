
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
void SdlPlayerDisplay::init(SDL_Renderer *renderer, int width, int height) throw(const char*){
	_width = width;
	_height = height;
	_renderer = renderer;
}

void SdlPlayerDisplay::close(void) {

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

}

void SdlPlayerDisplay::draw(void) {
int FPS = 60;
static int frameTime = 0;
SDL_Rect PlayerRectDest;
int texW = 0;
int texH = 0;
texture = IMG_LoadTexture(_renderer, "../data/avatar.jpg");
SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
frameW = texW;
frameH = texH;
PlayerRectDest.x = _width / 2 - texW / 2;
PlayerRectDest.y = _height / 2 - texH / 2;
PlayerRectDest.w = frameW;
PlayerRectDest.h = frameH;
SDL_RenderCopy(_renderer, texture, NULL, &PlayerRectDest);
SDL_DestroyTexture(texture);
return ;
}

std::ostream & operator<<(std::ostream & o, SdlPlayerDisplay const & rhs);
