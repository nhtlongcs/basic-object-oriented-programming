# Seminar about template meta programming in C++

This is the markdown version of the seminar about template meta programming in C++. For the full version, please visit the [latex version](latex/README.md).

## Abstract

**Metaprogramming** là cách viết mã nguồn bằng cách xây dựng các
**template**. Từ các **template** được quy định trình biên dịch sẽ xem
cách thức gọi các **template** và sinh ra mã nguồn thực dựa trên quy
trình gọi và quá trình thực thi. **Metaprogramming** được sử dụng để
nâng cao hiệu suất bằng cách thực hiện tối ưu hóa **run-time** bằng cách
đưa các tác vụ có thể tính toán tại **compile-time** và lưu trữ, chẳng
hạn như làm việc gì đó một lần tại **compile-time** thay vì mỗi khi
chương trình được chạy - ví dụ, bằng cách yêu cầu trình biên dịch bỏ các
vòng lặp để loại bỏ các bước và giảm số vòng lặp bất cứ khi nào chương
trình được thực thi.

Phần báo cáo được chia ra làm **5 mục chính**, bao gồm giới thiệu cú
pháp và nền tảng cơ bản với **template**, kế đến sẽ đi vào các khái niệm
và nguyên tắc về thiết kế, cụ thể là sự linh động của **tính đa hình**
được trong việc thiết kế các thư viện. Tiếp tục thảo luận sâu hơn về các
nguyên tắc và tính rành mạch của ta sẽ đi sâu hơn vào khái niệm
**concept**. Cuối cùng là thực nghiệm với các ví dụ và đưa ra các nhận
định, thảo luận sau quá trình nghiên cứu về **metaprogramming**.


## Metafunctions and templates


Trong mục này, ta sẽ thảo luận về các khái niệm cơ bản thông qua từng ví
dụ. Mở đầu là ví dụ cơ bản về **metafunction**. Tiếp đến là về
**specialization** được sử dụng cho các trường hợp cụ thể hoá đầu vào.
Sau đó sẽ là về các thao tác và ngữ cảnh cơ bản với **template** thông
qua tham số là kiểu dữ liệu.

Khởi đầu
--------

``` {#code:abs .c++ caption="Ví dụ cho hàm trị tuyệt đối \cite{Walter}" label="code:abs" language="C++"}
template <int N>
struct abs {
    static_assert(N != INT_MIN); // There is no opposite number of the smallest int
    static constexpr auto value = (N > 0) ? N : -N;
}
// ...
int const n = -15;
std::cout << (abs<n>::value) << std::endl;
```

