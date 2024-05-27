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
	try {
		Bureaucrat b("Emile Stelewells", 50);
		b.decrement_grade();
		b.decrement_grade();
		b.decrement_grade();
		b.increment_grade();
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b("John Doe", 151);
		std::cout << b << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
	return 0;
}