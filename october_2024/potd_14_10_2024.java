// User function Template for Java
import java.util.*;

class Solution {
    public List<Integer> rearrange(List<Integer> arr) {

        ArrayList<Integer> res = new ArrayList<>(arr.size());

        for (int i = 0; i < arr.size(); i++)
            res.add(-1);

        for (int el : arr)
            if (el >= 0 && el < arr.size())
                res.set(el, el);

        return res;
    }
}