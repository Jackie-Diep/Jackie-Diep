package shapehierarchyimplementation;
public abstract class TwoDimensionalShape extends Shape {
    //Declare the variables    
    private int dim1;    
    private int dim2;    
    public TwoDimensionalShape(int x, int y, int d1, int d2) {        
        super(x, y);        
        dim1 = d1;        
        dim2 = d2;    
    }
    
    //Create the accessor methods for dim1 and dim2
    public int getDim1()
    {
        return this.dim1;
    }
    
    public void setDim1(int dim1)
    {
        this.dim1 = dim1;
    }
    
    public int getDim2()
    {
        return this.dim2;
    }
    
    public void setDim2(int dim2)
    {
        this.dim2 = dim2;
    }
    
    //Create an abstract area method    
    public abstract int getArea();
    
}
