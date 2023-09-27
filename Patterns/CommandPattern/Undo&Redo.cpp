//Undo and Redo functionalities

class Unit
{
    public:
        void MoveTo(int x, int y) {}
        Unit* GetSelectedUnit() { return nullptr; }
        int GetX() { return 0; }
        int GetY() { return 0; }
};

class MoveUnitCommand : public Command
{
    public :
        MoveUnitCommand(Unit* unit, int x, int y) : unit_(unit), x_(x), y_(y) {}
        virtual void Execute(GameActor& actor) 
        { 
            unit_->MoveTo(x_, y_); 
        }
    private :
        Unit* unit_;
        int x_, y_;
        Command* HandleInput()
        {
            Unit* unit = GetSelectedUnit();
            if(IsPressed(BUTTON_UP)) 
            {
                int destY = unit->GetY() - 1;
                return new MoveUnitCommand(unit, unit->GetX(), destY);
            }
            else if(IsPressed(BUTTON_DOWN)) 
            {
                int destY = unit->GetY() + 1;
                return new MoveUnitCommand(unit, unit->GetX(), destY);
            }

            return nullptr;
        }
};

class Command
{
    public :
        virtual ~Command() {}
        virtual void Execute() = 0;
        virtual void Undo() = 0;
};

//Updated MoveUnitCommand with Undo 

class MoveUnitCommand : public Command
{
    public : 
        MoveUnitCommand(Unit* unit, int x, int y) : 
        unit_(unit), 
        xBefore_ (0), 
        yBefore_ (0), 
        x_(x), y_(y)
        {}

        virtual void Execute()
        {
            xBefore_ = unit_->GetX();
            yBefore_ = unit_->GetY();

            unit_->MoveTo(x_,y_);
        }

        virtual void Undo()
        {
            unit_->MoveTo(xBefore_, yBefore_);
        }

    private :
        Unit* unit_;
        int xBefore_, yBefore_;
        int x_, y_;
}

//In JavaScript with real closures

function MakeMoveUnitCommand(unit, x, y) 
{
  // This function here is the command object:
  return function() 
  {
    unit.MoveTo(x, y);
  }
}

function MakeMoveUnitCommand(unit, x, y) 
{
  var xBefore, yBefore;
  return 
  {
    execute: function() 
    {
      xBefore = unit.x();
      yBefore = unit.y();
      unit.MoveTo(x, y);
    },
    undo: function() 
    {
      unit.MoveTo(xBefore, yBefore);
    }
  };
}

