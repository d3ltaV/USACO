import java.io.*;
import java.util.*;
public class cf959div1and2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int maxToxicity = Integer.parseInt(st.nextToken());
        int[] levelsT = new int[n];
        StringTokenizer stt = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            levelsT[i] = Integer.parseInt(stt.nextToken());
        }
    }
}
