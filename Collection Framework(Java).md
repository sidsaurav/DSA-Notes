# Java Collections Framework - Complete Interview Guide

## Table of Contents
1. [Introduction and Motivation](#1-introduction-and-motivation)
2. [Collection Framework Overview](#2-collection-framework-overview)
3. [Collection Interface Hierarchy](#3-collection-interface-hierarchy)
4. [List Interface and Implementations](#4-list-interface-and-implementations)
5. [Cursors in Java Collections](#5-cursors-in-java-collections)
6. [Set Interface and Implementations](#6-set-interface-and-implementations)
7. [Queue Interface and Implementations](#7-queue-interface-and-implementations)
8. [Map Interface and Implementations](#8-map-interface-and-implementations)
9. [Utility Classes](#9-utility-classes)
10. [Best Practices and Interview Tips](#10-best-practices-and-interview-tips)

---

## 1. Introduction and Motivation

### Why Collections are Needed?

**Problem Statement**: Representing a large number of values (e.g., 10,000 student records) using individual variables leads to:
- Poor code readability
- Maintenance nightmare
- Memory management issues

### Problems with Arrays

| Problem | Description | Example |
|---------|-------------|---------|
| **Fixed Size** | Once created, size cannot be changed | `Student[] s = new Student[1000];` - Fixed at 1000 |
| **Homogeneous Elements** | Can only store same type objects | `s[1] = new Customer();` → **CompileTime Error** |
| **No Built-in Methods** | No ready-made methods for common operations | Must implement sorting, searching manually |
| **Size Prediction** | Need to know size in advance | Not always possible in real applications |

### Arrays vs Collections Comparison

| Aspect | Arrays | Collections |
|--------|--------|-------------|
| **Size** | Fixed | Growable/Dynamic |
| **Memory** | Not recommended for dynamic data | Recommended |
| **Performance** | Better (direct memory access) | Slightly slower |
| **Data Types** | Homogeneous only | Both homogeneous & heterogeneous |
| **Implementation** | Not based on standard DS | Based on standard data structures |
| **Methods** | No built-in methods | Rich set of methods available |
| **Type Support** | Primitives + Objects | Objects only |
| **API Support** | No predefined classes | Extensive API in java.util |
| **Cursors** | Not supported | Enumeration, Iterator, ListIterator |

---

## 2. Collection Framework Overview

### Key Definitions

- **Collection(I)**: Interface representing a group of objects as a single entity
- **Collections(C)**: Utility class with static methods for operations like sorting, searching

### 9 Key Interfaces (with versions)

1. **Collection (1.2)** - Root interface
2. **List (1.2)** - Ordered collection with duplicates
3. **Set (1.2)** - No duplicates allowed
4. **SortedSet (1.2)** - Sorted set
5. **NavigableSet (1.6)** - Navigation methods for sorted set
6. **Queue (1.5)** - FIFO operations
7. **Map (1.2)** - Key-value pairs
8. **SortedMap (1.2)** - Sorted map by keys
9. **NavigableMap (1.6)** - Navigation methods for sorted map

---

## 3. Collection Interface Hierarchy

```
Collection(I)
├── List(I)
│   ├── ArrayList(C)
│   ├── LinkedList(C)
│   ├── Vector(C)
│   └── Stack(C)
├── Set(I)
│   ├── HashSet(C)
│   ├── LinkedHashSet(C)
│   └── SortedSet(I)
│       └── NavigableSet(I)
│           └── TreeSet(C)
└── Queue(I)
    ├── PriorityQueue(C)
    └── LinkedList(C)

Map(I) [Separate Hierarchy]
├── HashMap(C)
├── LinkedHashMap(C)
├── Hashtable(C)
├── Properties(C)
└── SortedMap(I)
    └── NavigableMap(I)
        └── TreeMap(C)
```

### Collection Interface Methods

**Important Interview Methods:**

```java
// Basic Operations
boolean add(Object o)
boolean remove(Object o)
int size()
boolean isEmpty()
void clear()

// Bulk Operations
boolean addAll(Collection c)
boolean removeAll(Collection c)  // Removes elements present in 'c'
boolean retainAll(Collection c)  // Keeps only elements present in 'c'

// Query Operations
boolean contains(Object o)
boolean containsAll(Collection c)

// Conversion
Object[] toArray()
```

**Interview Question**: `removeAll()` vs `clear()`

| removeAll() | clear() |
|-------------|---------|
| Removes elements by comparing with another collection | Blindly removes all elements |
| Returns boolean | Returns void |
| Requires two collection objects | Requires only one collection |
| Slower - O(n²) complexity | Faster - O(n) complexity |
| Use when removing specific elements | Use when removing all elements |

---

## 4. List Interface and Implementations

### List Interface Characteristics
- **Duplicates**: Allowed
- **Insertion Order**: Preserved
- **Index-based**: Access elements by index
- **Methods**: Adds index-based methods to Collection interface

### 4.1 ArrayList

**Declaration:**
```java
public class ArrayList<E> extends AbstractList<E> 
    implements List<E>, RandomAccess, Cloneable, Serializable
```

**Key Properties:**
- **Underlying DS**: Resizable/Growable Array
- **Duplicates**: Allowed
- **Insertion Order**: Preserved
- **Heterogeneous**: Allowed
- **Null**: Allowed
- **Best for**: Frequent retrieval operations
- **Worst for**: Frequent insertion/deletion in middle

**Constructors:**
```java
ArrayList() // Default capacity 10
ArrayList(int initialCapacity)
ArrayList(Collection c) // For inter-conversion
```

**Growth Strategy:**
- **Initial Capacity**: 10
- **Growth Formula**: `newCapacity = (oldCapacity * 3/2) + 1`
- **Java 8+**: `newCapacity = oldCapacity + (oldCapacity >> 1)`

**Interview Insights:**
- Implements `RandomAccess` marker interface → O(1) access time
- Implements `Serializable` and `Cloneable` by default
- Thread-unsafe → Use `Collections.synchronizedList()` for thread safety

### 4.2 LinkedList

**Declaration:**
```java
public class LinkedList<E> extends AbstractSequentialList<E> 
    implements List<E>, Deque<E>, Cloneable, Serializable
```

**Key Properties:**
- **Underlying DS**: Doubly Linked List
- **Best for**: Frequent insertion/deletion in middle
- **Worst for**: Random access operations
- **Implements**: Both List and Deque interfaces

**Unique Methods:**
```java
// At beginning
void addFirst(Object o)
Object removeFirst()
Object getFirst()

// At end  
void addLast(Object o)
Object removeLast()
Object getLast()
```

**ArrayList vs LinkedList:**

| Aspect | ArrayList | LinkedList |
|--------|-----------|------------|
| **Internal Structure** | Dynamic Array | Doubly Linked List |
| **Access Time** | O(1) - RandomAccess | O(n) - Sequential |
| **Insertion/Deletion** | O(n) - shifting required | O(1) - no shifting |
| **Memory** | Contiguous | Non-contiguous |
| **Interfaces** | List only | List + Deque |
| **Use Case** | Frequent retrieval | Frequent modification |

### 4.3 Vector

**Key Differences from ArrayList:**

| ArrayList | Vector |
|-----------|--------|
| Non-synchronized | Synchronized |
| Multiple threads can access | Thread-safe |
| Better performance | Slower performance |
| Non-legacy (1.2) | Legacy (1.0) |
| Growth: (n*3/2)+1 | Growth: n*2 |

**Thread Safety:**
```java
// Getting synchronized ArrayList
ArrayList al = new ArrayList();
List syncList = Collections.synchronizedList(al);
```

### 4.4 Stack

**Declaration:**
```java
public class Stack<E> extends Vector<E>
```

**LIFO Operations:**
```java
Object push(Object o)    // Insert
Object pop()             // Remove and return top
Object peek()            // Return top without removal
boolean empty()          // Check if empty
int search(Object o)     // Return offset (1-based)
```

**Interview Note**: Stack search returns **1-based offset**, not 0-based index.

---

## 5. Cursors in Java Collections

### Overview
Cursors are used to retrieve objects one by one from collections.

| Cursor | Since | Direction | Operations | Scope |
|--------|--------|-----------|------------|-------|
| **Enumeration** | 1.0 | Forward only | Read only | Legacy classes only |
| **Iterator** | 1.2 | Forward only | Read + Remove | All collections |
| **ListIterator** | 1.2 | Bidirectional | Read + Remove + Add + Replace | List only |

### 5.1 Enumeration (Legacy)

```java
// Creation
Enumeration e = vector.elements();

// Methods
boolean hasMoreElements()
Object nextElement()
```

**Limitations:**
- Only for legacy classes (Vector, Hashtable)
- Read-only operations
- Forward direction only

### 5.2 Iterator (Universal Cursor)

```java
// Creation
Iterator itr = collection.iterator();

// Methods
boolean hasNext()
Object next()
void remove() // Remove current element
```

**Advantages:**
- Works with any Collection
- Supports remove operation
- Fail-fast behavior

### 5.3 ListIterator (Most Powerful)

```java
// Creation
ListIterator ltr = list.listIterator();

// Forward methods
boolean hasNext()
Object next()
int nextIndex()

// Backward methods  
boolean hasPrevious()
Object previous()
int previousIndex()

// Modification methods
void add(Object o)
void remove()
void set(Object o)
```

**Interview Tip**: ListIterator is the most powerful cursor but limited to List implementations only.

---

## 6. Set Interface and Implementations

### Set Characteristics
- **Duplicates**: Not allowed
- **add() method**: Returns false for duplicate insertions (no exceptions)

### 6.1 HashSet

**Key Properties:**
- **Underlying DS**: Hash Table
- **Duplicates**: Not allowed
- **Insertion Order**: Not preserved (hash-based)
- **Null**: Allowed (only once)
- **Best for**: Search operations

**Constructors:**
```java
HashSet()                    // Default capacity 16, load factor 0.75
HashSet(int initialCapacity)
HashSet(int initialCapacity, float loadFactor)
HashSet(Collection c)
```

**Load Factor**: Threshold for creating new HashSet
- Default: 0.75 (75% full)
- After 75% capacity, new HashSet created with increased size

### 6.2 LinkedHashSet

**Differences from HashSet:**

| HashSet | LinkedHashSet |
|---------|---------------|
| Hash Table | LinkedList + Hash Table |
| Insertion order not preserved | Insertion order preserved |
| Since 1.2 | Since 1.4 |

**Use Case**: Cache-based applications where insertion order matters

### 6.3 TreeSet

**Key Properties:**
- **Underlying DS**: Balanced Tree (Red-Black Tree)
- **Duplicates**: Not allowed
- **Insertion Order**: Not preserved
- **Sorting**: Automatic (natural or custom)
- **Heterogeneous**: Not allowed
- **Null**: Not allowed (from Java 1.7+)

**Important Interview Points:**
- Objects must be **Comparable** for natural sorting
- `ClassCastException` for heterogeneous objects
- Implements `NavigableSet` interface

**Constructors:**
```java
TreeSet()                    // Natural sorting
TreeSet(Comparator c)        // Custom sorting
TreeSet(Collection c)
TreeSet(SortedSet s)
```

### Comparable vs Comparator

| Comparable | Comparator |
|------------|------------|
| **Package**: java.lang | **Package**: java.util |
| **Methods**: compareTo() | **Methods**: compare(), equals() |
| **Purpose**: Default natural sorting | **Purpose**: Custom sorting |
| **Implementation**: By class author | **Implementation**: By class user |

**Comparable Example:**
```java
public int compareTo(Object o) {
    // Return -ve: this < o
    // Return +ve: this > o  
    // Return 0: this == o
}
```

**Comparator Example:**
```java
public int compare(Object o1, Object o2) {
    // Return -ve: o1 < o2
    // Return +ve: o1 > o2
    // Return 0: o1 == o2
}
```

### SortedSet and NavigableSet Methods

**SortedSet Methods:**
```java
Object first()                          // First element
Object last()                           // Last element
SortedSet headSet(Object obj)          // Elements < obj
SortedSet tailSet(Object obj)          // Elements >= obj
SortedSet subSet(Object obj1, Object obj2) // Elements >= obj1 and < obj2
Comparator comparator()                // Returns comparator or null
```

**NavigableSet Methods:**
```java
Object floor(Object e)      // Highest element <= e
Object lower(Object e)      // Highest element < e
Object ceiling(Object e)    // Lowest element >= e
Object higher(Object e)     // Lowest element > e
Object pollFirst()          // Remove and return first
Object pollLast()           // Remove and return last
NavigableSet descendingSet() // Reverse order view
```

### Set Implementation Comparison

| Property | HashSet | LinkedHashSet | TreeSet |
|----------|---------|---------------|---------|
| **Underlying DS** | Hash Table | LinkedList + Hash Table | Balanced Tree |
| **Duplicates** | Not allowed | Not allowed | Not allowed |
| **Insertion Order** | Not preserved | Preserved | Not preserved |
| **Sorting** | NA | NA | Yes |
| **Heterogeneous** | Allowed | Allowed | Not allowed |
| **Null** | Allowed | Allowed | Not allowed |
| **Performance** | O(1) | O(1) | O(log n) |

---

## 7. Queue Interface and Implementations

### Queue Characteristics
- **Purpose**: Represent objects prior to processing
- **Default Order**: FIFO (First In, First Out)
- **Custom Order**: Possible with PriorityQueue

### Queue Methods

| Method | Exception on Failure | Return Value on Failure |
|--------|---------------------|------------------------|
| **add(e)** | Throws Exception | - |
| **offer(e)** | - | Returns false |
| **remove()** | NoSuchElementException | - |
| **poll()** | - | Returns null |
| **element()** | NoSuchElementException | - |
| **peek()** | - | Returns null |

### PriorityQueue

**Key Properties:**
- **Underlying DS**: Heap (Binary Tree)
- **Order**: Priority-based (natural or custom)
- **Duplicates**: Not allowed
- **Null**: Not allowed
- **Default Capacity**: 11

**Constructors:**
```java
PriorityQueue()                           // Natural ordering, capacity 11
PriorityQueue(int initialCapacity)
PriorityQueue(int initialCapacity, Comparator c)
PriorityQueue(SortedSet s)
PriorityQueue(Collection c)
```

---

## 8. Map Interface and Implementations

### Map Characteristics
- **Not a Collection**: Separate hierarchy
- **Structure**: Key-Value pairs (Entry objects)
- **Keys**: No duplicates allowed
- **Values**: Duplicates allowed

### Map Interface Methods

**Basic Operations:**
```java
Object put(Object key, Object value)     // Returns old value if key exists
void putAll(Map m)
Object get(Object key)
Object remove(Object key)
```

**Query Operations:**
```java
boolean containsKey(Object key)
boolean containsValue(Object value)
boolean isEmpty()
int size()
void clear()
```

**Collection Views:**
```java
Set keySet()           // All keys
Collection values()    // All values  
Set entrySet()        // All key-value pairs
```

### Entry Interface

```java
// Map.Entry methods
Object getKey()
Object getValue()
Object setValue(Object newValue)
```

### 8.1 HashMap

**Key Properties:**
- **Underlying DS**: Hash Table (Array of LinkedLists/Trees in Java 8+)
- **Insertion Order**: Not preserved
- **Null**: Allowed for both key (once) and values (multiple)
- **Thread Safety**: Not thread-safe
- **Performance**: O(1) average for basic operations

**Java 8+ Improvements:**
- **Treeification**: LinkedList → Balanced Tree when bucket size > 8
- **Detreeification**: Tree → LinkedList when bucket size < 6

**Constructors:**
```java
HashMap()                              // Capacity 16, load factor 0.75
HashMap(int initialCapacity)
HashMap(int initialCapacity, float loadFactor)
HashMap(Map m)
```

### 8.2 LinkedHashMap

**Differences from HashMap:**

| HashMap | LinkedHashMap |
|---------|---------------|
| Hash Table | LinkedList + Hash Table |
| Insertion order not preserved | Insertion order preserved |
| Since 1.2 | Since 1.4 |

### 8.3 TreeMap

**Key Properties:**
- **Underlying DS**: Red-Black Tree
- **Sorting**: By keys (natural or custom)
- **Null Keys**: Not allowed (from Java 1.7+)
- **Null Values**: Allowed
- **Performance**: O(log n)

### 8.4 Hashtable

**HashMap vs Hashtable:**

| HashMap | Hashtable |
|---------|-----------|
| Non-synchronized | Synchronized |
| Null allowed | Null not allowed |
| Since 1.2 (non-legacy) | Since 1.0 (legacy) |
| Better performance | Slower performance |
| Initial capacity: 16 | Initial capacity: 11 |

### 8.5 Specialized Map Implementations

**IdentityHashMap:**
- Uses `==` for key comparison instead of `equals()`
- Same keys with different references treated as different

**WeakHashMap:**
- Keys are weak references
- Entries eligible for garbage collection when key has no other references

### SortedMap and NavigableMap Methods

**SortedMap Methods:**
```java
Object firstKey()
Object lastKey()
SortedMap headMap(Object key)
SortedMap tailMap(Object key)
SortedMap subMap(Object key1, Object key2)
Comparator comparator()
```

**NavigableMap Methods:**
```java
Object floorKey(Object key)
Object lowerKey(Object key)
Object ceilingKey(Object key)
Object higherKey(Object key)
Map.Entry pollFirstEntry()
Map.Entry pollLastEntry()
NavigableMap descendingMap()
```

### Properties Class

**Special Map Implementation:**
- Both keys and values must be Strings
- Used for configuration files
- Extends Hashtable

**Key Methods:**
```java
String setProperty(String key, String value)
String getProperty(String key)
Enumeration propertyNames()
void load(InputStream is)
void load(Reader r)
void store(OutputStream os, String comment)
void storeToXML(OutputStream os, String comment)
```

---

## 9. Utility Classes

### 9.1 Collections Class

**Sorting:**
```java
static void sort(List list)                    // Natural order
static void sort(List list, Comparator c)     // Custom order
```

**Searching:**
```java
static int binarySearch(List list, Object key)
static int binarySearch(List list, Object key, Comparator c)
```

**Binary Search Results:**
- **Successful**: Returns index (0 to n-1)
- **Unsuccessful**: Returns insertion point (-(n+1) to -1)
- **Total Range**: -(n+1) to n-1

**Other Utilities:**
```java
static void reverse(List list)
static Comparator reverseOrder()
static Comparator reverseOrder(Comparator c)
static void shuffle(List list)
static void swap(List list, int i, int j)
static Object max(Collection c)
static Object min(Collection c)
```

**Synchronization:**
```java
static List synchronizedList(List list)
static Set synchronizedSet(Set s)
static Map synchronizedMap(Map m)
```

### 9.2 Arrays Class

**Sorting:**
```java
static void sort(int[] a)                      // Primitives
static void sort(Object[] a)                  // Objects - natural order
static void sort(Object[] a, Comparator c)    // Objects - custom order
```

**Searching:**
```java
static int binarySearch(int[] a, int key)
static int binarySearch(Object[] a, Object key)
static int binarySearch(Object[] a, Object key, Comparator c)
```

**Array to List Conversion:**
```java
static List asList(Object... a)
```

**Important Notes for asList():**
- Creates a **fixed-size list** backed by the array
- Changes in array reflect in list and vice versa
- `UnsupportedOperationException` for size-changing operations
- `ArrayStoreException` for incompatible type assignments

---

## 10. Best Practices and Interview Tips

### 10.1 When to Use Which Collection?

| Use Case | Recommended Implementation |
|----------|---------------------------|
| **Frequent random access** | ArrayList |
| **Frequent insertion/deletion** | LinkedList |
| **Thread safety required** | Vector or synchronized wrappers |
| **No duplicates, fast lookup** | HashSet |
| **No duplicates, maintain order** | LinkedHashSet |
| **No duplicates, sorted** | TreeSet |
| **Key-value pairs, fast access** | HashMap |
| **Key-value pairs, maintain order** | LinkedHashMap |
| **Key-value pairs, sorted** | TreeMap |
| **Thread-safe key-value pairs** | Hashtable or ConcurrentHashMap |

### 10.2 Common Interview Questions

**1. Fail-Fast vs Fail-Safe Iterators:**
- **Fail-Fast**: Throws ConcurrentModificationException if collection modified during iteration
- **Fail-Safe**: Work on copy, don't throw exceptions

**2. Load Factor in HashMap:**
- Default: 0.75
- Trade-off between time and space
- Higher load factor → less memory, more collisions
- Lower load factor → more memory, fewer collisions

**3. Why String is popular as HashMap key?**
- Immutable
- Proper hashCode() and equals() implementation
- Thread-safe

**4. HashMap internal working (Java 8+):**
- Array of buckets (initial size 16)
- Hash collision handled by LinkedList (initially)
- Treeification when bucket size > 8
- Detreeification when bucket size < 6

**5. Comparable vs Comparator:**
- Comparable: Single sorting sequence, natural ordering
- Comparator: Multiple sorting sequences, custom ordering

### 10.3 Time Complexity Summary

| Operation | ArrayList | LinkedList | HashMap | TreeMap | HashSet | TreeSet |
|-----------|-----------|------------|---------|---------|---------|---------|
| **Access** | O(1) | O(n) | O(1) | O(log n) | - | - |
| **Search** | O(n) | O(n) | O(1) | O(log n) | O(1) | O(log n) |
| **Insertion** | O(1)* | O(1) | O(1) | O(log n) | O(1) | O(log n) |
| **Deletion** | O(n) | O(1) | O(1) | O(log n) | O(1) | O(log n) |

*O(n) for insertion in middle due to shifting

### 10.4 Memory Considerations

**ArrayList Growth:**
- Grows by ~50% when capacity exceeded
- May lead to memory wastage
- Use `trimToSize()` to reduce capacity

**HashMap Memory:**
- Default load factor 0.75 balances time-space tradeoff
- Consider initial capacity for known data size

**LinkedList Memory:**
- Each node has extra memory overhead for pointers
- Better for frequent modifications, worse for storage

### 10.5 Thread Safety Guidelines

**Thread-Safe Collections:**
- Vector, Hashtable, Stack
- Collections.synchronizedXxx() wrappers
- java.util.concurrent package (ConcurrentHashMap, etc.)

**Thread-Unsafe Collections:**
- ArrayList, LinkedList, HashMap, HashSet, TreeMap, TreeSet

### 10.6 Performance Tips

1. **Initialize with appropriate capacity** if size is known
2. **Use StringBuilder** for string concatenation in loops
3. **Prefer ArrayList** over Vector unless thread safety needed
4. **Use HashMap** over Hashtable unless thread safety needed
5. **Consider LinkedHashMap** for cache implementations
6. **Use TreeMap/TreeSet** only when sorting is required
7. **Implement proper hashCode() and equals()** for custom objects

---

## Conclusion

The Java Collections Framework provides a rich set of data structures and algorithms for common programming tasks. Understanding the characteristics, performance implications, and appropriate use cases for each implementation is crucial for writing efficient Java code and succeeding in technical interviews.

**Key Takeaways:**
1. Choose the right collection based on your use case
2. Understand time complexity implications
3. Be aware of thread safety requirements
4. Know the internal working of commonly used implementations
5. Practice with real-world scenarios and edge cases

This comprehensive guide covers all essential aspects of Java Collections Framework with implementation details that are frequently asked in technical interviews. 
