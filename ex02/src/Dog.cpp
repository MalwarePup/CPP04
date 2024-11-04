#include <iostream>
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		Brain *tmp = new Brain(*other._brain);
		delete _brain;
		_brain = tmp;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
	_brain = NULL;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof woof" << std::endl;
}

void Dog::setIdea(const std::string &idea, int index)
{
	_brain->setIdea(idea, index);
}

std::string Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}


