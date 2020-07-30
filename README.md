# Leetcode
source code of mine

# USEFUL STL C++

## Vector：
### Initial:
Vector\<type\> a;<br>
vector\<int\> number = {10, 20, 30};<br>

### Useful Function:
a.push_back()：add element<br>
a.pop_back(): remove the last element<br>
a.size(): vector長度<br>
a.begin(): iliterator 指標指到第一個元素<br>
a.end(): illiterator 指標指到最後一個元素<br>
a.front(): 回傳第一個元素<br>
a.empty(): 是否回空直<br>
a.swap(b): a, b array對調<br>
a.insert(it, num): 插入值<br>
a.erase(it.begin() + i): 刪掉第幾個元素<br>
sort(tmp.begin(), tmp.end());<br>
greater\<int\>() / less\<int\>()<br>
 
## Queue:
### Initial:
queue\<type\> myqueue;<br>

### Useful Function:
a.back(): 回傳最後一個element<br>
a.front(): 回傳第一個element<br>
a.push(): 放到queue的最後<br>
a.pop(): 拿出第一個element<br>
a.empty(): 是否回空直<br>
a.size()<br>

## priority Queue:
`functions跟Queue一樣，差別差再越前面的一定越大`<br>
priority_queue< int,vector\<int\>,greater\<int\>()\>：這樣宣告則是越小的越前面<br>
a.top(): 回傳最前面的element但不取出<br>

 
## Stack
### Initial:
stack\<type\> mystack;<br>

### Useful Function:
a.top(): 回傳最上面的element但不取出<br>
a.push(): 放到stack最上面<br>
a.pop(): 移除最上面的element<br>
a.size()<br>
a.empty()<br>

## Set
### Initial:
set\<type\> myset -> `以紅黑樹implement，裡面的數都是有序的`<br>

### Useful Function:
a.insert(a): 把a放進集合<br>
a.erase(a): 把a移出<br>
a.count(a): 看a有沒有在裡面<br>

## Unordered Set
### Initial:
unordered_set\<type\> myset -> `使用hash table實踐，search速度幾乎是O(1)，但空間利用大`<br>

### Useful Function:
a.insert(a): 把a放進集合<br>
a.erase(a): 把a移出<br>
a.count(a): 看a有沒有在裡面<br>

## Map
### Initial:
map\<type1, type2\> mymap

### Useful Function:
a\[index\]: 得到對應的值, EX: my_map['a'] = b -> assign<br>
a.insert(pair<type1, type2>(value1, value2)) : 塞入一個pair<br>
a.count(a): 看a有沒有在裡面<br>
a..clear(): 刪除map整個element<br>
a.erase(key / it): 刪除鍵值對

## Unordered map
### Initial:
unordered_map\<type\> mymap -> `使用hash table實踐，search速度幾乎是O(1)，但空間利用大`<br>

### Useful Function:
a[idx]: 得到對應的值, EX: my_map['a'] = b -> assign<br>
a.insert(pair<type1, type2>(value1, value2)) : 塞入一個pair<br>
a.count(b): 看b有沒有在裡面<br>
a.clear(): 刪除map整個element<br>
a.erase(key / it): 刪除鍵值對<br>

## List:
### Initial:
list <Type> listT; <br>
list <Type*> listTP; <br>

### Useful Function:
listT.push_back (b);	// 將 b 複製丟到 listT 後面 <br>
listT.push_front (f)	// 將 f 複製丟到 listT 前面 <br>
mylist.push_front (200) // Insert element at beginning <br>
mylist.pop_front(); // Delete first element <br>
mylist.push_back(myint); // Add element at the end <br>
mylist.pop_back(); // Delete last element <br>
mylist.insert(it,10); // 在itor前面insert 10， itor指的目標不會變 <br>
mylist.erase(it1); // delete itor所指的值 <br>
first.swap(second); // first 跟 second 互換 <br>
mylist1.splice (it, mylist2) // mylist2拼接到mylist1 <br>
```cpp
// set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                          
  mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
```


