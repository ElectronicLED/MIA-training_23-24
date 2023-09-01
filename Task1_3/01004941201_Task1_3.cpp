#include <bits/stdc++.h >

using namespace std;

vector<string> tasks;

void addTask(){

    string task;

    cout<<"Enter task description: ";
    cin.ignore();

    getline(cin, task);


    tasks.push_back(task);
    cout<<"Task added successfully!\n"<<endl;
}


void viewTasks(){

    if(tasks.size() > 0){

        cout<<"Current Tasks:\n";

        for(int i = 0; i < tasks.size() ; i++){

            cout<<"Task ID: "<<i+1<<endl;
            cout<<"Description: "<<tasks[i]<<endl<<endl;

        }

    }else{
        cout<<"No tasks running"<<endl;
    }
}

void removeTask(){

    int taskID;

    cout<<"Enter task ID to remove:";
    cin>>taskID;
    cout<<endl;

    if(taskID <= tasks.size() && taskID > 0){

        tasks.erase(tasks.begin() + taskID-1);

        cout<<"Task removed successfully!"<<endl;

    }else{
        cout<<"Invalid task ID"<<endl;
    }




}

int main()
{
    int userInput;


    cout<<"Minions Task Manager"<<endl;
    cout<<"1. Add Task"<<endl;
    cout<<"2. View Tasks"<<endl;
    cout<<"3. Remove Task"<<endl;
    cout<<"4. Exit\n"<<endl;



    do{

        cout<<"Select an option: ";
        cin>>userInput;
        cout<<endl;

        if(userInput == 1){
            addTask();
        }
        else if(userInput == 2){
            viewTasks();
        }
        else if(userInput == 3){
            removeTask();
        }
        else if(userInput == 4){

        }
        else{
            cout<<"Invalid input\n";
        }


    }while(userInput != 4);




    cout << "Exiting Minions Task Manager. Have a great day!" << endl;

    return 0;
}
