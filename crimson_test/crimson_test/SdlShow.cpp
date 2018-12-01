
#include "SdlShow.hpp"

SdlShow::SdlShow(void) {
	return ;
}
SdlShow::SdlShow(const SdlShow & obj) {

}
SdlShow::~SdlShow(void) {

}
SdlShow & SdlShow::operator=(SdlShow const & src) {
	return *this;
}


void SdlShow::start(const int &width, const int &height) throw(const char*){
bool running = true;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
int imgFlags = IMG_INIT_PNG;
if( !( IMG_Init( imgFlags ) & imgFlags ) )
{
	std::cout << "SDL_image could not initialize!" << std::endl;
	running = false;
}
SdlPlayerDisplay player;
player.init(width, height);
SDL_Event e;
while (running)
{
	while( SDL_PollEvent( &e ) != 0 )
	{
		if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			running = false;
		if (e.type == SDL_MOUSEMOTION)
			continue;
		if (e.type == SDL_KEYDOWN)
			SdlKeysDown(e.key.keysym.sym);
		if (e.type == SDL_KEYUP)
			SdlKeysUp(e.key.keysym.sym);
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			ft_check_retry(e.key.keysym.sym);
			ft_check_other(keystate);
			ft_check_extra_keys(keystate);
			ft_check_pause(keystate);
		}
		check_mousebuttons();
		player.handleEventH( e );
	}
player.draw();
}
player.close();
TTF_Quit();
SDL_Quit();
}

void SdlShow::draww(void) {
	return ;
}

void SdlShow::update(void) {
	return ;
}

void SdlShow::SdlKeysDown(int key)
{
	if (key == SDLK_RIGHT)
		keys.right = 1;
	if (key == SDLK_LEFT)
		keys.left = 1;
	if (key == SDLK_UP)
		keys.up = 1;
	if (key == SDLK_DOWN)
		keys.down = 1;
}

void SdlShow::SdlKeysUp(int key)
{
	if (key == SDLK_RIGHT)
		keys.right = 0;
	if (key == SDLK_LEFT)
		keys.left = 0;
	if (key == SDLK_UP)
		keys.up = 0;
	if (key == SDLK_DOWN)
		keys.down = 0;
}

void SdlShow::draw(void) {
	return ;
}

std::ostream & operator<<(std::ostream & o, SdlShow const & rhs);
