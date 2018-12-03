
#ifndef SdlEnemyDisplay_HPP
# define SdlEnemyDisplay_HPP

# include "SdlDisplay.hpp"
# include <ctime>

class SdlEnemyDisplay : public SdlDisplay
{
public:
	SdlEnemyDisplay(void);
	SdlEnemyDisplay(const SdlEnemyDisplay & src);
	~SdlEnemyDisplay(void);
	SdlEnemyDisplay &	operator=(const SdlEnemyDisplay & src);
	void				init(SDL_Renderer *renderer, int width, int height)throw(const char *);
	void				draw(void);
	void 				handleEventH(SDL_Event& e);
	void 				handleMovement(SDL_Event& e, int offsetX, int offsetY);
	void                close(void);

public:
	SDL_Renderer *_renderer;
	SDL_Window *window;
	SDL_Surface *surf_cpu;
	SDL_Surface *surf_1;
	SDL_Surface *surf_2;
	SDL_Surface *surf_3;
	TTF_Font *font;
	SDL_Color color;
	bool running;
	SDL_Texture *texture;
	SDL_Texture *texture1;
	SDL_Texture *texture2;
	SDL_Texture *texture3;
	SDL_Event event;
	int windowID;
	int frameW;
	int frameH;
	int _width;
	int _height;
	int x;
	int y;
	double velocity[2];
	double speed;
};

#endif
