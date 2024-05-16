/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:18:40 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 16:18:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

class Intern
{
	private:
		Form	*_forms[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &rhs);

		Form	*makeForm(std::string form, std::string target);
};

#endif