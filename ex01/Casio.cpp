/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casio.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:23:25 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 17:00:20 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include "Organiser.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

void	WaitForCommand(PhoneBook *phonebook);
void	AddContact(PhoneBook *phonebook);
void	SearchContact(PhoneBook *phonebook);

int	main(void) {	
	PhoneBook	phonebook;
	DisplayHeader();
	DisplayGuide();
	DisplayFooter();
	WaitForCommand(&phonebook);
}

void	WaitForCommand(PhoneBook *phonebook) {
	while (true)
	{
		std::string command;
		
		std::cout << "⇝  ";
		std::cin >> command;
		if (command == "ADD")
			AddContact(phonebook);
		else if (command == "SEARCH")
			SearchContact(phonebook);
		else if (command == "EXIT") {
			Display("ℙense bem antes de nos invocar novamente.");
			//std::exit(0); // Finishing with exit makes memory still reachable.
			return ;
		} else {
			Display("𝒱igiai! 𝔑ão obedecemos a tais comandos! ৳");
		}
	}
}

void	AddContact(PhoneBook *phonebook) {	
	Contact	new_contact;
	std::string	input;
	std::string	temp;

	Display("༱ 𐍂evele qvem merece o pior dos castigos?");
	std::cin.ignore(); // Clears the newline character left in the buffer by the previous std::cin.
	std::cout << "Nome: ";
	std::getline(std::cin, input);
	temp = Trimmer(input);
	new_contact.set_name(temp);
	std::cout << "\033[A\033[2K"; // Erases current line from the terminal.

	std::cout << "Clã: ";
	std::getline(std::cin, input);
	temp = Trimmer(input);
	new_contact.set_surname(temp);
	std::cout << "\033[A\033[2K";

	std::cout << "Vulgo: ";
	std::getline(std::cin, input);
	temp = Trimmer(input);
	new_contact.set_nickname(temp);
	std::cout << "\033[A\033[2K";

	std::cout << "Contato: ";
	std::getline(std::cin, input);
	temp = Trimmer(input);
	new_contact.set_number(temp);
	std::cout << "\033[A\033[2K";

	std::cout << "Segredo mais obscuro: ";
	std::getline(std::cin, input);
	temp = Trimmer(input);
	new_contact.set_secret(temp);
	std::cout << "\033[A\033[2K";

	if (new_contact.get_name().empty() || new_contact.get_surname().empty()
	|| new_contact.get_nickname().empty() || new_contact.get_number().empty()
	|| new_contact.get_secret().empty()) {
		Display("𝔓reencha tvdo para não pvnir um inocente.");
	} else {
		phonebook->set_contact(new_contact);
		Display("༪ ℒocalizaremos e pvniremos essa alma. ࿂ ");
	}
}

void	SearchContact(PhoneBook *phonebook) {
	DisplayHeader();
	DisplayList(phonebook);
	DisplayFooter();
	if (phonebook->get_contact_count() == 0) {
		Display("𝔑ão indicaste almas para pvnir. Diga ADD.");
		return ;
	}
	std::cin.ignore();
	std::cout << "Diga o número e o segredo será revelado: ";
	std::string	input;
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]) && input[0] - '0' > 0
		&& input[0] - '0' <= phonebook->get_contact_count()) {
		int chosenContact;
		std::istringstream(input) >> chosenContact;
		// Another way of converting string to int. Needs the sstream library.
		DisplayContactInformation(phonebook, chosenContact - 1);
	} else {
		Display("O Ꙫráculo só pode te mostrar essas almas.");
	}
}
