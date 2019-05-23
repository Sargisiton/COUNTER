class Counter{
    private:
         std::string str2;
         double t;
    public:
        void EXECUTE();
        void MAINEXECUTE();
        void fun2();//處理負數
        void fun1();//處理大於十的數
        bool compare(std::string opA,std::string opB);
        double result_function2(double t1,double t2);
        double result_function1(double t1,double t2);
        void result();
        double result(std::string tr);
        void parseFormula();
        bool judge(std::string tr);
        bool if_judge(char c);
        std::string judge_fail1(std::string tr);
        std::string judge_fail2(std::string tr);
        int get_relation(std::string tr);
        bool if_true(int i,int a,int b);
};
