/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:36:58 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 16:47:14 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// No need for constructors and destructors in this exercise,
// because there is no dynamic memory allocation.

// Mutators (setters)
void	Contact::set_name(std::string name) {
	this->name_ = name;
}

void	Contact::set_surname(std::string surname) {
	this->surname_ = surname;
}

void	Contact::set_nickname(std::string nickname) {
	this->nickname_ = nickname;
}

void	Contact::set_number(std::string number) {
	this->number_ = number;
}

void	Contact::set_secret(std::string secret) {
	this->secret_ = secret;
}

// Accessors (getters)
std::string	Contact::get_name(void) {
	return (this->name_);
}

std::string	Contact::get_surname(void) {
	return (this->surname_);
}

std::string	Contact::get_nickname(void) {
	return (this->nickname_);
}

std::string	Contact::get_number(void) {
	return (this->number_);
}

std::string	Contact::get_secret(void) {
	return (this->secret_);
}
