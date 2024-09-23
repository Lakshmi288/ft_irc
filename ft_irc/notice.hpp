/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notice.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:08:53 by lps               #+#    #+#             */
/*   Updated: 2024/09/23 17:08:54 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTICE_HPP
#define NOTICE_HPP

#include "Server.hpp"

std::vector<std::string>  convert_to_vector(std::string msg);
std::string ParamsJoin(std::vector<std::string> vec);

class notice
{
     private:
        int sender_fd;
        Server *serv;
        std::vector<std::string> params;
        msg_struct *msg_info;
        
    private:
        void CheckConditions();
        void SendToChannel();
        void SendToClient();
    public:
        notice(Server *serv, int sender_fd, msg_struct msg_info);
};

#endif

/* 
	  Command: NOTICE
  Parameters: <target>{,<target>} <text to be sent>
  
  notice command s used to send notices between users as well as send
  notices to channels.
  <target> is a channel name or the nickname of a client.
  <text to be sent> is the notice to be sent.
  NOTICE message is similar to PRIVMSG. the different is that automatic
  replies must never be sent in response to a NOTICE message.

 */