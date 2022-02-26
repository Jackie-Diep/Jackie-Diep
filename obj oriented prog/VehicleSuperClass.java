/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vehiclesuperclass;

//Import Scanner for user input
import java.util.Scanner;
/**
 *
 * @author tripl
 */
public class VehicleSuperClass {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        //Create a scanner class object
        Scanner scanner = new Scanner(System.in);
        
        //Declare variables to be used in the constructors
        String make;
        String model;
        int year;
        double tonnage;
        
        //Prompt for make
        System.out.println("Input make: ");
        make = scanner.nextLine();
        
        //Prompt for model
        System.out.println("Input model: ");
        model = scanner.nextLine();
        
        //Prompt for year
        System.out.println("Input year: ");
        year = scanner.nextInt();
        
        //Prompt for tonnage
        System.out.println("Input tonnage: ");
        tonnage = scanner.nextInt();
        
        //Create a truck class object
        Truck truck = new Truck(make, model, year, tonnage);
        
        //Call the printTruck function
        truck.printTruck();
    }
    
}
