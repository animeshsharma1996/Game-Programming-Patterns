//Updated Command Class with Directions for Actors

class GameActor
{
    public:
        void Jump() {}
};

class Command
{
    public:
        virtual ~Command() {}
        virtual void Execute(GameActor& actor) = 0;
};

class JumpCommand : public Command
{
    public:
        virtual void Execute(GameActor& actor) 
        { 
            actor.Jump(); 
        }
};

//Updated Input Handler Class

class InputHandler
{
    public : 
        Command* HandleInput()
        {
            if(IsPressed(BUTTON_X)) return buttonX_;
            else if(IsPressed(BUTTON_Y)) return buttonY_;
            else if(IsPressed(BUTTON_A)) return buttonA_;
            else if(IsPressed(BUTTON_B)) return buttonB_;

            return nullptr;
        }
        bool IsPressed(int button) {  return true; }
        void ExecuteCommand(Command* command)
        {
            command->Execute(*actor);
        }

    private:
        GameActor* actor;
        Command* buttonX_;
        Command* buttonY_;
        Command* buttonA_;
        Command* buttonB_;

        const int BUTTON_X = 0;
        const int BUTTON_Y = 1;
        const int BUTTON_A = 2;
        const int BUTTON_B = 3;
};