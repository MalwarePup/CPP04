#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "\033[1;34m\n--- Animal tests ---\033[0m" << std::endl;
	const int numAnimals = 10;
	Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new Dog();
	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < numAnimals; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	std::cout << "\033[1;34m\n--- Dog deep copy test ---\033[0m" << std::endl;
	Dog originalDog;
	originalDog.setIdea("Chase the cat", 0);
	Dog copiedDog = originalDog;

	std::cout << "Original Dog's idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea: " << copiedDog.getIdea(0) << std::endl;

	originalDog.setIdea("Sleep all day", 0);
	std::cout << "Original Dog's new idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea after original changed: " << copiedDog.getIdea(0) << std::endl;

	std::cout << "\033[1;34m\n--- Cat deep copy test ---\033[0m" << std::endl;
	Cat originalCat;
	originalCat.setIdea("Catch the mouse", 0);
	Cat copiedCat = originalCat;

	std::cout << "Original Cat's idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied Cat's idea: " << copiedCat.getIdea(0) << std::endl;

	originalCat.setIdea("Eat the fish", 0);
	std::cout << "Original Cat's new idea: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied Cat's idea after original changed: " << copiedCat.getIdea(0) << std::endl;

	return 0;
}
