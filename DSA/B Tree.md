## Giới thiệu về B Tree
**B Tree** là một loại cây trong nhóm cây m nhánh, được thiết kế để tối ưu việc truy xuất dữ liệu, đặc biệt là trong các hệ thống quản lý bộ nhớ. 
- Trong cây B tree bậc $m$, mỗi node có thể có đến $m$ con và $m-1$ khoá, giúp quản lý bộ nhớ một cách tối ưu.
- Giá trị của $m$ phụ thuộc vào các thông số phần cứng (đĩa nhớ và kich thước của khoá).
- Ưu điểm chính của cây B chính là khả năng lưu trữ lượng lớn giá trị trong cùng một node => giảm đáng kể chiều cao của cây.
- Giống như các cây cân bằng khác, B tree cho phép truy xuất và tìm kiếm, cập nhật dữ liệu một cách nhanh chóng.
- Độ phức tạp thời gian cho các thao tác của B tree khá ổn định. (các thao tác xoá, thêm, tìm kiếm đều chỉ mất $O(logn)$.

Hình dưới đây là một B Tree bậc 5:
![[attachments/Pasted image 20250624094425.png]]

###### Cây B thường được định nghĩa trong code như sau
```cpp
struct Node {
    int n;
    int key[MAX_KEYS];
    Node* child[MAX_CHILDREN];
    bool leaf;
};
```
## Tính chất
Một B Tree bậc $m$ có thể được định nghĩa giống như một cây m nhánh, các tính chất của nó cũng tương tự như vậy:

- Mọi lá đều nằm chung một level => Các lá có cùng chiều cao.
- Mọi khoá nằm trong các node đều được sắp xếp theo thứ tự tăng dần.
- Trong B Tree, nodes không phải lá (ngoại trừ node gốc), sẽ có ít nhất $\frac{m}{2}$ con.*
- Mọi nodes đều có ít nhất $\frac{m}{2}-1$ khoá.* 
- Số node con tối đa của một node bằng số khoá tối đa của node đó + 1.* 
- Nếu node gốc là lá thì node gốc sẽ không có con và sẽ có ít nhất 1 khoá, còn nếu node gốc không là lá thì sẽ có hai con, mỗi con có ít nhất 1 khoá.
- Một node không phải lá với $n-1$ khoá sẽ có n node con khác NULL.*

Một tính chất khác để tính toán chiều cao của B Tree gồm n nodes:
![[attachments/Pasted image 20250624095324.png]]

## Các thao tác trong cây
### Tìm kiếm 
Tìm kiếm tuyến tính trên các node, nếu giá trị x nằm giữa hai khoá bất kì thì ta tiếp tục tìm kiếm trên node con tương ứng.

```cpp
Node* BtreeSearch(Node* x, int k) {
    int i = 0;
    while (i < x->n && k > x->key[i]) {
        i++;
    }
    if (i < x->n && k == x->key[i]) {
        return x;
    }
    if (x->leaf) {
        return nullptr;
    }
    return BtreeSearch(x->child[i], k);
}
```

=> Nếu node đang xét là node lá thì không thể tìm kiếm các node con tiếp nữa.

## Thêm và xoá node
Khá rườm rà nên tôi xin bỏ qua.
Bạn có thể tham khảo ở nguồn sau:
- Thao tác thêm node: <a href="https://www.geeksforgeeks.org/insert-operation-in-b-tree/">Insertion Operation in B Tree</a>
- Thao tác xoá node: <a href="https://www.geeksforgeeks.org/delete-operation-in-b-tree/"> Deletion Operation in B Tree</a>

Tôi chú trọng ở thao tác xoá:
- Nếu khoá nằm trong node lá thì chỉ cần xoá.
- Không thì làm theo các bước sau:
	- 

# Các dạng bài tập về B Tree
Năm tôi thi DSA thì đây là nội dung mới cho nên việc tìm kiếm các dạng bài tập khá khó khăn.

### Một B Tree có số khoá tối đa là 5, thì cây đó có số khoá tối thiểu trong các node khác gốc là?
Trả lời: Số node tối đa là 5 nên bậc của cây là 6 (bằng với số con tối đa của mỗi node). Số node tối thiểu của các node khác gốc là: $\frac{6}{2}-1 = 2$. Vậy mỗi node khác gốc có ít nhất 2 khoá.

### Một B Tree bậc 4 sau 10 thao tác thêm node thì số thao tác tách node tối đa có thể xảy ra là bao nhiêu?
Trả lời: Chúng ta liên tục thêm các giá trị lớn hơn giá trị lớn nhất trong cây thì các node đó sẽ dồn dần về node lá phải cùng dẫn đến nhiều thao tác tách node diễn ra ở đó.
Mô phỏng lại thao tác thêm node với dãy 1 2 3 4 5 6 7 8 9 10 thì ta thấy được số thao tác cần dùng để tách node là 5. Đây cũng chính là số thao tác tách node cần tìm.
Kết quả của B Tree sau khi thêm dãy trên:
![[attachments/Pasted image 20250624103143.png]]


### Một cây B có 4 level thì nếu thêm một node vào thì số node tối đa có thể được tạo ra trong quá trình thêm này là?
Trả lời: Để có thể tạo ra được nhiều node nhất => ta sẽ giả sử cây mà ta đang xét thì các nodes ở các tầng đều đang đầy. Ý tưởng chính là khi thêm khoá mới, từ node lá sẽ liên tục split và lan lên tới node gốc.

Từ đây, ta thấy rằng ngoại trừ node lá được thêm node mới sẽ tạo ra hai node con và đưa khoá ở giữa lên node cha thì các node ở các tầng trên đều chỉ tạo ra được 1 node mới.
Vậy ta có:
Ở tầng cuối: tạo ra 2 node.
Các tầng khác (ngoại trừ tầng cuối): tạo ra 1 node.
Vậy có thể tạo ra tối đa $3\cdot1 + 2 = 5$ node mới.




