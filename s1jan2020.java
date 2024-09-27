//Find number Q: Elsies basket has at most Q; while Bessies basket have less than Q. Loop thorugh all Qs (max n. berries).
//Mistake: not realizing that there is a threshold/number and there is no reason to give Bessie more than that number!!

import java.io.*;
import java.util.*;

public class s1jan2020 {
    static int N, K;
    static int[] B;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("berries.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        B = new int[N];
        int max = -1;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            B[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, B[i]);
        }
        br.close();

        int res = -1;
        for (int i = 1; i <= max; i++) {
            int count = 0;
            int[] leftOver = new int[N];
            for (int j = 0; j < N; j++) {
                count += B[j] / i;
                leftOver[j] = B[j] % i;
            }

            if (count >= K) {
                // If count can account for both Bessie and Elsie, allocate K/2 * i to Bessie
                res = Math.max(res, K / 2 * i);
            } else if (count >= K / 2) {
                // Handle partial baskets using leftovers
                int berries = 0;
                berries += (count - K / 2) * i;
                Arrays.sort(leftOver);
                int ix = leftOver.length - 1;
                for (int j = count - K / 2; j < K / 2; j++) {
                    if (ix < 0) continue;
                    berries += leftOver[ix--];
                }

                res = Math.max(res, berries);
            }
        }

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("berries.out")));
        out.println(res);
        out.flush();
        out.close();
    }
}


// import java.io.*;
// import java.util.*;
// public class s1jan2020 {
//     public static void main(String[] args) throws IOException {
//         // BufferedReader br = new BufferedReader(new FileReader("berries.in"));
//         // PrintWriter pw = new PrintWriter("berries.out");
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         PrintWriter pw = new PrintWriter(System.out);
//         StringTokenizer st = new StringTokenizer(br.readLine());
//         int n = Integer.parseInt(st.nextToken());
//         int k = Integer.parseInt(st.nextToken());
//         int[] berries = new int[n];
//         StringTokenizer stb = new StringTokenizer(br.readLine());
//         for (int i = 0; i < n; i++) {
//             berries[i] = Integer.parseInt(stb.nextToken());
//         }
//         int[] bessie = new int[k];
//         int[] elsie = new int[k];
//         int counter1 = 0;
//         int counter2 = 0;
//         for (int i = (n - 2 * k); i < (n - k); i++) {
//             bessie[counter1] = i;
//             counter1++;
//         }
//         for (int i = n - k; i < n; i++) {
//             elsie[counter2] = i;
//             counter2++;
//         }
//         int counter = 0;
//         while (counter < k) {
//             int a = (int) elsie[counter] / 2;
//             int b = (int) Math.ceil(elsie[counter] / 2);
//             if (a > bessie[0]) {
//                 bessie[0] = a;
//                 elsie[counter] = b;
//                 Arrays.sort(bessie);
//                 Arrays.sort(elsie);
//                 if (bessie[k - 1] > elsie[0]) {
//                     int temp = elsie[0];
//                     elsie[0] = bessie[k - 1];
//                     bessie[k - 1] = temp;
//                     Arrays.sort(elsie);
//                 }
//             }
//             counter++;
//         }
//         // for (int i = 0; i < n; i++) {
            
//         // }
//         int sum = 0;
//         for (int i = 0; i < k; i++) {
//             sum += bessie[i];
//         }
//         pw.println(sum);
//         pw.flush();
//         pw.close();
//         br.close();

//     }
// }
