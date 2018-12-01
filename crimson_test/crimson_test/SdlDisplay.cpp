
#include "SdlDisplay.hpp"

SdlDisplay::SdlDisplay(void) {
	return ;
}
SdlDisplay::SdlDisplay(const SdlDisplay & obj) {

}
SdlDisplay::~SdlDisplay(void) {

}

SDL_Texture * SdlDisplay::ft_load_png(std::string path)throw(const char*)
{
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
        throw("Unable to load image!");
    else
    {
        newTexture = SDL_CreateTextureFromSurface( this->renderer, loadedSurface );
        if( newTexture == NULL )
            throw( "Unable to create texture from !");
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

SdlDisplay & SdlDisplay::operator=(SdlDisplay const & src) {
	return *this;
}
 void SdlDisplay::init(void) throw(const char*){
	 return ;
 }


 
void SdlDisplay::draw(void) {
	return ;
}

std::ostream & operator<<(std::ostream & o, SdlDisplay const & rhs);
