
#ifndef SDLSHOW_HPP
# define SDLSHOW_HPP

#include "SdlPlayerDisplay.hpp"
#include "SdlEnemyDisplay.hpp"
#include "SdlTargetDisplay.hpp"
#include "DisplayInterface.hpp"
#include "SdlBulletDisplay.hpp"
#include "SDL.h"
#include <iostream>
#include <stdlib.h>
#include "game.hpp"

class SdlShow : public DisplayInterface
{
public:
	SDL_Renderer *renderer;
	SDL_Window *window;
	TTF_Font *font;
	SDL_Color color;
	int		enemies;
	int		ammo;

	SdlShow( void );
	SdlShow( const SdlShow & src );
	virtual ~SdlShow( void );
	SdlShow &	operator=( const SdlShow & src );
	virtual void				start(const int &width, const int &height, const int &enemies, int ammo)throw(const char *);
	virtual void				draww(void);
	virtual void				draw(void);
	virtual void				update(void);
	virtual void				SdlKeysDown(int key);
	virtual void				SdlKeysUp(int key);
	virtual void				CheckMovement(void);
	virtual void				CheckMouseClick(SDL_Event& e, SdlBulletDisplay &bullet);
	virtual void				CheckCollision(SDL_Event &e, SdlEnemyDisplay enemy[10], SdlBulletDisplay &bullet);

protected:
	int width;
	int height;
	int offsetX;
	int offsetY;
	t_keys keys;

};

#endif
