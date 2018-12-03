
#include "SdlShow.hpp"

SdlShow::SdlShow(void) {
	return ;
}
SdlShow::SdlShow(const SdlShow & obj) {

}
SdlShow::~SdlShow(void) {

}
SdlShow & SdlShow::operator=(SdlShow const & src) {
	return *this;
}


void SdlShow::start(const int &width, const int &height, const int &enemies, int ammo) throw(const char*){
	this->width = width;
	this->height = height;
	this->enemies = enemies;
	this->ammo = ammo;
	bool running = true;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_image could not initialize!" << std::endl;
		running = false;
	}
	window = SDL_CreateWindow("crimson",
		0, 500, width, height, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
	font = TTF_OpenFont("./src/font.ttf", 25);
	SDL_SetRenderDrawColor(renderer, 55, 55, 55, 55);
	SdlPlayerDisplay player;
	SdlEnemyDisplay enemy[10];
	SdlTargetDisplay target;
	SdlBulletDisplay bullet;
	for (int i = 0; i < enemies; i++)
		enemy[i].init(renderer, width, height);
	player.init(renderer, width, height);
	target.init(renderer, width, height);
	bullet.init(renderer, width, height);
	SDL_Event e;
	while (running)
	{
		SDL_RenderClear(renderer);
		offsetX = 0;
		offsetY = 0;
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				running = false;
			if (e.type == SDL_MOUSEMOTION)
				continue;
			if (e.type == SDL_KEYDOWN)
			SdlKeysDown(e.key.keysym.sym);
			if (e.type == SDL_KEYUP)
				SdlKeysUp(e.key.keysym.sym);	
			if (e.type == SDL_KEYDOWN)
				CheckMovement();
			CheckMouseClick(e, bullet);
			player.handleEventH( e );
		}
		for (int i = 0; i < enemies; i++)
		{
			enemy[i].handleMovement(e, offsetX, offsetY);
			enemy[i].draw();
		}
		CheckCollision(e, enemy, bullet);
		target.handleMovement(e);
		bullet.handleMovement(e);
		player.draw();
		target.draw();
		bullet.draw();
	SDL_RenderPresent(renderer);
	}
	player.close();
	TTF_Quit();
	SDL_Quit();
}

void SdlShow::draww(void) {
	return ;
}

void SdlShow::update(void) {
	return ;
}

void SdlShow::SdlKeysDown(int key)
{
	if (key == SDLK_RIGHT)
		keys.right = 1;
	if (key == SDLK_LEFT)
		keys.left = 1;
	if (key == SDLK_UP)
		keys.up = 1;
	if (key == SDLK_DOWN)
		keys.down = 1;
}

void SdlShow::SdlKeysUp(int key)
{
	if (key == SDLK_RIGHT)
		keys.right = 0;
	if (key == SDLK_LEFT)
		keys.left = 0;
	if (key == SDLK_UP)
		keys.up = 0;
	if (key == SDLK_DOWN)
		keys.down = 0;
}

void SdlShow::CheckMovement()
{
	if (keys.right)
		offsetX -= 8;
	if (keys.left)
		offsetX += 8;
	if (keys.up)
		offsetY += 8;
	if (keys.down)
		offsetY -= 8;
}

void SdlShow::CheckCollision(SDL_Event &e, SdlEnemyDisplay enemy[10], SdlBulletDisplay &bullet)
{
	for (int i = 0; i < this->enemies; i++)
	{
		if (std::abs(enemy[i].x - bullet.x) <= 15 && std::abs(enemy[i].y - bullet.y) <= 15)
		{
			enemy[i].running = 0;
			enemy[i].x = 5000;
			enemy[i].y = 5000;
			bullet.running = 0;
			bullet.x = width / 2;
			bullet.y = height / 2;
		}
	}
}

void SdlShow::CheckMouseClick(SDL_Event& e, SdlBulletDisplay &bullet)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		if (e.button.button == SDL_BUTTON_LEFT && !bullet.running && ammo)
		{
			double length;
			int x_velocity;
			int y_velocity;

			ammo--;
			bullet.running = 1;
			bullet.x = width / 2;
			bullet.y = height / 2;
			x_velocity = e.motion.x - width / 2;
			y_velocity = e.motion.y - height / 2;
			length = std::sqrt((x_velocity * x_velocity) + (y_velocity * y_velocity));
			bullet.velocity[0] = x_velocity / length;
			bullet.velocity[1] = y_velocity / length;
		}
}

void SdlShow::draw(void) {
	return ;
}

std::ostream & operator<<(std::ostream & o, SdlShow const & rhs);
