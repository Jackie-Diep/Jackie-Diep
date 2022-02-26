/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datetest;

/**
 *
 * @author w10076331
 */
// Fig. 8.7: Date.java 
// Date class declaration.

public class Date {
   private int month; // 1-12
   private int day; // 1-31 based on month
   private int year; // any year

   private static final int[] daysPerMonth = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   
   // constructor: confirm proper value for month and day given the year
   public Date(int month, int day, int year) {
      // check if month in range
      if (month <= 0 || month > 12) {
         throw new IllegalArgumentException(
            "month (" + month + ") must be 1-12");
      }

      // check if day in range for month
      if (day <= 0 || 
         (day > daysPerMonth[month] && !(month == 2 && day == 29))) {
         throw new IllegalArgumentException("day (" + day + 
            ") out-of-range for the specified month and year");
      }
      
      if (year <= 0) {
          throw new IllegalArgumentException("year (" + year + "} out-of-range because it is negative");
      }
      
      // check for leap year if month is 2 and day is 29
      if (month == 2 && day == 29 && !(year % 400 == 0 || 
           (year % 4 == 0 && year % 100 != 0))) {
         throw new IllegalArgumentException("day (" + day +
            ") out-of-range for the specified month and year");
      }
   
      this.month = month;
      this.day = day;
      this.year = year;

      System.out.printf("Date object constructor for date %s%n", this);
   } 
   
   public void setDay(int day) {
       this.day = day;
   }
   
   public void setMonth(int month) {
       this.month = month;
   }
   
   public void setYear(int year) {
       this.year = year;
   }
   
   public void IncrementDay() {
       day++;
       if ((day > daysPerMonth[month] && !(month == 2 && day == 29))) {
           day = 0;
           setDay(day);
           IncrementMonth();
       }
        
       else {
           setDay(day);
       }
   }
   
   public void IncrementMonth() {
       month++;
        if(month > 12) {
        month = 0;
        setMonth(month);
           IncrementYear();
        }
        else {
            setMonth(month);
        }
   }
   
   public void IncrementYear() {
       year++;
       setYear(year);
   }
   /*public void tick() {
       if(second < 0 || second >= 60)
       {
           throw new IllegalArgumentException("second must be 0-59");
       }
       else
       {
           second++;
           if(second >= 60)
           {
               second = 0;
                setSecond(second);
               incrementMinute();
           }
           else
           {
               setSecond(second);
           }
       }
   } */
   
   // return a String of the form month/day/year
   public String toString() {
      return String.format("%d/%d/%d", month, day, year); 
   } 
} 



/**************************************************************************
 * (C) Copyright 1992-2018 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
