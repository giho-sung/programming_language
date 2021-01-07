import sys
sys.setrecursionlimit(10**5)

class Tree:
    def __init__(self):
        self.root = None
        self.x_dict = None
    
    def set_x_dict(self, x_dict):
        self.x_dict = x_dict


    def put_data(self, val_depth):
        if self.root == None:
            self.root = Node(val_depth)
            return
        self.root.push_node(val_depth)
        
    
    def preorder(self, array):
        self._preorder(self.root, array)
        # action
        # left
        # right
    def _preorder(self, node, array):
        if node == None:
            return
        array.append(self.x_dict[node.val])
        self._preorder(node.left, array)
        self._preorder(node.right, array)

    
    def postorder(self, array):
        self._postorder(self.root, array)
        # left
        # right
        # action
    def _postorder(self, node, array):
        if node == None:
            return
        self._postorder(node.left, array)
        self._postorder(node.right, array)
        array.append(self.x_dict[node.val])

class Node:
    def __init__(self, val_depth):
        self.left = None
        self.right = None
        self.val = val_depth[0]
        self.depth = val_depth[1]
    
    def push_node(self, val_depth):
        if self.val < val_depth[0]:
            if self.right == None:
                self.right = Node(val_depth)
                return
            self.right.push_node(val_depth)
        else:
            if self.left == None:
                self.left = Node(val_depth)
                return
            self.left.push_node(val_depth)
    

def solution(nodeinfo):
    answer = [[] for _ in range(2)]
    # dictionary for key: x, value: index + 1
    x_dict = {}
    for i in range(len(nodeinfo)):
        node = nodeinfo[i]
        x_dict[node[0]] = i + 1
    # make tree with nodeinfo
    nodeinfo.sort(key=lambda x: x[1], reverse=True)
    tree = Tree()
    for node in nodeinfo:
        tree.put_data(node)
    
    tree.set_x_dict(x_dict)
    
    tree.preorder(answer[0])
    tree.postorder(answer[1])

    return answer