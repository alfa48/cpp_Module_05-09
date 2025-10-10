#include "../hpp/ShrubberyCreationForm.hpp"
#include "../../Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("sCreationForm_default", 145, 137),  target("target")
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &sCreationForm) : AForm("ShrubberyCreationForm", 145, 137), target(sCreationForm.getTarget())
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Deconstructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &srcForm)
{
    if (this != &srcForm){AForm::operator=(srcForm);}
    return (*this);
}

std::string const &ShrubberyCreationForm::getTarget() const {return (this->target);}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());

    if (!outfile)
    {
        std::cerr << "Erro ao criar o arquivo " << this->getTarget() << "_shrubbery" << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    / ~*%  ~ ~\\" << std::endl;
    outfile << "  /~ ~   *   ~%~\\" << std::endl;
    outfile << " |%   ^  %  ^ % |" << std::endl;
    outfile << "  \\*_- *%  -_ */" << std::endl;
    outfile << "      \\\\||//" << std::endl;
    outfile << "       |  |"<< std::endl;
    outfile << "       |  |"<< std::endl;
    outfile << "       |  |"<< std::endl;
    outfile << "^^^%^^^^^%*^^^^^^^^^"<< std::endl;


    outfile.close();

    std::cout << "Arquivo '" << this->getTarget() << "_shrubbery' criado com sucesso" << std::endl;
}
