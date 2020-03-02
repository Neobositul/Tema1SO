#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct list{
    char *key;
    char *val;
    struct list *next;
};

struct map{
    int size;
    struct list **lists;
};

struct map *Create_Map(int size){
    int i;

    struct map *m = (struct map *)malloc(sizeof(struct map));

    m->size = size;
    m->lists = (struct list **)malloc(sizeof(struct list *) * size);

    for(i = 0; i < size; i++){
        m->lists[i] = NULL;
    }

    return m;
}

int Hash_Func(char *key){
    int position = (int)key[0];
    return position;
}

void add(struct map *m, char *key, char *val){
    int position = Hash_Func(key);
    struct list *aux = m->lists[position];
    struct list *new = (struct list *)malloc(sizeof(struct list));

    new->key = key;
    new->val = val;
    new->next = aux;
    m->lists[position] = new;
}

char *val_of(struct map *m, char *key){
    int position = Hash_Func(key);
    struct list *aux = m->lists[position];

    while (strcmp(key, aux->key) != 0){
        aux = aux->next;
    }
    if(aux == NULL){
        return "Nu exita!";
    }

    return aux->val;
}

int main(int argc, char *argv[]){
    struct map *Map = Create_Map(100);

}