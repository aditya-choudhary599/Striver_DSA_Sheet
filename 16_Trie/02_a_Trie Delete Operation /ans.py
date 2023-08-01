# Question Link : https://www.codingninjas.com/studio/problems/trie-delete-operation_1062663?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

from os import *
from sys import *
from collections import *
from math import *

# A trie node


class TrieNode:

    def __init__(self):
        self.isEnd = False
        # children is the array which serves as index for the characters. There are 26 different characters
        # Therefore the size of the array is 26
        self.children = [None] * 26


def deleteWord(root, word):
    if len(word) == 0:
        root.isEnd = False
        return root

    idx = ord(word[0]) - ord('a')
    if root.children[idx] is not None:
        return deleteWord(root.children[idx], word[1:])
    else:
        return root
