        left = 0
        zeroes = 0
        max_len = 0

        for right in range(len(arr)):
            if arr[right] == 0:
                zeroes += 1

            while zeroes > k:
                if arr[left] == 0:
                    zeroes -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len