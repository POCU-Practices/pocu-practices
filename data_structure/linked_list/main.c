#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} node_t;

void print_node(const node_t* head)
{
    const node_t* ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    puts("");
}

void destroy(node_t* head) /*호출한 블록에서 argument로 전달한 head에 NULL을 대입한다.*/
{
    node_t* ptr = head;

    while (ptr != NULL) {
        node_t* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }    
}

void insert_front(node_t** phead, int n)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->value = n;
    new_node->next = *phead;

    *phead = new_node;   
}

void insert_sorted(node_t** phead, int n)
{
    node_t* new_node = malloc(sizeof(node_t));
    node_t** pp = phead;

    while (*pp != NULL) {
        if ((*pp)->value >= n) {
            break;
        }
        pp = &(*pp)->next;
    }

    new_node->value = n;
    new_node->next = *pp;

    *pp = new_node;
}

void remove_node(node_t** phead, int n)
{
    node_t** pp = phead;
    node_t* tmp;

    while (*pp != NULL) {
        if ((*pp)->value == n) {
            break;
        }
        pp = &(*pp)->next;
    }

    tmp = (*pp)->next;
    free(*pp);
    *pp = tmp;
}

int main(void)
{
    node_t* head = NULL;

    insert_front(&head, 3);
    insert_front(&head, 5);
    insert_front(&head, 2);
    insert_front(&head, 0);
    print_node(head);

    remove_node(&head, 3);
    remove_node(&head, 2);
    print_node(head);

    insert_sorted(&head, 4);
    insert_sorted(&head, 1);
    print_node(head);

    remove_node(&head, 1);
    remove_node(&head, 0);
    print_node(head);    

    destroy(head);
    head = NULL;
    return 0;
}
