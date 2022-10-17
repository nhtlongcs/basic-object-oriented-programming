<!-- * Nội dung: bài 6.2 và 6.3 trong slides 6. -->

## How to compile using make
```bash 
$ cd assignments/<assignment-name>
$ make main && ./main
```

## Banking Account 
Cho lớp Account như sau:

```C++
class Account 
{
private:
    float m_balance;
public:
    float currBalance() { return () { return m_balance; }
    void deposit(float (float amount) { m_balance += amount; }
    bool withdraw(float amount)
    {
        if (amount <= m_balance) {
            m_balance -= amount;
            return true; 
        }
        return false;
    }
}; 
```

Dựa trên lớp Account, xây dựng lớp SavingAccount như sau:
- Có thêm thông tin:
    - [x] Kỳ hạn gửi.
    - [x] Lãi suất.
    - [x] Số tháng đã gửi.
- [x] Khi nạp tiền, tính lãi và số tháng gửi tính lại từ đầu.
- [x] Khi rút tiền, tính lãi và số tháng gửi tính lại từ đầu.
- [x] Cho phép tăng số tháng đã gửi

## Vehicle

Một chiếc xe máy chạy không tải 100km tốn 2 lit xăng, cứ chở thêm 10kg hàng xe tốn thêm 0.1lit xăng (mỗi 100km). 
Một chiếc xe tải chạy không tải 100km tốn 20lit xăng, cứ chở thêm 1000kg hàng xe tốn thêm 1lit xăng (mỗi 100km). 
Dùng kế thừa để xây dựng lớp Bike và Truck cho phép:

- [x] Chất một lượng hàng lên xe.
- [x] Bỏ bớt một lượng hàng xuống xe.
- [x] Đổ một lượng xăng vào xe.
- [x] Cho xe chạy một đoạn đường.
- [x] Kiểm tra xem xe đã hết xăng chưa.
- [x] Cho biết lượng xăng còn trong xe