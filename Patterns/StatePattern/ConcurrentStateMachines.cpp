//Concurrent State Machine

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
    virtual HeroineState* handleInput(Heroine& heroine, Input input) {}
	virtual void Enter(Heroine& heroine) {}
	virtual void Exit(Heroine& heroine) {}
	virtual void update(Heroine& heroine) {}

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

//Standing State
class StandingState : public HeroineState
{
};

//Ducking State
class DuckingState : public HeroineState
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