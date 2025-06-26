#dsa
Trong phần này, cấu trúc một node sẽ được định nghĩa như sau:
```cpp
struct Node{
    int val;
    Node *left, *right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};
```
# Khái niệm 
## **BST**
- Về **cây nhị phân tìm kiếm BST**, có thể tham khảo thêm ở nguồn sau: <a href=" https://en.wikipedia.org/wiki/Binary_search_tree">Cây Nhị Phân</a>
- Điểm cần chú ý ở BST chính là các công thức liên quan đến nó.
- Quizzes về BST: <a href="https://www.geeksforgeeks.org/quizzes/top-mcqs-on-binary-search-tree-bst-data-structure-with-answers/?ref=bst_lp">Quizzes about BST</a>
- [[Bài tập cây BST]].
- Chiều cao của cây là số cạnh lớn nhất từ root đến node lá. Quy ước chiều cao của node gốc là 0.
- Level tại bất kì node đang xét là số node cần đi từ node gốc để đến được node đó. Quy ước level của gốc là 1.
## **AVL**
- Cây AVL **là một cây tìm kiếm nhị phân tự cân bằng, và là cấu trúc dữ liệu đầu tiên có khả năng này**. Trong một cây AVL, tại mỗi nút chiều cao của hai cây con sai khác nhau không quá một.
# Các loại cây nhị phân

|                     **Tên**                      | **Tính chất**                                                                                                                 |
| :----------------------------------------------: | :---------------------------------------------------------------------------------------------------------------------------- |
|               Cây nhị phân đầy đủ                | Mỗi node **hoặc có 0 con hoặc đúng 2 con** (không có node chỉ có 1 con).                                                      |
|             Cây nhị phân hoàn chỉnh              | - Tất cả các tầng (trừ tầng cuối cùng) đều **đầy đủ**.<br>    <br>- Tầng cuối cùng được **lấp từ trái sang phải**.            |
|              Cây nhị phân cân bằng               | Chiều cao của cây con trái và phải của **mọi node chênh lệch không quá 1**.                                                   |
| Cây tìm kiếm nhị phân (Binary Search Tree - BST) | - Mỗi node có giá trị:<br>    - con trái < node<br>    - con phải > node<br>- Duyệt theo thứ tự LNR sẽ ra dãy tăng dần.       |
|              Cây nhị phân hoàn hảo               | - Tất cả các node trong cây đều có đúng 0 hoặc 2 node con<br>    <br>- Tất cả các lá (leaf nodes) đều **nằm ở cùng một tầng** |
# Tính chất

## **BST**  
*Các tính chất của BST khá đơn giản nên mình sẽ lược bỏ bớt*
## **AVL**
- Ưu điểm chính của Cây AVL là độ phức tạp về thời gian của tất cả các thao tác (tìm kiếm, chèn và xóa, max, min, sàn và trần) trở thành **O(Log n)**. Điều này xảy ra vì chiều cao của cây AVL bị giới hạn bởi **O(Log n).** Trong trường hợp của BST thông thường, chiều cao có thể lên tới **O(n).**
- Cây AVL duy trì chiều cao của nó bằng cách **thực hiện một số công việc bổ sung trong quá trình chèn và xóa.** Nó chủ yếu sử dụng **phép quay** để duy trì cả thuộc tính BST và cân bằng chiều cao.
- Độ phức tạp các thao tác tìm kiếm, chèn xoá: *O(logn)*
### **Các trường hợp cần xoay cây**
**1. Lệch phải** 
![[Pasted image 20250612210805.png]]

**2. Lệch trái**
![[Pasted image 20250612210859.jpg]]

**3. Lệch trái - phải**
![[Pasted image 20250612210934.png]]
**4. Lệch phải - trái**
![[Pasted image 20250612210947.png]]
____

# Cây Heap
Trong phần này, cây Heap có lượng lớn kiến thức có thể ra thi nên tôi chú trọng vào các vấn đề đối với cây Heap. Cây heap là một cây nhị phân hoàn chỉnh
## Cây Heap thường được ứng dụng để cài đặt hàng đợi ưu tiên
Vì tính chất vun đống mà cây Heap có thể được dùng để cài đặt hàng đợi ưu tiên.
Các thao tác chính của heap khi cài đặt hàng đợi ưu tiên bao gồm: **Sift up** và **Sift down**  
Dưới đây là thao tác cài đặt hai thao tác trên cho MinHeap. Từ đó có thể làm tương tự với MaxHeap.

