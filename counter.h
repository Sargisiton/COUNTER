class Counter{
    private:
         std::string str2;
         double t;
    public:
        void EXECUTE();
        void MAINEXECUTE();
        void fun2();//�B�z�t��
        void fun1();//�B�z�j��Q����
        bool compare(std::string opA,std::string opB);
        double result_function2(double t1,double t2);
        double result_function1(double t1,double t2);
        void result();
        void parseFormula();
};
