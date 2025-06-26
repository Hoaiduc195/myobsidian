
## Giới thiệu về cây đỏ đen
Giống với cây AVL, cây đỏ đen là một cây tìm kiếm nhị phân có cấu trúc tự cân bằng dựa vào một tập các quy tắc đượcn quy định sẵn. 
Khác với cây AVL, bộ quy tắc của cây đỏ đen không dựa theo chiều cao của từng node mà dựa vào việc phân loại các node vào màu sắc. Cụ thể thì mỗi node có thể có màu đỏ hoặc đen.

## Tính chất
- Màu của node chỉ có thể là đỏ hoặc đen.
- Node gốc luôn có màu đen.
- Node đỏ không thể có con màu đỏ (không có hai node đỏ liên tiếp nhau trên một đường đi từ gốc đến lá bất kì)
- Mọi đường đi xét từ bất kì node nào đến các node lá đều có cùng một số lượng node đen giống nhau.
- Các node null đều được cho là có màu đen.

=> Những tính chất trên khiến cho tỉ số giữa đường đi dài nhất và đường đi ngắn nhất từ gốc đến là luôn không quá 2, duy trì được sự hiểu quả trong các thao tác.

#### So sánh với cây AVL
Cây AVL sẽ cân bằng hơn so với cây đỏ đen. Tuy nhiên trong quá trình chèn và xoá các node mới, cây AVL có thể yêu cầu rất nhiều thao tác xoay, vậy nên với các chương trình thường xuyên phải thực hiện các thao tác chèn, xoá thì cây đỏ đen sẽ được ưu tiên hơn.

## Các thao tác trên cây đỏ đen.
*Chú ý: tôi chỉ đề cập các thao tác khác so với cây AVL.*
### Thêm Node mới vào cây.
Chú ý: Node được thêm luôn là <span style="color: red">node đỏ</span>.
Chiến lược chính:
- Chèn node có <span style="color:red;">màu đỏ</span>.
- Chỉnh sửa lại cho đúng luật cây đỏ đen.

Có 4 trường hợp khi thêm node vào cây.
- <span style="color:red;">Chú đỏ:</span> ta đổi màu của cha và chú thành đen, đổi màu ông nội thành đỏ và tiến hành chỉnh sửa với ông nội.
- <span style="color:grey;">Chú đen:</span> gồm chú đen thẳng và chú đen cong (tam giác)
	- Thẳng thì xoay ở ông nội. Đổi màu của ông nội với cha.
	- Cong thì xoay ở cha. 
Ở hai trường hợp chú đen thì đều xoay ngược hướng với node đang xét.
Tham khảo ở video sau: <a href="https://www.youtube.com/watch?v=5IBxA-bZZH8">Red Black Tree</a>

### Xoá Node khỏi cây
Chiến lược chính:
- Xoá giống cây BST.
- Sửa lại lỗi.

Có 4 trường hợp khi xoá một node <span style="color:grey;">đen</span> khỏi cây:
- <span style="color:red;">Kế đỏ:</span> Xoay cha và đổi màu kế và cha.
- <span style="color:grey;">Kế đen:</span> gồm hai trường hợp:
	- <span style="color:grey;">Con kế đen:</span> đổi màu kế và tiếp tục chỉnh sửa lên trên.
	- <span style="color:red;">Kế có ít nhất 1 con đỏ:</span> 
		- Nếu con xa của kế là đỏ thì xoay cha và kế, đổi màu.
		- Nếu con gần của kế là đỏ thì xoay kế và con kế, đổi màu kế và con kế, sau đó xử lý bên trên.

*P/S: Khó hiểu quá.*



