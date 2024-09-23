/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:07:45 by lps               #+#    #+#             */
/*   Updated: 2024/09/23 17:07:47 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Server.hpp"
#include "Channel.hpp"

#define VALID_LEN 15
class Server;

struct msg_struct
{
	std::string prefix;
	std::string cmd;
	std::string parameter;
};

int  pass(Server *server, int clifdent_fd, msg_struct msg_info);
void nick(Server *server, int fd, msg_struct msg_info);
void user(Server *server, int client_fd, msg_struct msg_info);
void quit(Server *server, int fd, msg_struct msg_info);
void pong(Server *server, int client_fd, msg_struct msg_info);
int  join(Server *server, int client_fd, msg_struct msg_info);
void kick(Server *server, int client_fd, msg_struct msg_info);
int  part(Server *server, int client_fd, msg_struct msg_info);
int  invite(Server *server, int client_fd, msg_struct msg_info);
int  topic(Server *server, int client_fd, msg_struct msg_info);
void  list(Server *server, int fd, msg_struct cmd_infos);

#endif