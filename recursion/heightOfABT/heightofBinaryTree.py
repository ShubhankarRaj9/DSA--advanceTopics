class BT:
    def __init__(self,data):
        self.data = data
        self.left = left
        self.right = right

class BinaryTree:
    def height( self, root) -> int :
        if root is None :
            return 0
        left = self.height(root.left)
        right = self.height(root.right)
        return max(left,right) + 1

if __name__ == "__main__":
    tree = BinaryTree()

    root = BT(1)
    root.left = BT(2)
    root.right = BT(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    # print 
    res = tree.height(root)
    print(res)
