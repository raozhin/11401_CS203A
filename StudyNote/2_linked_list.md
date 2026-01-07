# 鏈結串列 (Linked List)

## 1. 核心定義與特性 (Definition & Characteristics)

鏈結串列 (Linked List) 是一種線性資料結構，由一系列的**節點 (Nodes)** 組成，這些節點在記憶體中**不必連續**存放 。

### 關鍵特性

* **非連續記憶體 (Non-contiguous Memory)**：與陣列不同，鏈結串列的節點散落在堆積 (Heap) 的不同位置，透過指標 (Pointer) 串連 。


* **動態大小 (Dynamic Size)**：不需要在建立時指定大小，可隨時新增或刪除節點，記憶體使用更有彈性 。


* **循序存取 (Sequential Access)**：不支援隨機存取 (Random Access)，若要存取第 $k$ 個元素，必須從頭開始遍歷 (Traverse) 。

## Visualization  

![linkedlist](./img/linkedlist.png)
---

## 2. 抽象資料型別 (ADT: Linked List)

鏈結串列定義了一組有序的元素集合，並支援以下操作 ：

* **Create()**: 初始化一個空的鏈結串列。
* **Insert(x, pos)**: 在指定位置或特定節點後方插入值 $x$ 。
* **Delete(pos)**: 移除指定位置的節點。
* **Search(x)**: 尋找包含值 $x$ 的節點。
* **Traverse()**: 從頭到尾走訪每一個節點 (通常用於列印或處理資料)。
* **Update(pos, x)**: 修改指定位置節點的值。

---

## 3. 資料結構與實作 (Data Structure & Implementation)

### 3.1 節點結構 (Node Structure)

每個節點包含兩個部分 ：

1. **資料欄位 (Data)**：儲存數值 (Value)。
2. **指標欄位 (Next Pointer)**：儲存下一個節點的記憶體位址 (Address)。

**C 語言定義 (Singly Linked List)**

```c
#include <stdio.h>
#include <stdlib.h>

// 定義節點結構
typedef struct Node {
    int data;           // 資料
    struct Node* next;  // 指向下一個節點的指標
} Node;

// 建立新節點的輔助函式
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

```

---

## 4. 鏈結串列的變形 (Variations)

| 類型 | 描述 | 特點 |
| --- | --- | --- |
| **單向鏈結串列 (Singly Linked List)** | 每個節點只有一個 `next` 指標。 | 最節省空間，但只能單向遍歷 。|
| **雙向鏈結串列 (Doubly Linked List)** | 每個節點有 `prev` (前一個) 與 `next` (下一個) 指標。 | 可雙向遍歷，刪除節點更方便 (因已知前驅節點)，但佔用更多記憶體 。|
| **環狀鏈結串列 (Circular Linked List)** | 尾節點 (Tail) 的 `next` 指向頭節點 (Head)。 | 適用於 Round-Robin 排程或循環播放清單 。|

---

## 5. 複雜度分析 (Complexity Analysis)

令  為節點總數。

| 操作 | 時間複雜度 (Time) | 說明 |
| --- | --- | --- |
| **Access (存取)** | $O(n)$ | 必須從 Head 開始循序走訪，無法像陣列用 Index 直接跳查 。|
| **Search (搜尋)** | $O(n)$ | 線性搜尋 (Linear Scan) 。|
| **Insert (頭部)** | $O(1)$ | 建立新節點，指向原 Head，更新 Head 指標即可 。|
| **Insert (已知節點後)** | $O(1)$ | 僅需修改指標連結 (Relink)，不需移動其他元素 。|
| **Insert (尾部)** | $O(1)$ / $O(n)$ | 若有維護 `tail` 指標為 $O(1)$，否則需遍歷至最後為 $O(n)$。|
| **Delete (頭部)** | $O(1)$ | 移動 Head 指標並釋放記憶體 。|
| **Delete (已知節點)** | $O(1)$ | (雙向鏈結串列) 修改前後節點指標即可 。|
| **Delete (指定值/位置)** |  $O(n)$ | 需先搜尋找到該節點的前一個節點 (Predecessor) 才能刪除 。|

**空間複雜度**:  (儲存  個節點)，額外開銷 (Overhead) 為每個節點的指標空間 。

---

## 6. 陣列 vs. 鏈結串列 (Comparison)

這是面試與考試最常見的比較題 。

| 特性 | 陣列 (Array) | 鏈結串列 (Linked List) |
| --- | --- | --- |
| **記憶體配置** | 連續 (Contiguous) | 非連續 (Non-contiguous) |
| **大小調整** | 固定 (Static) / 成本高 (Dynamic Array resize) | 動態 (Dynamic)，隨時可增減 |
| **隨機存取** | 支援 O(1)  | 不支援 O(n)  |
| **插入/刪除 (中間)** | 慢 O(n) (需搬移資料) | 快 O(1) (僅改指標，假設已在該位置) |
| **記憶體利用率** | 高 (無額外指標) | 較低 (需儲存指標 overhead) |
| **Cache 效能** | 佳 (Spatial Locality) | 差 (節點散落，易 Cache Miss) |

---

## 7. 進階實作：插入與刪除 (C Code Snippets)

### 7.1 在頭部插入 (Insert at Head) - $O(1)$ 

```c
void insertAtHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;  // 新節點指向原本的頭
    *head = newNode;        // 更新頭指標指向新節點
}

```

### 7.2 刪除特定值的節點 (Delete by Value) - $O(n)$

```c
void deleteNode(Node** head, int key) {
    Node *temp = *head, *prev = NULL;

    // Case 1: 刪除的是頭節點
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Case 2: 搜尋要刪除的節點，並紀錄前一個節點 (prev)
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 若找不到該值
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
}

```

---

## 8. 常見應用場景 (Applications)

1. **實作其他資料結構**：堆疊 (Stack)、佇列 (Queue)、圖的鄰接表 (Adjacency List) 。
2. **動態記憶體配置**：如 OS 的 free list 管理。
3. **不需要快速查詢，但需要頻繁增刪**的資料集合 (例如：Todo List, 播放清單) 。