import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Prac {
    public static void main(String args[]) throws Exception{
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int mat[][] = new int[m][1000];
        int row[] = new int[m];
        String[] strNums;
        int n=0, zero=0;

        for(int i=0;i<m;i++){
            int sum = 0;
            n = 0;
            strNums = bi.readLine().split("\\s");
            for(int j=0; j<strNums.length; j++) {
                n++;
                mat[i][j] = Integer.parseInt(strNums[j]);
                if(mat[i][j] == 0) zero++;
                sum += mat[i][j];
            }
            row[i] = sum;
            //System.out.println(row[i]);
        }
        //System.out.println();

        int col[] = new int[n];
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += mat[j][i];
            }
            col[i] = sum;
        }
        //System.out.println(n);
        if(zero >= (m*n)/2) {
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i < m && j < n && mat[i][j] == 0){
                        //System.out.println(i+" "+j+"");
                        if(row[i] <= col[j]){
                            if(row[i]%2 == 0) mat[i][j] = 2;
                            else mat[i][j] = 1;
                        }
                        else{
                            if(row[i]%3 == 0) mat[i][j] = 3;
                            else if(row[i]%3 == 2) mat[i][j] = 1;
                            else mat[i][j] = 2;
                        }
                        row[i] += mat[i][j];
                        col[j] += mat[i][j];
                        zero--;
                        //System.out.println(row[i]+" "+col[i]);
                    }
                }
                if(m*n/2 > zero) break;
                
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++)
                    System.out.print(mat[i][j]+" ");
                System.out.println();
            }

        }
        else System.out.println(-1);
    }
}
