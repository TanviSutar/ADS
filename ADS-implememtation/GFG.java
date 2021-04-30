
import java.io.*;
import java.util.*; 


class GFG{
    public static void main(String args[]) throws IOException { 
        int m = 3, n = 3, k = 4;
        long cnt = 0;
        long arr[][] = {{2,2,3},
                        {3,4,5},
                        {4,5,5}};
        if(m == 1 && n == 1 && arr[0][0] >= k){
            System.out.println(1);
            //continue;
        }
        long mat[][] = new long[m][n];
        mat[0][0] = arr[0][0];
        if(mat[0][0] >= k) cnt++;
        for(int i=1;i<m;i++){
            mat[i][0] = mat[i-1][0] + arr[i][0];
            if(arr[i][0] >= k) cnt++;
        }
        for(int i=1;i<n;i++){
            mat[0][i] = mat[0][i-1] + arr[0][i];
            if(arr[0][i] >= k) cnt++;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j] = arr[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
                if(arr[i][j] >= k) cnt++;
            }
        }
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }*/
        int mem[] = new int[m+1];
        Arrays.fill(mem,n-1);

        for(int i=1;i<m;i++){
            for(int j=1;j<=i;j++){
                cnt += bSearch(mat,mem,m,n,i,j,mem[j+1],j+1,k);
            }
        }

        System.out.println(cnt);
    } 
    public static long bSearch(long mat[][],int mem[],int m,int n,int row,int low,int high,int s,int k){
        int ans = high+1,mid=0;
        long tmp;
	    try{
    	    while(low <= high){
    	        mid = (low+high)/2;
                tmp = (row>=s)?mat[row-s][mid]:0;
                //System.out.println(tmp+" mat"+(row-s)+mid);
                tmp += (mid>=s)?mat[row][mid-s]:0;
                //System.out.println(tmp+" mat"+row+(mid-s));
                tmp -= (row>=s && mid>=s)?mat[row-s][mid-s]:0;
                //System.out.println(tmp+" mat"+(row-s)+(mid-s));
                tmp = (mat[row][mid]-tmp)/(s*s);
                //System.out.println(tmp);
    	        if(tmp >= k){
                    //System.out.println(tmp+" "+row+" "+mid);
    	            ans = mid;
    	            high = mid-1;
    	        }
                else low = mid+1;
                //System.out.println(ans);
    	    }
	    }catch(Exception e){
	        System.out.println("Error");
        }
        tmp = (mem[s]-ans+1)*(m-row);
        //System.out.println("("+mem[s]+"-"+ans+"+1"+")*("+m+"-"+row+")");
        mem[s] = ans-1; 
        //System.out.println(tmp);
	    return tmp;
	}
} 

/*
3 3 4

2 2 3
3 4 5
4 5 5
*/