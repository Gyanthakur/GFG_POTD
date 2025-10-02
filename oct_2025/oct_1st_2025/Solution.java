import java.util.*;
class Solution {
    static void backtrack(ArrayList<Integer> nums,ArrayList<ArrayList<Integer>> arr, ArrayList<Integer> list){
        if(nums.size()==0){
            arr.add(new ArrayList<>(list));
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums.get(i) == nums.get(i-1)) continue;
            int val=nums.get(i);
            nums.remove(i);
            list.add(val);
            backtrack(nums,arr,list);
            list.remove(list.size()-1);
            nums.add(i,val);
        }
    }
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] nums) {
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        ArrayList<Integer> list=new ArrayList<>();
        for(int i=0;i<nums.length;i++)list.add(nums[i]);
        Collections.sort(list);
        backtrack(list,arr,new ArrayList<>());
        return arr;
    }
};