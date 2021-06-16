//目标接口（新接口）
class ITarget{
public:
    virtual void process()=0; // 纯虚函数必须实现
};

//遗留接口（老接口）
class IAdaptee{
public:
    virtual void foo(int data)=0;
    virtual int bar()=0;
};

//遗留类型
class OldClass: public IAdaptee{
    //....
};

//对象适配器
class Adapter: public ITarget{ //继承  新接口
protected:
    IAdaptee* pAdaptee;//组合 老接口, 在新接口的子类里声明老接口的对象指针
    
public:
    
    Adapter(IAdaptee* pAdaptee){ // 初始化老对象
        this->pAdaptee=pAdaptee;
    }
    
    virtual void process(){  // 实现新接口里的纯虚函数
        int data=pAdaptee->bar();
        pAdaptee->foo(data);
        
    }
    
    
};


//类适配器
class Adapter: public ITarget,
               protected OldClass{ //多继承
               //继承ITarget类型, protected继承遗留类型
               
}


int main(){
    IAdaptee* pAdaptee=new OldClass();
    
    
    ITarget* pTarget=new Adapter(pAdaptee);
    pTarget->process();
    
    
}


class stack{
    deqeue container;
    
};

class queue{
    deqeue container;
    
};









