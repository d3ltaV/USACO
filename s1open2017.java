import java.io.*;
import java.util.*;

public class s1open2017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("pairup.in"));
        PrintWriter pw = new PrintWriter("pairup.out");
        int n = Integer.parseInt(br.readLine());
        int[][] cows = new int[n][2];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int temp1 = Integer.parseInt(st.nextToken());
            int temp2 = Integer.parseInt(st.nextToken());
            cows[i][0] = temp1;
            cows[i][1] = temp2;
        }
        Arrays.sort(cows, (a, b) -> Integer.compare(a[1], b[1]));
        int maxTime = Integer.MIN_VALUE;
        int pointer1 = 0;
        int pointer2 = n - 1;
        while (pointer1 < pointer2) {
            if (cows[pointer1][1] + cows[pointer2][1] > maxTime) {
                maxTime = cows[pointer1][1] + cows[pointer2][1];
            }
            if (cows[pointer1][0] == cows[pointer2][0]) {
                cows[pointer1][0] = 0;
                cows[pointer2][0] = 0;
                pointer1++;
                pointer2--;
            } else if (cows[pointer1][0] < cows[pointer2][0]) {
                cows[pointer2][0] = cows[pointer2][0] - cows[pointer1][0];
                cows[pointer1][0] = 0;
                pointer1 +=1;
            } else {
                cows[pointer1][0] = cows[pointer1][0] - cows[pointer2][0];
                cows[pointer2][0] = 0;
                pointer2 -= 1;
            }
        }
        pw.println(maxTime);
        pw.flush();
        br.close();
        pw.close();
    }
}
