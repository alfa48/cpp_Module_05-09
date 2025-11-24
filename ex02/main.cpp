#include "./hpp/Base.hpp"
#include "./hpp/A.hpp"
#include "./hpp/B.hpp"
#include "./hpp/C.hpp"
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()



Base * generate(void){

    std::srand(static_cast<unsigned int>(std::time(0)));
    int num = std::rand() % 3;
    if (num == 0) return (new A());
    else if (num == 1) return (new B());
    else if (num == 2)return (new C());
    else {
        std::cout << "Error: algo deu errado!" << std::endl;
        return (NULL);
    }

}

void identify(Base* p){
    if (dynamic_cast<A *>(p)){
        std::cout << "Tipo real do objecto: A" << std::endl;
    }
    else if  (dynamic_cast<B *>(p)){
        std::cout << "Tipo real do objecto: B" << std::endl;
    }
    else if (dynamic_cast<C *>(p)){
        std::cout << "Tipo real do objecto: C" << std::endl;
    }
    else {std::cout << "Error: Tipo desconhecido!" << std::endl;}
}

void identify(Base& p){
   
            try
            {

                A &a = dynamic_cast<A &>(p);
                (void)a;
                std::cout << "Tipo real do objecto: A" << std::endl;
            }
            catch(const std::exception&)
            {
                try
                {
                    B &b = dynamic_cast<B &>(p);
                    (void)b;
                    std::cout << "Tipo real do objecto: B" << std::endl;
                }
                catch(const std::exception&)
                {
                    try
                    {
                        C &b = dynamic_cast<C &>(p);
                        (void)b;
                        std::cout << "Tipo real do objecto: C" << std::endl;
                    }
                    catch(const std::exception&)
                    {
                        std::cout << "Tipo desconhecido!" << std::endl;
                    }
                }
            }

}

int main(void){

        Base *realType = generate();
		if (realType == NULL)
			return (1);
		else
		{
			identify(realType);
			identify(*realType);
			delete (realType);
		}
        return (0);
}