# Question Link : https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode:
    def __init__(self):
        self.ls = [None] * 26
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def helper_insert(self, root: TrieNode, word: str) -> None:
        if len(word) == 0:
            root.is_end = True
            return

        index = ord(word[0]) - ord('a')
        if root.ls[index] is None:
            root.ls[index] = TrieNode()

        self.helper_insert(root.ls[index], word[1:])

    def insert(self, word: str) -> None:
        self.helper_insert(self.root, word)

    def helper_search(self, root: TrieNode, word: str) -> bool:
        if len(word) == 0:
            return root.is_end

        index = ord(word[0]) - ord('a')
        if root.ls[index] is None:
            return False

        return self.helper_search(root.ls[index], word[1:])

    def search(self, word: str) -> bool:
        return self.helper_search(self.root, word)

    def helper_startsWith(self, root: TrieNode, prefix: str) -> bool:
        if len(prefix) == 0:
            return True

        index = ord(prefix[0])-ord('a')
        if root.ls[index] is None:
            return False

        return self.helper_startsWith(root.ls[index], prefix[1:])

    def startsWith(self, prefix: str) -> bool:
        return self.helper_startsWith(self.root, prefix)

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
