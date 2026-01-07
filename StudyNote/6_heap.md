# 堆積 (Heap)

## 1. 核心定義 (Definition)

堆積 (Heap) 是一種特殊的樹狀結構，必須同時滿足以下兩個條件 ：

1.  **結構特性 (Shape Property)**：必須是**完全二元樹 (Complete Binary Tree)**。
    * 除了最後一層外，每一層都是填滿的。
    * 最後一層的節點必須由左至右依序填入。
    ***優點**：可以有效率地使用**陣列 (Array)** 來儲存，不會有記憶體空洞 。
2.  **順序特性 (Heap-Order Property)**：父節點與子節點之間必須滿足特定的大小關係。
    * **最大堆積 (Max Heap)**：每個父節點的值都**大於或等於**其子節點的值 (Root 為最大值) 。
    * **最小堆積 (Min Heap)**：每個父節點的值都**小於或等於**其子節點的值 (Root 為最小值)。



---

## 2. 記憶體實作 (Array Representation)

由於堆積是完全二元樹，通常使用**陣列**來實作，而非指標，這樣能節省空間並提升 Cache 效能 。

假設 Root 位於陣列索引 `i = 0` (或是 1，視習慣而定，以下以 0 為例)：
* **Parent(i)** = `(i - 1) / 2`
* **Left Child(i)** = `2 * i + 1`
* **Right Child(i)** = `2 * i + 2`

這種索引算術讓我們能在 $O(1)$ 時間內找到任意節點的父子關係。



---

## 3. 關鍵操作 (Key Operations)

### 3.1 插入 (Insertion) - $O(\log n)$
將新元素加到堆積中，並保持堆積特性。
1.  **Add**: 將新元素放到陣列的**最後一個位置** (維持完全二元樹結構)。
2.  **Heapify Up (Bubble Up)**: 與父節點比較，若違反堆積順序 (例如在 Max Heap 中比爸爸大)，則交換。重複此步驟直到滿足條件或到達 Root。

### 3.2 移除根節點 (Extract Max/Min) - $O(\log n)$
移除堆積中的極值 (Root) 。
1.  **Replace**: 將陣列**最後一個元素**移到 Root 位置 (覆蓋掉要移除的值)。
2.  **Remove**: 將陣列長度減一。
3.  **Heapify Down (Bubble Down)**: 將新的 Root 與子節點比較。若違反順序，則與**較大/較小** (視 Max/Min Heap 而定) 的子節點交換。重複此步驟直到滿足條件或成為葉節點。

### 3.3 取得極值 (Peek) - $O(1)$
直接回傳陣列的第一個元素 (`array[0]`) 。

---

## 4. 堆積排序 (Heap Sort)

利用堆積特性進行排序的演算法，時間複雜度為 $O(n \log n)$，空間複雜度為 $O(1)$ (In-place) 。

**步驟**：
1.  **Build Heap**: 將輸入陣列轉換成 Max Heap (從最後一個非葉節點開始往前做 Heapify Down)。
2.  **Sort**:
    * 將 Root (最大值) 與陣列最後一個元素交換。
    * 將堆積大小減一 (排除已排序的最大值)。
    * 對新的 Root 執行 Heapify Down。
    * 重複上述步驟直到堆積為空。

---

## 5. 複雜度分析 (Complexity Analysis)

| 操作 | 時間複雜度 | 說明 |
| :--- | :---: | :--- |
| **Peek (Top)** | $O(1)$ | 直接讀取 `arr[0]` |
| **Insert** | $O(\log n)$ | 最壞情況需從底部浮動到根部 (樹高 $h = \log n$) |
| **Delete (Extract)** | $O(\log n)$ | 最壞情況需從根部下沉到葉子 |
| **Build Heap** | $O(n)$ | 透過 Bottom-up 方式建立堆積是線性的 (數學證明) |
| **Heap Sort** | $O(n \log n)$ | 執行 $n$ 次 Extract Max |

---

## 6. 優先佇列 (Priority Queue)

堆積是實作**優先佇列**最理想的資料結構 。
* **定義**：一種佇列，但元素出列的順序是根據**優先權 (Priority)** 而非進入順序 (FIFO)。
* **應用**：作業系統的任務排程 (Process Scheduling)、Dijkstra 最短路徑演算法 。

---

## 7. 實作範例 (C Code Snippet)

**Heapify Down (Max Heap) 實作**
```c
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // 如果左子節點比根大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子節點比目前最大值大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // 遞迴處理受影響的子樹
        heapify(arr, n, largest);
    }
}

```

---

## 8. 優缺點總結 (Pros & Cons)

### 優點

* **效率高**：隨時都能以  取得最大/最小值， 插入刪除。
* **空間節省**：不需要像 Linked List 儲存指標，陣列利用率高。

### 缺點

* **搜尋慢**：尋找任意值 (非 Root) 需要 ，因為堆積只保證父子關係，不保證左右兄弟關係。
* **非穩定排序**：Heap Sort 是 Unstable Sort。


