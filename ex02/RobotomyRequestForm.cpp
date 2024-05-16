/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:54:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:54:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
}

void	RobotomyRequestForm::action(void) const
{
	srand(time(NULL));
	std::cout << "Brrrrr, *some drilling noises*... " << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
