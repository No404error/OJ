class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> temp=new ArrayList<>(40);
        for(int i=0;i<40;i++)
            temp.add(0);
        Arrays.sort(candidates);
        dfs(res,0,candidates,target,temp,0);
        return res;
    }
    private void dfs(List<List<Integer>> res,int index,int[] candidates,int diff,List<Integer> temp,int indexP){
        if(diff==0){
            List<Integer> resP=new ArrayList<>();
            resP.addAll(temp.subList(0,indexP));
            res.add(resP);
            return;
        }

        for(int i=index;i<candidates.length;i++){
            if(candidates[i]>diff)
                return;

            temp.set(indexP,candidates[i]);
            dfs(res,i,candidates,diff-candidates[i],temp,indexP+1);
        }

    }
}