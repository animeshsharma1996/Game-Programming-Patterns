//A Monolithic Bjorn Class

class World;
class Graphics;
class Sprite;
class Volume;

class Bjorn
{
public : 
	Bjorn() : velocity_(0), x_(0), y_(0) {}

	void Update(World& world, Graphics& Graphics);

private :
	static const int WALK_ACCELERATION = 1;

	int velocity_;
	int x_, y_;

	Volume volume_;

	Sprite spriteStand_;
	Sprite spriteWalkLeft_;
	Sprite spriteWalkRight_;
};

void Bjorn::Update(World& world, Graphics& graphics)
{
	//Apply user input to hero's velocity
	switch(Controller::GetJoystickDirection())
	{
		case DIR_LEFT : 
			velocity_ -= WALK_ACCELERATION; 
			break;
		case DIR_RIGHT : 
			velocity_ += WALK_ACCELERATION; 
			break;
	}

	//Modify Positon by velocity
	x_ += velocity_;
	world.ResolveCollision(volume_, x_, y_, velocity_);

	//Draw the appropriate sprite
	Sprite* sprite = &spriteStand_;
	if(velocity_ < 0)
	{	
		sprite = &spriteWalkLeft_;
	}
	else if(velocity_ > 0)
	{
		sprite = &spriteWalkRight_;
	}
	graphics.Draw(*sprite, x_, y_);
}

