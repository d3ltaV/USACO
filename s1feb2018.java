//Easy simulatino problem. Had trouble due to large integers; changing everything to long fixed issue.
import java.io.*;
import java.util.*;

public class s1feb2018 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("reststops.in"));
        PrintWriter pw = new PrintWriter("reststops.out");
        StringTokenizer st = new StringTokenizer(br.readLine());
        long length = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());
        long jSpeed = Long.parseLong(st.nextToken());
        long bSpeed = Long.parseLong(st.nextToken());
        long[][] tastiness = new long[(int)n][2];
        long maxPos = -1;
        long max = -1; // tastiness
        int ind = 0; // index in the tastiness array
        long pos = -1; // x

        for (int i = 0; i < n; i++) {
            StringTokenizer stt = new StringTokenizer(br.readLine());
            tastiness[i][0] = Long.parseLong(stt.nextToken());
            tastiness[i][1] = Long.parseLong(stt.nextToken());
        }

        Arrays.sort(tastiness, (a, b) -> Long.compare(a[0], b[0]));

        for (int i = 0; i < n; i++) {
            if (tastiness[i][1] > max) {
                max = tastiness[i][1];
                ind = i;
                pos = tastiness[i][0];
            }
            if (tastiness[i][0] > maxPos) {
                maxPos = tastiness[i][0];
            }
        }

        long[] jTimeSteps = new long[(int)length];
        long[] bTimeSteps = new long[(int)length];
        long jCounter = 0;
        long bCounter = 0;
        for (int i = 0; i < length; i++) {
            jCounter += jSpeed;
            bCounter += bSpeed;
            jTimeSteps[i] = jCounter;
            bTimeSteps[i] = bCounter;
        }

        long counter = 0;
        while (pos <= maxPos) {
            long diff = jTimeSteps[(int)(pos - 1)] - bTimeSteps[(int)(pos - 1)];
            System.out.println(diff);
            System.out.println(max);
            System.out.println(diff * max);
            counter += (diff * max);
            System.out.println(bTimeSteps[(int)(pos - 1)]);

            // Update bessie time steps and find next resting position; update all vars
            if (pos == maxPos) {
                break;
            }
            for (int i = (int)pos; i < length; i++) {
                bTimeSteps[i] += diff;
            }
            max = -1;
            for (int i = ind + 1; i < n; i++) {
                if (tastiness[i][1] > max) {
                    max = tastiness[i][1];
                    ind = i;
                    pos = tastiness[i][0];
                }
            }
        }
        pw.println(counter);
        pw.flush();
        pw.close();
        br.close();
    }
}