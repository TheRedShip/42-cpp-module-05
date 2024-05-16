/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:07:51 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 16:07:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		
		void execute(Bureaucrat const &executor) const;
		void action(void) const;
};

#endif