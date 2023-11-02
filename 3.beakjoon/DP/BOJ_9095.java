import java.util.*;
import java.io.*;

public class BOJ_9095 {
  public static void main(String[] args) throws Exception {
   BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
   int  t = Integer.parseInt(reader.readLine());
   int[] dp =  new int[11];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 11; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

   for (int tc = 0; tc < t; tc++){
    int n = Integer.parseInt(reader.readLine());
    System.out.println(dp[n]);
   }
  }
}
