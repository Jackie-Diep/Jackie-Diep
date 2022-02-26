package heartratecalculator;
import java.util.Scanner;
public class HeartRateCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int age;
        int maxHeartRate;
        double targetHeartRateLow;
        double targetHeartRateHigh;
        System.out.print("Age of the person in question is: ");
        age = scanner.nextInt();
        maxHeartRate = 220 - age;
        targetHeartRateLow = .50 * maxHeartRate;
        targetHeartRateHigh = .85 * maxHeartRate;
        System.out.printf("Age: %d%n", age);
        System.out.printf("Maximum Heart Rate: %d bpm%n", maxHeartRate);
        System.out.printf("Target Heart Rate: %.2f bpm - %.2f bpm%n", targetHeartRateLow, targetHeartRateHigh);
    }
    
}
