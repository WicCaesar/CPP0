/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 04:45:41 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 16:38:07 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

void	DisplayTime(void) {
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%I:%M", timeinfo);
	std::cout << buffer;
}

// Header with current time.
void	DisplayHeader(void) {
	if (std::system("clear") == 0) {
		std::cout << "╭─────────⍏───────────⍏───────────⍏─────────╮\n"
				  << "│ ";
		DisplayTime();
		std::cout << "   ⇜  ∀ta ⅁⎈é♰ica d'റmbra𝓁 ⇝	 ᯤ  │\n"
				  << "├─────────────────────⧪─────────────────────┤\n"
				  << "│					    │" << std::endl;
	}
}

// Initial "screen" with three possible commands.
void	DisplayGuide(void) {
	std::cout << "│𐍃alve! ℇntre com vm dos segvintes comandos:│\n"
			  << "│					    │\n"
			  << "│𝙰𝙳𝙳: cadastrar vma alma (sem campos vazios)│\n"
			  << "│					    │\n"
			  << "│𝚂𝙴𝙰𝚁𝙲𝙷: bvscar entre as existentes (máx. 8)│\n"
			  << "│					    │\n"
			  << "│𝙴𝚇𝙸𝚃: deixar as alminhas descansando em paz│\n"
			  << "│					    │" << std::endl;
}

// Displays the current list of contacts.
// Aligns to the right (std::setw(x)) and truncates (Truncate()) if necessary.
// If there are less than 8 contacts, fills the "screen" with empty lines.
// TODO: fix accents counting up as two characters (misaligns and bugs on 9th).
void	DisplayList(PhoneBook *phonebook) {
	int id = 0;
	while (id < phonebook->get_contact_count()) {
		std::cout << "│" << std::setw(10) << id + 1 << "│"
				  << std::setw(10) << Truncate(phonebook->get_contact(id).get_name()) << "│"
				  << std::setw(10) << Truncate(phonebook->get_contact(id).get_surname()) << "│"
				  << std::setw(10) << Truncate(phonebook->get_contact(id).get_nickname()) << "│" << std::endl;
		id++;
	}
	while (id < 8) {
		std::cout << "│					    │" << std::endl;
		id++;
	}
}

// Fully displays the contact information (no truncating).
// If the id is invalid, returns -1, otherwise returns the id.
int	DisplayContactInformation(PhoneBook *phonebook, int id) {
	if (id >= 0 && id <= phonebook->get_contact_count()) {
		DisplayHeader();
		std::cout << "│ Nome: "		<< phonebook->get_contact(id).get_name();
		FillTheRest(8 + phonebook->get_contact(id).get_name().length());
		std::cout << "│ Clã: "		<< phonebook->get_contact(id).get_surname();
		FillTheRest(7 + phonebook->get_contact(id).get_surname().length());
		std::cout << "│ Vulgo: "	<< phonebook->get_contact(id).get_nickname();
		FillTheRest(9 + phonebook->get_contact(id).get_nickname().length());
		std::cout << "│ Contato: "	<< phonebook->get_contact(id).get_number();
		FillTheRest(11 + phonebook->get_contact(id).get_number().length());
		std::cout << "│ Segredo mais obscuro: ";
		SplitString(19, phonebook->get_contact(id).get_secret());
		std::cout << "│					    │\n"
				  << "│					    │\n"
				  << "│					    │" << std::endl;
		DisplayFooter();
		return (id + 1);
	}
	return (-1);
}

// Displays a message in the middle of the "screen".
// The message must be 41 characters long, or less.
void	Display(std::string message) {
	DisplayHeader();
	std::cout << "│					    │\n"
			  << "│					    │\n"
			  << "│					    │\n"
			  << "│ "  << message <<  " │\n"
			  << "│					    │\n"
			  << "│					    │\n"
			  << "│					    │\n"
			  << "│					    │" << std::endl;
	DisplayFooter();
}

void	DisplayFooter(void) {
	std::cout << "│					    │\n"
			  << "╰─────────⊗───────────⦿───────────⧀─────────╯" << std::endl;
}