Khi làm việc với compile-time, chúng ta sẽ không thể can thiệp vào các
ảnh hưởng trong lúc run-time, và chính vì thế chỉ có thể làm việc với
các biến số ta biết được tại thời điểm compile. **Đoạn mã
[\[code:abs\]](#code:abs){reference-type="ref" reference="code:abs"}**
cho thấy có thể gọi **abs\<-3\>**, hay tổng quát hơn có thể gọi
**abs\<n\>** với $n$ là hằng số. Đó là bởi vì trình biên dịch biết được
$n$ tại thời điểm biên dịch. Tóm tắt, **templates** được sử dụng để sinh
ra code tại thời điểm biên dịch, **sử dụng các thông tin mà trình biên
dịch biết được tại compile-time.**

**abs** là một **template struct**. Được gán giá trị như là một là một
thuộc tính **static** có thể gọi giá trị mà không cần khởi tạo thực thể
**abs** (như thể đang làm việc với **namespace**). Phương thức cài đặt
trên được gọi là một **metafunction**.

Specialization {#sec:specialization}
--------------

Đối với trường hợp các hàm lặp, hay chúng ta muốn chỉ định cụ thể hoá
đầu vào như một chữ ký hàm, ta có thể sử dụng kĩ thuật
**specialization**. Ở ví dụ mã nguồn
[\[code:gcd\]](#code:gcd){reference-type="ref" reference="code:gcd"},
tìm ước chung lớn nhất cho hai hằng số biết trước ở thời điểm biên dịch.
Điểm đặc biệt có thể thấy ở đây chính là quá trình đệ quy này sẽ kết
thúc khi **N=0**. Chính vì thế. Cụ thể hoá trường hợp này như hàm
**gcd\<M,0\>**, đây gọi là kĩ thuật **partial specialization**.

``` {#code:gcd .c++ caption="Ví dụ cho hàm đệ quy \cite{Walter}" label="code:gcd" language="C++"}
template <unsigned M, unsigned N> 
struct gcd {
    static constexpr auto value = gcd<N, M%N>::value;
}

template <unsigned M>
// partial specialization
struct gcd<M,0> { 
    static_assert(M != 0);
    static constexpr auto value = M;
}
```

Template với tham số là kiểu dữ liệu
------------------------------------

Tuy nhiên trong hầu hết các trường hợp, **template** trong C++ được biết
đến nhiều hơn với cách sử dụng với tham số đầu vào là kiểu dữ liệu. Khác
với các ví dụ trên, **templates** nhận vào là các giá trị được biết đến
trong compile-time. Ở đây có thể gọi một hàm nhưng hoạt động với nhiều
kiểu dữ liệu khác nhau, như **int** hay **double** đều hoạt động một
cách tương tự.

``` {#code:rank .c++ caption="Đếm số chiều của một array-type \cite{Walter}" label="code:rank" language="C++"}
template <class T>
// general (meta)function for all type T
struct rank { static constexpr size_t value = 0; } 

template <class T, size_t N>
// partial spec for array type, T[N] has at least one dimension [N]
struct rank <T[N]> { 
    // removed dimension [N], the remaining is T
    static constexpr size_t value = 1 + rank<T>::value; 
}
```

Ví dụ [\[code:rank\]](#code:rank){reference-type="ref"
reference="code:rank"} cho ta thấy được cú pháp khi truyền vào template
một loại dữ liệu dạng mảng nhiều chiều và tính toán số chiều của chúng.
Còn về mặt tính toán, hàm sẽ trả về 0 nếu không phải là loại dữ liệu
dạng mảng, ngược lại sẽ trả về kết quả là **1 + số chiều còn lại sau khi
giảm 1 chiều**. Khi viết **template** nhận vào là kiểu dữ liệu, có thể
viết là **class T** hoặc **typename T**, không khác biệt. Tuy nhiên
**typename** sử dụng trong một ngữ cảnh khác.

Template trả về kiểu dữ liệu
----------------------------

Ngoài việc sử dụng kiểu dữ liệu như tham số đầu vào, **metafunction**
còn có thể trả về kết quả là một kiểu dữ liệu. Ở ví dụ
[\[code:rmconst\]](#code:rmconst){reference-type="ref"
reference="code:rmconst"}, mục tiêu của hàm là trả về kiểu dữ liệu không
còn là hằng số, ví dụ như đầu vào là **const int**, hàm sẽ trả về
**int**. Ta có thể thấy **remove** ở đây chính là **trả về một kiểu dữ
liệu tương đồng với dữ liệu đầu vào** và không phải **const**.

``` {#code:rmconst .c++ caption="Xoá const của một kiểu dữ liệu \cite{Walter}" label="code:rmconst" language="C++"}
template <class T>
// generally, just throw back whatever type the user gave you....
struct remove_const { using type = T; } 

template <class T>
// ... but if the user gave something has const with it, 
// return them the same thing but without const
struct remove_const<T const> { using type = T; } 
typename remove_const<T>::type var1; 
typename remove_const_t<T> var2; // C++14 equivalent
```

Ví dụ [\[code:rmconst\]](#code:rmconst){reference-type="ref"
reference="code:rmconst"} hoạt động bằng cách sử dụng một trường hợp
tổng quát và **specialize** trường hợp đầu vào là kiểu dữ liệu **const**
để xử lý. Quy ước thường được dùng khi **metafunction** trả về một kiểu
dữ liệu có **typename** bên trong đại diện cho tên kiểu dữ liệu sẽ được
đặt tên là **type**. Khai báo một biến bắt đầu bằng **typename**, lúc
này **typename** có thể coi là kiểu dữ liệu. Để truy cập **typename**
được trả về, ta có thể sử dụng cú pháp **remove\_const\<T\>::type** hoặc
hậu tố **\_t** như trên ví dụ.

``` {#code:if .c++ caption="Trả về kiểu dữ liệu dựa trên điều kiện \cite{Walter}" label="code:if" language="C++"}
template <class T>
struct type_is { using type = T; }

template <bool, class T, class> // unnamed params as place holders
struct IF : type_is<T> { }; // general

template <class T, class F>
struct IF<false, T, F> : type_is<F> { }; // partial specialization
```

Ví dụ ([\[code:if\]](#code:if){reference-type="ref"
reference="code:if"}) về **metafunction** sử dụng các kĩ thuật trên để
trả về đầu tiên nếu giá trị **boolean** là true, ngược lại trả về tên
kiểu thứ hai.

Variadic template
-----------------

Trong lập trình template, **variadic template** là kỹ thuật sử dụng
template có số lượng tham số không cố định[@Variadic]. Đặc trưng của kỹ
thuật này là sử dụng toán tử \"...\" để thể hiện chiều dài không xác
định của danh sách tham số (gọi là **parameter pack**). Các parameter
pack có thể được mở rộng thông qua việc xử lí lần lượt các argument và
giảm số lượng argument ở mỗi lần gọi đệ quy, cho đến khi gặp
**specialization** trùng khớp nhất. Khi lập trình meta bằng template,
variadic template đóng vai trò đóng gói các danh sách kiểu dữ liệu
(**typelist**), nhờ đó ta có thể truy xuất từng kiểu dữ liệu theo độ dài
của typelist bằng việc gọi đệ quy, điều này giúp tính toán trên kiểu dữ
liệu dễ dàng hơn.

Ta xem xét ví dụ về việc sử dụng variadic template để cài đặt phương
thức **is\_one\_of** của thư viện **type\_traits**. Phương thức này kiểm
tra xem một kiểu **T** có thuộc danh sách kiểu hay không.

``` {#code:variadic .c++ caption="Ví dụ variadic template \cite{Walter}" label="code:variadic" language="C++"}
template <class T, class... P0toN>
struct is_one_of;

template <class T>
struct is_one_of<T> : false_type{};

template <class T, class... P1toN>
struct is_one_of<T, T, P1toN...> : true_type {};

template <class T, class P0, class... P1toN>
struct is_one_of<T, P0, P1toN...> : is_one_of<T, P1toN...> {};
```

Đầu tiên, ta khai báo interface của **metafunction is\_one\_of**. Sau
đó, lần lượt cài đặt các **specialization của template với các danh sách
tham số khác nhau**. Hai trường hợp cơ sở bao gồm trường hợp **T đứng
đầu typelist P0toN**, và trường hợp **typelist không còn kiểu nào** (tức
là đã duyệt hết danh sách), ta lần lượt trả về **true\_type** và
**false\_type**. Còn ở trường hợp cuối, ta thấy **P0** được tách ra từ
**P0toN**, và với việc gọi đệ quy, P1, P2, ...cũng sẽ dần được bóc tách
ra khỏi typelist cho đến khi specialization template được gọi và trả về
**true\_type/false\_type**.

## Polymorphism

Tính đa hình động
-----------------

Tiếp cận đến các kĩ thuật thiết kế thì tính đa hình là một trong các chủ
đề ứng dụng cao. Cụ thể có nhiều loại đa hình nhưng trong phần này sẽ
tập trung vào mô tả tính đa hình trên góc nhìn hướng đối tượng (OOP) dựa
trên **virtual function** (hay có thể coi là tính **đa hình
run-time**[@poly-cpp]) và so sánh với **tính đa hình
compile-time**[@poly-cpp] dựa trên template.

Tính đa hình động, hoạt động lúc run-time (thời điểm chạy chương trình).
Nó hoạt động dựa trên hướng đối tượng và cho phép chúng ta phân tách
giữa interface để giao tiếp và việc thực hiện phân cấp lớp kế thừa, từ
đó có thể tác động những thay đổi đến cách hoạt động trong lúc run-time.

``` {#code:dynamic .c++ caption="Dynamic polymophism \cite{poly}" label="code:dynamic" language="C++"}
#include <chrono>
#include <iostream>

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

struct MessageSeverity{                         
    virtual void writeMessage() const {         
        std::cerr << "unexpected" << '\n';
    }
};

struct MessageInformation: MessageSeverity{     
    void writeMessage() const override {        
        std::cerr << "information" << '\n';
    }
};

struct MessageWarning: MessageSeverity{         
    void writeMessage() const override {        
        std::cerr << "warning" << '\n';
    }
};

struct MessageFatal: MessageSeverity{};

void writeMessageReference(const MessageSeverity& messServer){   // (1)
    
    writeElapsedTime();
    messServer.writeMessage();
    
}

void writeMessagePointer(const MessageSeverity* messServer){    // (2)
    
    writeElapsedTime();
    messServer->writeMessage();
    
}

int main(){

    std::cout << '\n';
  
    MessageInformation messInfo;
    MessageWarning messWarn;
    MessageFatal messFatal;
  
    MessageSeverity& messRef1 = messInfo;        // (3)      
    MessageSeverity& messRef2 = messWarn;        // (4)
    MessageSeverity& messRef3 = messFatal;       // (5)
  
    writeMessageReference(messRef1);              
    writeMessageReference(messRef2);
    writeMessageReference(messRef3);
  
    std::cerr << '\n';
  
    MessageSeverity* messPoin1 = new MessageInformation;   // (6)
    MessageSeverity* messPoin2 = new MessageWarning;       // (7)
    MessageSeverity* messPoin3 = new MessageFatal;         // (8)
  
    writeMessagePointer(messPoin1);               
    writeMessagePointer(messPoin2);
    writeMessagePointer(messPoin3);
  
    std::cout << '\n';

}
```

Ví dụ [\[code:dynamic\]](#code:dynamic){reference-type="ref"
reference="code:dynamic"} trên ta thấy **MessageSeverity** là một kiểu
dữ liệu **static** đại diện cho interface để giao tiếp của các lớp kế
thừa, kiểu **dynamic MessageInformation** để kế thừa và thực hiện nó.
Kiểu static được sử dụng tại compile-time và kiểu dynamic tại run-time.
Tại thời điểm chạy, **messPoint1** có kiểu **MessageInformation**; do
đó, hàm ảo **writeMessage** của **MessageInformation** được gọi, đây gọi
là **dynamic dispatch**. Một lần nữa, **dynamic dispatch** yêu cầu một
thực thể gián tiếp như một con trỏ làm tham chiếu hoặc có thể sử dụng
một hàm ảo. **writeMessagePointer** yêu cầu mỗi đối tượng đầu vào phải
là kế thừa từ **MessageSeverity**. Nếu vi phạm điều này thì trình biên
dịch sẽ báo lỗi.

***Dynamic dispatch** là thuật ngữ để chỉ việc chương trình cần chọn
cách cài đặt nào để định nghĩa phương thức đa hình (được kế thừa) để gọi
tại run-time.* Loại đa hình này là một thiết kế **contract-driven**
[@poly]. Hàm

Tính đa hình tĩnh và giới thiệu bài toán *duck-typing*
------------------------------------------------------

Trái ngược với thiết kế theo **contract-driven**, thiết kế sử dụng
**template** thích hợp với thiết kế **behavioral-driven** [@poly] với
tính đa hình tĩnh.

Ở hướng tiếp cận này, cách thiết kế sẽ quan tâm đến **behavior** hơn là
**interface**, hay nôm na là quy định giữa các đối tượng, ý tưởng này
còn gọi là **duck-typing**[@duck-type].

**"When I see a bird that walks like a duck and swims like a duck and
quacks like a duck, I call that bird a duck."** - Trích **James Whitcomb
Rileys**[@duck-test].

``` {#code:static .c++ caption="Dynamic polymophism \cite{poly}" label="code:static" language="C++"}
// duckTyping.cpp

#include <chrono>
#include <iostream>

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

struct MessageSeverity{
  void writeMessage() const {
      std::cerr << "unexpected" << '\n';
  }
};

struct MessageInformation {
  void writeMessage() const {              
    std::cerr << "information" << '\n';
  }
};

struct MessageWarning {
  void writeMessage() const {               
    std::cerr << "warning" << '\n';
  }
};

struct MessageFatal: MessageSeverity{};     

template <typename T>
void writeMessage(T& messServer){    // (1)                   
    
    writeElapsedTime();                                   
    messServer.writeMessage();                            
    
}

int main(){

    std::cout << '\n';
  
    MessageInformation messInfo;
    writeMessage(messInfo);
    
    MessageWarning messWarn;
    writeMessage(messWarn);

    MessageFatal messFatal;
    writeMessage(messFatal);
  
    std::cout << '\n';

}
```

Điều này tương tự với ví dụ
[\[code:static\]](#code:static){reference-type="ref"
reference="code:static"}, hàm **acceptOnlyDucks** chỉ chấp nhận đối
tượng vịt làm tham số. Trong các ngôn ngữ như C ++, tất cả các kiểu bắt
nguồn từ vịt đều có thể được sử dụng để gọi hàm. Tuy nhiên với thiết kế
**behavioral-driven** tất cả các kiểu, hoạt động giống như con vịt, đều
có thể được sử dụng để gọi hàm. Để làm cho nó cụ thể hơn: nếu một con
chim hành xử như một con vịt, nó là một con vịt.

Trong trường hợp đang xem xét, nếu ta gọi hàm **acceptsOnlyDucks** với
biến số là một con chim và mong đợi kết quả trả về không có bất kì lỗi
nào cả, nếu có chúng ta sẽ coi nó là các ngoại lệ với **exception
clause**. Một cách cơ bản thì chiến lược này được sử dụng trong Python.
Và để làm điều này, **template** là một công cụ không thể thiếu trong
**C++**. Trở về ví dụ trước đó, ta sẽ sử dụng **duck-typing**.

Hàm **writeMessage** áp dụng kiểu duck-typing. Hàm **writeMessage** giả
định rằng tất cả các đối tượng messServer hỗ trợ phương thức
**writeMessage**. Nếu không, quá trình biên dịch sẽ không thành công. Sự
khác biệt chính đối với Python là lỗi xảy ra trong C ++ tại thời điểm
biên dịch, nhưng trong Python tại thời điểm chạy.

Hàm **writeMessage** hoạt động đa hình, nhưng không an toàn về kiểu dữ
liệu cũng như không ghi thông báo lỗi có thể đọc được trong trường hợp
có lỗi


## Concept 

Định nghĩa và khái niệm
-----------------------

Lập trình với template cho phép định nghĩa hàm và lớp với nhiều loại
kiểu dữ liệu. Do đó, trường hợp khai báo hay sử dụng một template với
kiểu dữ liệu sai có thể dẫn đến kết quả lỗi tiềm ẩn do đối tượng hay
kiểu dữ liệu không thoả mãn các yêu cầu hay ràng buộc của template. Một
trong các khái niệm được đưa ra để giải quyết vấn đề trên là
**concepts**. Có thể hiểu khái niệm này như một nó chỉ là một cái
template parameter, lúc này trình biên dịch có thể kiểm tra các tham số
đầu vào. Các lợi ích khi sử dụng concepts bao gồm.

-   Khi sử dụng concepts, parameter-pack của template lúc này có thể
    ngầm hiểu là interface của đối tượng (tính đa hình tĩnh đã đề cập ở
    mục trên).

-   Overloading hay specializing có thể được viết dựa trên các concepts.

-   Lúc này các lỗi tiềm ẩn sẽ được chuyển thành các lỗi tường minh khi
    chúng ta kiểm tra kiểu dữ liệu đầu vào so với mẫu được quy định.

định nghĩa và sử dụng một concepts, cú pháp đơn giản sẽ là

``` {#code:syntax .c++ caption="Cú pháp concept \cite{concept-def}" label="code:syntax" language="C++"}
template <template-parameter-list>
concept concept-name = constraint-expression;
```

Về cơ bản **concept**[@concept-cpp] có thể coi là một **metafunction**
để kiểm tra điều kiện, đầu vào là danh sách các tham số đầu vào.
**concept** sẽ là một biểu thức ràng buộc để định nghĩa concept đó.
Thường thì ràng buộc này sẽ là một **predicate** trả về giá trị **true**
hoặc **false**. Có hai cách để viết biểu thức này, một là sử dụng các
kết hợp của phép logic sẽ được giới thiệu ở phần này, hai là sử dụng
**requires expression** sẽ được giới thiệu ở mục
[1.2](#sec:require_expr){reference-type="ref"
reference="sec:require_expr"}

***Predicate***[@predicate] *là một hàm trả về giá trị boolean hoặc một
đối tượng có phương thức **bool operator()**. Thường sẽ là câu trả lời
nhanh cho các tham số đầu vào, ví dụ dễ hiểu có thể nhắc đến các phương
thức **predicate** mặc định được cài đặt trong thư viện [STL
algorithms](http://en.cppreference.com/w/cpp/algorithm) như là lớn hơn
hay bé hơn. Tuy nhiên chỉ dùng cho việc hình dung một cách gần gũi, ở
ngữ cảnh hiện tại chỉ hỗ trợ các **compile-time predicate***.

``` {#code:integral .c++ caption="Integral concept\cite{concept-def}" label="code:integral" language="C++"}
template <typename T>
concept Integral = std::is_integral<T>::value;

Integral auto gcd(Integral auto a, Integral auto b) {
    if( b == 0 ) return a;
    else return gcd(b, a % b);
}    
```

Ví dụ [\[code:integral\]](#code:integral){reference-type="ref"
reference="code:integral"} mô tả cách hoạt động của concept một cách đơn
giản. Ở ví dụ trên, **concept Integral** được định nghĩa bằng một điều
kiện chính là **std::is\_integral\<T\>::value** phải là **true**, tức là
tham số là kiểu số nguyên bao gồm **int, long long, \...**. Ngược lại
trình biên dịch sẽ báo lỗi.

``` {#code:logic .c++ caption="Combine logic concept\cite{concept-def}" label="code:logic" language="C++"}
template <typename T>         
concept Integral = std::is_integral<T>::value;

template <typename T>          
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template <typename T>           
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;
```

Ví dụ [\[code:logic\]](#code:logic){reference-type="ref"
reference="code:logic"} sử dụng các **predicates** có sẵn của thư viện
[type\_traits](https://en.cppreference.com/w/cpp/header/type_traits), hỗ
trợ các predicate tại compile-time, từ đó xây dựng các concept
*Integral, SignedIntegral, UnsignedIntegral* bằng cách sử dụng
**expression** được kết hợp bằng các kiểu thức logic $(\&\&,||,!)$

Sử dụng concepts với từ khoá requires {#sec:require_expr}
-------------------------------------

Ở phần này, ta sẽ tập trung mô tả về cách sử dụng **requires**, hay còn
gọi là cách để viết các biểu thức requires, từ đó ta có thể định nghĩa
các concepts cụ thể và chi tiết hơn. Để định nghĩa cụ thể và rõ ràng
requires hơn, các khái niệm simple, type, compound, hay nested
requirements được đề xuất. Cấu trúc của biểu thức như sau:

``` {#code:require_syntx .c++ caption="Cú pháp của requires\cite{concept-req}" label="code:require_syntx" language="C++"}
requires (parameter-list(optional)) {requirement-seq}
```

Trong đó, **parameter-list** là danh sách các tham số được phân tách bởi
dấu **,** và **requirement-seq** là một chuỗi các requires. Việc sử dụng
requrires có thể kế thừa các concept đã được định nghĩa trước đó. Ví dụ
như

``` {#code:integral2 .c++ caption="Integral concept sử dụng requires\cite{concept-req}" label="code:integral2" language="C++"}
template<typename T>                                  
requires Integral<T>
T gcd(T a, T b) {
    if( b == 0 ) return a;
    else return gcd(b, a % b);
}
```

``` {#code:smpl_requr .c++ caption="Simple requires\cite{concept-req}" label="code:smpl_requr" language="C++"}
template<typename T>
concept Addable = requires (T a, T b) {
    a + b;
};
```

Ví dụ [\[code:smpl\_requr\]](#code:smpl_requr){reference-type="ref"
reference="code:smpl_requr"}, điều kiện định nghĩa concept Addable là
các tham số đầu vào chung một kiểu dữ liệu, và ở kiểu dữ liệu này cần hỗ
trợ phương thức **+**.

``` {#code:type_requr .c++ caption="Type requires\cite{concept-req}" label="code:type_requr" language="C++"}
template<typename T>
concept TypeRequirement = requires {
    typename T::value_type;
    typename Other<T>;    
};
```

Ở ví dụ [\[code:type\_requr\]](#code:type_requr){reference-type="ref"
reference="code:type_requr"}, ta sử dụng từ khoá **typename** để xem xét
T có phải là đối tượng thoả mãn với các thành phần cần có hay không,
trong trường hợp này ta xét qua **value\_type**. Ở đây **typename
Other\<T\>** dùng để kiểm tra xem có thể khởi tạo được đối tượng **T**
và trả về một typename hợp lệ hay không.

``` {#code:compound_requr .c++ caption="Compound requires\cite{concept-req}" label="code:compound_requr" language="C++"}
template<typename T>                                     
concept Equal = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};
```

Về cơ bản, một compound requirement yêu cầu về định dạng dữ liệu trả về.
Yêu cầu ở ví dụ
[\[code:compound\_requr\]](#code:compound_requr){reference-type="ref"
reference="code:compound_requr"} kết quả trả về cần có thể chuyển thành
định dạng boolean để không xảy ra lỗi

``` {#code:nested_requr .c++ caption="Nested requires\cite{concept-req}" label="code:nested_requr" language="C++"}
// template <typename T>                               // (1)
// concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

template <typename T>                                  // (2)
concept UnsignedIntegral = Integral<T> &&
requires(T) {
    requires !SignedIntegral<T>;
};
```

Một nested requirement là các yêu cầu lồng ghép với nhau, ví dụ
[\[code:nested\_requr\]](#code:nested_requr){reference-type="ref"
reference="code:nested_requr"} là một cách viết khác của ví dụ
[\[code:logic\]](#code:logic){reference-type="ref"
reference="code:logic"}, đoạn mã nguồn chú thích dòng (1), và thay đổi
bằng các đoạn mã ở dòng (2). Nested requires thường được sử dụng trong
các trường hợp không tồn tại các concept cần thiết cho biểu thức trước
đó.

Trở lại với ví dụ *duck-typing*
-------------------------------

Ở ví dụ [\[code:static\]](#code:static){reference-type="ref"
reference="code:static"}, hàm **writeMessage** hoạt động đa hình, nhưng
không an toàn vì không có kiểm tra kiểu dữ liệu (type-check), song tiêu
chí của **Metaprograming** là chương trình có thể tự kiểm tra lỗi trong
compile-time. Và với C++ 20 bằng cách sử dụng **concepts** để định nghĩa
và sử dụng khái niệm **MessageServer** (Dòng (1))

Khái niệm MessageServer yêu cầu một đối tượng **t** kiểu **T** phải hỗ
trợ phương thức **t.writeMessage**. Dòng (2) áp dụng **concept** trong
**template writeMessage**

``` {#code:concept .c++ caption="Concept trong Duck-typing" label="code:concept" language="C++"}
// duckTypingWithConcept.cpp

#include <chrono>
#include <iostream>

template <typename T>   // (1)
concept MessageServer = requires(T t) {
    t.writeMessage();
};

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

struct MessageSeverity{
  void writeMessage() const {
      std::cerr << "unexpected" << '\n';
  }
};

struct MessageInformation {
  void writeMessage() const {              
    std::cerr << "information" << '\n';
  }
};

struct MessageWarning {
  void writeMessage() const {               
    std::cerr << "warning" << '\n';
  }
};

struct MessageFatal: MessageSeverity{};     

template <MessageServer T>   // (2)
void writeMessage(T& messServer){                       
    
    writeElapsedTime();                                   
    messServer.writeMessage();                            
    
}

int main(){

    std::cout << '\n';
  
    MessageInformation messInfo;
    writeMessage(messInfo);
    
    MessageWarning messWarn;
    writeMessage(messWarn);

    MessageFatal messFatal;
    writeMessage(messFatal);
  
    std::cout << '\n';

}
 
```

## Conclusion

So sánh ưu nhược điểm
---------------------

Xét về **ưu điểm**, sử dụng **template metaprograming** sẽ nâng cao tính
tổng quát của chương trình bằng việc chỉ tập trung vào kiến trúc, và đẩy
việc cài đặt các hàm cụ thể cho trình biên dịch khi người dùng yêu cầu.
Nhờ đó có thể giảm kích thước mã và dễ bảo trì hơn. Ngoài ra việc mở
rộng chương trình và **tránh sự trùng lặp mã nguồn** cũng được cải thiện
đáng kể. Việc sử dụng type-checking, type-safe giúp chúng ta kiểm soát
được lỗi, **giảm thiểu lỗi do chương trình có thể tự đánh giá trong
compile-time**. Tiếp đến **hiệu suất, thời gian chạy cũng được nâng
cao** bằng việc tính toán hỗ trợ trong compile-time. Các thư viện lập
trình theo **function-oriented** như **Boost** đã được công nhận và sử
dụng rộng rãi vì tốc độ thực thi nhanh và tính linh động của nó.

Tuy vậy, không thể phủ nhận việc sử dụng **template metaprograming** đi
ngược lại với tính cách hay hướng viết mã nguồn kỉ luật của nhiều lập
trình viên vì sự **khó đọc**. Mã nguồn của một chương trình sử dụng hoàn
toàn template metaprograming rất **cồng kềnh** và cần phải biết được các
ngữ cảnh hay các thiết kế phổ biến để có thể sử dụng. Các đối tượng được
xem xét trong template metaprograming là **immutable**, vì vậy thiết kế
giải pháp cho những tác vụ đơn giản như trong hướng đối tượng sẽ **khó
hơn gấp nhiều lần** trong template meta programming, có thể kể đến như
chuyển từ lập trình tuần tự sang lập trình đệ quy. Ngoài ra nếu không
tuân thủ các quy định đóng góp mã nguồn, template meta programing sẽ
thông **báo lỗi khó hiểu để có thể kiểm soát về các kiểu dữ liệu**. Hơn
nữa với các trình biên dịch lỗi thời, các cú pháp trong trường phái này
có thể **không tương thích với nhiều trình biên dịch**.

Tóm tắt và thảo luận
--------------------

**Tổng kết**, qua quá trình nghiên cứu, nhóm đã tìm hiểu về công dụng
của Metaprograming sử dụng **Template trong C++** và các ý tưởng sơ
khai. Trọng điểm nhất là việc tham số hoá kiểu dữ liệu và các nguyên tắc
thiết kế. Nhóm đã đưa ra các ví dụ, triển khai và phát triển. Các thực
nghiệm và dẫn chứng thiết thực về tốc độ và hiệu năng cũng được khảo sát
và trình bày.

Song vẫn còn nhiều vấn đề tồn đọng và các trường hợp sử dụng kết hợp
linh hoạt các thành phần trong metaprograming chưa được đề cập đến. Hay
về các nội dung đề cập, nhóm chỉ tiến hành giới thiệu về **polymorphic
behavior** của templates chứ không đề cập về static polymorphism. Điều
này có thể đề cập đến **CRTP**. **CRTP** là viết tắt của **Curily
Recurring Template Pattern** và có nghĩa là một kỹ thuật trong C ++,
trong đó kế thừa một lớp **Derived** từ một lớp mẫu **Based** và
**Derived** sử dụng **Base** như một tham số mẫu.
