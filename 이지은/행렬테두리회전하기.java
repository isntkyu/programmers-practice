import java.util.*;

class Solution {
    public int[] solution(int r, int c, int[][] q) {
        // List<Integer> answer = new ArrayList<>();
        int[] answer = new int[q.length];
        
        int[][] matrix = new int[r][c];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = i * c + j + 1;
            }
        }
        
        for (int i = 0; i < q.length; i++) {
            int x = q[i][0] - 1;
            int y = q[i][1] - 1;
            int x2 = q[i][2] - 1;
            int y2 = q[i][3] - 1;
            
            int temp = matrix[x][y];
            int min = temp;
            
            for (int j = x; j <= x2 - 1; j++) {
                matrix[j][y] = matrix[j + 1][y];
                if (min > matrix[j][y]) min = matrix[j][y];
            }
            
            for (int j = y ; j <= y2 - 1; j++) {
                matrix[x2][j] = matrix[x2][j + 1];
                if (min > matrix[x2][j]) min = matrix[x2][j];
            }
            
            for (int j = x2; j > x; j--) {
                matrix[j][y2] = matrix[j - 1][y2];
                if (min > matrix[j][y2]) min = matrix[j][y2];
            }
            
            for (int j = y2; j >= y + 1; j--) {
                matrix[x][j] = matrix[x][j - 1];
                if (min > matrix[x][j]) min = matrix[x][j];
            }
            
            matrix[x][y + 1] = temp;
        
            
            answer[i] = min;
        }
        
        
        return answer;
    }
}