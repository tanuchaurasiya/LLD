#include <iostream>
using namespace std;

class Pizza{
    public:  
        virtual void type()=0;
};

class NewYorkCheesePizza: public Pizza{
    public: 
        void type() {
            cout<<"NewYorkCheeseizza\n";
        }
};

class NewYorkCornPizza: public Pizza{
    public: 
        void type() {
            cout<<"NewYorkCornPizza\n";
        }
};

class ChicagoCheesePizza: public Pizza{
    public: 
        void type() {
            cout<<"ChicagoCheeseizza\n";
        }
};

class ChicagoCornPizza: public Pizza{
    public: 
        void type() {
            cout<<"ChicagoCornPizza\n";
        }
};


class PizzaFactory{
    public:
        virtual Pizza* createCheesePizza()=0;
        virtual Pizza* createCornPizza()=0;
};

class NewyorkPizzaFactory: public PizzaFactory{
    public:
        Pizza* createCheesePizza(){
            Pizza* obj = new NewYorkCheesePizza();
            return obj;
        }
        Pizza* createCornPizza(){
            Pizza* obj = new NewYorkCornPizza();
            return obj;
        }
};

class ChicagoPizzaFactory: public PizzaFactory{
    public:
        Pizza* createCheesePizza(){
            Pizza* obj = new ChicagoCheesePizza();
            return obj;
        }
        Pizza* createCornPizza(){
            Pizza* obj = new ChicagoCornPizza();
            return obj;
        }
};

int main()
{
    NewyorkPizzaFactory* nk = new NewyorkPizzaFactory();
    nk->createCheesePizza()->type();
    nk->createCornPizza()->type();

    ChicagoPizzaFactory* cg = new ChicagoPizzaFactory();
    cg->createCheesePizza()->type();
    cg->createCornPizza()->type();

    return 0;
}