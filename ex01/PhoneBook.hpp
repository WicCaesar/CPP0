/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 05:32:41 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/11 20:59:18 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

class	PhoneBook {
	private:
		Contact		contact_list_[8];
		int			contact_index_;
		int			contact_count_;
	
	public:
		PhoneBook(void);
		//~PhoneBook(void);

		Contact		get_contact(int index);
		int			get_contact_count(void);
		void		set_contact(Contact contact);
};

#endif
