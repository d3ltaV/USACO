import java.io.*;
import java.util.*;

//DFS
public class cfBrainNetworkEasy {
    static boolean[] nodes;
    static List<Integer>[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        if (n - 1 != m) {
            pw.println("no");
        } else {
            nodes = new boolean[n];
            arr = new ArrayList[n];
            for (int i = 0; i < n; i ++) {
                arr[i] = new ArrayList<>();
            }
            for (int i = 0; i < m; i++) {
                StringTokenizer s = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(s.nextToken()) - 1;
                int b = Integer.parseInt(s.nextToken()) - 1;
                arr[a].add(b);
                arr[b].add(a);
            }
            dfs(0, -1);
            boolean f = false;
            for (int i = 0; i < nodes.length; i++) {
                if (nodes[i] == false) {
                    f = true;
                    break;
                }
            }
            if (f) {
                pw.println("no");
            } else {
                pw.println("yes");
            }
        }
        pw.flush();
        br.close();
        pw.close();
    }
    
    public static void dfs(int v, int p) {
        nodes[v] = true;
        for (int child : arr[v]) {
            if (nodes[child] != true) {
                dfs(child, v);
            }
        }
    }
}
