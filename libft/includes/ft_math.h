/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:30:17 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/15 17:59:47 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/**
 * Raise base to the power power
 * @param base		the base to be raised
 * @param power 	the power to which raise it
 * @return
 */
int				ft_powi(int base, int power);

/**
 * Return the absolute value of val
 *
 * @param val
 *
 * @return
 */
unsigned int	ft_absi(int val);

/**
 * Store the n'th digit of val in d, return the digit on 
 * success or 0 on failure
 *
 * @param val
 * @param d		a pointer to int used to store the digit
 * @param n		the position of the digit, 0 being the first one
 *
 * @return		the n'th digit of val, or 0 if val contain less than n
 * 				digit or if n < 0
 */
int				ft_digitat(int val, int *d, int n);

/**
 * Return the number of digits of a base 10 number
 *
 * @param val
 *
 * @return	the number of digits of the number, if number is 0
 *  return 1 (zero count as a digit)
 */
int				ft_getdigits(int val);

/**
 * Get the maximum value
 *
 * @param a
 * @param b
 * @return
 */
int				ft_min(int a, int b);

/**
 * Get the maximum value
 * @param a
 * @param b
 * @return
 */
int				ft_max(int a, int b);

#endif
