#ifndef VECTORCLASS
#define VECTORCLASS

typedef struct vectorchar
{
    char* arr;
    unsigned int size;
    unsigned int capacity;

    int  (*init)(struct vectorchar*);
    void (*push)(struct vectorchar*, char);
    void (*pusharr)(struct vectorchar*, char*);
    void (*delete)(struct vectorchar*);
} VectorChar;

int initVectorChar(VectorChar*);
void pushVectorChar(VectorChar*, char);
void pushArrVectorChar(VectorChar*, char*);
void deleteVectorChar(VectorChar*);

#endif //VECTORCLASS