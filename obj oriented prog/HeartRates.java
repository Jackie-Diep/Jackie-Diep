/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package heartrates;

//Import the Scanner
import java.util.Scanner;

//Class HeartRates
public class HeartRates {

    //Class Variables
        private String firstName;
        private String lastName;
        private int birthYear;
        private int birthDay;
        private int birthMonth;

    //Constructor
    public HeartRates(String firstName, String lastName, int birthYear, int birthDay, int birthMonth)
    {
        setFName(firstName);
        setLName(lastName);
        setBirthYear(birthYear);
        setBirthDay(birthDay);
        setBirthMonth(birthMonth);
    }

    //First Name
    public void setFName(String firstName)
    {
        this.firstName=firstName;
    }

        public String getFName()
            {
                return firstName;
            }

    //Last Name
    public void setLName(String lastName)
    {
        this.lastName=lastName;        
    }

        public String getLName()
        {
            return lastName;
        }

    //Birth Year
    public void setBirthYear(int birthYear)
    {
        this.birthYear=birthYear;
    }

        public int getBirthYear()
        {
            return birthYear;
        }

    //Birth Day
    public void setBirthDay(int birthDay)
    {
        this.birthDay=birthDay;
    }

        public int getBirthDay()
        {
            return birthDay;
        }

    //Birth Month
    public void setBirthMonth(int birthMonth)
    {
        this.birthMonth=birthMonth;
    }

        public int getBirthMonth()
        {
            return birthMonth;
        }

    //Calculate Age
    //*******Used today's date as the date of use
    public int calcAge()
    {
        int age;
        age = 2020 - birthYear;
        if (birthMonth >= 1)
                {
                    if (birthDay > 29)
                    {
                        age--;
                    }
                }
        return age;
    }

    //Calculate Max Heart Rate
    public int maxHeartRate()
    {
        int age = calcAge();
        int maxHeartRate = 220 - age;
        return maxHeartRate;
    }

    //Calculate Target Heart Rate
    public double targetHeartRateLow()
    {
        int maxHeartRate = maxHeartRate();
        double targetHeartRateLow = .50 * maxHeartRate;
        return targetHeartRateLow;
    }

    public double targetHeartRateHigh()
    {
        int maxHeartRate = maxHeartRate();
        double targetHeartRateHigh = .85 * maxHeartRate;
        return targetHeartRateHigh;
    }

//*****MAIN
public static void main(String[] args) 
{
    //Create a Scanner object
    Scanner scanner = new Scanner(System.in);

    //Prompt the user to input information
    System.out.println("What is your first name?");
        String firstName = scanner.nextLine();
    System.out.println("What is your last name?");
        String lastName = scanner.nextLine();
    System.out.println("What year were you born?");
        int birthYear = scanner.nextInt();
    System.out.println("What day of the month were you born?");
        int birthDay = scanner.nextInt();
    System.out.println("What numerical month of the year were you born?");
        int birthMonth = scanner.nextInt();
        
    //Instantiate a new class object using the user's information
    HeartRates hRate = new HeartRates(firstName, lastName, birthYear, birthDay, birthMonth);
    
    System.out.print("************************************************");
    //Calculate and print the user's age
    System.out.printf("%nThe user is %d years old.", hRate.calcAge());
    
    //Calculate and print the user's maximum heart rate
    System.out.printf("%nThe user's maximum heart rate is %d beats per minute.", hRate.maxHeartRate());
    
    //Calculate and print the user's target heart rate
    System.out.printf("%nThe user's target heart rate is between %.2f beats per minute and %.2f beats per minute.%n",
                    hRate.targetHeartRateLow(), hRate.targetHeartRateHigh());
    System.out.print("************************************************");
}
}
