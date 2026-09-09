class Solution {
    public String longestCommonPrefix(String[] s) {
        String pf = s[0];
        for(int i=1;i<s.length;i++){
            pf = cpf(pf,s[i]);
            if(pf.isEmpty()){
                return "";
            }
        }
        return pf;
    }
    String cpf(String a,String b){
        int minl = Math.min(a.length(),b.length()),i=0;
        while(i<minl && a.charAt(i)==b.charAt(i)){
            i++;
        }
        return a.substring(0,i);
    }
}