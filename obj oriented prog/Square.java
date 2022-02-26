package shapehierarchyimplementation;
public class Square extends TwoDimensionalShape{    
//Create the constructor    
    public Square (int x, int y, int side){        
        super(x, y, side, side);
    }    
    //create getArea that returns the area of the square    
    @Override    
    public int getArea(){        
    int area = getDim1() * getDim1();        
    return area;
    } 
    
//create the method 'getName()' which returns the name of the shape    
    @Override    
    public String getName()    {        
    return "Square";    }  
}
