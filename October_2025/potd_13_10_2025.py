/* Given the root of a binary tree with integer values. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included. */

class potd_13_10_2025:
    def getMaxSum(self, root):
        def solve(node):
            if not node:
                return (0, 0)  # (include, exclude)

            left_include, left_exclude = solve(node.left)
            right_include, right_exclude = solve(node.right)

            # If we include this node
            include = node.data + left_exclude + right_exclude

            # If we exclude this node
            exclude = max(left_include, left_exclude) + max(right_include, right_exclude)

            return (include, exclude)

        include, exclude = solve(root)
        return max(include, exclude)
