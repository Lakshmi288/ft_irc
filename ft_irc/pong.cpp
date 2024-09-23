/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:09:11 by lps               #+#    #+#             */
/*   Updated: 2024/09/23 17:09:13 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* 	 Command: PONG
  Parameters: [<server>] <token>
  Numeric replies: ERR_NOORIGIN (409)
replies to the ping command to make sure that the connection is there.
1. splits the params and store in vector
2. check if the params are empty. if yes send reply "ERR_NOORIGIN".
3. construct the pong message.
4. send the pong message.
	
 */

std::vector<std::string>  convert_to_vector(std::string msg);

void pong(Server *serv, int client_fd, msg_struct msg_info)
{
    std::vector<std::string> params = convert_to_vector(msg_info.parameter);
    if (params.size() == 0)
    {
        serv->SendReply(client_fd, ERR_NOORIGIN(msg_info.cmd));
        return ;
    }
    // Construct the PONG message
    std::string pongMessage = "PONG " + params[0] + "\r\n";
    // Send the PONG message back to the client
    serv->SendReply(client_fd, pongMessage);
}
