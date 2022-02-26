package shapehierarchyimplementation;
public class Cube extends ThreeDimensionalShape {    
    public Cube(int x, int y, int side) {        
        super(x, y, side, side, side);
    } 
    
    //Create a method to get the area    
    @Override     
    public int getArea() {        
    int area = (int) (6 * getDim1() * getDim1());        
    return area;    
    }    
    
    //Create a method to get the volume
    @Override
    public double getVolume() {        
    double volume = (getDim1() * getDim2() * getDim3());        
    return volume;    
    } 
    
    //Create a method to return name of shape    
    @Override    
    public String getName(){        
        return "Cube";    
    }
}