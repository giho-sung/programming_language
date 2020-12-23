#include <iostream>
#include <cmath>

class Point {
    private:
        int _x, _y;
    public: 
        Point(int x,int y);

        int get_x();
        int get_y();
        double distance(Point& another_point);
        void get_line(Point& another_point, double& a, double& b, double& c);
};

Point::Point(int x, int y){
    _x = x;
    _y = y;
}

int Point::get_x() {
    return _x;
}

int Point::get_y() {
    return _y;
}

void Point::get_line(Point& another_point, double& a, double& b, double& c){
    double x = (double) get_x();
    double y = (double) get_y();
    double x_ = (double) another_point.get_x();
    double y_ = (double) another_point.get_y();

    if( x == x_ ) {
        if( y == y_) {
            a = 0;
            b = 0;
            c = 0;
        }else { // y!= y_
            b = 0;
            
            a = 1;
            c = - a * x;
        }
    } else { // x != x_
        if( y == y_) {
            a = 0;

            b = 1;
            c = - b * y;
        }else { // y != y)
            a = 1;
            b = (x_-x) / (y-y_);
            c = -a * x + (x-x_)/(y-y_)*y;
        }
    }
}


double Point::distance(Point& another_point){
    return std::sqrt( std::pow(get_x() - another_point._x,2) + std::pow(get_y() - another_point._y,2) );
}


class Geometry {
    private:
        // an array which contaning 100 Points.
        Point* point_array[100];
    

    public:
        Geometry(Point **point_list); // point_list is array of pointer of one Point.
        Geometry();

        void AddPoint(Point &point);

        // the function calculating distance between all points.
        void PrintDistance();

        // the function printing the number of meet between the lines which can be made by all points.
        void PrintNumbMeets();

        void print_list();
};

void Geometry::print_list() {
    for( unsigned int i = 0 ; nullptr != point_array[i] ; i++ ){
        std::cout << i << "th Point [" << point_array[i]->get_x() << ", " << point_array[i]->get_y() << "]" << std::endl;
    }
}



int main() {

    Point** point_list = new Point*[30];
    const unsigned int initial_Point_num = 10;

    std::cout.precision(3);
    
    // initial point list generation
    for(unsigned int i = 0; i < initial_Point_num ; i++){
        Point *point = new Point(i,i+1);
        point_list[i] = point;
    }

    Geometry geometry(point_list);

    Point pt(100,100);
    //geometry.AddPoint(pt);
    geometry.PrintNumbMeets();

    //geometry.PrintDistance();
    geometry.print_list();
    
    

    return 0;
}


Geometry::Geometry( Point **point_list ) {
    // copying the pointer of Point not deep copying Point objects.
    for(unsigned int i = 0 ; point_list[i] != nullptr ; i++){
        point_array[i] = point_list[i];
    }
}

void Geometry::AddPoint(Point &point){

    // find where is the end of array
    unsigned int end_index;
    for( end_index = 0 ; nullptr != point_array[end_index] ; end_index++);

    point_array[end_index] = &point;

    return ;
}

void Geometry::PrintDistance() {
    
    for( unsigned int i =0 ; point_array[i] != nullptr ; i++ ) {
        std::cout << "Distance of " << i << " with ";
        for( unsigned int j = i+1 ; point_array[j] != nullptr ; j++ ) {
            Point* point_i = point_array[i];
            Point* point_j = point_array[j];
            double distance = point_i->distance(*point_j);
            std::cout << j << " :" << distance << " , \t";
        }
        std::cout << std::endl;
    }
}

void Geometry::PrintNumbMeets(){

    unsigned int total_number_of_meet = 0;
    
    for( unsigned int i = 0 ; nullptr != point_array[i] ; i++ ) {
        for( unsigned int j = i + 1 ; nullptr != point_array[j] ; j++ ) {
            // make ax + b + c = 0 
            double a,b,c;
            point_array[i]->get_line(*point_array[j],a,b,c);

            // it add points same with i and j.
            for( unsigned int k = i ; nullptr != point_array[k] ; k++ ) {
                for (unsigned int l = j; (nullptr != point_array[l]) && (k != l)  ; l++ ) {
                    double check_minus = ( a*point_array[k]->get_x() + b*point_array[k]->get_y() + c ) * ( a*point_array[l]->get_x() + b*point_array[l]->get_y() + c );
                    if( check_minus <= 0) {
                        total_number_of_meet++;
                    }
                }
            }
            total_number_of_meet -= 1;
        }
    }



    std::cout << "The number of meet is " << total_number_of_meet << std::endl;

}