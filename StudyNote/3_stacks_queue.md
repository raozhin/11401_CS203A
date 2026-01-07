# 資料結構學習筆記：堆疊與佇列 (Stack & Queue)

## 1. 核心概念 (Concepts)

堆疊與佇列是用來**管理待處理狀態或是任務**的線性資料結構，它們的主要差異在於資料存取的順序。

| 特性 | 堆疊 (Stack) | 佇列 (Queue) |
| :--- | :--- | :--- |
| **原則** | **後進先出 (LIFO, Last-In-First-Out)** [cite: 60] | **先進先出 (FIFO, First-In-First-Out)** [cite: 69] |
| **比喻** | 疊盤子、電梯裡的人進出 | 排隊買票、印表機任務 |
| **操作端點** | 單一端點 (Top) 進行推入與彈出 | 兩端操作：一端進 (Rear)，一端出 (Front) |

---

## 2. 堆疊 (Stack)

### 2.1 定義與 ADT
堆疊是一種限制只能在同一端（稱為 **Top**）進行插入與刪除的線性串列。

**主要操作 (Operations)** :
* **Push(x)**: 將元素 $x$ 加到堆疊頂端。
* **Pop()**: 移除並回傳堆疊頂端的元素。
* **Peek() / Top()**: 查看堆疊頂端的元素但不移除。
* **IsEmpty()**: 檢查堆疊是否為空。
* **Size()**: 回傳堆疊中元素的數量。



### 2.2 實作方式 (Implementation)

#### A. 陣列實作 (Array-based)
使用一個變數 `top` 來記錄頂端元素的索引 。
* **Push**: `array[++top] = data` (需檢查是否滿溢 Stack Overflow)。
* **Pop**: `return array[top--]` (需檢查是否為空 Stack Underflow)。
* **優點**：簡單快速。
* **缺點**：大小固定 (除非使用動態陣列)。

#### B. 鏈結串列實作 (Linked List-based)
使用指標，通常將 Head 當作 Stack 的 Top 。
* **Push**: 建立新節點，指向原 Head，更新 Head。
* **Pop**: 移除 Head 節點，更新 Head 指向 next。
* **優點**：動態大小，不會溢位 (除非記憶體耗盡)。
* **缺點**：額外的指標記憶體開銷。

### 2.3 應用場景 (Applications)
1.  **函式呼叫管理 (Function Call Stack)**：儲存遞迴呼叫的返回位址與區域變數。
2.  **復原/重做 (Undo/Redo)**：編輯器中的操作紀錄。
3.  **括號匹配 (Parenthesis Matching)**：編譯器檢查程式碼語法。
4.  **表達式求值**：中序轉後序 (Infix to Postfix) 運算。
5.  **瀏覽器上一頁**：儲存歷史紀錄。

---

## 3. 佇列 (Queue)

### 3.1 定義與 ADT
佇列是一種限制在不同端點進行操作的線性串列，資料由 **Rear (尾端)** 進入，由 **Front (前端)** 移出。

**主要操作 (Operations)** :
* **Enqueue(x)**: 將元素 $x$ 加入佇列尾端。
* **Dequeue()**: 移除並回傳佇列前端的元素。
* **Front() / Peek()**: 查看佇列前端的元素。
* **IsEmpty()**: 檢查佇列是否為空。



### 3.2 實作方式 (Implementation)

#### A. 陣列實作 (Array-based)
維護 `front` 和 `rear` 兩個索引 。
* **問題**：隨著 `front` 和 `rear` 不斷後移，陣列前方的空間會無法被重複利用 (假溢位 False Overflow)。
* [cite_start]**解法**：**環狀佇列 (Circular Queue)**。利用模運算 `%` 讓索引回到 0 。
    * `rear = (rear + 1) % capacity`
    * `front = (front + 1) % capacity`

#### B. 鏈結串列實作 (Linked List-based)
維護 `head` (作為 Front) 和 `tail` (作為 Rear) 指標  。
* **Enqueue**: 加在 Tail 後面，更新 Tail。
* **Dequeue**: 移除 Head，更新 Head。

### 3.3 應用場景 (Applications) [cite: 213-219, 36]
1.  **任務排程 (Job Scheduling)**：CPU 排程、印表機列印佇列。
2.  **廣度優先搜尋 (BFS)**：圖形演算法中的節點遍歷順序。
3.  **緩衝區 (Buffers)**：鍵盤輸入緩衝、IO 串流資料處理。
4.  **請求處理**：網頁伺服器處理連線請求 (Request Queue)。

---

## 4. 複雜度分析 (Complexity Analysis)

無論是使用陣列 (Array) 還是鏈結串列 (Linked List) 實作，標準的堆疊與佇列操作都能達到 **$O(1)$** 的時間複雜度。

| 操作 | 時間複雜度 | 空間複雜度 | 備註 |
| :--- | :---: | :---: | :--- |
| **Push / Enqueue** | $O(1)$ | $O(n)$ | 陣列擴充時 Amortized $O(1)$ |
| **Pop / Dequeue** | $O(1)$ | $O(n)$ | |
| **Peek / Front** | $O(1)$ | $O(n)$ | |
| **Search** | $O(n)$ | - | 不是標準操作，需遍歷 |

---

## 5. 總結比較 (Summary)

| 特徵 | Stack (LIFO) | Queue (FIFO) |
| :--- | :--- | :--- |
| **加入元素** | Push (Top) | Enqueue (Rear) |
| **移除元素** | Pop (Top) | Dequeue (Front) |
| **主要用途** | 處理「最近」的任務、反轉順序、遞迴 | 處理「依序」的任務、緩衝、排程 |
| **實作關鍵** | 只需維護 Top 指標 | 需維護 Front 與 Rear 指標 (環狀需注意) |

```