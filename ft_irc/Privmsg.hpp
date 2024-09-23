/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:09:20 by lps               #+#    #+#             */
/*   Updated: 2024/09/23 17:09:21 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSG_HPP
#define PRIVMSG_HPP

#include "Server.hpp"

std::vector<std::string>  convert_to_vector(std::string msg);
std::string ParamsJoin(std::vector<std::string> vec);

class privmsg
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
        privmsg(Server *serv, int sender_fd, msg_struct msg_info);
};

#endif

/* 
Command: PRIVMSG
  Parameters: <target>{,<target>} <text to be sent>

  the PRIVMSG command is used to send private messages between users as well
  as to send messages to channels.
  <target> is the nickname of a client or the name of a channel.

Command Examples:

  PRIVMSG Angel :yes I'm receiving it !
                                  ; Command to send a message to Angel.

  PRIVMSG %#bunny :Hi! I have a problem!
                                  ; Command to send a message to halfops
                                  and chanops on #bunny.

  PRIVMSG @%#bunny :Hi! I have a problem!
                                  ; Command to send a message to halfops
                                  and chanops on #bunny. This command is
                                  functionally identical to the above
                                  command.

Message Examples:

  :Angel PRIVMSG Wiz :Hello are you receiving this message ?
                                  ; Message from Angel to Wiz.

  :dan!~h@localhost PRIVMSG #coolpeople :Hi everyone!
                                  ; Message from dan to the channel
                                  #coolpeople
 */