#include "rush02.h"
#include "functions.h"
#include <stdio.h>//TODO da levere con le printf

char** generate_file_tab(char* file,int num_righe){
    
    int i;
    int len_righe;
    char** tab;
    
    len_righe = 1000;
    i = 0;
    tab = malloc(sizeof(*tab)*num_righe);
    if(!tab){
        return 0;
    }
    while(i<num_righe){
        tab[i]=malloc(sizeof(**tab)*len_righe);
        if(!tab[i])
            return 0;
        i++;
    }
    tab = fill_tab(file,tab);

    return tab;
}

t_nodo*   generate_diz(char** table,int num_righe){

	int i;
	int key;
	int decine;
	t_nodo* diz;
	
	i=0;
	diz=NULL;
	while(i<num_righe){
//printf("atoi di %s\n",table[i]);
		key = my_atoi2(table[i],&decine);
		diz=agg_ordinato_unico(key,decine,nome_key(table[i]),diz);
		i++;
	}
	return diz;
}

void stampa_lista(t_nodo *succ)
{
	if(succ != 0){
		printf("%d -> ",succ->valore);
		printf("%d -> ",succ->decine);
		printf("%s",succ->nome);
		printf("\n");
		stampa_lista (succ->next);
	}
	else{
		printf("NULL\n");
	}
}

t_nodo* agg_ordinato_unico(int num,int decine,char* nome,t_nodo *succ){
    if(succ==NULL){
        t_nodo *nuovo=malloc(sizeof(t_nodo));
        nuovo->next=succ;
        nuovo->valore=num;
        nuovo->decine=decine;
        nuovo->nome=nome;
        succ=nuovo;
        return succ;
    }
    else{
        if(decine>=succ->decine){
            if(succ->valore==num && succ->decine==decine ){
                return succ;
                }
            else{
                t_nodo *nuovo=malloc(sizeof(t_nodo));
                nuovo->next=succ;
                nuovo->valore=num;
                nuovo->decine=decine;
                nuovo->nome=nome;
                succ=nuovo;
        return succ;
            }
        }
        else{
            succ->next=agg_ordinato_unico(num,decine,nome,succ->next);
            return succ;
        }
    }
}

int my_atoi(char* str){

    int n;
    int i;
    
    i = 0;
    n = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= '0' && str[i] <= '9'){
            n = n * 10 + (str[i] - '0');
        }
        else
            return(-1);
        i++;
    }
    return (n);
}


char* nome_key(char* str){

	int i;

	i=0;
	while(str[i]>='0' && str[i]<='9')
		i++;
	while(str[i] == ' ' || str[i] == ':')
        i++;
	return &str[i];
    
}

int my_atoi2(char* str,int *ord){
	int i;
	int n;
    int flag;
	int decine;
	
    flag=0;
	decine=0;
	i=0;
	n=0;
	while(str[i]!='\0'){
		if(str[i]>=48 && str[i]<=57){
            if(n<21474836 && flag == 0){
                n=n*10+(str[i]-'0');
                decine++;
            }
            else{
                flag=1;
                decine++;
            }
		}
		else{
            if(flag)
                n=1;
			*ord=decine;
			return (n);
		}
		i++;
	}
    if(flag)
        n=1;
	*ord=decine;
	return (n);
}

int get_righe(char* file)
{
    int i[4];
    char* buffer;

    i[0] = 0;
    i[2] = open(file,O_RDONLY);
    buffer = (char*) malloc(sizeof(char)*SIZE_1B);
    if(!buffer){
        close(i[2]);
        return(0);
    }
    buffer[0] = '\0';
    i[1]= read(i[2], &buffer[0], SIZE_1B);
    while(i[1]>0){
        while(i[1]>0 && buffer[0]!='\n'){
            if( !is_printable(buffer[0]) ){
                close(i[2]);
                free(buffer);
                return(0);
            }
            i[1] = read(i[2], &buffer[0], SIZE_1B);
        }
        i[0]++;
        i[1] = read(i[2], &buffer[0], SIZE_1B);
    }
    return i[0];
}


char** fill_tab(char* file,char** tab){//todo non so se serve davvero il numrighe
    
    int i;
    int j;
    int fd;
    int n;
    char* buffer;

    i=0;
    fd = open(file,O_RDONLY);
    buffer = (char*) malloc(sizeof(char)*SIZE_1B);
    if(!buffer){
        close(fd);
        return(0);
    }
    buffer[0] = '\0';
    n= read(fd, &buffer[0], SIZE_1B);
    while(n>0){
        j=0;
        while(n>0 && buffer[0]!='\n'){
            tab[i][j]=buffer[0];
            
            
            n = read(fd, &buffer[0], SIZE_1B);
            j++;
        }
        tab[i][j]='\0';
        i++;
        n = read(fd, &buffer[0], SIZE_1B);
    }
    return tab;
}

int is_printable(char c){
    if (c < 32 || c > 126)
        return (0);
    else
        return (1);
}




















