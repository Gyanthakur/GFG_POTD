public int maxDistance(int[] arr) {
        HashMap<Integer, Integer> mpp = new HashMap<>();
        int res = 0;
        for(int i = 0; i < arr.length; i++) {
            if(!mpp.containsKey(arr[i])) {
                mpp.put(arr[i], i);
            } else {
                res = Math.max(res, i - mpp.get(arr[i]));
            }
        }
        return res;
    }
