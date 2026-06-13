# Ancient Civilization Reconstruction & Historical Intelligence Engine (ACRHIE)

## DSA-I Using C++ Case Study

### Student Details

**Name:** Pallavi Sarovar
**Roll Number:** 150096725219
**Course:** Data Structures and Algorithms Using C++
**University:** ITM Skills University

---

# 1. Introduction to the Case Study

The Ancient Civilization Reconstruction & Historical Intelligence Engine (ACRHIE) is a case study developed to demonstrate the practical application of Data Structures and Algorithms in archaeology and historical research.

Ancient civilizations are often connected through trade networks, migration routes, cultural exchanges, and artifact discoveries. Managing and analyzing such information requires efficient storage, retrieval, and processing mechanisms.

This case study applies various Data Structures and Algorithms to solve real-world challenges related to artifact management, excavation report processing, and civilization relationship analysis.

The project demonstrates how DSA concepts can be used to organize archaeological information and provide meaningful insights into historical civilizations.

---

# 2. Problem Statement / Case Background

## Background

Archaeologists frequently discover artifacts belonging to different civilizations. These discoveries provide valuable information regarding trade routes, migration patterns, and cultural interactions.

Managing such large amounts of historical data manually is inefficient and prone to errors. Therefore, an intelligent system is required to efficiently store, search, organize, and analyze archaeological information.

## Problem Statement

Design and implement a Historical Intelligence Engine capable of:

* Managing archaeological artifact records.
* Processing excavation reports.
* Maintaining classification history.
* Analyzing civilization relationships.
* Determining shortest trade routes.
* Demonstrating practical implementation of Data Structures and Algorithms using C++.

---

# 3. Case Study Design

The system is divided into four major modules:

## Artifact Management

* Store artifacts.
* Search artifacts.
* Sort artifacts by significance.
* Display artifacts according to age.

## Classification Management

* Reclassify artifacts.
* Undo previous classifications.

## Excavation Report Management

* Store excavation reports.
* Process reports in FIFO order.

## Civilization Network Analysis

* Analyze civilization relationships.
* Explore trade networks.
* Find shortest trade routes.

---

# 4. Methods & Algorithms Applied

## Quick Sort

Purpose:
Rank artifacts according to significance score.

Time Complexity:

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(n log n) |
| Average | O(n log n) |
| Worst   | O(n²)      |

---

## Binary Search

Purpose:
Efficient artifact searching by ID.

Time Complexity:

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |

---

## Hash Table

Purpose:
Instant artifact identification and retrieval.

Average Time Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Search    | O(1)       |

---

## Stack

Purpose:
Undo artifact reclassification.

Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Push      | O(1)       |
| Pop       | O(1)       |

---

## Queue

Purpose:
Process excavation reports.

Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Enqueue   | O(1)       |
| Dequeue   | O(1)       |

---

## Binary Search Tree (BST)

Purpose:
Store artifacts according to age.

Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Search    | O(log n)   |

---

## Breadth First Search (BFS)

Purpose:
Analyze civilization relationships.

Complexity:

O(V + E)

---

## Depth First Search (DFS)

Purpose:
Explore civilization networks deeply.

Complexity:

O(V + E)

---

## Dijkstra's Algorithm

Purpose:
Find shortest trade routes.

Complexity:

O((V + E) log V)

---

# 5. Technology Stack

* Programming Language: C++
* Paradigm: Object-Oriented Programming
* File Handling: C++ File Streams
* Development Environment: Visual Studio Code
* Version Control: Git & GitHub

---

# 6. Project Structure

```text
ACRHIE/
│
├── data/
│   └── sample_input.txt
│
├── main.cpp
├── Engine.cpp
├── Engine.h
├── Algorithms.h
├── DataStructures.h
├── models.h
│
└── README.md
```

---

# 7. Implementation Details

The system loads archaeological data from:

```text
data/sample_input.txt
```

The file contains:

* Artifact Records
* Trade Route Information
* Excavation Reports

Implemented functionalities include:

* Artifact Ranking using Quick Sort
* Artifact Search using Hashing
* Artifact Search using Binary Search
* Artifact Classification Undo using Stack
* Excavation Report Processing using Queue
* Artifact Timeline using BST
* Civilization Analysis using BFS
* Civilization Analysis using DFS
* Shortest Route Analysis using Dijkstra's Algorithm

---

# 8. Execution Steps

## Compile

```bash
g++ main.cpp Engine.cpp -o acrhie
```

## Run

```bash
./acrhie
```

or

```bash
acrhie.exe
```

---

# 9. Sample Input

```text
Artifacts:
101,Rosetta Stone,Egyptian,-196,99
102,Terracotta Army,Chinese,-210,95

TradeRoutes:
Egyptian,Greek,800
Egyptian,Babylonian,1200

Reports:
1,Valley of Kings,2023-01-15,3,Uncovered new tomb annex
```

---

# 10. Sample Output

## Binary Search

```text
Found Artifact via Binary Search:
Antikythera Mechanism (Civ: Greek)
```

## BFS

```text
BFS Traversal from Egyptian:
Egyptian Greek Babylonian Indian Chinese
```

## Dijkstra

```text
Shortest route distance: 6700

Path:
Egyptian -> Babylonian -> Indian -> Chinese
```

---

# 11. Screenshots


<table>
<tr>
<td>
<img src="https://github.com/user-attachments/assets/32da0913-5d34-4ad0-9750-8a3269c4cf5c" width="450">
</td>

<td>
<img src="https://github.com/user-attachments/assets/1574399a-89c2-4b84-a8fa-4c9956a4f94e" width="450">
</td>
</tr>

<tr>
<td>
<img src="https://github.com/user-attachments/assets/46bb3a29-8dc3-4647-9bc7-5b966bb6b7c2" width="450">
</td>

<td>
<img src="https://github.com/user-attachments/assets/249ad3ac-f3f2-4125-b4fb-4754bdbf09f1" width="450">
</td>
</tr>

<tr>
<td colspan="2">
<img src="https://github.com/user-attachments/assets/2fbaedae-bb5d-460e-9b06-a8ffe0a29fce" width="450">
</td>
</tr>
</table>

---

# 12. Results and Observations

* Hashing provides efficient artifact retrieval.
* Binary Search improves search efficiency on sorted records.
* Stack successfully maintains classification history.
* Queue processes excavation reports in FIFO order.
* BST efficiently organizes artifacts according to age.
* BFS and DFS analyze civilization relationships effectively.
* Dijkstra's Algorithm accurately determines shortest trade routes.

---

# 13. Conclusion

The Ancient Civilization Reconstruction & Historical Intelligence Engine (ACRHIE) successfully demonstrates the practical implementation of Data Structures and Algorithms in archaeological data management.

The project integrates Quick Sort, Binary Search, Hashing, Stack, Queue, BST, BFS, DFS, and Dijkstra's Algorithm into a single system capable of storing, processing, and analyzing historical information efficiently.

The case study fulfills all specified requirements while providing a scalable foundation for future archaeological intelligence systems.

---


