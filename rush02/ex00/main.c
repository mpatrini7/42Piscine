#include "rush02.h"
#include "functions.h"
#include <stdio.h>//TODO da levere con le printf

int main(int argc, char* argv[])
{
    if(argc == 1){//non ho nulla e prendo da tastiera
        
    }
    else if(argc == 2){//ho sono una cosa

        if(my_atoi(argv[1]) < 0){
            error();
            return (1);
        }
        else
            see_diz("dizionario/diz.en.txt",argv[1]);
    }
    else if(argc == 3){//ho due cose e devo fare cosa?
        if(my_atoi(argv[2]) < 0){
            error();
            return (1);
        }
        else
            see_diz(argv[1],argv[2]);
    }
    else{
        error();
        return (1);
    }
    return (0);
}

void error(){
    write(err, "Error\n", 6);
}

void error_diz(){
    write(err, "Dict Error\n", 11);
}

void see_diz(char* file, char* num){

//    printf("passato \"%s\"\n",num);
    int num_righe;
    char** tab;
    t_nodo* diz;
    
    num_righe=get_righe(file);
    tab = generate_file_tab(file,num_righe);
    if(!tab){
        error_diz();
         //free tab
         //free diz
         return;
     }
    diz = generate_diz(tab,num_righe);
    if(!diz){
        error_diz();
        //free tab
        //free diz
        return;
    }
//	stampa_lista(diz);
    print_numero(diz, num);
}

void print_numero(t_nodo* diz,char* num){
    num++;
    if(diz) num++;
}
