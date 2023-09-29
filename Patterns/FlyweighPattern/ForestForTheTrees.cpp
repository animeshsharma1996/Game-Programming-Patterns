//Forest of the Trees

class Tree
{
    private :
        Mesh mesh;
        Texture bark;
        Texture leaves;
        Vector position;
        double height;
        double thickness;
        Color barkTint;
        Color leafTint;
};

class TreeModel
{
    private :
        Mesh mesh;
        Texture bark;
        Texture leaves;
}

class Tree
{
    private :
        TreeModel* model;
        Vector position;
        double height;
        double thickness;
        Color barkTint;
        Color leafTint;
}

