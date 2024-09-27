import java.util.*;

//Find all children size of each node using DFS and aggregate.
public class cfITRestaurants {
    static int N;
    static List<Integer>[] adj = new ArrayList[5010];
    static boolean[] ans = new boolean[5010];
    static boolean[] tmp = new boolean[5010];

    static int dfs(int v, int p) {
        List<Integer> cs = new ArrayList<>();
        int n = 1;
        for (int i = 0; i < adj[v].size(); i++) {
            int w = adj[v].get(i);
            if (w == p) continue;
            int c = dfs(w, v);
            cs.add(c);
            n += c;
        }
        cs.add(N - 1 - cs.stream().mapToInt(Integer::intValue).sum());

        Arrays.fill(tmp, false);
        tmp[0] = true;
        for (int c : cs) {
            for (int k = N - c; k >= 0; --k) {
                System.out.print(k + " " + c + " " + v);
                System.out.println(tmp[k]);
                tmp[k + c] |= tmp[k];
            }
        }
        for (int k = 0; k <= N; ++k) {
            ans[k] |= tmp[k];
        }

        return n;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            for (int i = 0; i < N; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < N - 1; i++) {
                int a = scanner.nextInt() - 1;
                int b = scanner.nextInt() - 1;
                adj[a].add(b);
                adj[b].add(a);
            }

            Arrays.fill(ans, false);
            dfs(0, -1);
            ans[0] = ans[N - 1] = false;

            int count = 0;
            for (int i = 0; i < N; i++) {
                if (ans[i]) count++;
            }
            System.out.println(count);
            for (int i = 0; i < N; i++) {
                if (ans[i]) {
                    System.out.println(i + " " + (N - i - 1));
                }
            }
        }
    }
}


// import java.io.*;
// import java.util.*;

// //DFS; max number of restaurants is always n-1 (max), for every combination of {i (i = 1), max - i}, DFS tree until i nodes are traveled
// //If the ith node has more than one children, print {i, max - i}, else, go to next combination

// public class cfITRestaurants {
//     static List<Integer>[] arr;
//     static int nodesVisited = 0;
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         PrintWriter pw = new PrintWriter(System.out);
//         int n = Integer.parseInt(br.readLine());
//         arr = new ArrayList[n];

//         for (int i = 0; i < n - 1; i++) {
//             StringTokenizer st = new StringTokenizer(br.readLine());
//             int a = Integer.parseInt(st.nextToken()) - 1;
//             int b = Integer.parseInt(st.nextToken()) - 1;
//             arr[a].add(b);
//             arr[b].add(a);
//         }
//         int maxAns = n - 1;
//         for (int i = 1; i < maxAns; i++) {
//             nodesVisited = 0;
//             boolean[] visited = new boolean[n - 1];
//             int ret = dfs(i, visited, 0);
//             if (ret == 1) {
//                 int first = i;
//                 in second = 
//             }
//         }
//     }
//     public static int dfs(int limit, boolean[] visited, int node) {
//         if (nodesVisited >= limit) {
//             if (arr[node].size() > 2) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }
//         visited[node] = true;
//         nodesVisited += 1;
//         for (int child : arr[node]) {
//             if (!visited[child]) {
//                 int result = dfs(limit, visited, child);
//             }
//         }
//         return 0;
//     }
// }