
#ifndef SDLSHOW_HPP
# define SDLSHOW_HPP

#include "SdlPlayerDisplay.hpp"
#include "DisplayInterface.hpp"
#include "SDL.h"
#include <iostream>
#include <stdlib.h>
#include "game.hpp"

class SdlShow : public DisplayInterface
{
public:
	SdlShow( void );
	SdlShow( const SdlShow & src );
	virtual ~SdlShow( void );
	SdlShow &	operator=( const SdlShow & src );
	virtual void				start(const int &width, const int &height)throw(const char *);
	virtual void				draww(void);
	virtual void				draw(void);
	virtual void				update(void);
	virtual void				SdlKeysDown(int key);
	virtual void				SdlKeysUp(int key);

protected:
	int width;
	int height;
	t_keys keys;

};

#endif
