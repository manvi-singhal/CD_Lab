import java.util.Scanner;

public class StringComparison{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
       
        System.out.println("Enter the first string:");
        String str1 = scanner.nextLine();
       
        System.out.println("Enter the second string:");
        String str2 = scanner.nextLine();

        if (str1.equalsIgnoreCase(str2)) {
            System.out.println("The strings are equal (ignoring case).");
        } else {
            System.out.println("The strings are not equal (ignoring case).");
        }
       
        if (str1.equals(str2)) {
            System.out.println("The strings are equal (case-sensitive).");
        } else {
            System.out.println("The strings are not equal (case-sensitive).");
        }
       
        int result = str1.compareTo(str2);
        if (result == 0) {
            System.out.println("The strings are equal.");
        } else if (result < 0) {
            System.out.println("str1 comes before str2 in lexicographic order.");
        } else {
            System.out.println("str1 comes after str2 in lexicographic order.");
        }
       
        scanner.close();
    }
}

