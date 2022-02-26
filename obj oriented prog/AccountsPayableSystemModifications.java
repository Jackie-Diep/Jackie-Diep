/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package accountspayablesystemmodifications;

/**
 *
 * @author tripl
 */
public class AccountsPayableSystemModifications {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // create six-element Payable array
      Payable[] payableObjects = new Payable[6];
      
      payableObjects[0] = new Invoice("1", "blue", 10, 10.00);
      payableObjects[1] = new Invoice("2", "red", 20, 20.00);
      payableObjects[2] = new SalariedEmployee("Jackie", "Diep", "123-456-7890", 1000.00);
      payableObjects[3] = new HourlyEmployee("Michaela", "Lee", "0987-654-321", 20.00, 40);
      payableObjects[4] = new CommissionEmployee("Phil", "Murray", "321-654-0987", 5000, 0.20);
      payableObjects[5] = new BasePlusCommissionEmployee("Marina", "Campbell", "789-456-0123", 5000, 0.15, 300);

      System.out.println(
         "Invoices and Employees processed polymorphically:"); 

      // generically process each element in array payableObjects
      for (Payable currentPayable : payableObjects) {
         // output currentPayable and its appropriate payment amount
         System.out.printf("%n%s %npayment due: $%,.2f%n", 
            currentPayable.toString(), // could invoke implicitly
            currentPayable.getPaymentAmount()); 
      } 
   } 
}
    
