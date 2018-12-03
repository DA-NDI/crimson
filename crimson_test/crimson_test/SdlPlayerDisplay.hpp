
#ifndef SdlPlayerDisplay_HPP
# define SdlPlayerDisplay_HPP

# include "SdlDisplay.hpp"

class SdlPlayerDisplay : public SdlDisplay
{
public:
	SdlPlayerDisplay( void );
	SdlPlayerDisplay( const SdlPlayerDisplay & src );
	~SdlPlayerDisplay( void );
	SdlPlayerDisplay &	operator=( const SdlPlayerDisplay & src );
	void				init(SDL_Renderer *renderer, int width, int height)throw(const char *);
	void				draw(void);
	void 				handleEventH( SDL_Event& e );
	void 				handleMovement(SDL_Event& e);
    void                close(void);	

public:
	SDL_Renderer *_renderer;
	SDL_Window *window;
	TTF_Font *font;
	SDL_Color color;
	bool running;
	SDL_Texture *texture;
	SDL_Event event;
	int windowID;
	int frameW;
	int frameH;
	int _width;
	int _height;
};

#endif
