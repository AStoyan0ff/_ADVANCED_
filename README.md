<h1 align="center">
  C++ Advanced – Основни концепции:  
  <br>
  <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExbWFtdXd0ZjRsMmdnajdxN3UycjRuZmJ1Zmd4cnQ1cngxbGtwZWhubiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/xT9IgzoKnwFNmISR8I/giphy.gif"   
 width="100">
</h1>

📚 **C++ Advanced надгражда основите на езика, като въвежда концепции за обектно-ориентирано програмиране, управление на паметта, шаблони и стандартната библиотека (STL).**  

---

## 🔑 Основни теми в C++ Advanced:

---

### <span style="background:#0078d7; color:white; padding:4px 8px; border-radius:6px;">  1 Templates (Generic Programming)</span>

✔ Позволяват създаване на функции и класове, които работят с различни типове.

✔ Намаляват дублирането на код.

✔ Използват се за **STL контейнери** и алгоритми.  

✅ **Пример:**

```cpp
#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(5, 10) << endl;
    cout << add<double>(3.5, 4.2) << endl;
}
```

---

<span style="background:#0078d7; color:white; padding:4px 8px; border-radius:6px;">  2 STL (Standard Template Library)</span>

✔ Колекции като `vector`, `list`, `set`, `map`, `queue`, `stack`.

✔ Съдържа алгоритми за сортиране, търсене и трансформиране.

✔ Работи с итератори.

✅ Пример:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 9, 1};
    sort(nums.begin(), nums.end());
    
    for (int n : nums) {
        cout << n << " ";
    }
}
```

---

<span style="background:#0078d7; color:white; padding:4px 8px; border-radius:6px;">  3 Lambda Expressions & Functional Programming</span>

✔ Позволяват създаване на анонимни функции.

✔ Често използвани в алгоритми и callback функции.

✔ Поддържат capture на променливи.

✅ Пример:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4};
    for_each(nums.begin(), nums.end(), [](int n) {
        cout << n * n << " ";
    });
}
```

---

<span style="background:#0078d7; color:white; padding:4px 8px; border-radius:6px;">  4 Smart Pointers</span>

✔ Управляват динамична памет автоматично.

✔ Видове: `unique_ptr`, `shared_ptr`, `weak_ptr`.

✔ Предотвратяват memory leaks.

✅ Пример:

```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << *ptr << endl;
}
```

---

<span style="background:#0078d7; color:white; padding:4px 8px; border-radius:6px;">  5 Multithreading</span>  
 
✔ Използва `std::thread` за паралелно изпълнение.

✔ Синхронизация чрез `std::mutex` и `lock_guard.`

✔ Подобряване на производителността.

✅ Пример:

```cpp
#include <iostream>
#include <thread>
using namespace std;

void task() {
    cout << "Hello from thread!" << endl;
}

int main() {
    thread t(task);
    t.join();
}
```

---






 
