//bst.cpp
//Valdivia, Pedro
//pvaldivia1

#include"bst.h"
#include<queue>

BST::BST()
{
    m_root = NULL;
}

bool BST::insert(string input_string)
{
    return insert(input_string,m_root);
}

bool BST::insert(string input_string, Node *& cur_root)
{
    if (cur_root == NULL)
    {
        cur_root = new Node(input_string,cur_root);
        return true;
    }
    if(input_string == cur_root->m_string)
    {
        return false;
    }

    if (input_string < cur_root->m_string)
    {
        insert(input_string,cur_root->m_left);
    }
    else
    {
        insert(input_string,cur_root->m_right);
    }
    return true;
}

void BST::print(vector<string> & values)
{
    print(values,m_root);
}

void BST::print(vector<string> & values, Node * cur_root)
{
    if (cur_root == NULL)
    return;

    print(values,cur_root->m_left);
    values.push_back(cur_root->m_string);
    print(values,cur_root->m_right);
}

int BST::count_nodes()
{
    return count_nodes(m_root);
}

int BST::count_nodes(Node* cur_root)
{
    if (!cur_root)
    {
        return 0;
    }
    return 1 + count_nodes(cur_root->m_left) + count_nodes(cur_root->m_right);
}

bool BST::find(string input_string)
{
    return find(input_string, m_root);
}

bool BST::find(string input_string, Node *cur_root)
{
    if (cur_root == NULL)
    return false;

    if(cur_root->m_string == input_string)
    return true;

    if (input_string < cur_root->m_string)
    {
        return find(input_string,cur_root->m_left);
    }
    else if (input_string > cur_root->m_string)
    {
        return find(input_string,cur_root->m_right);
    }
    return false;
}

double BST::distance()
{
    double total = 0;
    double average;
    double size = (double) count_nodes();
    total = distance(m_root,total);
    average = total/size;
    return average;
}

double BST::distance(Node* cur_root, double dist)
{
    if (cur_root == NULL)
    return 0;
    
    return dist + distance(cur_root->m_left, dist + 1) + distance(cur_root->m_right, dist + 1);
}

void BST::breadth(vector<string> & values)
{
    breadth(values,m_root);
}

void BST::breadth(vector<string> & values, Node * cur_root)
{
    queue<Node*> my_queue;
    my_queue.push(m_root);
    if (m_root != NULL)
    {
        while (my_queue.size() > 0)
        {
            if (my_queue.front()->m_left != NULL)
            {
                my_queue.push(my_queue.front()->m_left);
            }
            if (my_queue.front()->m_right != NULL)
            {
                my_queue.push(my_queue.front()->m_right);
            }
            values.push_back(my_queue.front()->m_string);
            my_queue.pop();
        }
    }
}

int BST::balanced()
{
   return is_balanced(m_root);
}
int BST::is_balanced(Node *cur_root)
{
    if (cur_root == NULL)
    return 0;
    int left_height;
    int right_height;

    left_height = 1 + is_balanced(cur_root->m_left);
    right_height = 1 + is_balanced(cur_root->m_right);

    int difference = left_height - right_height;

    if (abs(difference) > 1)
    {
        return -1;
    }
    else if (left_height == 0 || right_height == 0)
    {
        return -1;
    }
    else
    {
        if (left_height > right_height)
        return left_height;
        else
        return right_height; 
    }

}

void BST::delete_tree()
{
    delete_tree(m_root);
}

void BST::delete_tree(Node*&cur_root)
{
    if (cur_root == NULL)
    return;

    delete_tree(cur_root->m_left);
    delete_tree(cur_root->m_right);
    delete cur_root;

    cur_root = NULL;
}
void BST::insert_from_vector(vector<string> & values)
{
    if (values.size() == 0)
    return;

    int begin = 0;
    int end = values.size() - 1;
    insert_from_vector(values,begin,end);

}

void BST::insert_from_vector(vector<string> & values, int begin_index, int end_index)
{
    if (begin_index == end_index)
    {
        insert(values[begin_index]);
        return;
    }
    if (end_index == -1 || end_index < begin_index)
    return;

    int middle_index;
    int vector_size;
    vector_size = end_index - begin_index;
    if (begin_index == 0)
    {
        middle_index = vector_size/2;
        insert(values[middle_index]);
    }
    else
    {
        middle_index = vector_size/2 + begin_index;
        insert(values[middle_index]);
    }

    insert_from_vector(values,middle_index + 1,end_index);
    insert_from_vector(values,begin_index,middle_index - 1);

}

void BST::delete_node(string input_string)
{
    delete_node(input_string,m_root);
}

void BST::delete_node(string input_string, Node *&cur_root)
{
    if (cur_root == NULL)
    {
        return;
    }
    else if (input_string < cur_root->m_string)
    {
    
        delete_node(input_string,cur_root->m_left);
    }
    else if (input_string > cur_root->m_string)
    {
        delete_node(input_string, cur_root->m_right);
    }
    else
    {
        if (cur_root->m_left == NULL && cur_root->m_right == NULL)
        {
            delete cur_root;
            cur_root = NULL;
        }
        else if (cur_root->m_left == NULL && cur_root->m_right != NULL)
        {
            Node * temp = cur_root;
            cur_root = cur_root->m_right;
            delete temp;
        }
        else if(cur_root->m_right == NULL && cur_root->m_left != NULL)
        {
            Node * temp = cur_root;
            cur_root = cur_root->m_left;
            delete temp;
        }
        else 
        {
            string current = cur_root->m_right->m_string;
            string temp = find_min(cur_root->m_right->m_string, cur_root->m_right);
            cur_root->m_right->m_string = current;
            cur_root->m_string = temp;
            delete_node(temp,cur_root->m_right);
        }
    }
}

string BST::find_min(string &input_string,Node* cur_root)
{
    
    if (input_string > cur_root->m_string)
    {
        input_string = cur_root->m_string;
    }
    if (cur_root->m_left != NULL)
    {
        find_min(input_string,cur_root->m_left);
    }
    else if (cur_root->m_right != NULL)
    {
        find_min(input_string,cur_root->m_right);
    }
    return input_string;
}
