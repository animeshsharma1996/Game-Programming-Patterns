//A Place To Put Down Roots

enum Terrain
{
    TERRAIN_GRASS,
    TERRAIN_HILL,
    TERRAIN_RIVER
    //Other terrains...
};

class World
{
    private :
        Terrain tiles[WIDTH][HEIGHT];

        int GetMovementCost(int x, int y)
        {
            switch(tiles[x][y])
            {
                case TERRAIN_GRASS : return 1;
                case TERRAIN_HILL : return 3;
                case TERRAIN_RIVER : return 2;
                //Other terrains...
            }
        }

        bool IsWater(int x, int y)
        {
            switch(tiles[x][y])
            {
                case TERRAIN_GRASS : false;
                case TERRAIN_HILL : false;
                case TERRAIN_RIVER : true;
                //Other terrains...
            }
        }
};

//Instead of enum Terrain, we can have class 

class Terrain
{
    public :
        Terrain
        (
            int movementCost_,
            bool isWater_,
            Texture texture_
        ) : movementCost(movementCost_), 
            isWater(isWater_), 
            texture(texture_) {}

        int GetMovementCost() const { return movementCost; }
        bool IsWater() const { return isWater; }
        const Texture& GetTexture() const { return texture; }
    
    private :
        int movementCost;
        bool isWater;
        Texture texture;
};

//Instead of having grid of enums or Terrain objects, it will good to have a 
//grid of pointers to Terrain objects since each type of tile is identical
//to it's own tile

class World
{
    private :
        Terrain* tiles[WIDTH][HEIGHT];

    //Other stuff...
}

//We can store the terrain instances directly in the world class

class World
{
    public :
        World()
        : grassTerrain(1, false, GRASS_TEXTURE),
          hillTerrain(3, false, HILL_TEXTURE),
          riverTerrain(2, true, RIVER_TEXTURE) {}

        GenerateTerrain()
        {
            //Fill the ground with grass.
            for(int x = 0; x < WIDTH, ++x)
            {
                for(int y = 0; y < HEIGHT; ++y)
                {
                    //Sprincle some hills.
                    if(random(10) == 0)
                    {
                        tiles[x][y] = &hillTerrain;
                    }
                    else
                    {
                        tiles[x][y] = &grassTerrain;
                    }
                }
            }

            //Lay a river.
            int x = random(WIDTH);
            for(int y = 0; y < HEIGHT; ++y)
            {
                tiles[x][y] = &riverTerrain;
            }
        }

        const Terrain& GetTile(int x, int y) const
        {
            return *tiles[x][y];
        }
    
    private :
        Terrain grassTerrain;
        Terrain hillTerrain;
        Terrain riverTerrain;
    
    //Other stuff...

};

int cost = world.GetTile(2, 3).GetMovementCost();