/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Organiser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:25:02 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/08 17:00:33 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORGANISER_HPP
# define ORGANISER_HPP

# include <cctype>
# include <iostream>
# include <iomanip>

int			strtoi(std::string &str);
void		FillTheRest(int printedsofar);
std::string Trimmer(const std::string &input);
std::string Truncate(const std::string &input);
void		SplitString(int printedsofar, const std::string &input);

#endif
