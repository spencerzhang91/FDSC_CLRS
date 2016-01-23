/* Excercise 7.8.5.c */
list_pointer convert2list(int *array, int len)
{
    if (len <= 0)
        return NULL;
    list_pointer curr;
    list_pointer head = (list_pointer)malloc(sizeof(struct list_node));
    // The following three line is not reusable, 
    // only vaible when MAX_DIGIT == 3
    head->key[0] = array[0] / 100;
    head->key[1] = (array[0] - head->key[0]*100) / 10;
    head->key[2] = (array[0] - head->key[0]*100 - head->key[1]*10);        
    head->link = NULL;
    curr = head;
    for (int i = 1; i < len; i++)
    {
        list_pointer temp = (list_pointer)malloc(sizeof(struct list_node));
        temp->key[0] = array[i] / 100;
        temp->key[1] = (array[i] - temp->key[0]*100) / 10;
        temp->key[2] = (array[i] - temp->key[0]*100 - temp->key[1]*10);  
        // only works for number smaller than 1000
        temp->link = NULL;
        curr->link = temp;
        curr = temp;
    }
    return head;
}

int *convert2array(list_pointer list)
{
    // only works when MAX_DIGIT == 3
    static int temp[LENGTH];
    int i = 0;
    while (list && i < LENGTH)
    {
        int num = list->key[0] * 100 + list->key[1] * 10 + list->key[2];
        temp[i] = num;
        list = list->link;
        i++;
    }
    return temp;
}