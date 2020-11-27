#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "models/patient.h"
#include "../controllers/cure.h"

int main(){
    int n, m;
    Patient value;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        add_patient(value);
    }
    for(int i = 0; i < m; i++){
        pop_head();
    }
    if(n - m > 0){
        printf("Need %d mode cure\n", n - m);
    }
    else{
        printf("All patients get the cure, %d cure left\n", m - n);
    }
    print_list();
    return 0;
}
