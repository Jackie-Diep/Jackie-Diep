package shapehierarchyimplementation;
public class Tetrahedron extends ThreeDimensionalShape {    
    public Tetrahedron(int x, int y, int side) {        
        super(x, y, side, side, side);
    } 
    
    //Create a method to get the area    
    @Override     
    public int getArea() {        
    int area = (int) (Math.sqrt(3) * getDim1() * getDim2());        
    return area;    
    }    
    
    //Create a method to get the volume
    @Override
    public double getVolume() {        
    double volume = (getDim1() * getDim2() * getDim3())/(6.0 * Math.sqrt(2));        
    return volume;    
    } 
    
    //Create a method to return name of shape    
    @Override    
    public String getName(){        
        return "Tetrahedron";    
    }
}