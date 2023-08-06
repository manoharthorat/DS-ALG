#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct point{
    double x, y, z;
};

void built_in_data_type(void);
void array_of_built_in_data_type(void);
void array_of_pointer_to_built_in_data_type(void);

void user_defined_data_type(void);
void array_of_user_defined_data_type(void);
void array_of_pointer_to_user_defined_data_type(void);

int main(void)
{
    built_in_data_type();
    array_of_built_in_data_type();
    array_of_pointer_to_built_in_data_type();

    user_defined_data_type();
    array_of_user_defined_data_type();
    array_of_pointer_to_user_defined_data_type();
    return 0;
}

void built_in_data_type(void)
{
    int * p = NULL;
    puts("built_in_data_type");

    p = (int *)malloc(sizeof(int));
    assert(p != NULL);
    memset(p, 0, sizeof(int));
    *p = 500;
    printf("*p = %d\n", *p);
    free(p);
    p = NULL;
}

void array_of_built_in_data_type(void)
{
    int *p = NULL;
    int i;
    int a_size = 5;
    puts("array_of_built_in_data_type");
    p = (int *)malloc(a_size * sizeof(int ));
    for(i = 0; i < a_size; ++i){
        p[i] = (i + 1) * 10;
    }

    for(i =0 ; i < a_size; ++i){
        printf("p(%d): %d \n", i, p[i]);
    }
    
    free(p);
    p = NULL;
}

void array_of_pointer_to_built_in_data_type(void){
    int ** pp = NULL;
    int i;
    int a_size = 5;
    puts("array_of_pointer_to_built_in_data_type");

    pp = (int**)malloc(a_size * sizeof(int*));
    assert(pp != NULL);
    memset(pp, 0, a_size * sizeof(int *));

    for(i = 0; i < a_size; ++i){
        pp[i] = (int*)malloc(sizeof(int));
        assert(pp[i] != NULL);
        *pp[i] = (i + 1) * 10;
    }

    for(i = 0; i < a_size; ++i)
    {
        printf("*pp[%d]: %d \n",i, *pp[i]);
    }

    for(i=0; i< a_size; ++i){
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);
    pp = NULL;
}

void user_defined_data_type(void){
    struct point * p_point = NULL;
    puts("user_defined_data_type");

    p_point = (struct point * )malloc(sizeof(struct point));
    assert(p_point);
    memset(p_point, 0, sizeof(struct point));
    p_point->x = 1.1;
    p_point->y = 2.2;
    p_point->z = 3.3;

    printf("p_point->x = %lf p_point->y = %lf p_point->z = %lf",
            p_point->x, p_point->y, p_point->z);
    free(p_point);
    p_point = NULL;
}

void array_of_user_defined_data_type(void){
    struct point * p_point = NULL;
    int a_size = 5;
    int i;
    puts("array_of_user_defined_data_type");
    p_point = (struct point *)malloc(a_size * sizeof(struct point));
    assert(p_point != NULL);
    memset(p_point, 0, a_size * sizeof(struct point * ));

    for(i =0; i < a_size; ++i){
        p_point->x = 1.1 + i;
        p_point->y = 2.2 + i;
        p_point->z = 3.3 + i;
    }

    for(i = 0; i <a_size; ++i){
        printf("p_point[%d].x:%.2lf p_point[%d].y:%.2lf p_point[%d].z:%.2lf\n", 
                i, p_point[i].x, i, p_point[i].y, i, p_point[i].z);
    }

    free(p_point);
    p_point = NULL;
}

void array_of_pointer_to_user_defined_data_type(void){
    struct point **pp_point = NULL;
    int a_size = 5;
    int i;
    puts("array_of_pointer_to_user_defined_data_type");
    pp_point = (struct point **)malloc(a_size * sizeof(struct point *));
    assert(pp_point != NULL);

    memset(pp_point, 0, a_size * sizeof(struct point *));
    for( i = 0; i < a_size; ++i){
        pp_point[i] = (struct point *)malloc(sizeof(struct point));
        assert(pp_point[i] != NULL);
        pp_point[i]->x = 1.1 + i;
        pp_point[i]->y = 2.2 + i;
        pp_point[i]->z = 3.3 + i;
    }

    for( i = 0; i < a_size; ++i){
        printf("pp_point[%d]->x:%.2lf pp_point[%d]->y:%.2lf pp_point[%d]->z:%.2lf\n", 
                i, pp_point[i]->x, i, pp_point[i]->y, i, pp_point[i]->z); 
    }

    for(i = 0; i< a_size; ++i){
        free(pp_point[i]);
        pp_point[i] = NULL;
    }

    free(pp_point);
    pp_point = NULL;
}
