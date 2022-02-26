package shapehierarchyimplementation;
public abstract class Shape {
    //Declare the variables
    private int x;
    private int y;
    
    //The Constructor will pass in the x and y values    
    public Shape(int x, int y) {        
        this.x = x;        
        this.y = y;    
    }
    public abstract String getName();
    
    public int getX()
    {
        return this.x;
    }
    
    public int getY()
    {
        return this.y;
    }
    
    public void setX(int x)
    {
        this.x = x;
    }
    
    public void setY(int y)
    {
        this.y = y;
    }
}