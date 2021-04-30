/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;



class Practice{
	public static void main(String []args){
		System.out.println(func("Program"));
	}
	static String func(String s){
		StringBuilder str = new StringBuilder(s);
		int n = str.length();
		//str.toLowerCase();
		for(int i=0;i<n;i++){
			if(str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u' || str.charAt(i) == 'A' || str.charAt(i) == 'E' || str.charAt(i) == 'I' || str.charAt(i) == 'O' || str.charAt(i) == 'U')
			{
				int res = i*5;
				if(res%2 == 0) res = res/2;
				else res = res/2+1;
				int outnum = res*res;
				int sum = 100000;
				while(true){
					sum = 0;
					while(outnum > 0){
						sum += outnum%10;
						outnum = outnum/10;
					}
					if(sum > 9){
						outnum = sum;
					}
					else break;
				}
				//System.out.println(sum+" "+str.charAt(i));
				str.setCharAt(i, Character.forDigit(sum,10));
			}
		}
		return str.toString();
	}
}