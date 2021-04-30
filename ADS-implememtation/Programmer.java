//User function Template for Java
// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 

class Solution 
{ 
    int virusInfection(String s, int k) 
    { 
        // code here
        int n = s.length();
        int cnt = 0;
        int last = -1;
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '0') continue;
            if(last >= n) break;
            cnt++;
            if(last == -1){
                if(i-k <= 0) cnt += i;
                else cnt += k;
                if(i+k <= n) cnt += k;
                else cnt += n-i;
                last = i+k;
                continue;
            }
            if(last < i){
                cnt += i-last;
            }
            else{
                cnt += (i+k)-last;
            }
            last = i+k;
        }
        return cnt;
    }
} 


class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String S = read.readLine().trim();
            int K = Integer.parseInt(read.readLine().trim());
            
            Solution ob = new Solution();
            int ans = ob.virusInfection(S, K); 
            System.out.println(ans);
        }
    } 
} // } Driver Code Ends
