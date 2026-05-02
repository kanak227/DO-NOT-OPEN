# Competitive Programming (CP) Guide

A well-organized collection of competitive programming templates, algorithms, and data structures for quick reference and implementation during contests.

## 📁 Directory Structure

### **Templates/**
Quick-start code templates for common setups:
- **FastIOTemplate.cpp** - Template with fast I/O optimization and common macros
- **SimpleTemplate.cpp** - Minimal template for quick coding

### **NumberTheory/**
Number theory algorithms and utilities:
- **gcd_lcm.cpp** - GCD, LCM, Extended GCD, Modular exponentiation
- **prime_sieve.cpp** - Sieve of Eratosthenes, Prime checking

### **Graphs/**
Graph algorithms and traversal techniques:
- **bfs_dfs.cpp** - BFS and DFS (recursive & iterative)
- **dijkstra.cpp** - Single-source shortest path algorithm

### **SearchingAndSorting/**
Searching and sorting algorithms:
- **binary_search.cpp** - Binary search, lower_bound, upper_bound implementations

### **DataStructures/**
Advanced data structure implementations:
- **segment_tree.cpp** - Range sum queries with point updates

### **StringAlgorithms/**
String manipulation and pattern matching:
- **kmp.cpp** - Knuth-Morris-Pratt algorithm for pattern matching

### **Math/**
Mathematical utilities and algorithms:
- **modular_arithmetic.cpp** - Modular exponentiation, inverse, nCr calculations

### **GeometryAndPointLocation/**
Geometry algorithms (to be added)

---

## 🚀 Quick Tips

### **Common Macros**
```cpp
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1e9 + 7
#define INF 1e18
```

### **Fast I/O**
```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
```

### **Time Complexity Quick Reference**
| Limit | Time | Algorithm |
|-------|------|-----------|
| N ≤ 10⁶ | O(n) | Linear scan |
| N ≤ 10⁶ | O(n log n) | Sorting, binary search |
| N ≤ 10³ | O(n²) | Nested loops |
| N ≤ 500 | O(n³) | Triple nested loops |
| N ≤ 20 | O(2^n) | Bitmask DP |

---

## 📚 Algorithm Checklist

### **Must Know Algorithms**
- [ ] Binary Search & Variants
- [ ] DFS/BFS
- [ ] Dijkstra's Algorithm
- [ ] BFS for 0-1 Weight Graphs
- [ ] Floyd-Warshall Algorithm
- [ ] Union-Find (DSU)
- [ ] Topological Sort
- [ ] Strongly Connected Components (SCC)
- [ ] Minimum Spanning Tree (Kruskal/Prim)
- [ ] Segment Tree/Fenwick Tree
- [ ] GCD/LCM/Modular Exponentiation
- [ ] Sieve of Eratosthenes
- [ ] KMP/Z-Algorithm
- [ ] DP (Knapsack, LCS, LIS, etc.)

### **Common Pitfalls**
- Integer overflow → Use `long long`
- Off-by-one errors → Check boundary conditions
- Modulo operations → Take mod in intermediate calculations
- Graph edges direction → Check if directed or undirected
- Zero-indexed vs one-indexed → Be consistent

---

## 💡 Useful C++ STL Functions

```cpp
// Sorting
sort(arr.begin(), arr.end());
sort(arr.begin(), arr.end(), greater<int>());

// Searching
binary_search(arr.begin(), arr.end(), x);
lower_bound(arr.begin(), arr.end(), x);
upper_bound(arr.begin(), arr.end(), x);

// Container Operations
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
auto it = find(v.begin(), v.end(), 3);

// Priority Queue
priority_queue<int> pq;  // Max heap
priority_queue<int, vector<int>, greater<int>> minpq;  // Min heap

// Map/Set
map<int, string> m;
set<int> s;
unordered_map<int, int> ump;  // O(1) average
```

---

## 🔥 Contest Tips

1. **Read the problem carefully** - Don't miss constraints and data types
2. **Start with brute force** - Then optimize if needed
3. **Test with examples** - Always verify with provided test cases
4. **Check edge cases** - Empty input, single element, maximum/minimum values
5. **Use assertions** - `assert(n >= 1 && n <= 1e5);`
6. **Template usage** - Adapt the template to your needs quickly
7. **Avoid common mistakes** - Overflow, modulo, array bounds, TLE

---

## 📖 Learning Resources

- **Competitive Programming 3** by Steven Halim
- **Codeforces** - Practice problems and editorials
- **AtCoder** - High-quality problems
- **LeetCode** - Good for interviews and fundamentals
- **GeeksforGeeks** - Algorithm explanations

---

## 📝 Implementation Strategy

1. Choose the right template (FastIO if multiple test cases, Simple otherwise)
2. Read algorithm from corresponding folder
3. Adapt code to specific problem
4. Test thoroughly before submission
5. Optimize if TLE occurs

---

*Last Updated: May 2026*
*Happy Coding! 🎯*
