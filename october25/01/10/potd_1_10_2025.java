import java.util.ArrayList;
import java.util.Arrays;

public class potd_1_10_2025 {
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        Arrays.sort(arr);
        do {
            ArrayList<Integer> perm = new ArrayList<>(arr.length);
            for (int x : arr)
                perm.add(x);
            res.add(perm);
        } while (nextPermutation(arr));
        return res;
    }

    private static boolean nextPermutation(int[] a) {
        int n = a.length;
        int i = n - 2;
        while (i >= 0 && a[i] >= a[i + 1])
            i--;
        if (i < 0)
            return false;
        int j = n - 1;
        while (a[j] <= a[i])
            j--;
        swap(a, i, j);
        reverse(a, i + 1, n - 1);
        return true;
    }

    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void reverse(int[] a, int l, int r) {
        while (l < r)
            swap(a, l++, r--);
    }
}