# Algorithm
## 排列組合類似題目：使用遞迴算出每個結果：
起始點：get_sequence(res, {}, nums);<br>
函數：<br>
```cpp
void get_sequence(vector<vector<int>> &res, vector<int> sub_array, vector<int> nums)
    {
        if(nums.empty())
        {
            res.push_back(sub_array); // 最終的結果放到res裡面
            return;
        }
        else
        {
            
            for(int i = 0; i < nums.size(); i++)
            {
                vector<int> tmp = sub_array;
                vector<int> tmp2 = nums;
                tmp.push_back(nums[i]);
                tmp2.erase(tmp2.begin() + i);
                get_sequence(res, tmp, tmp2); // 遞迴算出每個結果
            }
        }
    }
```

## 重複排列演算法(8! / 3!5!)
m 為大值，n為小值<br>
res需要使用long long int 以防overflow<br>
(8!) / (3!5!) => (8\*7\*6) / (1\*2\*3)，所以loop只需要算小值的次數就好<br>
```cpp
    int permut_wo_repeat(int m, int n){
         
        if(m == 0 || n == 0)
            return 1;
        
        long long res = 1;
        for(int i = 1; i <= n; i++)
        {
            res *= m - i + 1;
            res /= i;
        }    
        return (int)res;
    }
```

## Combination列出所有可能(candidates裡面 所有組成X數字的組合)
```cpp
void find_prob(vector<vector<int>>& res,  vector<int>& tmp, vector<int>& candidates, int target){  
          
        if(target == 0) // 表示combination是valid的  
        {  
            res.push_back(tmp);// 放數組到set裡  
            return;  
        }  
          
          
        for(auto i = 0; i < candidates.size() && target > 0; i++)   
        // 每次用loop找candidates裡面的數字，如果 <= target表是這個數字可以當作target的combination  
        {  
            if(candidates[i] <= target)  
            {  
                vector<int> tmp2 = tmp; // 用來存原本還沒放入這數字的array  
                tmp.push_back(candidates[i]); // 把新的數字放進去  
                find_prob(res,  tmp, candidates, target - candidates[i]); // 放入新數字之後再找下一個combination element => target - candidates[i]  
                tmp = tmp2; // 找完之後要把原本array放回來再找下一個element，EX: 2,"2" 找完 要找 2,"3".....  
            }  
        }  
          
    } 
```

## Binary Search 應用
```cpp
int find_lowbound(vector<int>& nums, int target){ // 找出第一個大於或等於target的元素
        
        int left = 0, right = nums.size() - 1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left; 
    }
```


## BFS Search Algorithm: 需要有一個Queue存input近來的數字順序
```cpp
void BFS_find(vector<vector<int>> &res, queue<TreeNode*> &q)  
{  
          
        if(q.front() == nullptr) // 如果pointer是空值，return  
            return;  
          
        while(!q.empty()) // BFS algorithm  
        {  
            vector<int> tmp;  
            int level_num = q.size(); // 先把同level的node個數存起來 ex: level 2有9個數  
              
            for(int i = 0; i < level_num; i++)   
            // iterate 同level的每個數，每次for loop會跑完同一個level的所有數字  
            {  
                cout << q.front()->val << endl;  // 把同level數字push到tmp  
              
                if(q.front()->left != nullptr) // 如果有左右節點，放到queue後面當作下一個level  
                    q.push(q.front()->left);  
                if(q.front()->right != nullptr)      
                    q.push(q.front()->right);  
                  
                q.pop(); // 把已push的node pop out  
                  
            }  
        }  
    }  
```

