#include "linked_list.h"
#include <stdio.h>


typedef struct{
	int size; /*ile jest nastepnikow*/
	node* possible; /*nastepniki */
}assoc_tab;

void make_trans_from_file(FILE *in, assoc_tab *where,int assoc_tab_size ); /*tworzy tablice przejsc na podstawie pliku*/

void write_trans_to_file(FILE *out, assoc_tab *from, int assoc_tab_size); /*zapisuje przejscia do pliku */


void assoc_push(assoc_tab* where, char *word); /*dodaje do tablicy przejsc pod wart. hash*/

char* get_by_hash(int hash_val, int number); /*zwraca slowo na pozycji number z tablicy przejsc, jezeli nie istnieje podaje pusty string */

