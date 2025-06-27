#dsa
# Các thuật toán sắp xếp
*Xem qua bảng dưới đây để nắm rõ hơn*

|      Tên       | Độ phức tạp thời gian trung bình | Thao tác chính                                                                                                                                                                                                                                                                                                                                                                                                             |
|:--------------:|:--------------------------------:| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Selection Sort |             $O(n^2)$             | Liên tục chọn ra các phần tử nhỏ nhất trong mảng để lấy ra đưa lên đầu mảng.                                                                                                                                                                                                                                                                                                                                               |
| Insertion Sort |             $O(n^2)$             | Liên tục chèn các phần tử nhỏ về phía bên trái cho đến khi không chèn được nữa.                                                                                                                                                                                                                                                                                                                                            |
|   Merge Sort   |           $O(nlog(n))$           | Chia mảng ra làm hai nửa, sắp xếp từng bên rồi trộn hai mảng đã được sắp xếp lại. Thuật toán chính của Merge Sort là trộn hai mảng đã sắp xếp. Ngoài ra, có thể đọc thêm <a href="https://stackoverflow.com/questions/1557894/non-recursive-merge-sort"> Non Recursive Merge Sort </a>.                                                                                                                                    |
|   Heap Sort    |            $O(nlogn)$            | Sử dụng cấu trúc dữ liệu heap để tìm ra phần tử lớn nhất của mảng, rồi lần lượt đem các phần tử lớn nhất đó ra sau mảng, cấu trúc lại cây heap.                                                                                                                                                                                                                                                                            |
|   Quick Sort   |            $O(nlogn)$            | Tư tưởng khá giống Merge Sort, nhưng thay vì sort trước thì Quick Sort sẽ chia mảng ra miễn sao các phần tử nằm đúng partition của chúng. Sau đó mới sort cho từng bên. Có nhiều kĩ thuật partition khác nhau, ví dụ như <a href="https://www.geeksforgeeks.org/dsa/lomuto-partition-algorithm/">Lomuto Partition</a>, <a href="https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/"> Hoare Partition </a>, ... |
|   Count Sort   |             $O(n+k)$             | Dựa trên việc đếm số lượng phần tử xuất hiện để tính toán vị trí của chúng trong mảng đã sắp xếp. *Chú ý: Không nên dùng khi số quá lớn.*                                                                                                                                                                                                                                                                                  |
|   Radix Sort   |           $O(d(n+k))$            | Sắp xếp dựa vào cơ số của các phần tử trong mảng. Có thể tham khảo thêm Binary Radix Sort.                                                                                                                                                                                                                                                                                                                                 |
# Các thuật toán sắp xếp khác
*Chú ý: việc tìm hiểu các thuật toán khác chủ yếu là dự phòng, không mang tính bắt buộc*
## Tim Sort
Ý tưởng chính của Tim Sort là lợi dụng thứ tự có sẵn của dữ liệu để giảm thiểu hoá thao tác so sánh và swap. Để đạt được điều đó, thuật toán sẽ chia mảng ra thành nhiều mảng con gọi là **runs**, mỗi **runs** đều đã được sắp xếp, sau đó sử dụng thuật toán merge của **merge sort** để gộp các **runs** lại.
=> Nói cách khác, Tim sort là thuật toán lai giữa Merge Sort và Insertion Sort.
##### Code C++
```cpp
void insertionSort(vector<int>& a, int l, int r){
    for(int i=l;i<=r;i++){
        int key = a[i];
        int j = i-1;
        while(j>=l && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void merge(vector<int>& a, int l, int m, int r){
    vector<int> left(a.begin()+l, a.begin()+m+1);
    vector<int> right(a.begin()+m+1, a.begin()+r+1);

    int i=0, j=0, k=l;
    while(i<left.size() && j<right.size()) a[k++] = (left[i]<right[j])?(left[i++]):right[j++];
    while(i<left.size()) a[k++] = left[i++];
    while(j<right.size()) a[k++] = right[j++];
}

void timSort(vector<int> &a){
    int n = a.size();
    for(int i=0;i<n;i+=RUN){
        insertionSort(a, i, min(i+RUN-1, n-1));
    }

    for(int size = RUN; size<n; size*=2){
        for(int left = 0; left<n; left+=2*size){
            int mid = left+size-1;
            int right = min(left+2*size-1, n-1);
            if(mid<right) merge(a, left, mid, right);
        }
    }
}
```
=> Ta thấy thuật toán chủ yếu nằm ở hàm timSort với ý tưởng chính là sort các runs với InsertionSort sau đó sử dụng merge các run lại với nhau.

