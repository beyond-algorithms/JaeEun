struct Node {
    Node* next;
    Node* prev;
    int val;

    Node(int val) {
        this->val = val;
    }
};

class MyCircularDeque {
   private:
    int cap;
    int _mSize;

    Node* front;
    Node* rear;

   public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        _mSize = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cap == _mSize) {
            return false;
        }
        Node* newNode = new Node(value);
        if (_mSize == 0) {
            front = rear = newNode;
            _mSize++;
            return true;
        }

        newNode->next = front;
        front->prev = newNode;
        newNode->prev = rear;
        rear->next = newNode;

        front = newNode;
        ++_mSize;

        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cap == _mSize) {
            return false;
        }
        Node* newNode = new Node(value);
        if (_mSize == 0) {
            front = rear = newNode;
            _mSize++;
            return true;
        }

        newNode->next = front;
        rear->next = newNode;
        newNode->prev = rear;
        front->prev = newNode;

        rear = newNode;
        _mSize++;

        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (_mSize == 0) {
            return false;
        }
        if (_mSize == 1) {
            delete front;
            _mSize--;
            return true;
        }

        front->prev->next = front->next;
        front->next->prev = front->prev;
        delete front;

        _mSize--;
        if (_mSize == 1) {
            rear->next = nullptr;
            rear->prev = nullptr;
        }

        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (_mSize == 0) {
            return false;
        }
        if (_mSize == 1) {
            delete front;
            _mSize--;
            return true;
        }

        rear->prev->next = rear->next;
        rear->next->prev = rear->prev;
        delete rear;

        _mSize--;
        if (_mSize == 1) {
            front->next = nullptr;
            front->prev = nullptr;
        }

        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return front->val;
    }

    /** Get the last item from the deque. */
    int getRear() {
        return rear->val;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _mSize == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _mSize == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */