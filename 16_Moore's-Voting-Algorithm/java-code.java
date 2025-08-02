
import java.util.*;

public class MooreVoting {

    // function for implementing Moore's Voting Algorithm
    public static void moore(int[] arr, int n) {
        int count = 0; //  keep track of current candidate count
        int el = 0;    //  store the potential majority element
        int cnt = 0;   //  count actual occurrences of candidate

        // Step 1: Finding a candidate for majority element
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                el = arr[i]; // setting current element as candidate
                count = 1;
            } else if (arr[i] == el) {
                count++; //if  Same as candidate → increment count
            } else {
                count--; // if Different → cancel out
            }
        }

        // Step 2: Verifying the candidate ( really majority?)
        for (int i = 0; i < n; i++) {
            if (arr[i] == el)
                cnt++;
        }

        // Step 3: Check if count > n/2
        if (cnt > (n / 2)) {
            System.out.println("Majority element is :: " + el);
        } else {
            System.out.println("No majority element");
        }
    }

   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;


        System.out.print("Enter the size of an array :: ");
        n = sc.nextInt();

        int[] arr = new int[n];

        System.out.print("Enter the elements for the array :: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

      
        moore(arr, n);
    }
}
