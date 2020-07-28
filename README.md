# Leetcode
source code of mine

# USEFUL STL C++

## Vector：
### initial:
Vector<type> a()
vector<int> number = {10, 20, 30};

### Useful Function:
push_back()：add element
pop_back(): remove the last element
size()
begin(): iliterator 指標指到第一個元素
end(): illiterator 指標指到最後一個元素
front(): 回傳第一個元素
empty(): 是否回空直
a.swap(b): a, b array對調
insert(it, num): 插入值
a.erase(it.begin() + i): 刪掉第幾個元素
sort(tmp.begin(), tmp.end());

## Queue:
### initial:
queue<type> myqueue;

### Useful Function:
back(): 回傳最後一個element
front(): 回傳第一個element
push(): 放到queue的最後
pop(): 拿出第一個element
empty(): 是否回空直
size()

## priority Queue:
functions跟Queue一樣，差別差再越前面的一定越大
priority_queue< int,vector<int>,greater<int> >：這樣宣告則是越小的越前面
top(): 回傳最前面的element但不取出

 
## Stack
### initial:
stack<type> mystack;

### Useful Function:
top(): 回傳最上面的element但不取出
push(): 放到stack最上面
pop(): 移除最上面的element
size()
empty()

## Set
### initial:
set<type> myset -> 以紅黑樹implement，裡面的數都是有序的

### Useful Function:
insert(a): 把a放進集合
erase(a): 把a移出
count(a): 看a有沒有在裡面

## Unordered Set
### initial:
unordered_set<type> myset -> 使用hash table實踐，search速度幾乎是O(1)，但空間利用大

### Useful Function:
insert(a): 把a放進集合
erase(a): 把a移出
count(a): 看a有沒有在裡面

## Map
### initial:
map<type1, type2> mymap

### Useful Function:
[]: 得到對應的值, EX: my_map[‘a’] = b -> assign
insert(pair<type1, type2>(value1, value2)) : 塞入一個pair
count(a): 看a有沒有在裡面
mymap.clear(): 刪除map整個element
erase (key / it): 刪除鍵值對

## Unordered map
### initial:
unordered_map<type> mymap -> 使用hash table實踐，search速度幾乎是O(1)，但空間利用大

### Useful Function:
[]: 得到對應的值, EX: my_map[‘a’] = b -> assign
insert(pair<type1, type2>(value1, value2)) : 塞入一個pair
count(a): 看a有沒有在裡面
mymap.clear(): 刪除map整個element
erase (key / it): 刪除鍵值對

# Algorithm

## 排列組合類似題目：使用遞迴算出每個結果：
起始點：get_sequence(res, {}, nums);
函數：
```
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

## Combination列出所有可能(candidates裡面 所有組成X數字的組合)
```
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
```
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
```
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
```
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
// 1. 由終點往前找看看哪一點是成功可以跳到終點的點，把它當作"上一個成功點"，再由上一個成功點再往前推。
// 2. 如果目前的點的數值 + 點的位置 >= 上一個成功點，表示目前的點一定可以跳到上一個成功點，到達上一個成功點就表示可以跳到終點。
// 最後再看看上一個成功點會不會等於最一開始的點(i == 0)，如果是表示此點一定可以到達終點
```
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


