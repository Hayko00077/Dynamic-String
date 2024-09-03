#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_SIZE 4096

int* create_buffer(){
    return (int*)mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}
void destroy_buffer(int** buffer,int* size){
    munmap(*buffer,*size);
}


int* extend_buffer(int* buffer,int* size){
    int odd_size = *size;
    int new_size = odd_size + PAGE_SIZE;

int* new_buffer = (int*)mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if(new_buffer == MAP_FAILED){
        perror("mmap filed");
        return buffer;
        
    }
    for(int i = 0; i < odd_size / sizeof(int); i++){
            new_buffer[i] = buffer[i];
    }

    munmap(buffer,odd_size);

    *size = new_size;
    return new_buffer;
}


int* push_front(int* buffer, int* size, const int element){
    if(*size % PAGE_SIZE == 0 && *size != 0){
        buffer = extend_buffer(buffer,size);
    }

    for(int i = *size; i>0; i--){
        buffer[i] = buffer[i - 1];
    }
    buffer[0] = element;
    (*size)++;

    return buffer;
}


int* push_back(int * buffer, int * size, const int element){
   if(*size % PAGE_SIZE == 0 && *size != 0){
        buffer = extend_buffer(buffer,size);
    }

    buffer[*size] = element;
    (*size)++;

    return buffer;
}


int* remove_element(int* buffer, int* size, const int index){
    if(index < 0 || index >= *size){
        printf("index error");
        return buffer;
    }

    for(int i = index; i <= *size; i++){
            buffer[i] = buffer[i + 1];
    }
    (*size)--;
    return buffer;
}



void current_state(int* buffer, const int size){
    for(int i = 0; i < size; i++){
        printf("%d",buffer[i]);
    }
    printf("\n");
}


