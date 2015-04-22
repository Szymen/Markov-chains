#include "linked_list.h"
#include <stdio.h>


typedef struct{
	int size; /*ile jest nastepnikow*/
	node* possible; /*nastepniki */
}assoc_tab;

void make_trans_from_file(char* out_file, assoc_tab *where[]); /*tworzy tablice przejsc na podstawie pliku*/

void write_trans_to_file(char* out_file, assoc_tab *from[], int assoc_tab_size); /*zapisuje przejscia do pliku */
char* get_word_by_id(node* first,int number);


void assoc_push(assoc_tab* where, char *word); /*dodaje do tablicy przejsc pod wart. hash*/

char* get_by_hash(int hash_val, int number); /*zwraca slowo na pozycji number z tablicy przejsc, jezeli nie istnieje podaje pusty string */

