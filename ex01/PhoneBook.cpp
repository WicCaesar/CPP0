/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:23:12 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 16:47:28 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "iostream"

// Creates and initialises the PhoneBook object.
PhoneBook::PhoneBook(void) {
	this->contact_index_ = 0;
	this->contact_count_ = 0;
}

// Adds a contact to the PhoneBook. Cannot store over 8 contacts, so it stops
// counting when this number is reached (there's no way of deleting a contact).
// If the index is 7 (full list), then it'll reset to 0, replacing the oldest.
void	PhoneBook::set_contact(Contact contact) {
	this->contact_list_[this->contact_index_] = contact;
	this->contact_index_ = (this->contact_index_ + 1) % 8;
	if (this->contact_count_ < 8)
		this->contact_count_++;
}

// Returns the contact information at the specified index.
Contact	PhoneBook::get_contact(int index) {
	return (this->contact_list_[index]);
}

// Tells how many contacts are stored in the PhoneBook.
int		PhoneBook::get_contact_count(void) {
	return (this->contact_count_);
}
