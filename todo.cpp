#include "todo.h"
#include <stdexcept>

void TodoList::init()
{
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; i++)
        tasks[i] = nullptr;
}

void TodoList::destroy()
{
    // TODO: delete all tasks and reset pointers
    for (int i = 0; i < size; i++)
    {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char *str) const
{
    // TODO: return the number of characters before '\0'
    int len = 0, i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void TodoList::string_copy(char *dest, const char *src) const
{
    // TODO: copy characters from src to dest
    int len = string_length(src);
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void TodoList::add_task(const char *task)
{
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size == MAX_TASKS)
        throw std::out_of_range("too many tasks");
    int len_new = string_length(task);
    char *task_new = new char[len_new + 1];
    string_copy(task_new, task);
    tasks[size] = task_new;
    size++;
}

void TodoList::remove_task(int index)
{
    // TODO: check bounds, delete task, shift left
    if (!(index < size) || index < 0)
        throw std::out_of_range("no tasks left");
    delete[] tasks[index];
    for (int i = index; i < size - 1; i++)
        tasks[i] = tasks[i + 1];
    size--;
}

const char **TodoList::get_pending_tasks(int &count) const
{
    // TODO: set count and return task array
    count = size;
    const char **result = new const char *[size];
    for (int i = 0; i < size; i++)
        result[i] = tasks[i];
    return size > 0 ? result : nullptr;
}