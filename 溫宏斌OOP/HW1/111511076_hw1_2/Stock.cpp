#include "Stock.h"
const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;
double Stock::cur_price = 57.88;
bool Stock::trade_available = 1;

Stock::Stock(string name):owner_name(name),ticket_num(0),avg_buy_price(0){};
Stock::Stock(string name, int n1):owner_name(name),ticket_num(n1){};
void Stock::operator + (const Stock &purchased){
  this->total += this->cur_price * purchased.ticket_num;
  this->ticket_num += purchased.ticket_num;
  this->avg_buy_price = this->total / this->ticket_num;
  return ;
}
void Stock::operator - (const Stock &sold){
  this->total -= this->cur_price * sold.ticket_num;
  this->ticket_num -= sold.ticket_num;
  this->avg_buy_price = this->total / this->ticket_num;
  return ;
}

void Stock::buy(){
   if (trade_available == 1){
     int temp;
     cout << "How many tickets do you want to buy: ";
     cin >> temp;
     Stock purchased(owner_name,temp);
     *this + purchased;
     return ;
   }
   else{
    cout << "The trade is not available today." << endl;
    return ;
   }
 }
 
void Stock::sell(){
   if (trade_available == 1){
     int temp;
     cout << "How many tickets do you want to sell: ";
     cin >> temp;
     Stock sold(owner_name,temp);
     *this - sold;
     return ;
   }
   else {
     cout << "The trade is not available today." << endl;
     return ;
   }

}

void Stock::show_stock(){
  cout << owner_name << ", you have " << ticket_num << " stocks and the average price is " << avg_buy_price << endl;
  return ;
}

string Stock::get_owner_name() const{
  return owner_name;
}

void Stock::show_current_price(){
  cout << "------------------------------------------" << endl;
  cout << "current price of the stock: " << cur_price << endl;
  return ;
}
void Stock::check_trade_is_available(){
  if (abs(static_cast<double>(cur_price - init_price)) / init_price > 0.1) trade_available = 0;  
  if (trade_available == 0) 
    cout << "trade is not available anymore" << endl;
  return ;
}
void Stock::refresh_current_price(){
  double old = cur_price;
  cur_price = old + static_cast<double>(rand() % 500) / 100 - 2.5;
  show_current_price();
  return ;
}


/* static const double init_price;
 static const double limit_ratio;
 static double cur_price;
 static bool trade_available;
 int ticket_num;
 double avg_buy_price;
 double total;
 const string owner_name;*/
