import java.io.*;
import java.util.*;


public class s1feb2019 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("herding.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("herding.out"));
        int n = Integer.parseInt(br.readLine());
        int[] line = new int[1000000000];

        //endpoints
        int minIndex = Integer.MAX_VALUE;
        int maxIndex = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++ ) {
            int curr = Integer.parseInt(br.readLine());
            line[curr] = 1;
            if (curr > maxIndex) {
                maxIndex = curr;
            }
            if (curr < minIndex) {
                minIndex = curr;
            }
        }

        //Find max number of moves
        //Find two gaps in line to close smaller gap. Number of empty spaces left is answer
        int countFirst = 0;
        int countLast = 0;
        int firstZero = 0;
        int lastZero = 0;

        for (int i = minIndex; i < n; i++) {
            if (line[i] == 0) {
                firstZero = i;
                while (line[i] == 0) {
                    countFirst += 1;
                    i++;
                }
                break;
            }
        }
        for (int i = maxIndex; i >= 0; i--) {
            if (line[i] == 0) {
                lastZero = i;
                while (line[i] == 0) {
                    countLast += 1;
                    i--;
                }
                break;
            }
        }
        if (countFirst < countLast) {
            line[minIndex] = 0;
            line[lastZero] = 1;
        } else {
            line[maxIndex] = 0;
            line[firstZero] = 1;
        }
        int maxAns = 0;
        for (int i = minIndex; i <= maxIndex; i ++) {
            if (line[i] == 0) {
                maxAns +=1;
            }
        }

        //Find min number of moves. 'Sliding window' to find consecutive gap of n to be filled with the max number of already occupied points. 
        // Only iterate over points that are 1.
        int minZ = 0;
        int start = 0;
        for (int i = minIndex; i <= maxIndex; i++) {
            if (line[i] == 0) {
                while (line[i] == 0) {
                    i++;
                }
            } else {
                int temp = 0;
                for (int j = i; j < i + n; j++) {
                    if (line[j] == 0) {
                        temp ++;
                    }
                }
                if (temp < minZ) {
                    minZ = temp;
                    start = i;
                }
            }
        }
        int minAns = 0;
        int i = start;
        int zeroOne = 0;
        while (i < start + n) {
            if (line[i] == 0) {
                zeroOne = i;
                break;
            }
            i++;
        }
        if (zeroOne == start + n - 1) {
            minAns = 2;
        } else {
            minAns = minZ;
        }
        pw.println(minAns);
        pw.println(maxAns);
        pw.flush();
        pw.close();
        br.close();

    }
}