#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
struct node *game(struct node *head, int N, int k)
{
    struct node *p = NULL;
    struct node *q = NULL;
    int i;
    while (head->next != NULL)
    {
        i = 1;
        p = q = head;
        while (i != k - 1)
        {
            p = p->next;
            i = (i + 1) % N;
        }
        q = p->next;
        if (p->next == p)
        {
            head ->next == NULL;
            break;
        }
        p->next = q->next;
        printf("Friend %d is shot dead\n",q->data);
        free(q);
        q = p;
        head = p->next;
    }
    return head;
}
int main()
{
    struct node *r = NULL, *p = NULL, *head = NULL;
    int ch = 0, val, fr, k;
    printf("Enter number of friends : ");
    scanf("%d", &fr);
    printf("Enter the skip value : ");
    scanf("%d", &k);

    while (ch != fr)
    {
        p = (struct node *)malloc(sizeof(struct node));
        if (p != NULL)
        {
            printf("Enter friend no. : ");
            scanf("%d", &val);
            p->data = val;
            if (r == NULL && head == NULL)
            {
                r = head = p;
            }
            else
            {
                r->next = p;
                r = p;
            }
        }
        ch++;
    }
    r->next = head;
    display(head);
    head = game(head, fr, k);
    printf("Winner of the game is friend no. %d ",head->data);
}
