//
//  main.c
//  Debug
//
//  Created by 任 洪杰 on 2019/5/5.
//  Copyright © 2019 YiDian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int value;
    struct _Node *next;
}Node, *List;

List createList(int array[], int count) {
    if (array == NULL || count <= 0)
    {
        return NULL;
    }
    Node *head = NULL;
    Node *lastNode = NULL;
    for (int i = 0; i < count; ++i)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = array[i];
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            lastNode = node;
        } else {
            lastNode->next = node;
            lastNode = node;
        }
    }
    return head;
}

void deleteList(List head) {
    while (head) {
        Node *tmpNode = head->next;
        free(head);
        head = tmpNode;
    }
}

void printList(List head) {
    while (head) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

Node *reverseList(List head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node *pre = NULL;
    Node *cur = head;
    Node *next = NULL;//head->next;
    
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
        //next = next->next;
        
    }
    
    return cur;
}

int main() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = 1;
    printf("Node value:%d\n", node->value);
    printf("Hello World!\n");
    free(node);
    
    int array[] = {4, 8, 2, 9, 7};
    List list = createList(array, 5);
    printList(list);
    reverseList(list);
    printList(list);
    deleteList(list);
    
    return 0;
}

