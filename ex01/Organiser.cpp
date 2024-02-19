/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Organiser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:22:58 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 17:08:36 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Organiser.hpp"

// Trims leading and trailing white spaces from a string.
// std::string::size_type is used here to represent the size of a string.
// The find_first_not_of() and find_last_not_of() functions return the position
// of the first and last character that is not in the specified character set.
// If no such character is found, return npos ("not a position").
std::string	Trimmer(const std::string &input) {
	std::string trimmed = input;

	std::string::size_type leading = trimmed.find_first_not_of("  \t\n\f\r\v");
	if (leading != std::string::npos)
		trimmed.erase(0, leading);
	else
		trimmed.clear(); // If the string is all white spaces, clears it.
	std::string::size_type trailing = trimmed.find_last_not_of("  \t\n\f\r\v");
	if (trailing != std::string::npos)
		trimmed.erase(trailing + 1);
	return (trimmed);
}

// If the user's input is over 10 characters, only 9 are displayed on the
// search screen, followed by a dot. On the details screen, everything appears.
std::string	Truncate(const std::string &input) {
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	else
		return (input);
}

// The function std::setw() is used to align the text to the right by default,
// with a total width of 10 characters. To align to the left, use std::left.
// Requires the iomanip library.
void	RightAlign(std::string string) {
	std::cout << std::setw(10) << string;
}

// Fills the rest of the line with spaces and prints the right border
// to properly frame lines with inputs of variable length.
void	FillTheRest(int printedsofar) {
	while (printedsofar < 44) {
		std::cout << " ";
		printedsofar++;
	}
	std::cout << "│" << std::endl;
}

// If the input is too big, for example, when describing one's darkest secret,
// this function splits the string into smaller chunks so it can be printed and
// keep the proper framing of the "screen".
void SplitString(int maxFirstChunk, const std::string &input) {
	int totalSpace = 45;
	int printedSoFar = totalSpace - 2 - maxFirstChunk; // -2 because of "│ ".
	int maxChunkLength = 41;
	int length = input.length();
	// In this project, the simulated screen has 45 chars of width (totalSpace).
	// It always displays two borders, and, occasionally, spaces next to them.
	// To calculate printedSoFar without knowing the string that came earlier,
	// subtract maxFirstChunk from totalSpace - 2 (left border and space).
	// This is only important on the first chunk, that follows another text.
	// For the rest of the lines, the maxChunkLength is used.

	if (length <= maxFirstChunk) {
		std::cout << input;
		FillTheRest(printedSoFar + length);
	} else {
		std::cout << input.substr(0, maxFirstChunk) << " │" << std::endl;
		for (int i = maxFirstChunk; i < length; i += maxChunkLength) {
			std::string chunk = input.substr(i, maxChunkLength);
			std::cout << "│ " << chunk;
			FillTheRest(2 + chunk.length());
		}
    }
}
