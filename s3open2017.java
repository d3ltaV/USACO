import java.io.*;
import java.util.*;

public class s3open2017 {
	static final int MAX_N = 20;

	static char[][] image = new char[MAX_N][MAX_N];
	static boolean[][] visited = new boolean[MAX_N][MAX_N];

	static int iMin, iMax, jMin, jMax;
	static void floodfill(int i, int j, char color) {
		if (i < iMin || j < jMin || i > iMax || j > jMax || visited[i][j] ||
		    image[i][j] != color) {
			return;
		}

		visited[i][j] = true;

		floodfill(i + 1, j, color);
		floodfill(i - 1, j, color);
		floodfill(i, j + 1, color);
		floodfill(i, j - 1, color);
	}

	// Check whether a given region is a PCL
	static boolean isPCL(int i1, int j1, int i2, int j2) {
		// keep track of num of regions for each color A-Z
		int[] regionCount = new int[26];

		// set bounds for floodfill
		iMin = i1;
		iMax = i2;
		jMin = j1;
		jMax = j2;

		// Count # of connected regions for each color present in bounds
		for (int i = i1; i <= i2; i++) {
			for (int j = j1; j <= j2; j++) {
				if (!visited[i][j]) {
					char currColor = image[i][j];
					regionCount[currColor - 'A']++;
					floodfill(i, j, currColor);
				}
			}
		}

		// Reset visited vector for the next call
		visited = new boolean[MAX_N][MAX_N];

		// Verify PCL conditions
		int colorCount = 0;
		boolean colorWithOneRegion = false;
		boolean colorWithMoreRegions = false;
		for (int i = 0; i < regionCount.length; i++) {
			if (regionCount[i] != 0) { colorCount++; }
			if (regionCount[i] == 1) { colorWithOneRegion = true; }
			if (regionCount[i] > 1) { colorWithMoreRegions = true; }
		}

		return (colorCount == 2 && colorWithOneRegion && colorWithMoreRegions);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("where.in"));
		int n = Integer.parseInt(read.readLine());
		for (int i = 0; i < n; i++) {
			String row = read.readLine();
			for (int j = 0; j < n; j++) { image[i][j] = row.charAt(j); }
		}
		read.close();

		List<PCL> pcls = new ArrayList<>();
		// Brute force every rectangle to find PCLs
		for (int i1 = 0; i1 < n; i1++) {
			for (int j1 = 0; j1 < n; j1++) {
				for (int i2 = 0; i2 < n; i2++) {
					for (int j2 = 0; j2 < n; j2++) {
						if (isPCL(i1, j1, i2, j2)) {
							pcls.add(new PCL(i1, j1, i2, j2));
						}
					}
				}
			}
		}

		int pclCount = 0;
		// If a PCL is inside another PCL, don't count it
		for (int i = 0; i < pcls.size(); i++) {
			boolean validPCL = true;
			for (int j = 0; j < pcls.size(); j++) {
				if (i == j) { continue; }
				if (pcls.get(i).isInside(pcls.get(j))) {
					validPCL = false;
					break;
				}
			}
			pclCount += validPCL ? 1 : 0;
		}

		PrintWriter written = new PrintWriter("where.out");
		written.println(pclCount);
		written.close();
	}

	/**
	 * PCL delimited by the top left corner (i1, j1)
	 * & bottom right corner (i2, j2)
	 */
	static class PCL {
		public int i1, j1;
		public int i2, j2;
		public PCL(int i1, int j1, int i2, int j2) {
			this.i1 = i1;
			this.j1 = j1;
			this.i2 = i2;
			this.j2 = j2;
		}

		public boolean isInside(PCL other) {
			return (i1 >= other.i1 && i2 <= other.i2 && j1 >= other.j1 &&
			        j2 <= other.j2);
		}
	}
}