# 資料結構學習筆記：陣列 (Array)

## 1. 核心定義與特性 (Definition & Characteristics)

陣列 (Array) 是一種將**相同資料型態 (Data Type)** 的元素，儲存在**連續記憶體空間 (Contiguous Memory)** 中的資料結構。

### 關鍵特性
* **隨機存取 (Random Access)**：透過索引 (Index) 可以直接計算出記憶體位址，存取時間複雜度為 $O(1)$。
* **固定大小 (對於靜態陣列)**：宣告時需決定大小，無法隨意擴充 (除非使用動態陣列) 。
* **快取友善 (Cache Friendly)**：由於記憶體連續，CPU 在讀取時能有效利用空間局部性 (Spatial Locality)，減少 Cache Miss。

---

## 2. 抽象資料型別 (ADT: Array)

陣列作為一個 ADT，定義了一組 `<index, value>` 的配對集合，並支援以下操作：

* **Create(n)**: 建立一個大小為 n 的陣列。
* **Retrieve/Access(A, i)**: 取得索引 i 的值，時間複雜度 $O(1)$。
* **Store/Update(A, i, x)**: 將索引 i 的值修改為 x，時間複雜度 $O(1)$。
* **Insert(A, i, x)**: 在索引 i 插入值 x，後續元素需向後移動，時間複雜度 $O(n)$。
* **Delete(A, i)**: 刪除索引 i 的值，後續元素需向前移動，時間複雜度 $O(n)$。
* **Search(A, x)**: 尋找值 x 所在的索引。

---

## 3. 記憶體配置與宣告 (Memory & Declaration)

陣列在記憶體中的表現形式取決於它是「靜態」還是「動態」。

### 3.1 靜態陣列 (Static Array)
記憶體配置在 **Stack** (堆疊) 上，大小在編譯時期 (Compile-time) 決定 。

**一維陣列 (1D Array)**
```c
int arr[5] = {10, 20, 30, 40, 50}; // 初始化
// 記憶體位址示意: 假設 arr[0] 在 0x1000, int 為 4 bytes
// arr[1] = 0x1004, arr[2] = 0x1008...

```

**多維陣列 (Multi-dimensional Array)** 
C 語言中的多維陣列是 **Row-Major (列優先)** 儲存。

```c
int matrix[3][4]; // 3列(rows) 4行(columns)
// 記憶體排列順序: row0 全部 -> row1 全部 -> row2 全部

```

> **記憶體位址計算公式**：
> 假設宣告 `Type A[R][C]`，起始位址為 `Base`，每個元素大小 `Size`。
> 欲存取 `A[i][j]` 的位址：
> 
> 

### 3.2 動態陣列 (Dynamic Array)

記憶體配置在 **Heap** (堆積) 上，大小可在執行時期 (Runtime) 決定，需手動管理記憶體 。

**宣告與操作 (C 語言範例)**

```c
// 1. 配置 (malloc)
int *arr;
int n = 10;
arr = (int *) malloc(n * sizeof(int));

// 2. 重新調整大小 (realloc)
// 當空間不足時，通常策略是將容量翻倍 (Double Capacity)
n = n * 2;
int *temp = (int *) realloc(arr, n * sizeof(int));
if (temp != NULL) {
    arr = temp;
} else {
    // 處理配置失敗
}

// 3. 釋放 (free) - 避免 Memory Leak
free(arr);

```


> 當擴充陣列時，如果原記憶體區塊後方有足夠空間，系統會直接延伸；若空間不足，系統會尋找一塊新的、更大的記憶體，將舊資料**複製**過去，並釋放舊空間。因此，**擴充後的陣列起始位址可能會改變** 。
> 
> 

---

## 4. 關鍵操作與演算法 (Operations & Algorithms)

### 4.1 插入與刪除 (Insertion & Deletion)

這是在陣列中成本最高的操作，因為需要「移動」元素以保持記憶體連續性 。

* **Insert at index **: 需要將  之後的所有元素向**後**移 (i -> i + 1)。最壞情況 $O(n)$。
* **Delete at index **: 需要將  之後的所有元素向**前**移 (i + 1 -> i)。最壞情況 $O(n)$。

4.2 搜尋 (Searching) 

* **線性搜尋 (Linear Search)**: 適用於未排序陣列。從頭走到尾。時間複雜度 $O(n)$。
* **二元搜尋 (Binary Search)**: 適用於**已排序**陣列。每次切一半查找。時間複雜度 $O(/log n)$ 。

4.3 排序 (Sorting) 

雖然現代語言多直接呼叫 `qsort` 或 `std::sort`，但理解基礎排序對陣列操作很有幫助：

1. **氣泡排序 (Bubble Sort)**: 兩兩比較交換，最大值浮到最後。$O(n^2)$
2. **選擇排序 (Selection Sort)**: 每一輪找出最小值，放到前面。$O(n^2)$。
3. **插入排序 (Insertion Sort)**: 像撲克牌理牌，將元素插入已排序區塊的正確位置。$O(n^2)$。

---

## 5. C++ STL 容器比較 (Modern C++)

在 C++ 開發中，通常不使用原始 C-Style 陣列，而使用 STL 容器 。

| 特性 | std::array (靜態) | std::vector (動態) | C-Style Array |
| --- | --- | --- | --- |
| **大小** | 編譯期固定 (Fixed) | 執行期可變 (Dynamic) | 固定 (Static) / 手動管理 (Malloc) |
| **記憶體位置** | Stack | Heap | Stack or Heap |
| **安全性** | 支援 `.at()` 邊界檢查 | 支援 `.at()` 邊界檢查 | 無檢查 (易 Buffer Overflow) |
| **傳遞方式** | Value 或 Reference | Value 或 Reference | Decay 成 Pointer (遺失長度資訊) |
| **常用函式** | `size()`, `begin()`, `end()` | `push_back()`, `resize()`, `capacity()` | 無 |

---

6. 複雜度分析總表 (Complexity Analysis) 

| 操作 | 時間複雜度 (Time) | 空間複雜度 (Space) | 備註 |
| --- | --- | --- | --- |
| **Access (讀取)** | $O(1)$ | - |  |
| **Update (修改)** | $O(1)$ | - |  |
| **Traversal (遍歷)** | $O(n)$ | - |  |
| **Insert (插入)** | $O(n)$ | $O(1)$ | 需搬移資料 |
| **Insert (結尾)** | Amortized  | - | 動態陣列容量足夠時 |
| **Delete (刪除)** | $O(n)$ | - | 需搬移資料 |
| **Search (未排序)** | $O(n)$ | - | 線性搜尋 |
| **Search (已排序)** | $O(log n)$ | - | 二元搜尋 |

---

