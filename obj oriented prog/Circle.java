package shapehierarchyimplementation;
public class Circle extends TwoDimensionalShape {    
//create the constructor    
    public Circle(int x, int y, int radius) {        
        super(x, y, radius, radius);
    }    
    
    //Create a method to get the area    
    @Override     
    public int getArea() {        
    int area = (int) (Math.PI * getDim1() * getDim1());        
    return area;    
    }    
    
    //Create a method to return name of shape    
    @Override    
    public String getName(){        
        return "Circle";    
    }
}