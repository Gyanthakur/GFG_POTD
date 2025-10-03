class Solution {
    class Node{
        ArrayList<Character>[] map;
        
        Node(){
            this.map = (ArrayList<Character>[]) new ArrayList[10];
            int j = 0;
            for(int i = 0; i < 10; i++){
                map[i] = new ArrayList<>();
                if(i > 1){
                    int inc = 4;
                    if(i != 7 && i != 9) inc = 3;
                    for(int k = j; k < j+inc; k++){
                        char ch = (char)(k+'a');
                        map[i].add(ch);
                    }
                    j = j+inc;
                }
            }
        }
    }
    Node node = new Node();
    public ArrayList<String> possibleWords(int[] arr) {
        // code here
        int n = arr.length;
        
        ArrayList<String> list = backTrack(new ArrayList<String>(),node.map,arr,n-1);
        
        return list;
    }
    private ArrayList<String> backTrack(ArrayList<String> list, ArrayList<Character>[] map, int[] arr, int idx){
       if(idx < 0) return list;
       
       ArrayList<Character> list2 = map[arr[idx]];
       if(list2.size() == 0) return backTrack(list,map,arr,idx-1);
       
       ArrayList<String> list3 = new ArrayList<>();
       for(int i = 0; i < list2.size(); i++){
           char ch = list2.get(i);
           if(list.size() == 0) list3.add(ch+"");
           else
           for(int j = 0; j < list.size(); j++){
               list3.add(ch+""+list.get(j));
           }
           
       }
       
       return backTrack(list3,map,arr,idx-1);
        
    }
}