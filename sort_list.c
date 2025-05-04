
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*start;
	int		tmp;
	int		sorted;

	if (!lst)
		return (NULL);
	sorted = 0;
	start = lst;
	while (!sorted)
	{
		sorted = 1;
		lst = start;
		while (lst->next)
		{
			if (!cmp(lst->data, lst->next->data))
			{
				tmp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = tmp;
				sorted = 0;
			}
			lst = lst->next;
		}
	}
	return (start);
}


//////////////////////////////////
// alternativa
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;//temp
	t_list	*start;

	start = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)// se uguale a zero non e' ordinato
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst = lst->next; // vai l nodo succ
		return (start);
	}
}


// int ascending(int a, int b)
// {
// 	return (a >= b);
// }

//TO TEST
// Funzione per creare un nuovo nodo
t_list *create_node(int value)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

// Funzione per stampare la lista
void print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(void)
{
	// Creo manualmente la lista: 3 -> 1 -> 4 -> 2
	t_list *n1 = create_node(3);
	t_list *n2 = create_node(1);
	t_list *n3 = create_node(4);
	t_list *n4 = create_node(2);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	printf("Lista prima dell'ordinamento:\n");
	print_list(n1);

	t_list *sorted = sort_list(n1, ascending);

	printf("Lista dopo l'ordinamento:\n");
	print_list(sorted);

	// Pulizia memoria (opzionale)
	free(n1);
	free(n2);
	free(n3);
	free(n4);

	return 0;
}
