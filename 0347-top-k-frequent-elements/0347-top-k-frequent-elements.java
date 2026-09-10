class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> f = new HashMap<>();
        int[] ans = new int[k];
        //creating hashmap
        for (int num:nums){
            if(f.containsKey(num)){
                f.put(num,f.get(num)+1);
            }
            else{
                f.put(num,1);
            }
        }
        for(int i=0;i<k;i++){
            int max=-1,maxv=0;
            for(Map.Entry<Integer, Integer> e:f.entrySet()){
                if(e.getValue() > maxv){
                    max = e.getKey();
                    maxv = e.getValue();
                }
            }
            ans[i]=max;
            f.remove(max);
        }
        return ans;
    }
}