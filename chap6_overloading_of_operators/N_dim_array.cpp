#include <iostream>


class Array;
class Int;


class Array {
     
    friend Int;
    
    const int dim; // dimension of array
    int* size;

    struct Address {
        // the lowest level( dim - 1 ) points array of data.
        // other levels point 1 step lower level of Address. 
        int level;
        void* next;
    };

    Address* top;

    

    public:


        class Iterator{
            int* location;
            Array* arr;

            public:
                Iterator(Array* arr, int* loc = nullptr) : arr(arr) {
                    location = new int[arr->dim];
                    for (int i = 0; i != arr->dim; i++) {
                        location[i] = (loc != nullptr ? loc[i] : 0);
                    }
                }
                Iterator(const Iterator& itr) : arr(itr.arr) {
                    location = new int[arr->dim];
                    for (int i = 0; i != arr->dim; i++)
                        location[i] = itr.location[i];
                }
                ~Iterator() { delete[] location; }
                    
        

                Iterator& operator++();
                Iterator operator++(int) {
                    Iterator temp(*this);
                    ++(*this);
                    return temp;
                }
                Int operator*();
                Iterator& operator=(const Iterator& itr);
                bool operator!=(const Iterator& itr);


        };


        
        Array(int dim, int* array_size);
        Array(const Array& arr);
        ~Array();

        void initialize_address(Address *current);
        void delete_address(Address *current);
        
        Int operator[](const int index);

        Iterator begin() {
            int* arr = new int[dim];
            for (int i = 0; i != dim; i++) arr[i] = 0;

            Iterator temp(this, arr);

            return temp;
        }
        Iterator end() {
            int* arr = new int[dim];
            arr[0] = size[0];
            for (int i = 1; i < dim; i++) arr[i] = 0;

            Iterator temp(this, arr);
            delete[] arr;

            return temp;
        }
 
};

class Int {
    void* data;

    int level;
    Array* array;

    public:
        Int(int index, int _level, void *_data, Array *_array);
        Int(const Int& i) : data(i.data), level(i.level), array(i.array) {}

        operator int() {
            if (data) return *static_cast<int *>(data);
            return 0;
        }

        Int& operator=(const int& a) {
            if (data) *static_cast<int *>(data) = a;
            return *this;
        }

        Int operator[](const int index);

};


int main() {

    int size[] = {2, 3, 4};
    Array arr(3, size);
    Array::Iterator itr = arr.begin();
    for (int i = 0; itr != arr.end(); itr++, i++) (*itr) = i;
    for (itr = arr.begin(); itr != arr.end(); itr++)
        std::cout << *itr << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = (i + 1) * (j + 1) * (k + 1) + arr[i][j][k];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                std::cout << i << " " << j << " " << k << " " << arr[i][j][k]
                << std::endl;
            }
        }
    }

    return 0;
}

// Int 
Int::Int(int index, int _level = 0, void *_data = nullptr, Array *_array = nullptr)
: level(_level) , data(_data) , array(_array) {
    if (level < 1 || index >= array->size[level-1]) {
        data = nullptr;
        return;
    }
    if (level == array->dim) { // saving int* to the data
        data = static_cast<void *>( 
        (static_cast<int *>(static_cast<Array::Address *>(data)->next) + index ));
    } else { // saving Address * to the data
        data = static_cast<void *>(
            (static_cast<Array::Address *>(static_cast<Array::Address *>(data)->next) + index));
    }
}

Int Int::operator[](const int index) {
    if(!data) return 0;
    return Int(index, level + 1, data, array );
}
// end Int
// Array
Array::Array(int dim, int* array_size) : dim(dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) size[i] = array_size[i];

    top = new Address;
    top->level = 0;

    initialize_address(top);
}

Array::Array(const Array& arr) : dim(arr.dim) {
    size = new int[dim];
    for (int i = 0; i < dim; i++) {
        size[i] = arr.size[i];
    }

    top = new Address;
    top->level = 0;

    initialize_address(top);
}
Array::~Array() {
    delete_address(top);
    delete[] size;
}



// dynamic allocation function with variable size of array.
// it deals with variable size of array by recurssive function.
void Array::initialize_address(Address *current) {
    if(!current) return;
    if(current->level == dim - 1) { // end condition of recurssive function.
        current->next = new int[size[current->level]];
        return ;
    }
    current->next = new Address[size[current->level]];
    for (int i = 0; i != size[current->level]; i++) {
        (static_cast<Address *>(current->next) + i)->level = current->level + 1;

        initialize_address(static_cast<Address *> (current->next) + i ); 
    }
}

void Array::delete_address(Address *current) {
    if(!current) return;
    for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
        delete_address(static_cast<Address *>(current->next) + i);
    }

    if(current->level == dim - 1){ // one step before int array
        delete[] static_cast<int *>(current->next);
    } else {
        delete[] static_cast<Address *>(current->next);
    }
}

Int Array::operator[](const int index) {
    return Int(index, 1, static_cast<void *>(top), this);
}

// Iterator in Array
Array::Iterator& Array::Iterator::operator++() {
    if(location[0] >= arr->size[0]) return (*this);

    bool carry = false;
    int i = arr->dim - 1;
    do {
        location[i]++;
        if (location[i] >= arr->size[i] && i >= 1) {
            location[i] -= arr->size[i];
            carry = true;
            i--;
        } else
            carry = false;
    } while (i >= 0 && carry);

    return (*this);
}

Int Array::Iterator::operator*() {
    Int start = arr->operator[](location[0]);
    for (int i = 1; i <= arr->dim - 1; i++) {
        start = start.operator[](location[i]);
    }
    return start;
}

Array::Iterator& Array::Iterator::operator=(const Iterator& itr){
    arr = itr.arr;
    location = new int[itr.arr->dim];
    for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];

    return (*this);
}
bool Array::Iterator::operator!=(const Iterator& itr){
    if(itr.arr->dim != arr->dim) return true;

    for (int i = 0; i != arr->dim; i++) {
        if (itr.location[i] != location[i]) return true;
    }

    return false;
}

// end Iterator in Array

// end Array