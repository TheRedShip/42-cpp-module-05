/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:22:01 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 16:00:14 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;

	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string	get_name() const;
		int			get_grade() const;

		void		increment_grade();
		void		decrement_grade();
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif