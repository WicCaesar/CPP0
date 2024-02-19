/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 05:08:42 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 16:12:27 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include "Organiser.hpp"
# include "PhoneBook.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>

void	Display(std::string message);
void	DisplayTime(void);
void	DisplayHeader(void);
void	DisplayGuide(void);
void	DisplayList(PhoneBook *phonebook);
int		DisplayContactInformation(PhoneBook *phonebook, int id);
void	DisplayFooter(void);

#endif
