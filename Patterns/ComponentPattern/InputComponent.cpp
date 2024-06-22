
class Bjorn;
class Controller;
class World;
class Graphics;
class Sprite;
class Volume;

enum Direction { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_NONE };

class InputComponent
{
public:
	void Update(Bjorn& bjorn)
	{
		switch(Controller::GetJoystickDirection())
		{
			case DIR_LEFT : 
				bjorn.velocity_ -= WALK_ACCELERATION; 
				break;
			case DIR_RIGHT : 
				bjorn.velocity_ += WALK_ACCELERATION; 
				break;
		}
	}

private:
	static const int WALK_ACCELERATION = 1;
};


class Bjorn
{
public : 
	Bjorn() : velocity_(0), x_(0), y_(0) {}

	void Update(World& world, Graphics& Graphics)
	{
		input_.Update(*this);

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

private :
	InputComponent input_;

	Volume volume_;

	Sprite spriteStand_;
	Sprite spriteWalkLeft_;
	Sprite spriteWalkRight_;
};