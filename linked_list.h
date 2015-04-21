typedef struct node{
	struct node *next;
	char *word;
}node;




void list_push(char* data,node* first); /*dodaje na koniec listy podane slowo */
				    /*node* first- wskaźnik na pierwszy element listy  */

/*wiecej mozliwosci nie bedzie uzywanych*/
