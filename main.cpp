#include <stdio.h>

//struct node_t
//{
//	struct linked_list_t *next;
//	// struct linked_list_t* prev;
//};

#define UNUSED(v) ( ( void ) v )


#define max(a,b) ( ( a ) > ( b ) ? ( a ) : ( b ) )
#define min(a,b) ( ( a ) < ( b ) ? ( a ) : ( b ) )

struct list_t
{
	int data;
	struct list_t *next;
};



list_t* list_create()
{
	list_t* l = new list_t;

	l->data = 0;
	l->next = 0;

	return l;
}

void list_add(list_t* head, int value)
{
    list_t* new_node = list_create();
    new_node->data = value;

    list_t* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new_node;
}

void list_destroy(list_t* head)
{
    list_t* current = head;
    while (current != nullptr)
    {
        list_t* next = current->next;
        delete current;
        current = next;
    }
}

list_t* list_merge(list_t* left, list_t* right)
{
    list_t* merged_list = list_create();
    list_t* current = merged_list;

    while (left != nullptr || right != nullptr)
    {
        if (left != nullptr && (right == nullptr || left->data < right->data))
        {
            current->next = list_create();
            current->next->data = left->data;
            current = current->next;
            left = left->next;
        }
        else
        {
            current->next = list_create();
            current->next->data = right->data;
            current = current->next;
            right = right->next;
        }
    }

    return merged_list->next;
}

void print_list(list_t* list, const char* title)
{
    list_t* current = list;
    printf("%s: ", title);
    while (current != nullptr)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char** argv, char **envp )
{
    UNUSED(argc);
    UNUSED(argv);
    UNUSED(envp);

    list_t* head1 = list_create();
    list_add(head1, 1);
    list_add(head1, 3);
    list_add(head1, 5);
    list_add(head1, 7);

    list_t* head2 = list_create();
    list_add(head2, 2);
    list_add(head2, 4);
    list_add(head2, 6);
    list_add(head2, 8);
    list_add(head2, 10);
    list_add(head2, 12);
    list_add(head2, 16);

    print_list(head1->next, "List1");
    print_list(head2->next, "List2");

    list_t* m = list_merge(head1->next, head2->next);

    print_list(m, "Merged List");

    list_destroy(m);
    list_destroy(head1);
    list_destroy(head2);

    return 0;
}