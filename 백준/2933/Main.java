import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static Integer n, m;
	public static char board[][];
	public static Integer bars[];
	public static Integer dy[] = { -1, 0, 1, 0 };
	public static Integer dx[] = { 0, 1, 0, -1 };

	public static void main(String[] args) throws Exception {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		board = new char[n][m];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < m; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		int t = Integer.parseInt(br.readLine());
		bars = new Integer[t];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < t; i++) {
			bars[i] = Integer.parseInt(st.nextToken());
		}
		solve();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bw.write(board[i][j]);
			}
			bw.write("\n");
		}
		bw.close();
		br.close();
	}

	public static void bfs(Pair p) {
		int check[][] = new int[n][m];
		Queue<Pair> q = new LinkedList<Pair>();
		for (int i = 0; i < m; i++) {
			if (board[n - 1][i] == 'x') {
				q.add(new Pair(n - 1, i));
				check[n - 1][i] = 1;
			}
		}

		while (!q.isEmpty()) {
			Pair cur = q.poll();
			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				if (isrange(ny, nx)) {
					if (check[ny][nx] == 0 && board[ny][nx] == 'x') {
						q.add(new Pair(ny, nx));
						check[ny][nx] = 1;
					}
				}
			}
		}
		List<Pair> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'x' && check[i][j] == 0)
					list.add(new Pair(i, j));
			}
		}
		Collections.sort(list);
		List<Pair> list2 = new ArrayList<>(list);

		while (list.size() > 0) {
			List<Pair> temp = new ArrayList<>();
			boolean flag = false;
			for (Pair c : list) {
				int y = c.y + 1;
				int x = c.x;
				if (!isrange(y, x)) {
					flag = true;
					break;
				}
				if (check[y][x] == 1) {
					flag = true;
					break;
				}
				temp.add(new Pair(y, x));
			}
			if (flag)
				break;
			list = temp;
		}
		for (Pair c : list2)
			board[c.y][c.x] = '.';
		for (Pair c : list)
			board[c.y][c.x] = 'x';

	}

	public static void solve() {
		for (int i = 0; i < bars.length; i++) {
			Pair p = Throw(bars[i], i);
			if (!isrange(p.y, p.x))
				continue;
			board[p.y][p.x] = '.';
			bfs(p);

		}
	}

	public static boolean isrange(int y, int x) {
		return 0 <= y && y < n && 0 <= x && x < m;
	}

	public static Pair Throw(int h, int cnt) {
		int y = n - h;
		int x = cnt % 2 == 0 ? 0 : m - 1;
		while (isrange(y, x)) {
			if (board[y][x] == 'x')
				break;
			x += cnt % 2 == 0 ? 1 : -1;
		}
		return new Pair(y, x);
	}
}

class Pair implements Comparable<Pair> {
	public Integer y, x;

	public Pair(Integer y, Integer x) {
		this.y = y;
		this.x = x;
	}

	public Pair() {
	}

	@Override
	public int compareTo(Pair o) {
		if (this.y > o.y)
			return -1;
		return 1;
	}

}
