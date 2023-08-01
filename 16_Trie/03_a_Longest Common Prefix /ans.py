def longestCommonPrefix(arr, n) -> str:
    # Write your code here
    # Return a string
    if len(arr) == 1:
        return arr[0]

    rcall = longestCommonPrefix(arr[1:], n)
    ans = ""

    i = 0
    j = 0
    while i < len(arr[0]) and j < len(rcall):
        if rcall[j] == arr[0][i]:
            ans += rcall[j]
            j += 1
            i += 1
        else:
            return ans

    return ans
