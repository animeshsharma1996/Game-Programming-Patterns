//Instantiated States

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
private:
	HeroineState* state_;

public:
	void handleInput(Input input)
	{
		HeroineState* state = state_->handleInput(*this, input);

		if (state != nullptr)
		{
			delete state_;
			state_ = state;

			state_->Enter(*this);
		}
	}

	void setGraphics(Image image)
	{
		// Set the image
	}
};

//Standing State
class StandingState : public HeroineState
{
public:
	virtual void Enter(Heroine& heroine)
	{
		heroine.setGraphics(IMAGE_STAND);
	}

	HeroineState* handleInput(Heroine& heroine, Input input)
	{
		if (input == PRESS_DOWN)
		{
			//other code
			return new DuckingState();
		}

		return nullptr;
	}
};	

//Ducking State
class DuckingState : public HeroineState
{
public:
	HeroineState* handleInput(Heroine& heroine, Input input)
	{
		if (input == RELEASE_DOWN)
		{
			return new StandingState();
		}

		return nullptr;
	}
};

//Jumping State
class JumpingState : public HeroineState
{
};	

//Diving State
class DivingState : public HeroineState
{
};

