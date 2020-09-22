#include <iostream>

// to use strlen in string.h
#include <string.h>

class MyString {
    char* string_content;
    int string_length;
    int memory_capacity;

    public: 
        MyString(char c);

        MyString(const char* str);

        MyString(const MyString& str);
        ~MyString();

        int length() const;
        int capacity() const;
        void reserve(int size);

        void print() const;
        void println() const;

        MyString& assign(const MyString& str);
        MyString& assign(const char* str);
        char at(int i) const ;
        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, char c);
        MyString& erase(int loc, int num);
        int find(int find_from, MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        int compare(const MyString& str) const;
        
    
};


int main() {
    MyString str1("very long string");
    MyString str2("<some string inserted between>");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    str1.insert(5,str2);
    str1.println();

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();

    MyString str3("abcd");
    str3.println();
    str3.erase(1,2);
    str3.println();

    MyString str4("this is a very very long string");
    std::cout << "Location of first <very> in the string : " << str4.find(0,"very") << std::endl;
    std::cout << "Location of second <very> in the string : " 
    << str4.find(str4.find(0,"very")+1,"very") << std::endl;
 
    MyString str5("abcdef");
    MyString str6("abcde");

    std::cout << "str5 and str6 compare : " << str5.compare(str6) << std::endl;

    return 0;
}

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];
    memory_capacity = string_length;

    for( int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];
    memory_capacity = string_length;

    for(int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString() { delete[] string_content; }

int MyString::length() const {
    return string_length;
}

int MyString::capacity() const {
    return memory_capacity;
}

void MyString::reserve(int size) {
    if(size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for( int i = 0; i != string_length; i++) {
            string_content[i] = prev_string_content[i];
        }

        delete[] prev_string_content;
    }
}


void MyString::print() const {
    for( int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const {
    print();
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if(str.string_length > string_length) {
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.memory_capacity;
    }

    for(int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if(str_length > string_length) {
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    

    for(int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;

    return *this;
}

char MyString::at(int i) const {
    if(i >= string_length || i < 0) {
        return NULL;
    }else {
        return string_content[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    if(loc < 0 || loc > string_length) return *this;

    if(string_length + str.string_length > memory_capacity) {

        if(memory_capacity *2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for(i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }

        for(int j = 0; j != str.string_length; j++) {
            string_content[i+j] = str.string_content[j];
        }

        for(; i < string_length; i++) {
            string_content[str.string_length+i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = str.string_length + string_length;
        return *this;
    }

    for(int i = string_length -1; i >= loc; i--) {
        string_content[i+str.string_length] = string_content[i];
    }

    for(int i = 0; i < str.string_length; i++) {
        string_content[i+loc] = str.string_content[i];
    }

    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    if(num < 0 || loc < 0 || loc > string_length) return *this;

    int i;
    for(i = loc + num; i != string_length; i++) {
        string_content[i-num] = string_content[i];
    } 
    // when num exccced the number of string, num is limited

    num = std::min(num, string_length - loc);

    string_length -= num;
    return *this;
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for ( i = find_from; i <= string_length - str.string_length; i++) {
        for( j = 0; j < str.string_length; j++) {
            if(string_content[i+j] != str.string_content[j]) break;
        }
        if (j == str.string_length) return i;
    }

    return -1;
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const{
    // 1 means much later in the dictionary
    for(int i = 0; i < std::min(string_length, str.string_length); i++) {
        if(string_content[i] > str.string_content[i]) return 1;
        if(string_content[i] < str.string_content[i]) return -1;
    }

    if(string_length == str.string_length) return 0;
    
    else if(string_length > str.string_length) return 1;

    return -1;
}