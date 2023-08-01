# Question Link : https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1

class Trie_Node:
    def __init__(self, ch):
        self.ch = ch
        self.children = {}
        self.prefix_cnt = 0
        self.is_end = 0


class Trie:
    def __init__(self):
        self.root = Trie_Node('#')

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Trie_Node(char)
            node = node.children[char]
            node.prefix_cnt += 1
        node.is_end += 1

    def countWordsEqualTo(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return 0
            node = node.children[char]
        return node.is_end

    def countWordsStartingWith(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return 0
            node = node.children[char]
        return node.prefix_cnt

    def erase(self, word):
        node = self.root
        # (node, level) tuple to keep track of the node and its level in the Trie
        stack = [(node, 0)]
        for char in word:
            if char not in node.children:
                return
            node = node.children[char]
            stack.append((node, stack[-1][1] + 1))

        if node.is_end > 0:
            node.is_end -= 1

        while stack:
            node, level = stack.pop()
            if level > 0:
                node.prefix_cnt -= 1
                if node.prefix_cnt == 0:
                    parent, _ = stack[-1] if stack else (None, None)
                    if parent:
                        del parent.children[node.ch]
                    else:
                        node.is_end = 0
                        node.prefix_cnt = 0
