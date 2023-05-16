#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

template <class T>
void print(T out) {
    cout << out << "\n";
}

template <class T, class G>
void print(T out, G end) {
    cout << out << end;
}

template <class T>
string input(T *out) {
    string in;
    print(out, "");
    cin >> in;
    return in;
}

template <typename T> 
struct Node {
    T cargo;
    Node<T>* next;
    Node<T>* previous;

    Node(T cargo, Node* next) {
        Node(cargo, next, NULL)
    }

    Node(T cargo, Node* next, Node* previous) {
        this->cargo = cargo;
        this->next = next;
        this->previous = previous;
    }

    template <typename U>
    static string to_string(U obj) {
        return std::to_string(obj);
    }

    static string to_string(string obj) {
        return obj;
    }

    string to_string() const {
        return this->to_string(cargo);
    }
};

// very leaky
template <typename T> 
struct LinkedList {
    int len;
    Node<T>* head;
    Node<T>* tail;

    public:
        LinkedList<T>() {
            len = 0;
            head = NULL;
            tail = NULL;
        }

        LinkedList<T>(T *starting_array) {
            for (int i = 0; i < sizeof(starting_array); i++) {
                this->append(starting_array[i]);
            }
        }

        void append(T obj) {
            if (len == 0){
                Node<T>* obj_node = new Node<T>(obj, NULL, NULL);
                head = obj_node;
                tail = obj_node;
                len++;
            } else {
                Node<T>* obj_node = new Node<T>(obj, NULL, tail);
                tail->next = obj_node;
                tail = obj_node;
                len++;
            }
        }

        void prepend(T obj) {
            if (len == 0){
                Node<T>* obj_node = new Node<T>(obj, NULL, NULL);
                head = obj_node;
                tail = obj_node;
                len++;
            } else {
                Node<T>* obj_node = new Node<T>(obj, head, NULL);
                head->previous = obj_node;
                head = obj_node;
                len++;
            }
        }

        Node<T>* get_node(int index) {
            if (index == len - 1) return tail;
            if (index < 0 || index > len) throw index;
            // there is a one line way to do this I think
            Node<T>* node = head;
            for (int i = 0; i < index; i++){
                node = node->next;
            }
            return node;
        }

        T get(int index) {
            return get_node(index)->cargo;
        }

        T pop(int index) {
            Node<T>* node = get_node(index);
            node->next->previous = node->previous;
            node->previous->next = node->next;
            len--;
            return node->cargo;
        }

        void insert(int index, T obj) {
            if (index == 0){
                this->prepend(obj);
            } else if (index == len) {
                this->append(obj);
            } else {
                Node<T>* neighbor = get_node(index);
                Node<T>* obj_node = new Node<T>(obj, neighbor, neighbor->previous);
                neighbor->previous->next = obj_node;
                neighbor->previous = obj_node;
                len++;
            }
        }

        string to_string() const {
            string return_string = "(";
            Node<T>* node = head;
            for (int i = 0; i < len; i++) {
                return_string.append(node->to_string());
                return_string.append(",");
                node = node->next;
            }
            return_string.append(")");
            return return_string;
        }
};

int main() {
    int nums[8] = {1,2,3,4,5,6,7,8};
    LinkedList<int>* num_list = new LinkedList<int>(nums);
    print(num_list->to_string());
    print(num_list->len);
    print(num_list->pop(3));
    print(num_list->to_string());
    print(num_list->len);
}