import java.io.*;
import java.util.*;
public class s1jan2016 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("angry.in"));
        PrintWriter pw = new PrintWriter("angry.out");
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] haybales = new int[n];
        for (int i = 0; i < n; i++) {
            haybales[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(haybales);
        int min = haybales[0];
        int max = haybales[n - 1];
        int left = 1;
        int right = (max - min + 1) / 2;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            boolean valid = search(k, haybales, n, mid, min, max);
            if (valid) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        pw.println(res);
        pw.flush();
        br.close();
        pw.close();
    }

    public static boolean search(int k, int[] x, int n, int r, int min, int max) {
        int[] haybales = Arrays.copyOf(x, x.length);
        boolean valid = true;
        int pointer = min;
        int ind = 0;
        int shootCounter = 0; //k
        while (pointer < max) {
            int currShotMax = pointer + 2 * r;
            for (int i = ind; i < n; i++) {
                if (haybales[i] <= currShotMax) {
                    haybales[i] = -1;
                } else {
                    break;
                }
            }
            for (int i = ind; i < n; i++) {
                if (haybales[i] != -1) {
                    pointer = haybales[i];
                    ind = i;
                    break;
                }
                if (i == (n - 1) && haybales[i] == -1) {
                    pointer = max;
                }
            }
            shootCounter++;
        }
        if (shootCounter > k) {
            valid = false;
        }
        return valid;
    }
}
