#include"vector.hpp"


int main(void){
    vector* p_vector = new vector; 

    p_vector->push_back(100); 
    p_vector->show("after pushing back 100"); 
    
    p_vector->push_back(200); 
    p_vector->show("after pushing back 200"); 

    p_vector->push_back(300); 
    p_vector->show("after pushing back 300"); 

    p_vector->push_back(400); 
    p_vector->show("after pushing back 400"); 
    
    p_vector->push_back(500); 
    p_vector->show("after pushing back 500"); 

    delete p_vector; 
    p_vector = 0; 

    return (0); 
}


