//Enums & Switches

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

State state_ = STATE_STANDING;
float yVelocity_ = 0.0f;
float JUMP_VELOCITY = 10.0f;

void setGraphics(Image image)
{
	// Set the image
}

void HandleInput(Input input)
{
	switch (state_)
	{
		case STATE_STANDING:
		{  
			if (input == PRESS_B)
			{
				state_ = STATE_JUMPING;
				yVelocity_ = JUMP_VELOCITY;
				setGraphics(IMAGE_JUMP);
			}
			else if (input == PRESS_DOWN)
			{
				state_ = STATE_DUCKING;
				setGraphics(IMAGE_DUCK);
			}
			break;
		}

		case STATE_JUMPING:
		{  
			if (input == PRESS_DOWN)
			{
				state_ = STATE_DIVING;
				setGraphics(IMAGE_DIVE);
			}
			break;
		}

		case STATE_DUCKING:
		{ 
			if (input == RELEASE_DOWN)
			{
				state_ = STATE_STANDING;
				setGraphics(IMAGE_STAND);
			}
			break;
		}
	}
}

