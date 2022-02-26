
package bmicalculator;

import java.util.Scanner;
public class BMICalculator {
//BMI = kg/m^2
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double weight;
        double height;
        double bmi;
        boolean metric;
        boolean english;
        metric = false;
        english = false;
        int selection;
        
        while(metric == false && english == false)
        {
            System.out.println("Will you use metric or English units?");
            System.out.print("Enter 1 for metric and 2 for English: ");
            selection = scanner.nextInt();
            switch(selection)
            {
                case 1: 
                    metric = true;
                    break;
                case 2:
                    english = true;
                    break;
                default:
                    System.out.println("Invalid answer");
                    System.out.println();
            }
            if(metric == true)
            {
                System.out.print("\nEnter your weight in kilograms: ");
                weight = scanner.nextDouble();
                System.out.print("Enter your height in centimeters: ");
                height = scanner.nextDouble();
            }
            else if(english == true)
            {
                System.out.print("\nEnter your weight in pounds: ");
                weight = scanner.nextDouble();
                weight = weight / 2.205;
                System.out.print("Enter your height in feet(not including inches): ");
                int feet = scanner.nextInt();
                System.out.print("Enter your height in inches(not including feet: ");
                int inches = scanner.nextInt();
                height = feet*12 + inches;
                height = height * 2.54;
            }
            else
            {
                System.out.println("Error");
                break;
            }
            height = height / 100;
            bmi = weight / (height*height);
            System.out.printf("%nYour BMI: %.2f%n", bmi);
            if(bmi >= 30)
            {
                System.out.println("Your BMI is obese.");
            }
            else if(bmi >= 25)
            {
                System.out.println("You BMI is overweight.");
            }
            else if(bmi >= 18.5)
            {
                System.out.println("You BMI is normal.");
            }
            else
            {
                System.out.println("You BMI is underweight.");
            }
            System.out.println("\nBMI VALUES");
            System.out.println("Underweight: Less than 18.5");
            System.out.println("Normal: between 18.5 and 24.9");
            System.out.println("Overweight: between 25 and 29.9");
            System.out.println("Obese: 30 or greater");
        }
    }
    
}
