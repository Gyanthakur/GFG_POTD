class Solution:
    def constructTree(self, pre, post):
        post_index = {val: i for i, val in enumerate(post)}
        self.pre_idx = 0
        
        def build(start, end):
            if self.pre_idx >= len(pre) or start > end:
                return None
                
            root = Node(pre[self.pre_idx])
            self.pre_idx += 1
            
            if start == end or self.pre_idx >= len(pre):
                return root
                
            next_val = pre[self.pre_idx]
            idx = post_index[next_val]
            
            if idx <= end:
                root.left = build(start, idx)
                root.right = build(idx + 1, end - 1)
            
            return root
        
        return build(0, len(post) - 1)