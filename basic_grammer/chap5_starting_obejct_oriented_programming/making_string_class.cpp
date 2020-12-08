#include <iostream>
#include <string.h>

class string {
    char *str;
    int len;

    public:
        string(char c, int n); // the string which have n th char of c;
        string(const char *s);
        string(const string &s);
        ~string();

        void add_string(const string &s);
        void copy_string(const string &s);
        char* get_str();
        int strlen();
};



int main(){
    
    string a('a',1);
    std::cout << a.strlen() << std::endl;
    
    string b('b',2);
    string c = a;
    string d = a;
    
    c.add_string(b);
    d.copy_string(c);

    std::cout << "b: " << b.get_str() << std::endl;
    std::cout << "c: " << c.get_str() << std::endl;
    std::cout << "d: " << d.get_str() << std::endl;
    
    return 0;
}

char* string::get_str() {
    return str;
}

string::string(char c, int n){
    str = new char[n +1];
    for( unsigned int i = 0; i < n ; i++ ) {
        str[i] = c;
    }
    str[n] = '\0';
    len = n;
}

string::string(const char *s){
    
    
    unsigned int i = 0;
    for(i = 0 ; 0 != s[i] ; i++ );
    int len_s = i - 1;
    
    str = new char[len_s+1];
    for(i = 0 ; 0 != s[i] ; i++ ){
        str[i] = s[i];
    }

    len = len_s;
}
string::string(const string &s){
    str = new char[s.len + 1];
    for( unsigned int i = 0 ; i <= s.len; i++ ){
        str[i] = s.str[i];
    }
    len = s.len;

}

void string::add_string( const string &s ) {
    
    char* str_temp = str;
    str = new char[ len + s.len + 1 ];
    for( unsigned int i = 0 ; i < len ; i++) {
        str[i] = str_temp[i];
    }
    for( unsigned int i = 0 ; i < s.len ; i++ ) {
        str[len + i] = s.str[i];
    }
    str[len+s.len] = '\0';
    len += s.len;

    delete[] str_temp;
}

void string::copy_string( const string &s ) {
    char *str_temp = str;
    str = new char[ s.len + 1];
    for( unsigned int i = 0 ; i <= s.len ; i++ ) {
        str[i] = s.str[i];
    }
    len = s.len;

    delete[] str_temp;

}

string::~string() {
    delete[] str;
}

int string::strlen() {
    return len;
}