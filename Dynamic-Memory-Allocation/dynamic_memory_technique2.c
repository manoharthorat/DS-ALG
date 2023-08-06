#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void build_in_data_type(void);
void array_of_build_in_data_type(void);
void array_of_pointer_to_build_in_data_type(void);

int main(void){
    build_in_data_type();
    array_of_build_in_data_type();
    array_of_pointer_to_build_in_data_type();
    return 0;
}

void build_in_data_type(void){
    int * ch = NULL;
    puts("build_in_data_type");
    ch = (char *)malloc(sizeof(char));

    //NULL return nahi na kele ? check this
    assert(ch != NULL); // malloc la aapn jewdhe bytes magitle tewdhe bhtetle aahet ka?
 
    memset(ch, 0, sizeof(ch));
    *ch = 'm';
    printf("Character = %c\n", *ch);
    free(ch);
    ch = NULL;
}

void array_of_build_in_data_type(void){
    int * ch = NULL;
    int a_size = 5;
    int i;
    puts("array_of_build_in_data_type");
    ch = (char *)malloc(sizeof(char) * a_size);
    assert(ch != NULL);

    // Ethe initialize direct values ne karat aahe so memset skip karu shakto
    for (i =0; i < a_size; ++i){
        ch[i] = 'a' + i;
    }

    for (i = 0; i < a_size; ++i){
        printf("%c \n", ch[i]);
    }
    free(ch);
    ch = NULL;
}

void array_of_pointer_to_build_in_data_type(void){
    int **chpp = NULL;
    int a_size = 5;
    int i;
    puts("array_of_pointer_to_build_in_data_type");
    chpp = (char**)malloc(sizeof(char*) * a_size);
    assert(chpp != NULL);
    memset(chpp, 0, a_size * sizeof(char*));

    for(i = 0; i < a_size; ++i){
        chpp[i] = (char*)malloc(sizeof(char));
        assert(chpp[i] != NULL);
        *chpp[i] = 'a' + i;
    }

    for(i = 0; i < a_size; ++i){
        printf("ch = %c\t", *chpp[i]);
    }

    for(i =0; i < a_size; ++i){
        free(chpp[i]);
        chpp[i] = NULL;
    }
    free(chpp);
    chpp = NULL;
}