# Binary Radix Sort

Thuật toán Radix Sort hoạt động dựa vào tính chất thứ tự của các cơ số. Điều này làm cho thuật toán này khá nhanh vì số lượng cơ số không quá nhiều. Tuy nhiên thuật toán Radix Sort có một nhược điểm là không thể cài đặt để sắp xếp các mảng có số âm (hoặc số thực). Để khắc phục điều đó, ta có để quy đổi số ở cơ số 10 (decimal) về cơ số 2 (binary), tính chất thứ tự cơ số vẫn được giữ nguyên. Do đó ta có thể sort được cả với số âm.
Do việc code thuật toán này khá phức tạp, nên tôi chỉ đề cập đến nguồn tài liệu tham khảo.
Tham khảo nguồn dưới đây: <a href="https://duvanenko.tech.blog/2022/04/09/in-place-binary-radix-sort/#:~:text=One%20way%20to%20implement%20Radix,digit%20matches%20the%20bin%20number.">Binary Radix Sort</a>

![[attachments/Pasted image 20250618103720.png]]

Việc cài đặt có thể liên quan đến các thao tác trên bit, có thể tham khảo ở nguồn sau: <a href="https://viblo.asia/p/thao-tac-xu-ly-bit-va-ung-dung-bit-manipulation-3kY4gxl9JAe">Bit Manipulation</a>

# Bucket Sort
Ý tưởng chính của thuật toán này là đưa các giá trị của mảng vào các Bucket riêng biệt nhau, sau đó sort cục bộ trên các Bucket đó. Ưu điểm của việc làm này là giảm được độ phức tạp so với các thuật toán sort duyệt tuyến tính. Tuy nhiên, nhược điểm lớn nhất của thuật toán này chính là độ phức tạp về không gian. 
*Chú ý: thuật toán này phức tạp ở thao tác đưa các phần tử vào các Bucket thích hợp. Ý tưởng chính của việc đưa vào Bucket là các phần tử nằm trong cùng một Bucket nằm trong cùng một range.*
Nguồn tham khảo: <a href="https://www.geeksforgeeks.org/bucket-sort-2/">Bucket Sort</a>

# Practice 

## Thuật toán Quick Select
Yêu cầu: tìm phần tử lớn thứ k (0-based) của mảng chưa được sắp xếp mà không sắp xếp mảng.
Đây là một biến thể của thuật toán Quick Sort. 
Ý tưởng chính như sau:
``` pseudocode
hàm quickSelect(danh sách, trái, phải, k)   
  
   nếu trái = phải   
      trả về danh sách[trái]   
  
   Chọn một pivotIndex giữa trái và phải   
  
   pivotIndex := phân vùng(danh sách, trái, phải, pivotIndex)   
   nếu k = pivotIndex   
      trả về danh sách[k]   
   nếu không thì nếu k < pivotIndex   
      phải := pivotIndex - 1   
   nếu không thì   
      trái := pivotIndex + 1
      
```

##### Code C++
```cpp
int partition(vector<int>& a, int l, int r){
    int pivot = a[l]; int j = l;
    for(int i=l+1;i<=r;i++){
        if(a[i]<pivot) swap(a[++j], a[i]);
    }
    swap(a[j], a[l]);
    return j;
}

int quickSelect(vector<int>& a, int l, int r, int k){
    if(k>0 && k<=(r-l+1)){
        int index = partition(a, l, r);
        if(index - l == k-1) return a[index];
        if(index - l>k-1){
            return quickSelect(a, l, index-1, k);
        }else{
            return quickSelect(a, index+1, r, k - index + l - 1);
        }
    }
    return INT_MAX;
}
```
*Chú ý: thuật toán hoạt động dựa trên sự kết hợp của binary search và quicksort*

## Thuật toán tìm kiếm trên rotated array
Yêu cầu: tìm kiếm một phần tử trong circularly rotated array.
Ý tưởng: dùng thuật toán binary search để tìm kiếm, ý tưởng chính là nắm được vị trí của phần tử cần tìm.

```cpp
int circularSearch(vector<int>& a, int x){
    int l = 0;
    int r = a.size()-1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m] == x) return m;
        if(a[l]<a[m]){
            // this means left haft in order
            if(x<a[m] && x>=a[l]) r = m-1; // this means x in left haft
            else l = m+1; // this means x is not in left haft
        }else{
            // this mean right haft in order
            if(x>a[m] && x<=a[r]) l = m+1; // this means x is in right haft
            else r = m-1; // this means opposite
        }
    }
    return -1;
}
```