*Nên nhớ: Đối với node i trong cây, node con của nó gồm node thứ ix2+1 và node ix2+2, ngoài ra node cha là node (i-1)/2*
##### Code C++
```cpp
void siftUp(int a[], int n, int i){
	while(i>0 && a[(i-1)/2]>a[i]){
		swap(a[i], a[(i-1)/2]);
		i = (i-1)/2;
	}
}

void siftDown(int a[], int size, int i){ 
	int min = i;
	int c1 = i*2+1;
	int c2 = i*2+2;

	if(c1<size && a[c1]<a[min]) min = c1;
	if(c2<size && a[c2]<a[min]) min = c2;

	if(min!=i){
		swap(a[min], a[i]);
		siftDown(a, size, min);
	}
}

// Non-recursive Sift Down
void siftDown(int a[], int n, int i){
	// Using while loop instead of recursive
	while(i*2+1<n){
		int c1 = i*2+1;
		int c2 = i*2+2;
		if(c2<n && a[c2]<a[c1]) c1 = c2;
		// compare a[i] with min(a[c1], a[c2])
		if(a[i]<=a[c1]) break;

		swap(a[c1], a[i]);
		i = c1;
	}
}
```

#### Cách trình bày cây Heap trong thi tự luận 
![[Pasted image 20250620144306.png]]

**Đối với yêu cầu mô phỏng quá trình Sort, tôi đã trình bày như sau:**
![[Pasted image 20250622141739.png]]

=> Việc mô phỏng thuật toán khá dài dòng.
# Các thuật toán liên quan

### Morris Traversal
Yêu cầu: Duyệt cây BST (AVL) mà **không** sử dụng stack hoặc đệ quy --> Dùng **Morris Traversal**
Ý tưởng của thuật toán Morris Traversal là từ **cây nhị phân theo luồng (Thread Binary Tree)** .
#### Inorder (LNR)
*Chú ý: Duyệt cây BST(AVL) theo thứ tự Inorder sẽ cho kết quả là một dãy tăng dần.*
Thuật toán được phát biểu với các bước như sau:
- Khởi tạo con trỏ **cur** là root. Sau đó lặp lại các bước dưới miễn là **cur** chưa là **nullptr**.
- Nếu **cur** không có con trái thì in **cur** và đi sang cây con bên phải.
- Nếu **cur** có con trái thì: 
	- Khởi tạo con trỏ **prev** trỏ tới con trái của **cur**, sau đó dịch prev sang con phải miễn là **prev->right** khác null và **prev->right** khác **cur**.
		- Nếu **prev->right** là null thì ta gán **prev->right** thành **cur** và dịch **cur** sang trái.
		- Nếu **prev->right** là **cur** thì ta in ra **cur** và dịch **cur** sang bên phải.

--> Ta nhận thấy rằng **ý tưởng chính** của thuật toán chính là **giữ lại kết nối giữa node phải cùng bên trái với node root của cây con đang xét** nhằm mục đích sau khi in hết các node bên trái của root thì từ node phải cùng bên trái (predecessor), ta có thể trở lại node gốc và đi tiếp tới cây con bên phải.
###### Code C++
```cpp
void MorrisTraversalInorder(Node* root){
    Node* cur = root;

    while(cur){
        if(!cur->left){
            cout<<cur->val<<" ";
            cur = cur->right;
        }else{
            Node* prev = cur->left;
            while(prev->right && prev->right!=cur) prev = prev->right;

            if(!prev->right){
                prev->right = cur; cur = cur->left;
            }

            if(prev->right == cur){
                cout<<cur->val<<" ";
                prev->right = nullptr;
                cur = cur->right; 
            }
        }
    }
    cout<<endl;
}
```

#### Preorder (NLR)
Ý tưởng của preorder khá tương tự với Inorder nhưng khác ở các vị trí in ra.

###### Code C++
```cpp
void MorrisTraversalPreorder(Node* root){
        Node* cur = root;

        while(cur){
            if(!cur->left){
                cout<<cur->val<<" ";
                cur = cur->right;
            }else{
                Node* prev = cur->left;
                while(prev->right && prev->right!=cur) prev=prev->right;

                if(!prev->right){
                    cout<<cur->val<<" ";
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        cout<<endl;
    }
```

#### Postorder (LRN)
Cách cài đặt postorder giống hệt preorder, chỉ cần đổi chỗ left, right và in ngược mảng phụ.
##### Code C++
```cpp
void postOrder(Node* root){
    Node* cur = root;
    vector<int> res;
    while(cur){
        if(!cur->right){
            res.push_back(cur->val);
            cur = cur->left;
        }else{
            Node* prev = cur->right;
            while(prev->left && prev->left!=cur) prev = prev->left;
            if(!prev->left){
                prev->left = cur;
                cur = cur->right;
            }else{
                res.push_back(prev->val);
                prev->left = nullptr;
                cur = cur->left;
            }
        }
    }
    reverse(res.begin(), res.end());
}
```

### Tìm phần tử lớn thứ k trong cây
Yêu cầu: tìm phần tử lớn thứ k trong cây BST.
Ý tưởng: dùng một biến đếm để lưu số lượng node đã thăm qua, sau đó duyệt cây theo thứ tự Inorder.
##### Code C++
```cpp
void foo(Node* root, int k, int& cnt, int& res){
	if(!root || cnt>=k) return;
	foo(root->left, k, cnt, res);
	cnt++;
	if(cnt == k){
		res = root->val;
	}
	foo(root->right, k, cnt, res);
}

int kSmallest(int k){
	if(k>0 && k<=size){
		int res = INT_MAX;
		int cnt = 0;
		foo(root, k, cnt, res);
		return res;
	}
	return INT_MAX;
}
```

