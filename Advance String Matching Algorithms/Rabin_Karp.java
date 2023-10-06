public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n-- > 0){
            String s = sc.next();
            String pattern = sc.next();

            RabinKarp(s, pattern);
        }
    }

   private static void RabinKarp(String s, String pattern){
       long mod = 1000_000_007;
       long pow = 1;
       long hashValue = 0;
       int prime = 31;

       for (int i = 0; i < pattern.length(); i++) {
           char ch = pattern.charAt(i);

           hashValue = (hashValue + ((ch-'a'+1)*pow) % mod) % mod;
           hashValue = (hashValue + mod) % mod;
           pow = (pow * prime) % mod;
       }

       long[] dp = new long[s.length()];
       long[] power = new long[s.length()];

       dp[0] = s.charAt(0)-'a'+1;
       power[0] = 1;
       pow = prime;

       for (int i = 1; i < s.length(); i++) {
           char ch = s.charAt(i);
           dp[i] = (dp[i-1] + ((ch-'a'+1) * pow) % mod) % mod;
           power[i] = pow;
           pow = (pow * prime) % mod;
       }

       ArrayList<Integer> res = new ArrayList<>();


       for(int ei = pattern.length()-1, si = 0; ei<power.length; ei++, si++){
           long hv = dp[ei];
           if(si > 0){
               hv = (dp[ei] - dp[si-1] + mod) % mod;
           }
           if(hv == hashValue*power[si] % mod){
               res.add(si+1);
           }
       }

       if(res.size()==0){
           System.out.println("Not Found");
       }
       else{
           System.out.println(res.size());
           for(int i : res){
               System.out.print(i+" ");
           }
           System.out.println();
       }
   }
}
