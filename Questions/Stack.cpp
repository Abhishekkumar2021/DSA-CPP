#include<bits/stdc++.h>
using namespace std;

class Stack{
    int arr[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(int data){
        if(top == 99){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top == -1;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    s.push(19);
    s.push(20);
    s.push(21);
    s.push(22);
    s.push(23);
    s.push(24);
    s.push(25);
    s.push(26);
    s.push(27);
    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);
    s.push(32);
    s.push(33);
    s.push(34);
    s.push(35);
    s.push(36);
    s.push(37);
    s.push(38);
    s.push(39);
    s.push(40);
    s.push(41);
    s.push(42);
    s.push(43);
    s.push(44);
    s.push(45);
    s.push(46);
    s.push(47);
    s.push(48);
    s.push(49);
    s.push(50);
    s.push(51);
    s.push(52);
    s.push(53);
    s.push(54);
    s.push(55);
    s.push(56);
    s.push(57);
    s.push(58);
    s.push(59);
    s.push(60);
    s.push(61);
    s.push(62);
    s.push(63);
    s.push(64);
    s.push(65);
    s.push(66);
    s.push(67);
    s.push(68);
    s.push(69);
    s.push(70);
    s.push(71);
    s.push(72);
    s.push(73);
    s.push(74);
    s.push(75);
    s.push(76);
    s.push(77);
    s.push(78);
    s.push(79);
    s.push(80);
    s.push(81);
    s.push(82);
    s.push(83);
    s.push(84);
    s.push(85);
    s.push(86);
    s.push(87);
    s.push(88);
    s.push(89);
    s.push(90);
    s.push(91);
    s.push(92);
    s.push(93);
    s.push(94);
    s.push(95);
    s.push(96);
    s.push(97);
    s.push(98);
    s.push(99);
    s.push(100);
    s.push(101);

    while(!s.empty()){
        cout << s.Top() << " ";
        s.pop();
    }

    return 0;
}
