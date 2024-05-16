/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:54 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 15:58:49 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	little_boss("little_boss", 100);
	Bureaucrat	big_boss("big_boss", 1);
	Form		paper("paper_1", 5, 5);

	std::cout << paper << std::endl;
	std::cout << little_boss << std::endl;
	try { //ERROR
		little_boss.signForm(paper);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}
	try { //no error
		big_boss.signForm(paper);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}
	try { //ERROR
		Form	wrong_paper("wrong_paper", -1, 10);
	} catch (Form::GradeTooHighException &e) {
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}
	return 0;
}