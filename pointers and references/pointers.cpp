#include <iostream>
#include <vector>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *fun(int *a, int*b){
    return a;
}

int main(int argc, char const *argv[])
{
    char a = 'q';
    char *b = &a;
    int *c = nullptr;
    int *d {nullptr};
    int e {0};
    double *f;
    std::string g = "asdfgas";
    unsigned long long *r {nullptr};
    
    std::cout<<sizeof(b)<<"--"<<b<<"--"<<*b<<std::endl;
    std::cout<<&e<<"--"<<f<<std::endl;
    

    int as {20};
    int *as_p = &as;

    std::cout<<&as <<"--"<<as_p<<std::endl;
    std::cout<<as<<"--"<<*as_p<<std::endl;
    
    std::vector<std::string> vec {"asd","qwe","zac"};
    std::vector<std::string> *vec_ptr {&vec};

    std::cout<<(*vec_ptr).at(0)<<std::endl;
    for (auto i : *vec_ptr){
        std::cout<< i <<std::endl;
    }



    //allocating memory at runtime
    int* neww {};
    neww = new int;
    std::cout<<neww<<std::endl;
    std::cout<<*neww<<std::endl;
    *neww = 10;
    std::cout<<neww<<std::endl;
    std::cout<<*neww<<std::endl;
    delete neww;

    int *asd = {};
    int size = 100;
    std::cout<<"neww"<<std::endl;
    
    asd = new int[size];
    std::cout<<asd<<std::endl;
    std::cout<<*asd<<std::endl;
    asd[0] = 10;
    asd[1] = 20;
    *(asd+2) = 30;
    std::cout<<asd[0]<<"--"<<asd[1]<<"---"<<*(asd+2)<<std::endl;
    delete [] asd;

    int scores[] = {5,10,15};
    std::cout<<scores<<std::endl;
    int *rr = scores;
    std::cout<<rr<<std::endl;
    std::cout<<rr+1<<std::endl;
    std::cout<<rr+2<<std::endl;
    std::cout<<*++rr<<std::endl;
    std::cout<<*rr++<<std::endl;
    
    const double* qwe = {nullptr}; //pointer to constant = data pointed cant be changed
    double *const qwer = {nullptr}; //constant pointer = pointer cant be changed
    const double *const qwert ={nullptr};//constant pointer to constant = data and pointer both cant be changed


    int po=10;int co = 20;
    std::cout<<po<<"--"<<co<<std::endl;
    swap(&po, &co);
    std::cout<<po<<"--"<<co<<std::endl;
    

    

    std::cout<<"completed"<<std::endl;
}
