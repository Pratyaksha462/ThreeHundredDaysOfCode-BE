package verifying_an_alien_dictionary.Java;

import java.io.*;
import java.util.*;

public class Driver {
    private static List<String> method(String filePath) {
        ArrayList<String> al = new ArrayList<>();

        try (BufferedReader buffer = new BufferedReader(
                new FileReader(filePath))) {

            String str;
            while ((str = buffer.readLine()) != null) {
                al.add(str);
            }
        } catch (IOException e) {

            e.printStackTrace();
        }
        return al;
    }

    public static void main(String[] args) {
        System.out.println(drivercode() ? "Accepted" : "Wrong Answer");

    }

    static boolean drivercode() {
        String filePath = "proddata/data/verifying_an_alien_dictionary/testcases.txt";
        List<String> al = method(filePath);

        String[] input1 = new String[0];
        String input2 = null;
        boolean out;

        boolean b = true;

        for (int i = 0; i < al.size(); i++) {
            if (i % 2 == 0) {
                String in[] = al.get(i).split(" ");
                input1 = Arrays.copyOfRange(in, 0, in.length - 1);
                input2 = in[in.length - 1];
            } else {
                out = al.get(i).equals("true") ? true : false;
                b = b & user_out(input1, input2) == out;
                if (b == false) {
                    System.out.println("Test case");
                    System.out.println(Arrays.toString(input1));
                    System.out.println(input2);
                    System.out.println("Your output  " + user_out(input1, input2));
                    System.out.println("Expected output  " + out);
                    return b;
                }
            }

        }
        return b;
    }

    public static boolean user_out(String words[], String order) {
        verifying_an_alien_dictionary.Java.Solution sol = new verifying_an_alien_dictionary.Java.Solution();
        return sol.isAlienSorted(words, order);
    }
}