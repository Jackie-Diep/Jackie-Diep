/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectangleclass;

//Import the Scanner
import java.util.Scanner;

public class RectangleClass {

    //Class Variables
        private float length;
        private float width;
        private float area;
        private float perimeter;
        
    //Constructor
        public RectangleClass()
        {
            length = 1;
            width = 1;
        }
        
    //Set length
        public void setLength(float length)
        {
            //Create a scanner object
            Scanner scanner = new Scanner(System.in);
            
            //Use a while loop to ensure that the user inputs a satisfactory value 
            int check = 0;
            while (check == 0)
            {
                
                //Check for a satisfactory value
                if(length > 0 && length < 20)
                {
                    this.length = length;
                    check++;
                }
                
                //Request a satisfactory value
                else
                {
                    System.out.println("**********Error**********");
                    System.out.println("Please select a length greater than 0.0 and less than 20.0.");
                    length = scanner.nextFloat();
                }
            }
        }
        
    //Get length
        public float getLength()
        {
            return length;
        }
        
    //Set width
        public void setWidth(float width)
        {
            //Create a Scanner object
            Scanner scanner = new Scanner(System.in);
            
            //Use a while loop to ensure that the user inputs a satisfactory value 
            int check = 0;
            while (check == 0)
            {
                //Check for a satisfactory value
                if(width > 0 && width < 20)
                {
                    this.width = width;
                    check++;
                }
                
                //Request a satisfactory value
                else
                {
                    System.out.println("**********Error**********");
                    System.out.println("Please select a width greater than 0.0 and less than 20.0.");
                    width = scanner.nextFloat();
                }
            }
        }
        
    //Get width
        public float getWidth()
        {
            return width;
        }
        
    //Calculate area
        public float calcArea()
        {
            area = length * width;
            return area;
        }
        
    //Calculate perimeter
        public float calcPerimeter()
        {
            perimeter = (length * 2) + (width * 2);
            return perimeter;
        }
        
//*****MAIN
    public static void main(String[] args) 
    {
        //Create a Scanner object
        Scanner scanner = new Scanner(System.in);
        //Instantiate a new class object
        RectangleClass rectangle = new RectangleClass();
        
        //Menu to test RectangleClass methods
        int menu = 0;
        do
        {
            
            //Display current rectangle length and width
            System.out.println("********************************");
            System.out.println("Current Rectangle Attributes");
            System.out.printf("Length: %.2f%nWidth: %.2f%n", rectangle.getLength(), rectangle.getWidth());
            System.out.println("********************************");
            
            //Display Menu options
            System.out.println("\nMenu Options: ");
            System.out.println("1. Set Length || 2. Set Width || 3. Calculate Area || 4. Calculate Perimeter || 5. Exit");
            
            //Prompt the user for a menu option
            System.out.print("Option: ");
            menu = scanner.nextInt();
            switch(menu)
                {
                
                //Option 1: Prompt for a length and call the setLength method
                case 1:
                    System.out.println("Selected Option: Set Length");
                    System.out.println("Select a length between 0.0 and 20.0.");
                    float length = scanner.nextFloat();
                    rectangle.setLength(length);
                    break;
                    
                //Option 2: Prompt for a width and call the setWidth method
                case 2:
                    System.out.println("Selected Option: Set Width");
                    System.out.println("Select a width between 0.0 and 20.0.");
                    float width = scanner.nextFloat();
                    rectangle.setWidth(width);
                    break;
                    
                //Option 3: Call the calcArea method and display the area
                case 3:
                    System.out.println("Selected Option: Calculate Area");
                    System.out.println("********************************");
                    System.out.printf("%nArea: %.2f%n", rectangle.calcArea());
                    break;
                    
                //Option 4: Call the calcPerimeter method and display the perimeter
                case 4:
                    System.out.println("Selected Option: Calculate Perimeter");
                    System.out.println("********************************");
                    System.out.printf("Perimeter: %.2f%n", rectangle.calcPerimeter());
                    break;
                    
                //Option 5: Thank the user for using the program and exit the do-while loop
                case 5: 
                    System.out.println("\nThank you for using this program.");
                    break;
                    
                //Invalid menu option: Inform the user that the option is not valid
                default:
                    System.out.println("That is not a valid menu option.");
                }
        }while (menu != 5);
    }
    
}
