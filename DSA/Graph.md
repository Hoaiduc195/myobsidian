# Phương pháp trình bày các thuật toán
Vì thi lý thuyết nên việc trình bày khá quan trọng, phần này chủ yếu là giới thiệu cách trình bày mà tôi hay dùng.
## Kruskal
*Chú ý: sắp xếp cạnh trước khi trình bày thuật toán.*
*Thuật toán Kruskal chủ yếu được trình bày dựa vào bảng sau:*
![[attachments/Pasted image 20250622141422.png]]
=> Nên thực hành để nhớ.

## Prim 
Thuật toán Prim được tôi minh hoạ như dưới đây:
![[attachments/Pasted image 20250622143319.png]]

Các thao tác chính bao gồm: chọn đỉnh gốc, từ các đỉnh trong tập cây khung hiện có, mở các đỉnh lận cận và chọn các cạnh có trọng số nhỏ nhất. 
*Chú ý: với cả hai thuật toán Prim và Kruskal, ta đều có thể tìm được cây khung cực đại.*
## Djisktra
Độ phức tạp thuật toán: $O(E\cdot log(V))$ với E là số cạnh còn V là số đỉnh của G.
Dựa vào nguồn tài liệu tôi kiếm được thì nên trình bày như sau:
![[attachments/Pasted image 20250622143003.png]]
***Chú ý: thuật toán Djisktra khác với thuật toán Prim là khi mở bất kì đỉnh mới nào cũng phải cập nhật đường đi đối với đỉnh gốc, còn thuật toán Prim chỉ cần cập nhật cạnh mà thôi.***

# Thuật toán Floyd - Warshall
Yêu cầu: xác định đường đi ngắn nhất giữa tất cả các cặp đỉnh (i, j) từ ma trận kề cho trước, với giá trị tại vị trí (i, j) là trọng số giữa hai đỉnh i và j, nếu không có cạnh giữa i và j thì giá trị tại đó là $\infty$ (có thể tự định nghĩa).

Điều đáng chú ý ở thuật toán Floyd - Warshall đối với các thuật toán khác là nó cho phép tính toán đường đi ngắn nhất đối với mọi cặp đỉnh trong 1 lần chạy (so với các thuật toán khác như BFS và Djisktra thì tối ưu hơn về mặt này).
Nhược điểm duy nhất của thuật toán này chính là độ phức tạp thời gian lên đến $O(n^{3})$, vậy nên thuật toán này chỉ nên dùng với những bài toán có constraint nhỏ (n<=1000).

Ý tưởng của thuật toán Floyd - Warshall: Xét hai cặp đỉnh (i, j), nếu ta tìm một đỉnh k sao cho tổng trọng số đường đi từ đỉnh i -> k  và đường đi từ k->j thì ta có thể khẳng định rằng, đường đi ngắn nhất của i -> j bây giờ chắc chắn phải đi qua k => ta cập nhật lại đường đi ngắn nhất từ i -> j.
Độ phức tạp thuật toán: $O( n^3 )$

##### Code C++
```cpp
void floydWarshall(vector<vector<int>>& mat){
    int n = mat.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX){
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
    }
}

```

# Thuật toán Bellman - Ford
Thuật toán của Bellman Ford là thuật toán tìm đường đi ngắn nhất từ đỉnh s tới các đỉnh khác trong đồ thị. Ưu điểm của thuật toán này chính là khả năng tìm kiếm đường đi ngắn nhất đối với đồ thị có trọng số âm, tuy nhiên nhược điểm chính là độ phức tạp thời gian cao hơn các thuật toán khác.

##### Code C++
```cpp
int n, m;
vector<vector<pair<int, int>>> adj;
void inp(){
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int x, y, w; cin>>x>>y>>w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

vector<int> bellmanFord(int s){
    vector<int> d(n, INT_MAX);
    d[s] = 0;

    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            if(d[i] == INT_MAX) continue;
            for(auto [v, w]:adj[i]){
                if(d[i]+w<d[v]) d[v]=d[i]+w;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(d[i] == INT_MAX) continue;
        for(auto [v, w]:adj[i]){
            if(d[i]+w<d[v]){ // negative cycle detected.
                return {};
            }
        }
    }
    return d;
}
```

Các bước chính của thuật toán bao gồm:
- Khởi tạo mảng đánh dấu đường đi ngắn nhất từ đỉnh s tới các đỉnh khác, $d[s]=0$, $d[i] = \infty, \forall i \ne s$.
- Thực hiện các bước sau $|V|-1$ lần:
	- Duyệt qua từng đỉnh $i$, nếu $d[i] \ne \infty$ thì ta kiểm tra các cặp đỉnh kề với $i$, cập nhậ lại đường đi ngắn nhất trên các đỉnh đó.
- Sau khi thực hiện $|V|-1$ lần bước trên, điều đã được chứng minh chính là $d[i]$ chính là đường đi ngắn nhất từ $s$ đến $i$.
- Tuy nhiên, ta cần kiểm tra lại liệu đò thị có chu trình âm hay không, vì nếu có chu trình âm thì mọi đường đi từ $s$ tới các đỉnh khác có thể giảm tới vô hạn bằng cách đi qua nhiều lần chu trình âm đó.

