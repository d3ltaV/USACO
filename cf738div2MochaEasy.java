
import java.io.*;
import java.util.*;
//multiple combos work. just check for all combos and make sure that you arent forming a cyclic graph through DFS or DSU

public class cf738div2MochaEasy {
    static List<Integer>[] ma;
    static List<Integer>[] da;
    static int n;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int mochaEdge = Integer.parseInt(st.nextToken());
        int dianaEdge = Integer.parseInt(st.nextToken());
        ma = new ArrayList[n];
        da = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            ma[i] = new ArrayList<>();
            da[i] = new ArrayList<>();
        }

        for (int i = 0; i < mochaEdge; i ++) {
            StringTokenizer sta = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(sta.nextToken()) - 1;
            int b = Integer.parseInt(sta.nextToken()) - 1;
            ma[a].add(b);
            ma[b].add(a);
        }
        for (int i = 0; i < dianaEdge; i++) {
            StringTokenizer stb = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(stb.nextToken()) - 1;
            int b = Integer.parseInt(stb.nextToken()) - 1;
            da[a].add(b);
            da[b].add(a);
        }

        int counter = 0;
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!ma[i].contains(j) && !da[i].contains(j)) {
                    ma[i].add(j);
                    ma[j].add(i);
                    da[i].add(j);
                    da[j].add(i);
                    if (!checkCycle(ma) && !checkCycle(da)) {
                        counter += 1;
                        ans.add(new ArrayList<>(List.of(i + 1, j + 1)));
                    } else {
                        ma[i].remove((Integer) j);
                        ma[j].remove((Integer) i);
                        da[i].remove((Integer) j);
                        da[j].remove((Integer) i);
                    }
                }
            }
        }
        pw.println(counter);
        for (ArrayList<Integer> pair : ans) {
            pw.println(pair.get(0) + " " + pair.get(1));
        }

        pw.flush();
        br.close();
        pw.close();
    }

    public static boolean checkCycleUtil(List<Integer>[] arr, boolean[] visited, int v, int p) {
        visited[v] = true;

        for (int child : arr[v]) {
            if (!visited[child]) {
                if (checkCycleUtil(arr, visited, child, v)) {
                    return true;
                }
            } else if (child != p) {
                return true;
            }
        }
        return false;
    }

    public static boolean checkCycle(List<Integer>[] arr) {
        boolean[] visited = new boolean[n];
        for (int u = 0; u < n; u++) {
            if (!visited[u] && checkCycleUtil(arr, visited, u, -1)) {
                return true;
            }
        }
        return false;
    }


}

// import java.io.*;
// import java.util.*;

// public class Main {
//     static Set<Integer>[] ma;
//     static Set<Integer>[] da;
//     static int n;
//     static UnionFind ufMa;
//     static UnionFind ufDa;

//     public static void main(String[] args) throws IOException {

//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         PrintWriter pw = new PrintWriter(System.out);
//         StringTokenizer st = new StringTokenizer(br.readLine());
//         n = Integer.parseInt(st.nextToken());
//         int mochaEdge = Integer.parseInt(st.nextToken());
//         int dianaEdge = Integer.parseInt(st.nextToken());
//         ma = new HashSet[n];
//         da = new HashSet[n];

//         for (int i = 0; i < n; i++) {
//             ma[i] = new HashSet<>();
//             da[i] = new HashSet<>();
//         }

//         ufMa = new UnionFind(n);
//         ufDa = new UnionFind(n);

//         for (int i = 0; i < mochaEdge; i++) {
//             StringTokenizer sta = new StringTokenizer(br.readLine());
//             int a = Integer.parseInt(sta.nextToken()) - 1;
//             int b = Integer.parseInt(sta.nextToken()) - 1;
//             ma[a].add(b);
//             ma[b].add(a);
//             ufMa.union(a, b);
//         }

//         for (int i = 0; i < dianaEdge; i++) {
//             StringTokenizer stb = new StringTokenizer(br.readLine());
//             int a = Integer.parseInt(stb.nextToken()) - 1;
//             int b = Integer.parseInt(stb.nextToken()) - 1;
//             da[a].add(b);
//             da[b].add(a);
//             ufDa.union(a, b);
//         }

//         int counter = 0;
//         ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (!ma[i].contains(j) && !da[i].contains(j)) {
//                     ma[i].add(j);
//                     ma[j].add(i);
//                     da[i].add(j);
//                     da[j].add(i);
//                     if (ufMa.find(i) != ufMa.find(j) && ufDa.find(i) != ufDa.find(j)) {
//                         counter += 1;
//                         ans.add(new ArrayList<>(List.of(i + 1, j + 1)));
//                         ufMa.union(i, j);
//                         ufDa.union(i, j);
//                     } else {
//                         ma[i].remove(j);
//                         ma[j].remove(i);
//                         da[i].remove(j);
//                         da[j].remove(i);
//                     }
//                 }
//             }
//         }

//         pw.println(counter);
//         for (ArrayList<Integer> pair : ans) {
//             pw.println(pair.get(0) + " " + pair.get(1));
//         }

//         pw.flush();
//         br.close();
//         pw.close();
//     }

//     // Union-Find Data Structure
//     static class UnionFind {
//         private int[] parent;
//         private int[] rank;

//         public UnionFind(int size) {
//             parent = new int[size];
//             rank = new int[size];
//             for (int i = 0; i < size; i++) {
//                 parent[i] = i;
//                 rank[i] = 0;
//             }
//         }

//         public int find(int x) {
//             if (parent[x] != x) {
//                 parent[x] = find(parent[x]); // Path compression
//             }
//             return parent[x];
//         }

//         public void union(int x, int y) {
//             int rootX = find(x);
//             int rootY = find(y);
//             if (rootX != rootY) {
//                 if (rank[rootX] > rank[rootY]) {
//                     parent[rootY] = rootX;
//                 } else if (rank[rootX] < rank[rootY]) {
//                     parent[rootX] = rootY;
//                 } else {
//                     parent[rootY] = rootX;
//                     rank[rootX]++;
//                 }
//             }
//         }
//     }
// }
