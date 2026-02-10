template <typename T>
Array<T>::Array(){
    array = NULL;
    u_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n){
    array = new T[n]();
    u_size = n;
}

template <typename T>
Array<T>::Array(const Array &src){
    this->u_size = src.u_size;
    this->array = new T[src.u_size]();
    for (unsigned int i = 0; i < this->u_size; i++)
    {array[i] = src.array[i];}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src){
    if (this != &src){
        delete[] this->array;

        u_size = src.u_size;
        this->array = new T[src.u_size]();
        for (unsigned int i = 0; i < this->u_size; i ++)
        {this->array[i] = src.array[i];}
    }
    return *this;
}

template <typename T>
Array<T>::~Array(){if (array) {delete[] array;}}

// 
template <typename T>
T &Array<T>::operator[](unsigned int index){
    if (index >= this->u_size || this->array == NULL){throw OutOfRangeException();}
    return this->array[index];
}

template <typename T>
unsigned int Array<T>::size() const{return this->u_size;}