import java.io.*;
import java.util.*;
//minimum relevance lol.

public class g1jan2018 {
    private static class Edge {
        int to;
        int relevance;
        public Edge(int to, int relevance) {
            this.to = to;
            this.relevance = relevance;
        }
    }

    static int threshold;
    static int numReachable;
    static boolean[] visited;
    static List<Edge>[] neighbors;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int videoNum = Integer.parseInt(st.nextToken());
        int queryNum = Integer.parseInt(st.nextToken());

        neighbors = new ArrayList[videoNum];
        for (int v = 0; v < videoNum; v++) { neighbors[v] = new ArrayList<>(); }
        
        for (int e = 0; e < videoNum - 1; e++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int relevance = Integer.parseInt(st.nextToken());
            neighbors[a].add(new Edge(b, relevance));
            neighbors[b].add(new Edge(a, relevance));
        }

        for (int q = 0; q < queryNum; q++) {
            st = new StringTokenizer(br.readLine());
            threshold = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken()) - 1;

            // Reset global variables for the current query
            numReachable = 0;
            visited = new boolean[videoNum];
            searchVideos(start);

            bw.write(numReachable + "\n");
        }

        br.close();
        bw.close();
    }

    /** Searches all vertices that can be reached through the current video v */
    static void searchVideos(int v) {
        visited[v] = true;
        for (Edge e : neighbors[v]) {
            /*
             * Only visit non-visited videos whose relevance
             * is greater than or equal to the current threshold
             */
            if (!visited[e.to] && e.relevance >= threshold) {
                numReachable++;
                searchVideos(e.to);
            }
        }
    }
}
