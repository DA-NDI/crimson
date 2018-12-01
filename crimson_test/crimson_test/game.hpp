#ifndef GAME_HPP
# define GAME_HPP
# define DOWN SDLK_DOWN
# define UP SDLK_UP
# define LEFT SDLK_LEFT
# define RIGHT SDLK_RIGHT
# define SPACE SDLK_SPACE
# include "SDL.h"

typedef struct		s_mouse
{
	float			x;
	float			y;
}					t_mouse;

typedef struct		s_hud
{
	SDL_Texture		*hud[13];
	float			enemy_speed;
	int				hp;
	int				ammo;
	int				lives;
	int				rockets;
	int				shield;
	int				jetpack;
	int				level;
}					t_hud;

typedef struct		s_keys
{
	int				right;
	int				left;
	int				up;
	int				down;
	int				w;
	int				s;
	int				a;
	int				d;
	int				shift;
	int				space;
	int				yrel;
	int				xrel;
	int				x;
	int				y;
	int				f;
	int				lctrl;
	int				enter;
	int				t;
	int				z;
}					t_keys;


#endif
