import java.io.*;
import java.util.*;

//DFS approach with adjacency list containing parents
//BFS approach with adjacency list containing noly children
public class s1dec2020 {
    static int n;
    static List<Integer>[] farms;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        n = Integer.parseInt(br.readLine());
        farms = new ArrayList[n];
        for (int i = 0 ; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int temp1 = Integer.parseInt(st.nextToken()) - 1;
            int temp2 = Integer.parseInt(st.nextToken()) - 1;
            farms[temp1].add(temp2);
            farms[temp2].add(temp1);
        }
        int ans = dfs(0, -1);
        pw.println(ans);
        pw.flush();
        br.close();
        pw.close();
    }
    public static int dfs(int start, int parent) {
        int ret = 0; 
        int cows = farms[start].size();
        if (parent != -1) {
            cows -= 1; // Adjust because we don't want to count the parent as a child
        }
        int current = 1;
        int days = 0;
        while (current < cows) {
            days += 1;
            cows *= 2;
        }
        ret += days;
        for (int next : farms[start]) {
            if (next != parent) {
                ret += 1 + dfs(next, start);
            }
          
        }
        return ret;
    }
    
}
