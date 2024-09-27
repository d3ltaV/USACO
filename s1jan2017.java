import java.io.*;
import java.util.*;

public class s1jan2017 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int tMax = Integer.parseInt(st.nextToken());

        int[] durations = new int[n];
        for (int i = 0; i < n; i++) {
            durations[i] = Integer.parseInt(br.readLine());
        }

        int left = 1;  
        int right = n;
        int result = n; 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            boolean sim = runSimul(mid, n, durations, tMax);
            if (sim) {
                result = mid;  
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        pw.println(result);
        pw.flush();
    }

    public static boolean runSimul(int k, int n, int[] durations, int tMax) {
        int[] stages = new int[k]; 
        for (int i = 0; i < n; i++) {

            int earliestStage = 0;
            for (int j = 1; j < k; j++) {
                if (stages[j] < stages[earliestStage]) {
                    earliestStage = j;
                }
            }

            stages[earliestStage] += durations[i];
        }

        int maxTime = 0;
        for (int i = 0; i < k; i++) {
            maxTime = Math.max(maxTime, stages[i]);
        }
        return maxTime <= tMax;
    }
}