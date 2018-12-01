
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
	void				init(int width, int height)throw(const char *);
	void				draw(void);
	void 				handleEventH( SDL_Event& e );
	void 				handleMovement(SDL_Event& e);
    void                close(void);	

public:
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
};

#endif
