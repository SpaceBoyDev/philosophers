/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:02:33 by dario             #+#    #+#             */
/*   Updated: 2025/05/03 21:46:55 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/** Prints in yellow the error message given below a red ERROR square
 * @param error_message Error message that's going to be displayed
*/
static void	error_msg(const char *error_message)
{
	printf(RED"╔═══════╗\n║ ERROR ║\n╚═══════╝\n");
	if (error_message)
		printf(YELLOW"%s\n"RST, error_message);
}

/** Exits the program after printing the error message
 * @param error_message Error message that's going to be displayed
 */
void	error_exit(const char *error_message)
{
	error_msg(error_message);
	exit(EXIT_FAILURE);
}
