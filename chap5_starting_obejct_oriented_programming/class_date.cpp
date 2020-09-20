#include <iostream>


class Date {
    private:
        int year_;
        int month_;
        int day_;

    public:
        void SetDate(int year, int month, int date){
            year_ = year;
            month_ = month;
            day_ = date;
        }
        // ignore leap years.
        void AddDay(int inc){
            const int days_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // the number of day matchs (index) month 
            int remaining_days = days_of_month[month_] - day_;
            // when inc is same or less than remaining_day, just add inc to days_
            if (inc <= remaining_days) { // current month
                day_ += inc;
            }else { // next month
                // alining to 1st day of next month
                int days_from_next_months = inc - remaining_days - 1;
                AddMonth(1);
                day_ = 1;
                
                int check_remaining_days = days_from_next_months - days_of_month[month_];
                
                // to go within a month
                while(check_remaining_days >= 0){ 
                    // to next month
                    AddMonth(1);
                    day_ = 1;
                    days_from_next_months = check_remaining_days;

                    check_remaining_days = days_from_next_months - days_of_month[month_];
                }

                // just add days_from_next_month to day_.
                day_ += days_from_next_months;                


            }
        }
        void AddMonth(int inc) {
            int remaining_month = 12 - month_;
            // when inc is same or less than remaining_month, just add inc to month_
            // else, the change of year is needed.
            if (inc <= remaining_month) { // current year
                month_ += inc;
                
            }else { // next years
                // process to next year
                int months_of_next_years = inc - remaining_month;
                AddYear(1);
                month_ = 1;

                AddYear(months_of_next_years / 12);
                month_ += months_of_next_years % 12;
            }

        }
        void AddYear(int inc) {
            year_ += inc;
        }

        void ShowDate(){
            std::cout << "Year : " << year_ << " Month : " << month_ << " Day : " << day_ << std::endl;
        }
};

int main(){
    Date date;
    date.SetDate(2012,2,28);
    date.AddDay(3);
    date.ShowDate();
  
    return 0;
}