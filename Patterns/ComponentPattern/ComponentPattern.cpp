class World;
class Graphics;
class InputComponent;
class PhysicsComponent;
class GraphicsComponent;
class Sprite;

enum Direction { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_NONE };

namespace Controller
{
	Direction GetJoystickDirection();
}

class Bjorn
{
public :
	int velocity;
	int x, y;

	Bjorn(InputComponent* input) : input_(input) {}

	void Update(World& world, Graphics& graphics)
	{
		input_->Update(*this);
		physics_->Update(*this, world);
		graphics_->Update(*this, graphics);
	}

private :
	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};


class InputComponent
{
public :
	virtual ~InputComponent() {}
	virtual void Update(Bjorn& bjorn) = 0;
};

class PlayerInputComponent : public InputComponent
{
public :
	virtual void Update(Bjorn& bjorn, World& world)
	{
		switch(Controller::GetJoystickDirection())
		{
			case DIR_LEFT : 
			{
				bjorn.x -= bjorn.velocity; 
				break;
			}
			case DIR_RIGHT : 
			{
				bjorn.x += bjorn.velocity; 
				break;
			}
		}
	}

private :
	static const int WALK_ACCELERATION = 1;
};	

class DemoInputComponent : public InputComponent
{
public :
	virtual void Update(Bjorn& bjorn)
	{
		//AI to automatically move Bjorn
	}
};

class PhysicsComponent
{
public :
	virtual void ~PhysicsComponent() {}
	virtual void Update(Bjorn& bjorn, World& world) = 0;
};

class GraphicsComponent
{
public :
	virtual void ~GraphicsComponent() {}
	virtual void Update(Bjorn& bjorn, Graphics& graphics) = 0;
};

