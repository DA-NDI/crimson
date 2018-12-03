

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

/* Hi. It's my try to make this game. Actually,
** i had only two days for that, so it's a little
** bit trash code and far far away from perfect, i just recreated some principles
** plus i didn't used provided framework. Mostly i worked 
** on macos and c# on windows, so it was easier for me to write my own 
** functions, that to figure out how to use provided ones. Thank you, that you
** spend some time, looking on this
** more of my code you can see here: 
** C code https://github.com/DA-NDI/Doom_Nukem-oldschool
** C++ https://github.com/DA-NDI/CPP-Piscine
** C# https://github.com/DA-NDI/WasteLess
** Andrii Volgin
*/

int main(int argc, char *argv[])
{
	MyFramework framework;
	SdlShow game;
	std::string args[10];
	int	width;
	int	height;
	int enemies;
	int ammo;

	std::srand(std::time(0));
	for (int i = 0; i < argc && i < 10; i++)
		args[i] = argv[i];
	if (argc == 9) //Here i assume that all args are correct
	{
		width = stoi(args[2]);
		size_t HeightPosition = args[2].find_first_of("x");
		height = stoi(args[2], &HeightPosition);
		enemies = (int)(std::stoi(args[6]));
		ammo = (int)(std::stoi(args[8]));
	}
	if (argc != 9 || width > 3000 || height > 3000 || enemies > 200 || enemies < 0 || ammo < 0)
	{
		enemies = 7;
		ammo = 22;
		width = 1024;
		height = 768;
	}
	game.start(width, height, enemies, ammo);
	return (0);
}
