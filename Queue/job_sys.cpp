#include <iostream>
using namespace std;

class Process {
public:
    int id;
    int priority;
};

class JobScheduler {
private:
    Process queue[100];
    Process stack[100];
    int front, rear, top, n;

public:
    JobScheduler() {
        front = 0;
        rear = -1;
        top = -1;
        n = 0;
    }

    void inputJobs() {
        cout<<"Enter number of jobs: ";
        cin>>n;

        for(int i=0; i<n; i++) {
            rear++;
            cout<<"Enter Process ID: ";
            cin>>queue[rear].id;
            cout<<"Enter Priority: ";
            cin>>queue[rear].priority;
        }
    }

    void sortByPriority() {
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(queue[i].priority < queue[j].priority) {
                    Process temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }

    void transferToStack() {
        for(int i=0; i<n; i++) {
            top++;
            stack[top] = queue[i];
        }
    }

    void executeJobs() {
        cout<<"\nJob Execution Order (Stack - LIFO):\n";
        while(top >= 0) {
            cout<<"Executing Process ID: "<<stack[top].id<<" Priority: "<<stack[top].priority<<endl;
            top--;
        }
    }

    void displayArrivalOrder() {
        cout<<"\nJob Arrival Order (Queue - FIFO):\n";
        for(int i=0; i<n; i++) {
            cout<<"Process ID: "<<queue[i].id<<" Priority: "<<queue[i].priority<<endl;
        }
    }
};

int main() {
    JobScheduler js;
    js.inputJobs();
    js.displayArrivalOrder();
    js.sortByPriority();
    js.transferToStack();
    js.executeJobs();
    return 0;
}
