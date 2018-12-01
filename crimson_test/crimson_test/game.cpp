

//#include "Framework.h"
#include "SDL.h"
#include <iostream>
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <string>
#include "Framework.h"
#include "SdlShow.hpp"
#include "Windows.h"
//
///* Test Framework realization */
class MyFramework : public Framework {

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 320;
		height = 200;
		fullscreen = false;
	}

	virtual bool Init() {

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
        drawTestBackground();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}
};
int	print_error(char *message)
{
	std::cout << message << std::endl;
	exit(1);
}

int main(int argc, char *argv[])
{
	MyFramework framework;
	SDL_Window *window;
	bool	fullscreen;
	SdlShow game;
	std::string args[10];
	int	width;
	int	height;

	for (int i = 0; i < argc; i++)
	{
		args[i] = argv[i];
	}
	if (argc == 1)
	{
		width = 640;
		height = 480;
	}
	else
	{
		width = stoi(args[2]);
		size_t HeightPosition = args[2].find_first_of("X");
		height = stoi(args[2], &HeightPosition);
	}
	game.start(width, height);
	fullscreen = 0;
	framework.PreInit(width, height, fullscreen);
	framework.Init();
	
	
	/*if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		std::cout << ("Failed to init SDL");
	if ((window = SDL_CreateWindow("Woo!", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, width, height, 0)) < 0)
		std::cout << ("Failed to create window. Exiting");
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		std::cout << ("Unable to load png");
	if ((TTF_Init()))
		std::cout << ("Unable to init ttf");
	while (1)
		;*/
	return (0);
//	return run(new MyFramework);
}
