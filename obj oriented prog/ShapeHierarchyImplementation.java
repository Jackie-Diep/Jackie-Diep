package shapehierarchyimplementation;
public class ShapeHierarchyImplementation {
public static void main(String[] args) {
        //create subclass objects        
        Circle circleObj = new Circle(54, 96, 4);        
        Square squareObj = new Square(10, 25, 6);          
        Triangle triangleObj = new Triangle(50, 20, 10);
        Sphere sphereObj = new Sphere(90, 30, 10);
        Cube cubeObj = new Cube(30, 50, 10);
        Tetrahedron tetrahedronObj = new Tetrahedron(70, 70, 10);
        
    //Note for Three Dimensional Objects          
    //there will be the same number of parameters.        
    //create an array of objects        
    Shape shapes[] = new Shape[6];        
    shapes[0] = circleObj;        
    shapes[1] = squareObj;
    shapes[2] = triangleObj;
    shapes[3] = sphereObj;
    shapes[4] = cubeObj;
    shapes[5] = tetrahedronObj;
    //create an 'enhanced-for-loop' to print all shapes        
    for (Shape currentShape : shapes) {                     
        if (currentShape instanceof TwoDimensionalShape) { 
            System.out.printf("Two Dimensional Shape: %s\n", currentShape.getName()); 
            TwoDimensionalShape twoDimensionalShape = (TwoDimensionalShape) currentShape;                
            System.out.printf("%s's area is %s\n", currentShape.getName(), twoDimensionalShape.getArea());            
        }     
        else if (currentShape instanceof ThreeDimensionalShape)
        {
            System.out.printf("Three Dimensional Shape: %s\n", currentShape.getName()); 
            ThreeDimensionalShape threeDimensionalShape = (ThreeDimensionalShape) currentShape;                
            System.out.printf("%s's area is %s\n", currentShape.getName(), threeDimensionalShape.getArea());  
            System.out.printf("%s's volume is %.2f\n", currentShape.getName(), threeDimensionalShape.getVolume()); 
        }
        System.out.println();        
    }    
}
}
    
