#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node* push(Node *start, int d){
    Node *a = new Node;
    a -> data = d;
    a -> next = start;
    return a;
}
Node* pop(Node *s, int &d){
    d = (s -> data);
    Node *a = s -> next;
    delete s;
    return a;
}
void move(Node **stack, int from, int to, int save, int *size, int *number){
    int k = 0;
    while(size[to] != number[to]){
        stack[from] = pop(stack[from], k);
        if(k - 1 == to){
            stack[to] = push(stack[to], k);
            size[to]++;
            cout << from + 1 << " " << to + 1 << endl;
        }
        else{
            stack[save] = push(stack[save], k);
            size[save]++;
            cout << from + 1 << " " << save + 1 << endl;
        }
        size[from]--;
    }
    if(save > to){
        while(size[save] != number[save]){
            stack[save] = pop(stack[save], k);
            stack[from] = push(stack[from], k);
            size[save]--;
            size[from]++;
            cout << save + 1 << " " << from + 1 << endl;
        }
    }
    else{
        while(size[save] != 0){
            stack[save] = pop(stack[save], k);
            stack[from] = push(stack[from], k);
            size[save]--;
            size[from]++;
            cout << save + 1 << " " << from + 1 << endl;
        }
    }

}

void to_one(Node **stack, int to, int m, int *size){
    int k = 0;
    for(int i = to + 1; i < m; i++){
        while(size[i] != 0){
            stack[i] = pop(stack[i], k);
            stack[to] = push(stack[to], k);
            size[to]++;
            size[i]--;
            cout << i + 1 << " " << to + 1 << endl;
        }

    }

}

int main(){
    int n = 0;
    int k = 0;
    cin >> n;
    Node **stack = new Node*[n]; 
    int *size = new int[n]; 
    int *number = new int[n]; 
    for(int i = 0; i < n; i++) number[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> size[i];
        for(int j = 0; j < size[i]; j++){
                cin >> k;
                number[k - 1]++;
                stack[i] = push(stack[i], k);
        } 
    }
    int from = 0;
    int m = n; 
    
    to_one(stack, from, m, size);
    int save = 1; 
    int to = m - 1;
    move(stack, from, to, save, size, number);
    
    save = to;
    
    m--;
    for(int i = m; i > from; i--){
        to = i - 1;
        to_one(stack, from, i, size);
        move(stack, from, to, save, size, number);
    }
    delete []number;
    delete []size;

    return 0;
}