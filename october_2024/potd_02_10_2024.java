int n = arr.size();
        int k = 1;
        
        while (n > 1) {
            // Rotate the array clockwise by 1 (moving the last element to the front)
            int last = arr.get(n - 1);
            arr.remove(n - 1);
            arr.add(0, last);
            
            // Delete the (n - k)th element from the end (convert it to 0-based index)
            int deleteIndex = n - k;
            arr.remove(deleteIndex);
            
            // Update the length of the array and increment k
            n--;
            k++;
        }
        
        return arr.get(0); // Return the last remaining element
    }
    
    public static void main(String[] args) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        arr1.add(1);
        arr1.add(2);
        arr1.add(3);
        arr1.add(4);
        arr1.add(5);
        arr1.add(6);
        System.out.println(findLastElement(arr1));  // Output: 3

        ArrayList<Integer> arr2 = new ArrayList<>();
        arr2.add(1);
        arr2.add(2);
        arr2.add(3);
        arr2.add(4);
        System.out.println(findLastElement(arr2));  // Output: 2
