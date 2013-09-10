#!/usr/bin/env python
#coding:utf-8

ancestor = {}
color = {}
ufs = UnionFindSet
P = [(4, 6)]
def lca(root):
    """
        Lowest Common Ancestor using Tarjan with Union-Find-Set
    """
    ancestor[root.value] = root.value
    ufs.MakeSet(root.value)

    lca(root.left)
    ufs.Union(root.left.value, root.value)
    ancestor[ufs.Find(root.value)] = root.value

    lca(root.right)
    ufs.Union(root.right.value, root.value)
    ancestor[ufs.Find(root.value)] = root.value

    color[root.value] = 'black'

class Node(object):
    """docstring for Node"""
    def __init__(self, value):
        super(Node, self).__init__()
        self.left = None
        self.right = None
        self.value = value

class UnionFindSet(object):
    def __init__(self):
        super(UnionFindSet, self).__init__()
        self.parent = {}
        self.rank = {}

    def MakeSet(self, ele):
        if not ele in self.parent:
            self.parent[ele] = ele
            self.rank[ele] = 0

    def Find(self, ele):
        """
            Find Operation with path compression
        """
        if self.parent[ele] != ele:
            self.parent[ele] = self.Find(self.parent[ele])

        return self.parent[ele]

    def Union(self, x, y):
        """
            Union Operation with rank
        """
        px = self.parent[x]
        py = self.parent[y]

        if self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[px] = py
            if self.rank[px] == self.rank[py]:
                self.rank[py] += 1

def test_UnionFindSet():
    ufs = UnionFindSet()

    disjoint_set = [(1, 2), (3, 4), (2, 5), (3, 6), (7, 8)]
    for (x, y) in disjoint_set:
        ufs.MakeSet(x)
        ufs.MakeSet(y)
        ufs.Union(x, y)

    print "1, 5 is in the same set:", ufs.Find(1) == ufs.Find(5)
    print "2, 3 is not in the same set:", ufs.Find(2) == ufs.Find(3)
    print "4, 6 is in the same set:", ufs.Find(4) == ufs.Find(6)

if __name__ == '__main__':
    # make a binary tree
    #           1
    #          / \
    #         2   3
    #        / \
    #       4   5
    #          / \
    #         6   7
    root = Node(1)
    node_2 = Node(2)
    node_3 = Node(3)
    node_4 = Node(4)
    node_5 = Node(5)
    node_6 = Node(6)
    node_7 = Node(7)
    
    root.left = node_2
    root.right = node_3

    node_2.left = node_4
    node_2.right = node_5

    node_5.left = node_6
    node_5.right = node_7
