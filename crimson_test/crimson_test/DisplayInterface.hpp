
#ifndef DISPLAYINTERFACE_HPP
# define DISPLAYINTERFACE_HPP

# include <string>

class	DisplayInterface {

public:
	virtual ~DisplayInterface(void) {}

	virtual void				draw( void ) = 0;
	virtual void				update( void ) = 0;
	virtual void				start( const int &width, const int &height, const int &enemies, int ammo ) = 0;
};


#endif
