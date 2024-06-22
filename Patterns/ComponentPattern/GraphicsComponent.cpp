class Bjorn;
class Volume;

class GraphicsComponent
{
public :
	void Update(Bjorn& bjorn, Graphics& graphics)
	{
		Sprite* sprite = &spriteStand_;
		if(velocity_ < 0)
		{	
			sprite = &spriteWalkLeft_;
		}
		else if(velocity_ > 0)
		{
			sprite = &spriteWalkRight_;
		}
		
		graphics.draw(*sprite, bjorn.x, bjorn.y);
	}

private :
	Sprite spriteStand_;
	Sprite spriteWalkLeft_;
	Sprite spriteWalkRight_;
};