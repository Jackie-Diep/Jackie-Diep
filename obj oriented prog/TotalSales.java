/*
Jackie Diep
February 17, 2020
Object Oriented Programming

Use a two-dimensional array to solve the following problem: A company has four salespeople (1 to 4) who sell five different products (1 to 5). Once a day, each salesperson passes in a slip for each type of product sold.
After processing all the information for last month, display the results in tabular format, with each column representing a salesperson and each row representing a particular product. Cross-total each row to get the total sales of each product for last month. 
Cross-total each column to get the total sales by salesperson for last month. 
Your output should include these cross-totals to the right of the totaled rows and to the bottom of the totaled columns.
*/
package totalsales;

//Imported Random class to randomly generate an amount of slips sold each day for thirty days
import java.util.Random;

//Main begins
public class TotalSales {


    public static void main(String[] args) {
        
        //Create a Random class object rand to use for number generation later
        Random rand = new Random();
        
        //Create the two dimensional array sales as well as two more arrays to hold totals for convenience
        int [][] sales = new int[4][5];
        int [] totalSales = new int [4];
        int [] salesmanTotal = new int [5];
        
        //Format the Upper line of the table with Salesman 1-5 and Product Total
        System.out.print("\t\t");
        for (int i = 0; i < 5; i++)
        {
            System.out.printf("Salesman %d\t", i+1);
        }
        System.out.println("Product Total");
        
        //Loop to randomly generate numbers that will be used in the program
        for(int i = 0; i < 4; i++)
            {
               for(int j = 0; j < 5; j++)
               {
                   for (int day = 0; day < 30; day++)
                   {   
                   int slips = rand.nextInt(5);
                   sales [i][j] = sales [i][j] + slips;
                   }
               }
            }
        
        //Loop to calculate total sales for each product
        for (int i = 0; i < 4; i++)
        {
            for (int j=0; j < 5; j++)
            {
                totalSales [i] += sales [i][j];
            }
        }
        
        //Loop to calculate total sold by each person
        for (int i = 0; i < 4; i++)
        {
            for (int j=0; j < 5; j++)
            {
                salesmanTotal [j] += sales [i][j];
            }
        }
        
        //Output the three arrays to console formatted as a table
        for(int i = 0; i < 4; i++)
        {
           System.out.printf("Product %d: ", i+1);
           for(int j = 0; j < 5; j++)
           {
               System.out.printf("\t%d\t", sales[i][j]);
           }
           System.out.printf("\t%d\n", totalSales[i]);
        }
        System.out.print("Person Total:\t");
        for (int i = 0; i < 5; i++)
        {
            System.out.printf("%d\t\t", salesmanTotal[i]);
        }
    }
    
}