## Transpose Matrix Algorithm(NxN)
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]); // 做transpose 只需要loop上對角線或是下對角線互換
        }
        
        
    }
};
```
## 需要判斷是否可以到終點(用暴力法判斷結果會超時)，這時可以使用由結果往前推的概念(55. Jump Game 是其中一個應用)
1. 由終點往前找看看哪一點是成功可以跳到終點的點，把它當作"上一個成功點"，再由上一個成功點再往前推。<br>
2. 如果目前的點的數值 + 點的位置 >= 上一個成功點，表示目前的點一定可以跳到上一個成功點，到達上一個成功點就表示可以跳到終點。<br>
3. 最後再看看上一個成功點會不會等於最一開始的點(i == 0)，如果是表示此點一定可以到達終點<br>
```cpp
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        
        int last_suc_pt = nums.size() - 1;
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(i + nums[i] >= last_suc_pt)
                last_suc_pt = i;
        }
        
        return (last_suc_pt == 0) ? true : false;
    }
};
```
## List All Subsets (refer to 78. Subsets) 
```cpp
// 需要列出所有可能，使用recursion 
// 第i 個數的subset只需要從i+1開始找就好了(避免重複)
// EX: {1,2,3} => 1會找到{1,2} {1,3} 如果2也去找1會變成{2,1} =====> 和{1,2}重複了
class Solution {
public:
    
    void find_subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& subseq, int index){ 
    // 找出所有subset
        
        for(int i = index; i < nums.size(); i++) // 從現有的index開始找，每找到一個數就把他加到res裡面
        {
            // EX: index = 0 時會從 {1, 2, 3} loop去找
            vector<int> tmp = subseq; // 把目前sub_seq存到tmp裡面避免目前的sub_seq被蓋掉
            
            tmp.push_back(nums[i]); // 把1加進去 
            res.push_back(tmp); // {1} 也算是subset
            find_subsets(nums, res, tmp, i + 1); // 1找過了，之後從1後面開始找{2,3}
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        res.push_back({}); // 空集合也算subset
        vector<int> start = {};
        
        find_subsets(nums, res, start, 0); // start 是空的array，從index 0開始找
        return res;
        
    }
};
```
## Traversal in Binary Tree以及Algorithms:
Tree的找法分成三種: (1) Inorder Traversal (2) Preorder Traversal (3) Postorder Traversal (4) Level-Order Traversal<br>
### Inorder Traversal: 左->中->右
### Preorder Traversal: 中->左->右
### Postorder Traversal: 左->右->中

![image](https://github.com/t51113030/Leetcode/blob/master/pic/Tree.jpg) <br>

### Inorder + Preorder array 或 Inorder + Postorder array 可以決定一棵樹的構造，參考以下程式碼: <br>
#### 106. Construct Binary Tree from Inorder and Postorder Traversal<br>
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* buildTree(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright){
        
        if(ileft > iright || pleft > pright) return nullptr;
        
        int i;
        for(i = ileft; i <= iright; i++)
            if(postorder[pright] == inorder[i]) break; // post 是最右邊為根節點，所以從右邊開始找
        
        TreeNode* node = new TreeNode(postorder[pright]);
        node->right = buildTree(inorder, i + 1, iright, postorder, pright - (iright - i) , pright - 1); // post 是左右中，所以中找完了就下一個就是找右邊subtree
        node->left = buildTree(inorder, ileft, i - 1, postorder, pleft, pright - (iright - i) - 1); // 右邊之後才是找左邊
        // 最難的是subtree 的左右邊界怎麼訂，一定要看清楚
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        TreeNode* tree = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        return tree;
    }
};
```
#### 105. Construct Binary Tree from Preorder and Inorder Traversal<br>
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* tree = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        
        return tree;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright){
        
        if(pleft > pright || ileft > iright)
            return nullptr;
        
        int bound;
        for(int i = ileft; i <= iright; i++)
        {
            if(preorder[pleft] == inorder[i]) // preoreder 是最左邊為根節點，所以從左邊開始找
            {
                bound = i;
                break;
            }
        }    
        
        TreeNode* node = new TreeNode(preorder[pleft]);
        node->left = buildTree(preorder, inorder, pleft + 1, pleft + bound - ileft, ileft, bound - 1); // pre 是中左右，所以中找完了就下一個就是找left subtree
        node->right = buildTree(preorder, inorder, pleft + bound - ileft + 1, pright, bound + 1, iright); //然後才是找right subtree
        
        return node;
        
    }
};
```
