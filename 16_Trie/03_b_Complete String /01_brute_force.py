# Question Link : https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

from typing import List, Dict


def check(s: str, mp: Dict[str, bool]) -> bool:
    pre = ""
    n = len(s)
    for i in range(n):
        pre += s[i]
        if pre not in mp:
            return False
    return True


def completeString(n: int, arr: List[str]) -> str:
    ans = ""

    mp = {}
    for s in arr:
        mp[s] = True

    for s in arr:
        if check(s, mp):
            if len(ans) < len(s):
                ans = s
            elif len(ans) == len(s):
                ans = min(ans, s)

    if not ans:
        return "None"
    return ans