**Giải thích code:** Nếu k<0 hoặc k>số lượng node trong cây thì trả về dương vô cùng, nếu không thì khởi tạo hai biến gồm **biến đếm** để đếm node trên đường duyệt và **biến kết quả** để lưu trữ kết quả. Sau đó, duyệt cây theo thứ tự Inorder thì khi **biến đếm = k**, giá trị tại node đang xét sẽ là giá trị cần tìm, ta lưu giá trị đó vào **biến kết quả**.  

### Truy vấn phần tử trong khoảng [L; R]
Yêu cầu: Cho cây BST và hai **số nguyên l, r**, hãy trả về các phàn tử x bên trong cây sao cho l <= x <= r.
Ý tưởng: mở rộng về 2 phía của cây cho đến khi không còn mở rộng được nữa.
##### Code C++
```cpp
void query(Node* root, int l, int r, vector<int>& res){
	if(!root) return;
	if(root->val > l) query(root->left, l, r, res);
	if(root->val>=l && root->val<=r) res.push_back(root->val);
	if(root->val < r) query(root->right, l, r, res);
}
vector<int> queryInRange(Node* root, int l, int r){
	vector<int> a;
	query(root, l, r, a);
	return a;
}
```

### Thuật toán tìm đường đi dài nhất từ gốc đến lá trong Binary Tree
Yêu cầu: tìm đường đi dài nhất từ đỉnh đến lá.
Ý tưởng: dùng thuật toán DFS kết hợp backtracking để tìm đường đi dài nhất đó.
##### Code C++
```cpp
void dfs(Node* root, vector<int>& cur, vector<int>& ans){
    cur.push_back(root->val);
    if(cur.size()>ans.size()) ans = cur;

    if(root->left) dfs(root->left, cur, ans);
    if(root->right) dfs(root->right, cur, ans);
    cur.pop_back();
}
void longestPath(Node* root){
    vector<int> ans, cur;
    dfs(root, cur, ans);
    for(int x: ans) cout<<x<<' ';
    cout<<endl;
}
```

Trong thuật toán trên, tôi backtrack bằng cách sử dụng hai vector, một vector dùng để duyệt qua các phần tử, vector còn lại để lưu kết quả lớn nhất.

### Thao tác xoá trong cây BST mà không dùng đệ quy
Ý tưởng: ý tưởng của thuật toán khá rườm rà. Có thể khái quát như sau:
- Khởi tạo node curr để duyệt qua cây và node parent luôn là cha của curr để dễ dàng cho thao tác xoá.
- Duyệt qua cây để tìm node có giá trị là key.
- Nếu không tìm được (curr = nullptr) thì trả về root.
- Nếu tìm được thì sẽ có các trường hợp sau:
	- Node cần tìm có cả con trái và con phải. Ta tìm node thế mạng cho nó bằng cách tìm phần tử nhỏ nhất bên cây con phải, sau đó **dịch curr tới node đó để tiến hành xoá chính node curr**.
	- Dù có hay không có hai node ở hai bên thì khi xoá curr ta vẫn cần nối lại cây con bên dưới curr với node parent.
	- Nhận xét: Node curr khi ta khai báo Node* child chắc chắn chỉ có duy nhất 1 con.
##### Code C++
```cpp
Node* deleteNode(Node* root, int key) {
    Node* parent = nullptr;
    Node* curr = root;

    while (curr && curr->val != key) {
        parent = curr;
        if (key < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (!curr) return root; 
    if (curr->left && curr->right) {
        Node* succParent = curr;
        Node* succ = curr->right;
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }
        curr->val = succ->val;
        curr = succ;
        parent = succParent;
        key = succ->val;
    }
    Node* child = (curr->left) ? curr->left : curr->right;

    if (!parent) {
        delete curr;
        return child;
    }
    if (parent->left == curr)
        parent->left = child;
    else
        parent->right = child;
    delete curr;
    return root;
}
```

## In cây theo kiểu string
Yêu cầu: Dựa vào bài tập sau trên LeetCode <a href="https://leetcode.com/problems/construct-string-from-binary-tree/">Construct string from binary tree</a>.
##### Code C++
```cpp
string tree2str(TreeNode* root) {
	if (!root)
		return "";
	string ans = to_string(root->val);
	if (root->left)
		ans += "(" + tree2str(root->left) + ")";
	if (root->right) {
		if (!root->left)
			ans += "()";
		ans += "(" + tree2str(root->right) + ")";
	}
	return ans;
}
```


Code của toàn bộ các thuật toán kể trên nằm trong file này, bạn có thể dùng nó để chạy thử: 
<div>
</div>
![[tmp10.cpp]]
