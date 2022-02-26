package shapehierarchyimplementation;
public class Sphere extends ThreeDimensionalShape {    
    public Sphere(int x, int y, int radius) {        
        super(x, y, radius, radius, radius);
    } 
    
    //Create a method to get the area    
    @Override     
    public int getArea() {        
    int area = (int) (Math.PI * getDim1() * getDim1());        
    return area;    
    }    
    
    //Create a method to get the volume
    @Override
    public double getVolume() {        
    double volume = ((4.0 / 3.0) * Math.PI * getDim1() * getDim1() * getDim1());        
    return volume;    
    } 
    
    //Create a method to return name of shape    
    @Override    
    public String getName(){        
        return "Sphere";    
    }
}
