package shapehierarchyimplementation;
public abstract class ThreeDimensionalShape extends Shape {
    //Declare the variables    
    private int dim1;    
    private int dim2;    
    private int dim3;
    public ThreeDimensionalShape(int x, int y, int d1, int d2, int d3) {        
        super(x, y);        
        dim1 = d1;        
        dim2 = d2;   
        dim3 = d3;
    }
    
    //Create the accessor methods for dim1, dim2, and dim3
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
    
    public int getDim3()
    {
        return this.dim3;
    }
    
    public void setDim3(int dim3)
    {
        this.dim3 = dim3;
    }
    
    //Create an abstract area method    
    public abstract int getArea();
    
    //Create an abstract Volume method    
    public abstract double getVolume();
    
}
