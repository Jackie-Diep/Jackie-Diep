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
public class DateTest {


    public static void main(String[] args) {
        Date date = new Date(11, 29, 2019);
        for (int i = 0; i < 40; i++)
        {
            date.IncrementDay();
            System.out.printf("Loop %d Date: %s",i , date.toString());
            System.out.println("");
        }
    }
    
}
