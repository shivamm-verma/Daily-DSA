import java.util.*;

public class TowerOfHanoiExample {

    // Recursive Java function to solve the Tower of Hanoi
    public static void TowerOfHanoi(int n, char src, char dest, char aux) {
        if (n == 1) { // Base Case
            System.out.println("Move disk 1 from source " + src + " to destination " + dest);
            return;
        }

        TowerOfHanoi(n - 1, src, aux, dest); // Recursive Call 1
        System.out.println("Move disk " + n + " from source " + src + " to destination " + dest);
        TowerOfHanoi(n - 1, aux, dest, src); // Recursive Call 2
    }

    // Driver code
    public static void main(String[] args) {
        int n = 4;
        TowerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the names of rods
    }
}

// Steps Followed:
// Move disk 1 from source A to destination C
// Move disk 2 from source A to destination B
// Move disk 1 from source C to destination B
// Move disk 3 from source A to destination C
// Move disk 1 from source B to destination A
// Move disk 2 from source B to destination C
// Move disk 1 from source A to destination C