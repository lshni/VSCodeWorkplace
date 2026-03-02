# 冒泡排序程序文档

## 概述
本项目包含一个简单的 C++ 实现，用于演示冒泡排序算法。算法封装在 `BubbleSorter` 类中，具有以下特点：

- 输入为一个整数数组（`std::vector<int>`）。
- 通过类的静态方法 `sort` 执行原地排序。
- 使用常见的冒泡排序机制，包含提前退出优化。

主程序自动生成 10 个随机整数，并调用 `BubbleSorter` 对它们进行排序，排序前后打印数组。

## 文件结构
```
Myfirst/
├── Makefile            # 生成可执行文件的规则
├── bubble_sort.cpp     # 冒泡排序实现与演示入口
├── binary_insertion_sort.cpp  # 之前的示例文件
├── sort               # 由 Makefile 生成的可执行文件
├── bubble_sort        # 冒泡排序可执行文件
└── doc/
    ├── vscode-code.md  # 其它文档
    └── bubble_sort.md  # 本文档
```

## 使用方法
1. **编译**
   ```sh
   make bubble_sort
   # 或者 make all
   ```

2. **运行**
   ```sh
   ./bubble_sort
   ```
   程序将输出原始数组和排序结果，例如：
   ```
   Original array:
   57 3 92 14 82 6 40 28 75 1 
   Sorted array:
   1 3 6 14 28 40 57 75 82 92 
   ```

## 代码说明
- `BubbleSorter` 类定义在 `bubble_sort.cpp`：
  ```cpp
  class BubbleSorter {
  public:
      static void sort(vector<int> &arr) {
          int n = arr.size();
          for (int i = 0; i < n - 1; ++i) {
              bool swapped = false;
              for (int j = 0; j < n - 1 - i; ++j) {
                  if (arr[j] > arr[j + 1]) {
                      swap(arr[j], arr[j + 1]);
                      swapped = true;
                  }
              }
              if (!swapped) break;
          }
      }
  };
  ```

- `main` 函数通过 `std::mt19937` 随机数生成器创建测试数据。

## 详细设计

### 类职责
- `BubbleSorter`
  - 提供一个 **静态方法** `sort`，接受对 `std::vector<int>` 的引用。
  - 负责对传入数据执行冒泡排序算法，原地修改数组。
  - 不持有状态，因此无需实例化。

### 算法流程
1. 计算数组大小 `n`。
2. 外层循环迭代 `i` 从 0 到 `n-2`：
   - 设置 `swapped=false` 以检测本轮是否发生交换。
   - 内层循环迭代 `j` 从 0 到 `n-2-i`：
     - 比较相邻元素 `arr[j]` 与 `arr[j+1]`。
     - 若顺序错误则交换并将 `swapped=true`。
   - 若一轮结束后 `swapped` 仍为 `false`，说明数组已排序，可提前退出。

### 复杂度分析
- **时间复杂度**
  - 最坏/平均情况：`O(n^2)`。
  - 最好情况（已排序）：`O(n)`，得益于提前退出优化。
- **空间复杂度**
  - `O(1)` 额外空间；排序在原数组上进行。

### 交互流程（main）
1. 使用 C++ 标准库随机数生成器初始化 10 个整数。
2. 显示生成的原始数组。
3. 调用 `BubbleSorter::sort`。
4. 输出排序后的结果。

### 错误处理
- 由于算法接收 `std::vector<int>&`，不存在越界问题。
- `main` 仅在生成数据阶段使用标准库；未加入异常捕获，但随机数生成异常极不可能。

### 可扩展性
- 将 `BubbleSorter` 模板化以处理任意可比较类型（`T`）。
- 提供重载版本支持传入迭代器范围。
- 添加日志/计数器以分析交换次数和比较次数等。

### 设计图 (伪代码)
```text
+----------------+
|   main()       |
+----------------+
        |
        v
+----------------+
| generate array |
+----------------+
        |
        v
+----------------+
| BubbleSorter   |
| ::sort(arr)    |
+----------------+
        |
        v
+----------------+
| sorted array   |
+----------------+
```

## 扩展建议
- 将排序类模板化以支持不同类型。
- 添加命令行参数用于指定数组大小或输入来源。
- 提供单元测试以验证算法正确性。

## 清理生成文件
```sh
make clean
```

---

文档由 GitHub Copilot 自动生成，适用于教育和演示用途。