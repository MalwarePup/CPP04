#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Animal type (" << type << ") constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	if (this != &animal)
	{
		_type = animal._type;
	}
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

std::string AAnimal::getType() const
{
	return _type;
}

void AAnimal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
