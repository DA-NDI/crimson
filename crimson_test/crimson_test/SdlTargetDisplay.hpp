
#ifndef SdlTargetDisplay_HPP
# define SdlTargetDisplay_HPP

# include "SdlDisplay.hpp"
# include <ctime>

class SdlTargetDisplay : public SdlDisplay
{
public:
	SdlTargetDisplay(void);
	SdlTargetDisplay(const SdlTargetDisplay & src);
	~SdlTargetDisplay(void);
	SdlTargetDisplay &	operator=(const SdlTargetDisplay & src);
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
};

#endif
