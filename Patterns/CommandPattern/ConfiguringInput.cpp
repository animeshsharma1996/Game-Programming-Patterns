//Input Handler Class

class InputHandler 
{
    public:
        void HandleInput() 
        {
            if(IsPressed(BUTTON_X)) Jump();
            else if(IsPressed(BUTTON_Y)) FireGun();
            else if(IsPressed(BUTTON_A)) SwapWeapon();
            else if(IsPressed(BUTTON_B)) LurchInEffectively();
        }
        void LurchInEffectively();
        bool IsPressed(int button) {  return true; }
        void Jump() {}
        void FireGun() {}
        void SwapWeapon() {}

    private:
        const int BUTTON_X = 0;
        const int BUTTON_Y = 1;
        const int BUTTON_A = 2;
        const int BUTTON_B = 3;
};

//Now Command Class

class Command
{
    public:
        virtual ~Command() {}
        virtual void Execute() = 0;
};

class JumpCommand : public Command
{
    public:
        virtual void Execute() { Jump(); }
        void Jump() {}
};

class FireCommand : public Command
{
    public:
        virtual void Execute() { FireGun(); }
        void FireGun() {}
};

//Updated Input Handler Class

class InputHandler
{
    public : 
        void HandleInput()
        {
            if(IsPressed(BUTTON_X)) buttonX_->Execute();
            else if(IsPressed(BUTTON_Y)) buttonY_->Execute();
            else if(IsPressed(BUTTON_A)) buttonA_->Execute();
            else if(IsPressed(BUTTON_B)) buttonB_->Execute();
        }
        bool IsPressed(int button) {  return true; }

    private:
        Command* buttonX_;
        Command* buttonY_;
        Command* buttonA_;
        Command* buttonB_;

        const int BUTTON_X = 0;
        const int BUTTON_Y = 1;
        const int BUTTON_A = 2;
        const int BUTTON_B = 3;
};