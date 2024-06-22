class Bjorn;
class Volume;

class PhysicsComponent
{
public :
	void Update(Bjorn& bjorn, World& world)
	{
		bjorn.x += bjorn.velocity;
		world.resolveCollision(volume_, bjorn.x, bjorn.y, bjorn.velocity);
	}

private :
	Volume volume_;
};