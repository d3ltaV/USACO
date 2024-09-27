import java.io.*;
import java.util.*;
public class s3dec2018 {
    static int[][] haybales;
    static int n;
    static int k;
    static int count;
    static ArrayList<ArrayList<Integer>> temp = new ArrayList<>();
    static int[][] previous;
    static boolean[][] visited;
    static boolean run = true;
    static int[][] changed;
    static int[][] copy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("mooyomooyo.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("mooyomooyo.out")));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        haybales = new int[n][10];
        visited = new boolean[n][10];
        previous = new int[n][10];
        copy = new int[n][10];
        changed = new int[n][10];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < 10; j++) {

                haybales[i][j] = Character.getNumericValue(s.charAt(j));
                previous[i][j] = -1;
            }
        }

        for (int i = 0; i < 10; i++) {
            ArrayList<Integer> temporary = new ArrayList<>();
            temp.add(temporary);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                copy[i][j] = haybales[i][j];
                changed[i][j] = -1;
            }
        }

        while (run) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    changed[i][j] = -1;
                    visited[i][j] = false;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    int region = floodfirst(i, j, haybales[i][j]);
                    changed[i][j] = region;
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < 10; y++) {
                            visited[x][y] = false;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    haybales[i][j] = changed[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    if (haybales[i][j] >= k || haybales[i][j] == 0) {
                        haybales[i][j] = 0;
                    } else {
                        haybales[i][j] = copy[i][j];
                    }
                }
            }

            for (int j = 0; j < 10; j++) {
                for (int i = 0; i < n; i++) {
                    if (haybales[i][j] != 0) {
                        temp.get(j).add(haybales[i][j]);
                    }
                }
            }
            for (int j = 0; j < 10; j++) {
                int tempSize = temp.get(j).size(); //returns 2
                int zeros = n - tempSize;
                int counter = 0;
                for (int i = 0; i < n; i++) {
                    if (i < zeros) {
                        haybales[i][j] = 0;
                    } else {
                        haybales[i][j] = temp.get(j).get(counter);
                        counter += 1;
                    }
                }
            }


            int[][] arr = new int[n][10];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    if (haybales[i][j] != previous[i][j]) {
                        run = true;
                        break;
                    } else {
                        run = false;
                    }
                }
            }

            if (run) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 10; j++) {
                        previous[i][j] = haybales[i][j];
                        copy[i][j] = haybales[i][j];
                    }
                }
                for (int i = 0; i < temp.size(); i++) {
                    temp.set(i, new ArrayList<>());
                }
            } else {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 10; j++) {
                        pw.print(haybales[i][j]);
                    }
                    pw.println();
                }
            }
        }
        pw.flush();
        br.close();
        pw.close();

    }

    static int floodfirst(int row, int col, int target) {
        if (target == 0 || row < 0 || col < 0 || row >= n || col >= 10 || haybales[row][col] != target || visited[row][col]) {
            return 0;
        }
        visited[row][col] = true;
        int count = 1;
        count += floodfirst(row + 1, col, target);
        count += floodfirst(row - 1, col, target);
        count += floodfirst(row, col - 1, target);
        count += floodfirst(row, col + 1, target);
        return count;
    }
}
// }
// import java.io.*;
// import java.util.*;

// public class Main {
//     static int[][] grid;
//     static int n, k;
//     static final int[] dx = {-1, 1, 0, 0};
//     static final int[] dy = {0, 0, -1, 1};
    
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new FileReader("mooyomooyo.in"));
//         PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("mooyomooyo.out")));
//         StringTokenizer st = new StringTokenizer(br.readLine());
//         n = Integer.parseInt(st.nextToken());
//         k = Integer.parseInt(st.nextToken());
//         grid = new int[n][10];
        
//         for (int i = 0; i < n; i++) {
//             String line = br.readLine();
//             for (int j = 0; j < 10; j++) {
//                 grid[i][j] = line.charAt(j) - '0';
//             }
//         }
        
//         boolean changed;
//         do {
//             changed = false;
//             boolean[][] visited = new boolean[n][10];
            
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < 10; j++) {
//                     if (grid[i][j] > 0 && !visited[i][j]) {
//                         List<int[]> region = new ArrayList<>();
//                         int size = floodFill(i, j, grid[i][j], visited, region);
                        
//                         if (size >= k) {
//                             for (int[] cell : region) {
//                                 grid[cell[0]][cell[1]] = 0;
//                             }
//                             changed = true;
//                         }
//                     }
//                 }
//             }
            
//             applyGravity();
//         } while (changed);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < 10; j++) {
//                 pw.print(grid[i][j]);
//             }
//             pw.println();
//         }
        
//         br.close();
//         pw.close();
//     }
    
//     static int floodFill(int x, int y, int value, boolean[][] visited, List<int[]> region) {
//         int size = 0;
//         Queue<int[]> queue = new LinkedList<>();
//         queue.add(new int[]{x, y});
//         visited[x][y] = true;
        
//         while (!queue.isEmpty()) {
//             int[] cell = queue.poll();
//             int cx = cell[0], cy = cell[1];
//             region.add(cell);
//             size++;
            
//             for (int i = 0; i < 4; i++) {
//                 int nx = cx + dx[i];
//                 int ny = cy + dy[i];
                
//                 if (nx >= 0 && ny >= 0 && nx < n && ny < 10 && !visited[nx][ny] && grid[nx][ny] == value) {
//                     queue.add(new int[]{nx, ny});
//                     visited[nx][ny] = true;
//                 }
//             }
//         }
        
//         return size;
//     }
    
//     static void applyGravity() {
//         for (int j = 0; j < 10; j++) {
//             int writeIdx = n - 1;
//             for (int i = n - 1; i >= 0; i--) {
//                 if (grid[i][j] != 0) {
//                     grid[writeIdx--][j] = grid[i][j];
//                 }
//             }
//             while (writeIdx >= 0) {
//                 grid[writeIdx--][j] = 0;
//             }
//         }
//     }
// }
