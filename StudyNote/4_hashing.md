# 雜湊表 (Hash Table)

## 1. 核心定義 (Definition)

雜湊表 (Hash Table) 是一種透過**雜湊函數 (Hash Function)** 將**鍵 (Key)** 映射到陣列**索引 (Index)** 的資料結構，用於實現高效的 `Key-Value` 存取 。

* **目的**：解決陣列需要連續記憶體且只能用整數索引的限制，提供類似陣列 $O(1)$ 的快速存取，但支援任意型態的 Key。
* **核心機制**：  $Index = Hash(Key) \pmod N$，其中 $N$ 為陣列大小。


---

## 2. 抽象資料型別 (ADT)

雜湊表支援以下主要操作 ：

* **Insert(key, value)**: 計算雜湊值，將 value 存入對應的 bucket。
* **Search/Get(key)**: 計算雜湊值，回傳對應的 value。
* **Delete(key)**: 計算雜湊值，移除對應的 entry。

---

## 3. 雜湊函數 (Hash Functions)

一個好的雜湊函數應具備以下特性 ：
1.  **快速計算**：計算過程不能太複雜。
2.  **均勻分佈 (Uniform Distribution)**：避免大量 Key 集中在同一個索引 (Clustering)，以減少碰撞。
3.  **確定性 (Deterministic)**：相同的 Key 必須永遠產生相同的雜湊值。

### 常見方法 (Supplement)
* **除法雜湊法 (Division Method)**: $h(k) = k \pmod m$ (通常取 $m$ 為質數以減少碰撞)。
* **乘法雜湊法 (Multiplication Method)**: 利用無理數小數部分打散分佈。
* **字串雜湊**: 如 DJB2, Polynomial Rolling Hash (將字串視為多項式)。

---

## 4. 碰撞處理 (Collision Resolution)

當兩個不同的 Key 被映射到同一個 Index 時 ( $Hash(k1) == Hash(k2)$)，稱為**碰撞 (Collision)** 。

### 4.1 鏈結法 (Separate Chaining)
每個 Bucket 實際上是一個指向**鏈結串列 (Linked List)** 的指標。當發生碰撞時，將新元素加到該 Bucket 的串列尾端 。

* **優點**：實作簡單，對 Load Factor 容忍度高 (可大於 1)。
* **缺點**：需要額外的指標空間，Cache 效能較差。



### 4.2 開放定址法 (Open Addressing)
所有元素都存在陣列中，不使用額外連結。當發生碰撞時，依照特定規則尋找下一個空位 。

1.  **線性探測 (Linear Probing)**: 檢查 $i+1, i+2, ...$
    * *缺點*：產生聚集 (Primary Clustering)。
2.  **二次探測 (Quadratic Probing)**: 檢查 $i+1^2, i-1^2, i+2^2, ...$
3.  **雙重雜湊 (Double Hashing)**: 使用第二個雜湊函數決定步伐， $i + 1 \times h_2(k), i + 2 \times h_2(k)...$

---

## 5. 複雜度分析 (Complexity Analysis)

令 $n$ 為元素數量，$m$ 為 Bucket 數量，負載因子 (Load Factor) $\alpha = n/m$ 。

| 操作 | 平均情況 (Expected) | 最壞情況 (Worst Case) | 說明 |
| :--- | :---: | :---: | :--- |
| **Search** | $O(1)$ | $O(n)$ | 最壞發生在所有 Key 都碰撞到同一 Bucket |
| **Insert** | $O(1)$ | $O(n)$ | 同上 |
| **Delete** | $O(1)$ | $O(n)$ | 同上 |

* **影響因素**：雜湊函數的品質、負載因子 $\alpha$ 的控制。當 $\alpha$ 過大時，需進行 **Rehashing** (擴大陣列並重新安置所有元素) 。

---

## 6. 優缺點比較 (Pros & Cons)

### 優點 (Pros) 
* **速度快**：平均 $O(1)$ 的查找速度，優於 BST 的 $O(\log n)$。
* **彈性鍵值**：Key 可以是字串、物件等任意型態。

### 缺點 (Cons) 
* **無序性**：資料在記憶體中是亂序存放，無法進行範圍查詢 (Range Query) 或排序輸出。
* **空間開銷**：為了維持低碰撞率，通常需要比實際資料量更大的陣列空間 (Load Factor < 0.7)。
* **最壞情況風險**：若 Hash Function 設計不良或遭受 Hash DoS 攻擊，效能會退化成 $O(n)$。

---

## 7. 實作補充 (C Code Snippet)

**鏈結法 (Chaining) 結構示意**
```c
struct Node {
    int key;
    int value;
    struct Node* next;
};

struct HashTable {
    int size;
    struct Node** buckets; // 指標陣列
};

int hash(int key, int size) {
    return key % size; // 簡單除法雜湊
}

void insert(struct HashTable* table, int key, int value) {
    int index = hash(key, table->size);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    // 頭插法 (Insert at Head)
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}
```
---

## 8. 應用場景 (Applications)
1.  **符號表 (Symbol Table) :** 編譯器用來儲存變數名稱與記憶體位址。
2.  **資料庫索引 (Database Indexing) :** 速查找紀錄 (Hash Index)。
3.  **快取 (Caching) :** 網頁快取、Memcached、Redis。
4.  **集合 (Set) 實作 :** 檢查元素是否存在 (如 Python 的 set 或 C++ std::unordered_set)。
