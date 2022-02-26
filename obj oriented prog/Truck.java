/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vehiclesuperclass;

/**
 *
 * @author tripl
 */
public class Truck extends Vehicle {
    //Declare private variable tonnage
    private final double tonnage;
    
    //Truck constructor using a call to super class Vehicle
    public Truck(String make, String model, int year, double tonnage)
    {
        super(make, model, year);
        this.tonnage = tonnage;
    }

    //Function to print truck variables
    public void printTruck()
    {
        printVehicle();
        System.out.println("Tonnage: " + tonnage);
    }
}
