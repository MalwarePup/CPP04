#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		Brain *tmp = new Brain(*other._brain);
		delete _brain;
		_brain = tmp;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
	_brain = NULL;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow meow" << std::endl;
}

void Cat::setIdea(const std::string &idea, int index)
{
	_brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
