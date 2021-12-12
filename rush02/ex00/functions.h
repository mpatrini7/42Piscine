#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void error(void);///
void error_diz(void);///
int my_atoi(char* str);///
int is_printable(char c);///
void see_diz(char* file, char* num);//
char** generate_file_tab(char* file,int num_righe);///
t_nodo*   generate_diz(char** table,int num_righe);///
void print_numero(t_nodo* diz,char* num);//
int get_righe(char* file);///
void stampa_lista(t_nodo *succ);///
t_nodo* agg_ordinato_unico(int num,int decine,char* nome,t_nodo *succ);///
char** fill_tab(char* file,char** tab);
int my_atoi2(char* str,int *ord);//
char* nome_key(char* str);//


#endif
