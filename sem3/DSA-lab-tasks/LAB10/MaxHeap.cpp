#include <iostream>
using namespace std;

class Max_heap {
private:
    int heap[100];    // Fixed size array
    int size;         // Current number of elements

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Heapify Up (after insertion)
    void heapify_up(int index) {
        while (index != 0 && heap[index] > heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    //Heapify Down (after deletion)
    void heapify_down(int index) {
        int largest = index; 
        int l = left(index); // index of left child
        int r = right(index); // index of right child

        // Find the largest among parent and children
        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        // If parent is not largest, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify_down(largest);
        }
    }

public:
    Max_heap() { size = 0; }

    // Insert a new element
    void insert(int value) {
        if (size == 100) {                 // Check for overflow
            cout << "Heap overflow!\n";
            return;
        }

        heap[size] = value;                // Step 1: Add at end
        heapify_up(size);                   // Step 2: Restore heap property
        size++;      
    }
    
    // Delete Max (root)
    void deleteMax() {
        if (size == 0) {
            cout << "Heap underflow!\n";
            return;}
        cout << "Deleted element: " << heap[0] << endl;
        // Step 1: Move last element to root
        heap[0] = heap[size - 1];
        size--;  // reduce heap size

        // Step 2: Heapify down to restore Max Heap property
        heapify_down(0);
    }
    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    Max_heap max_h;
    max_h.insert(10);
    max_h.insert(20);
    max_h.insert(5);
    max_h.insert(30);
    max_h.insert(3);

    cout << "Max Heap: ";
    max_h.display();
    max_h.deleteMax(); // delete root
    cout << "Heap after deletion: ";
    max_h.display();

    max_h.deleteMax(); // delete root again
    cout << "Heap after another deletion: ";
    max_h.display();
    return 0;
}