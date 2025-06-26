Trong note này, tôi sẽ tập trung các bài tập liên quan đến cây BST. Đơn giản là vì nó có nhiều nội dung lý thuyết.

## Câu hỏi: Cho một tập hợp gồm n phần tử và một cây nhị phân không gán nhãn thì liệu có bao nhiêu cách tạo cây với tập hợp đó?
Trả lời: Cây nhị phân không gán nhãn đã là một cấu trúc cố định. Cộng thêm tính chất của cây BST là node cha phải lớn hơn node con trái và nhỏ hơn node con phải nên chỉ có duy nhất 1 cách tạo cây với tập cho trước. *chú ý: câu trả lời này chỉ đúng với cây chưa gán nhãn, đừng nhầm lẫn với câu hỏi phía dưới.*

## Câu hỏi: Có thể tạo được bao nhiêu cây BST với n phần tử cho trước?
Trả lời: Đáp án là $\frac{1}{n+1} \binom{2n}{n}$ (số Catalan). Nói vậy chứ mình không biết chứng minh.

## Câu hỏi: The preorder traversal sequence of a binary search tree is 30, 20, 10, 15, 25, 23, 39, 35, 42. Which one of the following is the postorder traversal sequence of the same tree?
Trả lời: Preorder là duyệt theo thứ tự NLR nên kết quả là: 15, 10, 23, 25, 20, 35, 42, 39, 30

## Câu hỏi: ![[Pasted image 20250618210339.png]]
Trả lời: Công thức: Tổng của (số node level i * i) chia cho số node trong cây.
![[Pasted image 20250618210527.png]]



## Có thể thu được cây từ các thứ tự duyệt nào?
Trả lời: Preorder với Postorder.

## Câu hỏi: x = ? ![[Pasted image 20250618211506.png]]
Trả lời: ý tưởng chính để tạo cây có n nodes là chọn k-1 phần tử làm cây con bên trái và chọn n-k phần tử làm cây con bên phải (còn 1 node là node gốc). Do đó, x = n - k.

## Câu hỏi:
Câu này tôi làm sai.
![[Pasted image 20250618212027.png]]

Cách làm: Vẽ lại cây theo các bước tìm kiếm của cây BST, tìm cây có cấu trúc sai quy tắc của BST.
![[Pasted image 20250618212136.png]]


## Câu hỏi: Heap có 2022 node thì có bao nhiêu node lá?
Trả lời: Heap là cây nhị phân hoàn chỉnh nên nếu bỏ đi tầng cuối thì heap sẽ trở thành cây nhị phân hoàn hảo.

Số node trong cây nhị phân hoàn hảo là $2^{L} - 1$ với $L$ là level của tầng cuối. Số node lá ở tầng cuối là $2^h$ với $h$ là chiều cao của cây.

Ta cho $2023 = 2^L - 1$ thì L xấp xỉ $10,982$ vậy tầng cuối của cây hoàn hảo nói trên là có level là 10 => số node trong cây hoàn hảo là $2^{10} - 1 = 1023$ và chiều cao của cây hoàn hảo nói trên là 9.

Ta có được số node lá ở tầng cuối (của cây hoàn hảo) là $2^9$ = 512 lá. Ngoài ra do số node trong cây hoàn hảo là 1023 nên số node lá ở tầng cuối trong cây heap là $2022 - 1023 = 999$ lá. 

Với 999 lá ở tầng cuối của cây heap. Sẽ có 998 lá là con của 499 lá tầng trên và 1 là là con của 1 lá tầng trên => suy ra ở cây hoàn hảo chỉ có $512 - 500 = 12$ lá là lá thật sự của cây heap.

Vậy kết quả là 12 + 999 = 1011 lá của cây heap.
Ngoài ra, ta có công thức tính nhanh được chứng minh theo tác giả sau: <a href="https://cs.stackexchange.com/questions/841/proving-a-binary-heap-has-lceil-n-2-rceil-leaves">Proving a binary heap has ceil(n/2) leaves</a>

## ![[Pasted image 20250620131850.png]]
Cách làm: Ta có các nhận xét, từ đó suy ra được kết quả.
- Số đứng cuối dãy thứ tự sau luôn là node gốc => 2 là gốc => Nhìn theo dãy thứ tự giữa thì (9, 3, 1, 0, 4) sẽ nằm bên cây con trái của 2, còn (7, 6, 8, 5) sẽ nằm bên cây con phải.
- Tiếp tục ta thấy ở trong dãy thứ tự sau 3 nằm ở cuối so với cái số cùng cây con với mình => 3 là gốc của cây con đó => Nhìn lại dãy thứ tự giữa (9) thuộc cây con trái của 3 và (1, 0, 4) thuộc cây con phải của 3.
- Tương tự thì (7,6) thuộc cây con trái của 8 và (5) thuộc cây con phải của 8.
- Tiếp tục thì 0 nằm cuối trong các số nằm chung cây con của nó nên 0 là con phải của 3 (9 đã là con trái của 3). Làm liên tục thì ta sẽ có được cây hoàn chỉnh.
