
#ifndef SdlBulletDisplay_HPP
# define SdlBulletDisplay_HPP

# include "SdlDisplay.hpp"
# include <ctime>
# include <vector>

class SdlBulletDisplay : public SdlDisplay
{
public:
	SdlBulletDisplay(void);
	SdlBulletDisplay(const SdlBulletDisplay & src);
	~SdlBulletDisplay(void);
	SdlBulletDisplay &	operator=(const SdlBulletDisplay & src);
	void				init(SDL_Renderer *renderer, int width, int height)throw(const char *);
	void				draw(void);
	void 				handleEventH(SDL_Event& e);
	void 				handleMovement(SDL_Event& e);
	void                close(void);

public:
	SDL_Renderer *_renderer;
	SDL_Window *window;
	TTF_Font *font;
	bool running;
	SDL_Texture *texture;
	int windowID;
	int frameW;
	int frameH;
	int _width;
	int _height;
	int x;
	int y;
	int speed;
	double velocity[2];
};

#endif
