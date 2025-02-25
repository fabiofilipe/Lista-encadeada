#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    int getElement(int position) {
        if (position < 1 || position > size) {
            std::cerr << "Posicao invalida!" << std::endl;
            return -1;
        }
        Node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    void setElement(int position, int value) {
        if (position < 1 || position > size) {
            std::cerr << "Posicao invalida!" << std::endl;
            return;
        }
        Node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        current->data = value;
    }

    void insert(int position, int value) {
        if (position < 1 || position > size + 1) {
            std::cerr << "Posicao invalida!" << std::endl;
            return;
        }

        Node* newNode = new Node{value, nullptr};
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void remove(int position) {
        if (position < 1 || position > size) {
            std::cerr << "Posicao invalida!" << std::endl;
            return;
        }

        Node* temp;
        if (position == 1) {
            temp = head;
            head = head->next;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1; i++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
        }
        delete temp;
        size--;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;

    std::cout << "Criacao da lista vazia." << std::endl;
    std::cout << "Verificar se a lista esta vazia: " << (list.isEmpty() ? "Sim" : "Nao") << std::endl;
    std::cout << "Obter o tamanho da lista: " << list.getSize() << std::endl;

    list.insert(1, 10);
    list.insert(2, 20);
    list.insert(3, 30);
    list.insert(2, 15);
    
    std::cout << "Lista apos insercoes:" << std::endl;
    list.print();
    std::cout << "Obter o tamanho da lista: " << list.getSize() << std::endl;

    
    list.remove(2);
    std::cout << "Lista apos remocao na posicao 2:" << std::endl;
    list.print();

    std::cout << "Elemento na posicao 2: " << list.getElement(2) << std::endl;
    list.setElement(2, 25);
    std::cout << "Lista apos modificar o elemento na posicao 2:" << std::endl;
    list.print();

    return 0;
}