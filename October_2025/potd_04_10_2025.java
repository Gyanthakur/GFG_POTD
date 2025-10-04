import java.util.*;

class potd_04_10_2025{
    List<String> res = new ArrayList<>();

    public void dfs(String s, long target, int idx, String path, long eval, long prev) {
        if (idx == s.length()) {
            if (eval == target) res.add(path);
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (i != idx && s.charAt(idx) == '0') break; // skip leading zeros
            String curStr = s.substring(idx, i + 1);
            long cur = Long.parseLong(curStr);

            if (idx == 0) {
                dfs(s, target, i + 1, curStr, cur, cur);
            } else {
                dfs(s, target, i + 1, path + "+" + curStr, eval + cur, cur);
                dfs(s, target, i + 1, path + "-" + curStr, eval - cur, -cur);
                dfs(s, target, i + 1, path + "*" + curStr, eval - prev + prev * cur, prev * cur);
            }
        }
    }

    public List<String> addOperators(String s, int target) {
        res.clear();
        dfs(s, target, 0, "", 0, 0);
        Collections.sort(res);
        return res;
    }

    public static void main(String[] args) {
        potd_04_10_2025 sol = new potd_04_10_2025();
        String s = "125";
        int target = 7;
        System.out.println(sol.addOperators(s, target));
    }
}
