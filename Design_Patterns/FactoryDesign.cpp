#include <iostream>
using namespace std;

class Shape{
    public:  
        virtual void draw()=0;
};

class Circle: public Shape{
    public: 
        void draw() {
            cout<<"circle draw called\n";
        }
};

class Rectangle: public Shape{
    public:
        void draw() {
            cout<<"rectangle draw called\n";
        }
};

class ShapeFactory{
    public:
        virtual Shape* createShape()=0;
};

class CircleFactory: public ShapeFactory{
    public:
        Shape* createShape(){
            Shape* obj = new Circle();
            return obj;
        }
};

class RectangleFactory: public ShapeFactory{
    public:
        Shape* createShape(){
            Shape* obj = new Rectangle();
            return obj;
        }
};

int main()
{
    cout<<"hello\n";
    CircleFactory* CircleFactoryObj= new CircleFactory();
    CircleFactoryObj->createShape()->draw();
    
    RectangleFactory* RectangleFactoryObj= new RectangleFactory();
    RectangleFactoryObj->createShape()->draw();

    return 0;
}