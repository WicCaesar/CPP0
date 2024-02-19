/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 05:32:38 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 16:12:38 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact {
	private:
		std::string	name_;
		std::string	surname_;
		std::string	nickname_;
		std::string number_;
		std::string secret_;
	// Good practice: The underscore at the end indicates a private variable.

	public:
		std::string	get_name(void);
		std::string	get_surname(void);
		std::string	get_nickname(void);
		std::string	get_number(void);
		std::string	get_secret(void);

		void		set_name(std::string name);
		void		set_surname(std::string surname);
		void		set_nickname(std::string nickname);
		void		set_number(std::string number);
		void		set_secret(std::string secret);
};

#endif
