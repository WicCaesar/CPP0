/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:25:57 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/14 10:00:56 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printdiacritic(int cue);

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::wcout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	// Sets the locale to the system's default. Alternatively, use pt_BR.UTF-8.
	const char *compare = setlocale(LC_ALL, "");
	// If not part of the ASCII table, compares it to the following characters.
	compare = " áéíóúñæçãõàèâêôäëïöüþøðß";
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (argv[i][j] >= 32 && argv[i][j] <= 126)
				std::wcout << (char)toupper(argv[i][j]);
			else {
				for (int k = 0; compare[k]; k++) {
					if (argv[i][j] == compare[k]) {
						// If it matches, prints the corresponding uppercase.
						printdiacritic(k / 2);
						break;
					}
				}
			}
		}
	}
	std::wcout << std::endl;
	return (0);
}

//TODO: Improve efficiency and appearance.
void	printdiacritic(int cue)
{
	if (cue == 1)
		std::wcout << (wchar_t)193; // Á
	else if (cue == 2)
		std::wcout << (wchar_t)201; // É
	else if (cue == 3)
		std::wcout << (wchar_t)205; // Í
	else if (cue == 4)
		std::wcout << (wchar_t)211; // Ó
	else if (cue == 5)
		std::wcout << (wchar_t)218; // Ú
	else if (cue == 6)
		std::wcout << (wchar_t)209; // Ñ
	else if (cue == 7)
		std::wcout << (wchar_t)198; // Æ
	else if (cue == 8)
		std::wcout << (wchar_t)199; // Ç
	else if (cue == 9)
		std::wcout << (wchar_t)195; // Ã
	else if (cue == 10)
		std::wcout << (wchar_t)213; // Õ
	else if (cue == 11)
		std::wcout << (wchar_t)192; // À
	else if (cue == 12)
		std::wcout << (wchar_t)200; // È
	else if (cue == 13)
		std::wcout << (wchar_t)194; // Â
	else if (cue == 14)
		std::wcout << (wchar_t)202; // Ê
	else if (cue == 15)
		std::wcout << (wchar_t)212; // Ô
	else if (cue == 16)
		std::wcout << (wchar_t)196; // Ä
	else if (cue == 17)
		std::wcout << (wchar_t)203; // Ë
	else if (cue == 18)
		std::wcout << (wchar_t)207; // Ï
	else if (cue == 19)
		std::wcout << (wchar_t)214; // Ö
	else if (cue == 20)
		std::wcout << (wchar_t)220; // Ü
	else if (cue == 21)
		std::wcout << (wchar_t)222; // Þ
	else if (cue == 22)
		std::wcout << (wchar_t)216; // Ø
	else if (cue == 23)
		std::wcout << (wchar_t)208; // Ð
	else if (cue == 24)
		std::wcout << "SS"; // uppercase ß
}
