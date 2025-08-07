
import java.util.*;

public class MooreVoting {

    
    public static void moore(int[] arr, int n) {
        int count = 0; 
        int el = 0;   
        int cnt = 0;   

  
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                el = arr[i]; 
                count = 1;
            } else if (arr[i] == el) {
                count++; 
            } else {
                count--; 
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == el)
                cnt++;
        }


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
