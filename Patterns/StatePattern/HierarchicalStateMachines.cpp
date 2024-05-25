//Hierarchical State Machine

//A state can have a superstate (making itself a substate)

enum Input
{
  PRESS_B,
  PRESS_DOWN,
  RELEASE_DOWN
};

enum Image
{
  IMAGE_STAND,
  IMAGE_JUMP,
  IMAGE_DUCK,
  IMAGE_DIVE
};

enum State
{
	STATE_STANDING,
	STATE_JUMPING,
	STATE_DUCKING,
	STATE_DIVING
};

class HeroineState
{
	public:
	virtual ~HeroineState() {}
    virtual void handleInput(Heroine& heroine, Input input) {}
	virtual void Enter(Heroine& heroine) {}
	virtual void Exit(Heroine& heroine) {}
	virtual void update(Heroine& heroine) {}

	static OnGroundState onGround;
	static StandingState standing;
	static JumpingState jumping;
	static DuckingState ducking;
	static DivingState diving;
};

class Heroine
{
	//other code
public :
	void handleInput(Input input)
	{
		state_->handleInput(*this, input);
		equipment_->handleInput(*this, input);
	}

private :
	HeroineState* state_;
	HeroineState* equipment_;
};

//OnGround State
class OnGroundState : public HeroineState
{
public:
	virtual void handleInput(Heroine& heroine, Input input)
	{
		if(input == PRESS_B)
		{

		}
		else if(input == PRESS_DOWN)
		{

		}
	}
};

//Ducking State
class DuckingState : OnGroundState 
{
public:
	virtual void handleInput(Heroine& heroine, Input input)
	{
		if(input == RELEASE_DOWN)
		{
			//change to standing
		}
		else
		{
			//Didn't handle input, so walk up hierarchy
			OnGroundState::handleInput(heroine, input);
		}
	}
};

//Standing State
class StandingState : public HeroineState
{
};

//Jumping State
class JumpingState : public HeroineState
{
};	

//Diving State
class DivingState : public HeroineState
{
};