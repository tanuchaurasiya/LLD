#include <iostream>
using namespace std;

class Computer{
    public:  
        void setCPU(int c){
            cpu=c;
        }
        int getCPU(){
            return cpu;
        }
    private:
        int cpu;

};

class ComputerBuilder{
    public: 
        virtual void buildCPU(int cpu)=0; 
        
};

class DesktopComputerBuilder: public ComputerBuilder{
    public: 
        DesktopComputerBuilder(){
            com = Computer();
        }
        void buildCPU(int cpu) {
            com.setCPU(cpu);
        }
        Computer getComputer(){
            return com;
        }
    private:
        Computer com;
};

class Director: public DesktopComputerBuilder{
    public:
        Computer getDesktopComputerBuilder(ComputerBuilder* dcb){
            dcb->buildCPU(12);
            return dcb->getComputer();
        }
};



int main()
{
    ComputerBuilder* dcb = new DesktopComputerBuilder();
    Director dir;
    Computer com = dir.getDesktopComputerBuilder(dcb);
    cout<<com.getCPU()<<endl;

    return 0;
}