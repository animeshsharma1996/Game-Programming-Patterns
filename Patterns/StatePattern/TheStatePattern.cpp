//State Interface

#include "Heroine.h"

class HeroineState
{
	public:
	virtual ~HeroineState() {}
	virtual void handleInput(Heroine& heroine, Input input) {}
	virtual void update(Heroine& heroine) {}

	static StandingState standing;
	static JumpingState jumping;
	static DuckingState ducking;
	static DivingState diving;
};

//Ducking State

class DuckingState : public HeroineState
{
	public:
	DuckingState() : chargeTime_(0) {}

	virtual void handleInput(Heroine& heroine, Input input) 
	{
		if (input == RELEASE_DOWN)
		{
			// Change to standing state...
			heroine.setGraphics(IMAGE_STAND);
		}
	}

	virtual void update(Heroine& heroine) 
	{
		chargeTime_++;
		if (chargeTime_ > MAX_CHARGE)
		{
			heroine.superBomb();
		}
	}

	private:
	int chargeTime_;
};


//Delegate to the State

class Heroine
{
	public:
	virtual void handleInput(Input input)
	{
		state_->handleInput(*this, input);
	}

	virtual void update()
	{
		state_->update(*this);
	}

	void Jump
	(
		if (input == PRESS_B)
		{
			heroine.state_ = &HeroineState::jumping;
			heroine.setGraphics(IMAGE_JUMP);
		}
	)

	// Other methods...
	private:
	HeroineState* state_;
};