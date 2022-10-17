<!-- * Nội dung: bài 2.1, 2.2, 2.3, và 2.4 trong slides 2. -->

## 2.1 Fraction
Xây dựng lớp phân số cho phép thực hiện các thao tác:
- [x] Nhập, xuất.
- [x] Lấy tử số, mẫu số.
- [x] Gán giá trị cho tử số, mẫu số.
- [x] Nghịch đảo, rút gọn.
- [x] Cộng, nhân, so sánh với phân số khác
```python
Enter x: 4 8
X is: 4/8
X after inverse is: 8/4
X after compress is: 1/2
Enter y: 1 1
Y is: 1/1
X + Y is: 3/2
X * Y is: 1/2
X > Y is: false
X < Y is: true
X == Y is: false
```
## 2.2 Monomial
Xây dựng lớp đơn thức cho phép thực hiện các thao tác:
- [x] Nhập, xuất.
- [x] Lấy hệ số, số mũ.
- [x] Gán giá trị cho hệ số, số mũ.
- [x] Tính giá trị, đạo hàm.
- [x] Cộng (cùng bậc), nhân, so sánh với đơn thức khác

```python
Enter coefficent: 3
Enter exponent: 4

Enter coefficent: 6
Enter exponent: 5

3*x^4 // Raw monomial
6*x^5 // Raw monomial

2.5*x^4 // Replace coefficent = 2.5
6*x^4   // Replace exponent = 4

10*x^3 // Derivative monomial
24*x^3 // Derivative monomial

f(3) = 202.5 // Calculate value f at x = 3, f(x) = 2.5 * x ^ 4
g(6) = 7776  // Calculate value g at x = 6, g(x) = 6   * x ^ 4

8.5*x^4 // f(x) + g(x)
15*x^8  // f(x) * g(x)

F.compareTo(G) = -1 // Compare f(x) + g(x) and f(x) * g(x)
```

## 2.3 Student
Thông tin một học sinh bao gồm:
- Họ tên.
- Điểm văn, toán.
Xây dựng lớp học sinh cho phép thực hiện các thao tác:
- [x] Nhập, xuất.
- [x] Lấy họ tên, điểm văn, toán.
- [x] Gán giá trị cho họ tên, điểm văn, điểm toán.
- [x] Tính điểm trung bình.
- [x] Xếp loại theo tiêu chí:
- [x] Giỏi (>= 8.0), (>= 8.0), Khá (>= 7.0). (>= 7.0).
- [x] Trung bình (>= 5.0), (>= 5.0), Yếu (< 5)

```
nguyen van A
7 8 
nguyen van A
Van : 7. Toan : 8
abc def
Van : 7. Toan : 8
Mean score is: 7.5
Student grade: Kha
```

## 2.4 List

Xây dựng lớp mảng số nguyên cho phép thực hiện các thao tác sau:
- [ ] Nhập, xuất mảng.
- [ ] Lấy kích thước mảng.
- [ ] Lấy phần tử tại vị trí nào đó.
- [ ] Gán giá trị cho phần tử tại vị trí nào đó.
- [ ] Tìm phần tử nào đó trong mảng.
- [ ] Sắp xếp tăng, giảm

```
7
5 4 2 1 4 2 8
N = 7
A = 5 4 2 1 4 2 8 
N = 7
A = 5 4 2 1 10 2 8 
Size of A is: 7
Value at index 5 is: 2
Sorted ascending: 
N = 7
A = 1 2 2 4 5 8 10 
Sorted descending: 
N = 7
A = 10 8 5 4 2 2 1 
```