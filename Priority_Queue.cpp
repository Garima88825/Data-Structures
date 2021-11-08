#include <iostream>
#include <math.h>

using namespace std;

#define NN 20

class Heap{
    int n; //number of nodes in array
    int array[NN+1]; //arrayray is 1 based
public:
    Heap(){ n=0 ;}
    void minimum(int index);
    void insert(int k);
    int searraych(int k);
    void deleteKey(int k);
    int getMin();
};

void Heap::minimum(int i){
        int l = 2*i;
        int r = 2*i+1;
        int min = i;
        if(l<n && array[l]<array[min])
            min = l;
        if(r<n && array[r]<array[min])
            min = r;
        if(min != i){
            swap(array[i],array[min]);
            minimum(min);
        }
}

void Heap::insert(int k){
        if(n==NN) return;
        n++;
        array[n]= k;
        int p= n;
        while(p>1){
            int pr= p/2;
            if(array[pr]>array[p]){
                swap(array[pr],array[p]);
                p= pr;
            }
            else break;
        }
}

int Heap::getMin(){
    if(n==0) return -1;
    else return array[1];
}

int Heap::searraych(int ele){
    for(int i=1;i<=n;i++){
        if(array[i] == ele)
            return i;
        }
    return -1;
}

void Heap::deleteKey(int ele){
        int index = searraych(ele);
        array[index] = array[n];
        n--;
        minimum(index);
}

int main(){
    Heap mH; int choice; bool flag = true;   int x;
    cout << "You have following choices\n"
         << "1.Enter priority\n"
         << "2.Extract data\n"
         << "3.get Top priority.\n"
         << "4.Quit\n";
    while(flag){
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice){
            case 1 :    cout << "Enter p : ";
                        cin >> x;
                        mH.insert(x);
                        break;
            case 2 :    cout << "Enter x : ";
                        cin >> x;
                        mH.deleteKey(x);
                        break;
            case 3 :    cout << "Top priority : " <<  mH.getMin() << endl;
                        break;
            case 4 :    flag = false;
                        break;
        }
    }
    return 0;
}
