import java.util.ArrayList;
    
class potd_6_10_2025 {
    static int[] dx = {2, 1, -1, -2, -2, -1, 1, 2};
    static int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};


    static boolean isSafe(int x, int y, int n, ArrayList<ArrayList<Integer>> board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board.get(x).get(y) == -1);
    }

    static boolean knightTourUtil(int x, int y, int step, int n, ArrayList<ArrayList<Integer>> board) {
        if (step == n * n) {
            return true; 
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isSafe(nx, ny, n, board)) {
                board.get(nx).set(ny, step);
                if (knightTourUtil(nx, ny, step + 1, n, board)) {
                    return true;
                }
                board.get(nx).set(ny, -1);
            }
        }

        return false;
    }


    public static ArrayList<ArrayList<Integer>> knightTour(int n) {
        ArrayList<ArrayList<Integer>> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(-1);
            }
            board.add(row);
        }


        board.get(0).set(0, 0);

        if (knightTourUtil(0, 0, 1, n, board)) {
            return board;
        } else {

            return new ArrayList<>();
        }
    }
}
