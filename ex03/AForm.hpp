/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:07:04 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 16:46:21 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_grade_signed;
		const int			_grade_executed;
		bool				_signed;

	public:
		Form(std::string name, int _grade_signed, int _grade_executed);
		virtual ~Form();
		Form(const Form &src);
		Form &operator=(const Form &rhs);

		std::string	get_name() const;
		bool		get_signed() const;
		int			get_grade_signed() const;
		int			get_grade_executed() const;

		void			setSigned(bool sign);
		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		virtual void	action(void) const = 0;
			
		class GradeTooLowException : std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class GradeTooHighException : std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class FormNotSignedException : std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif