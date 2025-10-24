// Split Array Subsequences

class Solution {

    public boolean isPossible(int[] arr, int k) {
        // Code here
        LinkedHashMap<Integer, Integer> lm = new LinkedHashMap<>();
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        
        for(int num:arr){
            lm.put(num, lm.getOrDefault(num, 0) + 1);
        }
        
        if(lm.size()<k) return false;
        
        while(lm.size()>=k){
            Iterator<Map.Entry<Integer, Integer>> iterator = lm.entrySet().iterator();
            ArrayList<Integer> al = new ArrayList<>();
            int num = 0;
            while(iterator.hasNext()){
                Map.Entry<Integer, Integer> entry = iterator.next();
                if(num!=0 && num+1!=entry.getKey()){
                    break;
                }
                
                num = entry.getKey();
                if(entry.getValue()==1){
                    iterator.remove();
                }else{
                    lm.put(num, entry.getValue()-1);
                }
                
                al.add(num);
            }
            list.add(al);
        }
        
        if(lm.size()==0) return true;
        
        for(Map.Entry<Integer, Integer> entry:lm.entrySet()){
            int num = entry.getKey();
            for(int i=0;i<entry.getValue();i++){
                int j=0, flag = 0;
                ArrayList<Integer> al = new ArrayList<>();
                for(j=0;j<list.size();j++){
                    al = list.get(j);
                    if(num+1==al.get(0)){
                        al.addFirst(num);
                        break;
                    }
                    if(num-1==al.get(al.size()-1)){
                        al.add(num);
                        break;
                    }
                    if(num>al.get(0) && num<al.get(al.size()-1)){
                        int index = al.indexOf(num);
                        if(index+1>=k && al.size()-index>=k-1){
                            ArrayList<Integer> temp = new ArrayList<>(al.subList(index+1, al.size()));
                            ArrayList<Integer> temp1 = new ArrayList<>(al.subList(0, index));
                            list.add(temp);
                            list.add(temp1);
                            list.remove(j);
                            flag = 1;
                        }
                    }
                }
                if(flag==0){
                    if(j<list.size()){
                        list.set(j, al);
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
}
