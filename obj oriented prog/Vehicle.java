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
public class Vehicle {

   private String make;
   private String model;
   private int year;

   Vehicle(String make, String model, int year)
   {
      this.make = make;
      this.model = model;
      this.year = year;
   }

   public String getMake()
   {
      return make;
   }

   public String getModel()
   {
      return model;
   }

   public int getYear()
   {
      return year;
   }

   public void printVehicle()
   {
      System.out.println("Make: " + make + ", Model: " + model + ", Year: " +
                         year);
   }
}
