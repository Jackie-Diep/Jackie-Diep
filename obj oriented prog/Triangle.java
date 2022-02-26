package shapehierarchyimplementation;
public class Triangle extends TwoDimensionalShape{    
//Create the constructor    
    public Triangle (int x, int y, int side){        
        super(x, y, side, side);
    }    
    
    //create getArea that returns the area of the triangle   
    @Override    
    public int getArea(){        
    int area = (getDim1() * getDim2())/2;        
    return area;
    } 
    
//create the method 'getName()' which returns the name of the shape    
    @Override    
    public String getName()    {        
    return "Triangle";    }  
}