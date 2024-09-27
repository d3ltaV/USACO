import java.io.*;
import java.util.*;

public class s2feb2017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        boolean[] lights = new boolean[n];
//        for (int i = 0; i < n; i ++) {
//            lights[i] = false;
//        }
        for (int i = 0; i < b; i++) {
            int temp = Integer.parseInt(br.readLine());
            lights[temp - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            pw.println(lights[i]);
        }
        int minRepair = 0;
        for (int i = 0; i < k; i++) {
            if (lights[i] == true) {
                minRepair += 1;
            }
        }
        int current = minRepair;
        for (int i = 0; i < n - k; i++) {
            if (lights[i] == true) {
                current -= 1;
            }
            if (lights[i + k] == true) {
                current += 1;
            }
            if (current < minRepair) {
                minRepair = current;
            }
            pw.println(current);
        }
        pw.println(minRepair);
        pw.flush();
        br.close();
        pw.close();
    }
}
import java.io.*;
import java.util.*;

public class s2feb2017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        boolean[] lights = new boolean[n];
//        for (int i = 0; i < n; i ++) {
//            lights[i] = false;
//        }
        for (int i = 0; i < b; i++) {
            int temp = Integer.parseInt(br.readLine());
            lights[temp - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            pw.println(lights[i]);
        }
        int minRepair = 0;
        for (int i = 0; i < k; i++) {
            if (lights[i] == true) {
                minRepair += 1;
            }
        }
        int current = minRepair;
        for (int i = 0; i < n - k; i++) {
            if (lights[i] == true) {
                current -= 1;
            }
            if (lights[i + k] == true) {
                current += 1;
            }
            if (current < minRepair) {
                minRepair = current;
            }
            pw.println(current);
        }
        pw.println(minRepair);
        pw.flush();
        br.close();
        pw.close();
    }
}