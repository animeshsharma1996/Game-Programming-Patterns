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

class GameObject
{
public :
	int velocity;
	int x, y;

	GameObject(InputComponent* input, PhysicsComponent* physics, GraphicsComponent* graphics) : input_(input) {}

	GameObject* CreateBjorn()
	{
		return new GameObject(new PlayerInputComponent(), new BjornPhysicsComponent(), new BjornGraphicsComponent());
	}

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
	virtual void Update(GameObject& bjorn) = 0;
};

class PlayerInputComponent : public InputComponent
{
public :
	virtual void Update(GameObject& bjorn, World& world)
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


class BjornPhysicsComponent : public PhysicsComponent
{
public :
	virtual void Update(GameObject& obj, World& world)
	{
		// Update Bjorn's position based on velocity
	}
};

class BjornGraphicsComponent : public GraphicsComponent
{
public :
	virtual void Update(GameObject& obj, Graphics& graphics)
	{
		// Draw Bjorn's sprite
	}
};


