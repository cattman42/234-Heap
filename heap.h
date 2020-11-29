// Forward declarations of child classes
template <typename T> class Leaf;
template <typename T> class Internal;
template <typename T> class heap;

template <typename T> class Node {
protected:
    Internal<T>* parent;

    //Child Pointers
    Node *L, *ML, *MR, *R;
public:
    Node(T*);
    virtual Leaf<T>* toLeaf() { return nullptr; }
    virtual Internal<T>* toInternal() { return nullptr; }
    virtual Leaf<T>* insert(T key, Node<T>*& created);
};

template <typename T> class Leaf : public Node<T> {
private:
    T key;
public:
    Leaf(T value) { key = value; }
    virtual Leaf<T>* toLeaf() { return this; }
    virtual Leaf<T>* insert(T key, Node<T>*& created) {
        Leaf<T>* newLeaf = new Leaf<T>(key);
        created = newLeaf;
        return newLeaf;
    }
};

template <typename T> class Internal : public Node<T> {
private:
    T min;
    Node<T>* children[4];
    int childCount;
    int height;
public:
    virtual Internal<T>* toInternal() { return this; }

    virtual Leaf<T>* insert(T key, Node<T>*& created) {
        Node<T>* newNode = nullptr;
        // Tell the last of our children to handle the insert.
        // If it splits or creates a new leaf, that will come back
        // to us in the newNode parameter.
        Leaf<T>* newLeaf = children[childCount - 1]->insert(key, newNode);
        if (newNode != nullptr) {
            childCount++;
            if (childCount > 4) {
                // Split, assign the new Internal node to created
            }
            else
                children[childCount - 1] = newNode;
        }
        return newLeaf;
    };
};


template <typename T> class Heap{
private:
    int currentSize;
    int maxSize;
    Node<T>* root;
public:
    Heap(int size) {    //Constructor, takes size in
        static const int capacity = size;
        maxSize = size;
        currentSize = 0;
        Node<T>* heapArray[40]; //Reserving as many nodes as we need
    }

    void insert(T key) {
        if (currentSize == maxSize) {}// Size is full
        if (currentSize == 0) {
            //First create a leaf, then insert the leaf.
            // Once an internal node is created, use root.insert( blah blah);
            root = key;
            currentSize++;
        }
    }
    int returnRoot() {
        return root;
    }

    void deleteLeaf(T node) {
        //Finds leaf node and deletes it
    }
    Leaf<T>* minimum() {
        // return min leaf
    }
    void extractMin() {
        // Uses minimum to find the smallest leaf
        // Then uses deleteLeaf to get it out of heap
    }
    void decreaseKey(T node, T value) {
        //Will decreaseKey of node to value
    }
    Heap* unionHeaps(T heap1, T heap2) {
        //Will union the two heaps - have notes on this from class
    }



};


