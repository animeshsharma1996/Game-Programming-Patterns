//We've all been there

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

bool isJumping_ = false;
bool isDucking_ = false;
float yVelocity = 0.0f;
float JUMP_VELOCITY = 10.0f;

void setGraphics(Image image)
{
  // Set the image
}

void handleInput(Input input)
{
	if(input == PRESS_B)
	{
		yVelocity = JUMP_VELOCITY;
		setGraphics(IMAGE_JUMP);
	}
}

//Check Jumping

void handleInput(Input input)
{
	if(input == PRESS_B)
	{
		if(!isJumping_)
		{
			isJumping_ = true;
		}
	}
}


//Ducking

void handleInput(Input input)
{
  if (input == PRESS_B)
  {
    // Jump if not jumping...
  }
  else if (input == PRESS_DOWN)
  {
    if (!isJumping_)
    {
      setGraphics(IMAGE_DUCK);
    }
  }
  else if (input == RELEASE_DOWN)
  {
    setGraphics(IMAGE_STAND);
  }
}

//The heroine will switch to her standing graphic in the middle of the jump. Time for another flag…

void handleInput(Input input)
{
  if (input == PRESS_B)
  {
    if (!isJumping_ && !isDucking_)
    {
      // Jump...
    }
  }
  else if (input == PRESS_DOWN)
  {
    if (!isJumping_)
    {
      isDucking_ = true;
      setGraphics(IMAGE_DUCK);
    }
  }
  else if (input == RELEASE_DOWN)
  {
    if (isDucking_)
    {
      isDucking_ = false;
      setGraphics(IMAGE_STAND);
    }
  }
}

//Next, it would be cool if the heroine did a dive attack if the player presses down in the middle of a jump:
void handleInput(Input input)
{
  if (input == PRESS_B)
  {
    if (!isJumping_ && !isDucking_)
    {
      // Jump...
    }
  }
  else if (input == PRESS_DOWN)
  {
    if (!isJumping_)
    {
      isDucking_ = true;
      setGraphics(IMAGE_DUCK);
    }
    else
    {
      isJumping_ = false;
      setGraphics(IMAGE_DIVE);
    }
  }
  else if (input == RELEASE_DOWN)
  {
    if (isDucking_)
    {
      // Stand...
    }
  }
}