bool List::contains_sequence(int sequence[], int size)
{
    if (m_head == NULL)
    {
        return false;
    }

    Node *ptr = m_head;
    Node *temp = m_head;
    int index = 0;
    while (ptr != NULL)
    {
        index = 0
        temp = ptr;
        while(temp != NULL && temp->m_value == sequence[index])
        {
            index++;
            temp = temp->m_next;
            if (index == size)
            {
                return true;
            }
        }
        ptr = ptr->m_next;
    }
    return false;
}
