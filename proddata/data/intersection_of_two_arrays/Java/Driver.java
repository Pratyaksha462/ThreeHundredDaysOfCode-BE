package intersection_of_two_arrays.Java;

import java.io.*;
import java.util.*;

public class Driver {
    private static List<String> method(String filePath) {
        ArrayList<String> al = new ArrayList<>();

        try (BufferedReader buffer = new BufferedReader(
                new FileReader(filePath))) {

            String str;
            while ((str = buffer.readLine()) != null) {
                str = str.replace("], [","||");
                str = str.replace("[", "");
                str = str.replaceAll("]", "");
                str = str.replace(",", " ");
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
        String filePath = "proddata/data/intersection_of_two_arrays/testcases.txt";
        List<String> al = method(filePath);

        int testcases = Integer.parseInt(al.remove(0));
        int input1[] = new int[0];
        int input2[] = new int[0];
        int output[] = new int[0]; 
        boolean b = true;
        for (int i = 0; i < 2 * testcases; i++) {
            if (i % 2 == 0) {
                StringTokenizer st = new StringTokenizer(al.get(i),"||");
                String in[] = st.nextToken().split(" ");
                input1 = Arrays.stream(in).mapToInt(Integer :: parseInt).toArray();
                
                in = st.nextToken().split(" ");
                input2 = Arrays.stream(in).mapToInt(Integer :: parseInt).toArray();
            } else {
                String in[] = al.get(i).split(" ");
                output = Arrays.stream(in).mapToInt(Integer :: parseInt).toArray();
                int[] user_out = user_out(input1,input2);
                Arrays.sort(output);
                Arrays.sort(user_out);
                b = b & Arrays.equals(output, user_out) ? true : false;
                if (b == false) {
                    System.out.println("Test case");
                    System.out.println(Arrays.toString(input1));
                    System.out.println(Arrays.toString(input2));
                    System.out.println("Your output  " + Arrays.toString(user_out));
                    System.out.println("Expected output  " + Arrays.toString(output));
                    return b;
                }
            }
        }
        return b;
    }
    
    public static int[] user_out(int input1[], int input2[])
    {
        intersection_of_two_arrays.Java.Solution sol = new intersection_of_two_arrays.Java.Solution();
        return sol.intersection(input1, input2);
    }

}
