/*
Jackie Diep
April 28, 2020
CSC 317
Project 12 - FileReader Project

" Using tonight's FileReader Program, update the code to read in a text file with 25 test scores.  
Validate that thetest scores are between 0 - 100.  
Display the average of the test scores (between 0-100) on the screen after reading the text file.  
Also, display highest and lowest test scores (between 0-100)."
 */
package read;
import java.io.*;
import java.util.Scanner;

public class Read {

public static void main(String[] args) {

//try catch block to capture java.IOExceptions
try{

    //Open temp.txt to be read into the program
    Scanner input = new Scanner(new File("temp.txt"));

    //Number to hold the current grade being read from the file
    float number = 0;

    //Highest and Lowest to hold the highest and lowest grades read from the file
    float highest = 9999;
    float lowest = 9999;
    
    //Total to hold all of the grades being read from the file
    float total = 0;

    //Counter to calculate average instead of hard coding 25 in case there are more or less than 25 valid test grades
    int counter = 0;
    
    //Average to hold the average value of grades from the file
    double average;

    //While the file still has integers to be read from the file
    while(input.hasNextInt())
    {

        //Set number equal to the next float in the file
        number = input.nextFloat();
        
        //Check if the grade is inclusively between 0 and 100
        if(number >= 0 && number <= 100)
        {
            
            //If this is the first number read into the file set highest and lowest equal to the number
            if(counter == 0)
            {
                highest = number;
                lowest = number;
            }
            
            //If highest is less than the new number, set highest equal to the new number
            else if(highest < number)
            {
                highest = number;
            }
            
            //If lowest is greater than the new number, set lowest equal to the new number
            else if(lowest > number)
            {
                lowest = number;
            }
            
            //Add number to total
            total += number;

            //Increment counter for each grade read from the file
            counter++;
        }
    }
    
    //If no valid grades were read into the file
    if(counter == 0)
    {
        System.out.println("No valid grades were read into the file.");
    }
    
    //If grades were read into the file
    else
    {
    //Output Total to console
    System.out.printf("Total: %.0f%n", total);
    
    //Calculate Average
    average = total / counter;
    
    //Output Average to console
    System.out.printf("Average: %.2f%n", average);
    
    //Output Highest to console
    System.out.printf("Highest: %.0f%n", highest);
    
    //Output Lowest to console
    System.out.printf("Lowest: %.0f%n", lowest);
    }
}

//If the file was not found, output the error to console
    catch (FileNotFoundException ex)
    {
    System.out.println("File temp.txt does not exist");
    }
}
}