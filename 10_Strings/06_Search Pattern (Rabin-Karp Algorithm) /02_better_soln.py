# Question Link : https://www.codingninjas.com/studio/problems/stringmatch-rabincarp_1115738?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


from typing import List


def stringMatch(text: str, pattern: str) -> List[int]:
    target = hash(pattern)
    m = len(text)
    n = len(pattern)
    ans = []
    for i in range(0, m-n+1, 1):
        if target == hash(text[i:i+n:1]):
            ans.append(i+1)
    return ans
