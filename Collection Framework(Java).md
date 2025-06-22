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
11. [Concurrent Collections](#11-concurrent-collections)

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

### 4.5 CopyOnWriteArrayList

`CopyOnWriteArrayList` is a thread-safe variant of `ArrayList` in which all mutative operations (add, set, etc.) are implemented by making a fresh copy of the underlying array.

**Key Characteristics:**
- **Immutability of Snapshot**: It achieves thread safety by creating a new copy of the underlying array for every write operation. The original array remains untouched.
- **Read Operations**: Read operations are very fast as they do not require any locking and operate on an immutable snapshot of the array.
- **Write Operations**: Write operations are expensive as they involve creating a new array and copying elements.
- **Use Case**: Best suited for applications where reads far outnumber writes. A typical example is a listener list, where listeners are added or removed infrequently, but the list is iterated over frequently to fire events.
- **Iterator**: The iterator is fail-safe and works on a snapshot of the array at the time the iterator was created. It will not throw `ConcurrentModificationException`.

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

### 6.4 EnumSet

- **Element Type**: A specialized `Set` implementation for use with enum types.
- **Performance**: Extremely efficient, internally represented as a bit vector. All methods are implemented using bitwise arithmetic operations and are very fast.
- **Order**: Elements are always stored and iterated in the natural order of the enum.
- **Nulls**: Does not allow `null` elements.
- **Creation**: Cannot be instantiated with `new`. Use static factory methods like `EnumSet.of()`, `EnumSet.allOf()`, `EnumSet.noneOf()`.

### 6.5 CopyOnWriteArraySet
- A thread-safe `Set` that uses a `CopyOnWriteArrayList` internally.
- It shares the same basic properties as `CopyOnWriteArrayList`: thread-safety through copying on writes.
- Write operations are expensive. Read operations are fast.
- Suitable for concurrent applications where set size is small and read operations vastly outnumber write operations.


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

### 7.3 Concurrent Queues

The `java.util.concurrent` package introduces thread-safe collection implementations. For queues, `BlockingQueue` is a key interface.

#### BlockingQueue Interface

A `Queue` that additionally supports operations that wait for the queue to become non-empty when retrieving an element, and wait for space to become available in the queue when storing an element.

**Key Methods:**

| Operation | Blocking Method | Timed Blocking Method |
|-----------|-----------------|-----------------------|
| **Insert**| `put(e)`        | `offer(e, time, unit)`|
| **Remove**| `take()`        | `poll(time, unit)`    |

- `put(e)`: Blocks until space is available to insert the element.
- `take()`: Blocks until an element is available to be retrieved.
- `offer(e, time, unit)`: Waits for a specified time for space to become available.
- `poll(time, unit)`: Waits for a specified time for an element to become available.

Common implementations include `LinkedBlockingQueue`, `ArrayBlockingQueue`, and `PriorityBlockingQueue`.

#### PriorityBlockingQueue

- An unbounded blocking queue that uses the same ordering rules as `PriorityQueue`.
- It is thread-safe.
- It does not permit `null` elements.
- While this queue is logically unbounded, attempted additions may fail due to `OutOfMemoryError`.
- Ideal for task scheduling based on priority in multi-threaded applications.

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

#### IdentityHashMap
- **Comparison**: Uses reference equality (`==`) instead of object equality (`equals()`) to compare keys.
- **Use Case**: Useful when you need to distinguish between objects that are logically equal (`.equals()` returns true) but are distinct instances. It's often used for implementing object traversals in serialization or graph algorithms, or for maintaining metadata per object.
- **Example**:
  ```java
  Map<String, String> map = new IdentityHashMap<>();
  String s1 = new String("key");
  String s2 = new String("key");
  map.put(s1, "value1");
  map.put(s2, "value2");
  System.out.println(map.size()); // Output: 2
  ```

#### WeakHashMap
- **Garbage Collection**: The entries in a `WeakHashMap` can be garbage collected if the key is no longer strongly referenced elsewhere. It uses `WeakReference` for its keys.
- **Use Case**: Ideal for implementing caches or look-up tables where you don't want the map to prevent keys from being garbage collected. This helps in preventing memory leaks.
- **Example**: If you store metadata for objects, and you want the metadata to be removed when the object itself is garbage collected.

#### EnumMap
- **Key Type**: A specialized `Map` implementation for use with enum type keys.
- **Performance**: Very fast, implemented as an array internally. The performance is better than `HashMap`.
- **Order**: Iterators return keys in their natural order (the order in which the enum constants are declared).
- **Null keys**: Does not permit `null` keys.


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

### 8.6 ConcurrentHashMap

`ConcurrentHashMap` is a highly scalable, thread-safe map implementation from `java.util.concurrent`. It is the preferred choice for concurrent applications over `Hashtable` or `Collections.synchronizedMap(new HashMap<>())`.

**Key Features vs. Hashtable/SynchronizedMap:**
- **Locking Granularity**: It uses a finer-grained locking mechanism. Instead of locking the entire map (as `Hashtable` and synchronized wrappers do), it divides the map into segments (or nodes in Java 8+) and locks only the relevant part for write operations.
- **Read Operations**: Read operations are generally non-locking and can occur concurrently with writes.
- **Performance**: This leads to much higher concurrency and throughput. Multiple threads can read and write to the map simultaneously without blocking each other, as long as they operate on different parts of the map.
- **Iterator**: The iterator is fail-safe, meaning it will not throw `ConcurrentModificationException`. However, it reflects the state of the map at a point in time and may not reflect modifications made after the iterator was created.
- **Nulls**: It does not allow `null` keys or values.

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
| **LIFO (Stack)** | Stack, LinkedList, ArrayDeque |
| **FIFO (Queue)** | LinkedList, ArrayDeque |
| **Priority processing**| PriorityQueue, PriorityBlockingQueue |

### 10.2 Common Interview Questions

**1. Fail-Fast vs Fail-Safe Iterators:**
- **Fail-Fast**: Throws ConcurrentModificationException if collection modified during iteration
- **Fail-Safe**: Work on copy, don't throw exceptions. Iterators for concurrent collections (`ConcurrentHashMap`, `CopyOnWriteArrayList`) and `ReentrantReadWriteLock` are generally fail-safe.

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

**6. `hashCode()` and `equals()` Contract:**
- If you override `equals()`, you MUST override `hashCode()`.
- If `o1.equals(o2)` is true, then `o1.hashCode() == o2.hashCode()` must be true.
- If `o1.hashCode() == o2.hashCode()` is true, it does not mean that `o1.equals(o2)` must be true (hash collision).

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
2. **Use `StringBuilder`** for string concatenation in loops
3. **Prefer `ArrayList`** over `Vector` unless thread safety needed
4. **Use `ConcurrentHashMap`** over `Hashtable` or `synchronizedMap` for concurrent access.
5. **Consider `LinkedHashMap`** for cache implementations
6. **Use `TreeMap`/`TreeSet`** only when sorting is required
7. **Implement proper `hashCode()` and `equals()`** for custom objects in Hash-based collections.
8. **Use `EnumSet` and `EnumMap`** for enum keys for better performance.
9. **Use `CopyOnWriteArrayList`** for read-heavy concurrent scenarios like listener lists.

---

## 11. Concurrent Collections

The `java.util.concurrent` package provides a set of collection classes that are designed for use in multi-threaded contexts. They offer higher performance and better scalability than the traditional synchronized collections.

### Key Concurrent Collections:

- **`ConcurrentHashMap`**: A highly scalable, thread-safe `Map`. It uses fine-grained locking (lock striping) to allow multiple threads to access the map concurrently. Reads can happen without any locks. It is the standard choice for a concurrent map.
- **`CopyOnWriteArrayList`**: A thread-safe `List` where all mutative operations are implemented by making a fresh copy of the underlying array. It's efficient when reads are far more frequent than writes.
- **`CopyOnWriteArraySet`**: A thread-safe `Set` implementation backed by a `CopyOnWriteArrayList`.
- **`BlockingQueue`**: An interface for a `Queue` that blocks on insertion or retrieval when the queue is full or empty, respectively.
- **`LinkedBlockingQueue`**: An optionally bounded `BlockingQueue` based on linked nodes.
- **`ArrayBlockingQueue`**: A bounded `BlockingQueue` backed by an array.
- **`PriorityBlockingQueue`**: An unbounded `BlockingQueue` that uses the same ordering rules as class `PriorityQueue`.
- **`DelayQueue`**: An unbounded `BlockingQueue` of `Delayed` elements, in which an element can only be taken when its delay has expired.
- **`SynchronousQueue`**: A `BlockingQueue` in which each insert operation must wait for a corresponding remove operation by another thread, and vice versa.

### Fail-Safe Iterators

Iterators returned by concurrent collections are *fail-safe*. They do not throw `ConcurrentModificationException`. If the collection is modified while an iterator is traversing it, the iterator might not reflect the modification. It operates on a snapshot or a weakly consistent view of the collection.

This comprehensive guide covers all essential aspects of Java Collections Framework with implementation details that are frequently asked in technical interviews. 


https://www.baeldung.com/java-collections-interview-questions
https://www.digitalocean.com/community/tutorials/java-collections-interview-questions-and-answers
