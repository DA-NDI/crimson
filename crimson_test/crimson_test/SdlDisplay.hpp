
#ifndef SDLDISPLAY_HPP
# define SDLDISPLAY_HPP

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <string>
# include <iostream>

class SdlDisplay
{
public:
	SdlDisplay( void );
	SdlDisplay( const SdlDisplay & src );
	virtual ~SdlDisplay( void );
	SdlDisplay &	operator=( const SdlDisplay & src );
//	virtual void				updateData( void );
	virtual void				init(void)throw(const char *);
	virtual void				draw(void);
	SDL_Texture * 				ft_load_png(std::string path)throw(const char*);



public:
	SDL_Renderer *render;
};

#endif
