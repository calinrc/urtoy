/*
 *    file written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

enum CommandsId
{
    LOGIN, LOGOUT, GET_REMOTES, SEND_REOTE_COMMAND, NEW_REMOTE, RECORD_SIGNAL, LOAD_REMOTE_METAINF, SAVE_REMOTE_METAINF, UNKNOWN_COMMAND
};

enum ErrorCode
{
    EC_OK,
    EC_UNSUPPORTED_FORMAT,
    EC_UNSUPPORTED_VERSION,
    EC_SOCKET_FAIL,
    EC_BIND_FAIL,
    EC_LISTEN_FAIL,
    EC_ACCEPT_FAIL,
    EC_READ_FAIL,
    EC_WRITE_FAIL,
    EC_CLOSED,
    EC_IGNORED,
    EC_INVALID_LENGTH,
    EC_LOGIN_FAIL,
    EC_DEVICE_COMMAND_FAIL,
    EC_REMOTE_ALREADY_EXIST,
    EC_REMOTE_STORE_FAIL,
    EC_REMOTE_LOAD_FAIL,
    EC_REMOTE_NOT_FOUND,
    EC_NOT_IMPLEMENTED
};

enum DeviceErrorCode
{
    DEC_OK, DEC_READ_FAIL, DEC_WRITE_FAIL, DEC_NOT_IMPLEMENTED
};

#define PORT "port"
#define USERNAME "username"
#define PASSWORD "password"
#define DEVICEURI "deviceuri"
#define ROOTPATH "rootpath"

#define URTOY "urtoy"
#define VER_MAJOR 0
#define VER_MINOR 1
#define MAX_FILE_SIZE 2*1024*1024 // 2MB should be enough for any file used by in this app

class Transporter;
typedef Transporter* TRANSPORTER_HANDLER;

typedef char byte;

#define REMOTES_FILE "remotes.txt"
#define CONFIG_PROPERTIES "config.properties"


#endif /* CONSTANTS_H_ */
