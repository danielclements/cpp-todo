#include <iostream>
#include <vector>


struct task{
    std::string sDescription;
    bool bIsComplete;
} ;

std::vector <task> tasks;

int get_user_menu_command() {
    int iCurrentSelection;
    std::cout << "Press 1 for: Add new task\n"
                 "Press 2 for: View all tasks\n"
                 "Press 3 for: Mark a task as complete\n"
                 "Press 4 for: Delete a task\n"
                 "Press 5 to exit.\n";

    std::cin >> iCurrentSelection;
    std::cin.clear();
    std::cin.ignore(1, '\n');

    return iCurrentSelection;


}

void add_task() {
    std::string sTaskDescription;
    std::cout << "add a description to your task \n";
    std::getline(std::cin, sTaskDescription);
    task newTask = {sTaskDescription, false};
    tasks.push_back(newTask);
}

void view_tasks() {
    int iId = 0;
    if (tasks.size() == 0) {
        std::cout << "No Tasks found.\n";

    } else {
        for (auto task : tasks) {
            if (task.bIsComplete) {
                std::cout << iId << ". " << task.sDescription << "[x]" << "\n";
            } else {
                std::cout << iId << ". " << task.sDescription << "[ ]" << "\n";
            }
            iId++;
        }
    }

    std::cout << "press any key to continue.\n";
    std::cin.get();
}

void mark_task_complete() {
    int iId = 0;
    int i = 0;
    std::cout << "Select a task to mark complete\n";
    for (auto task : tasks) {
        if (task.bIsComplete) {
            std::cout << i << ". " << task.sDescription << "[x]" << "\n";
        } else {
            std::cout << i << ". " << task.sDescription << "[ ]" << "\n";
        }
        i++;
    }

    std::cin >> iId;

    tasks[iId].bIsComplete = true;
}


void delete_task() {
    int iId = 0;
    int i = 0;
    std::cout << "Select a task to delete\n";
    for (auto task : tasks) {
        if (task.bIsComplete) {
            std::cout << i << ". " << task.sDescription << "[x]" << "\n";
        } else {
            std::cout << i << ". " << task.sDescription << "[ ]" << "\n";
        }
        i++;
    }

    std::cin >> iId;

    tasks.erase(tasks.begin() + iId);

    std::cout << "Task Deleted\n";
}


int main() {
    bool bExit = false;

    while (!bExit) {
        switch (int userMenuCommand = get_user_menu_command()) {
            case 1:
                add_task();
            break;
            case 2:
                view_tasks();
            break;

            case 3:
                mark_task_complete();
            break;
            case 4:
                delete_task();
            break;

            case 5:
                bExit = true;
        }

    }


    return 0;
}