/*
 * constants.h
 *
 *  Created on: 2 Jan 2021
 *      Author: xmaster
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define CONFIGURATION_FILE_LOCATION "port.info"

#define MAX_NUMBER_OF_TCP_CONNECTIONS 10

#define DELETE_FILE_OP 201
#define DELETE_FILE_SUCCESS_STATUS 212
#define DELETE_FILE_FAILURE_NOT_FOUND_STATUS 1001

#define DOWLOAD_FILE_OP 200
#define DOWLOAD_FILE_SUCCESS_STATUS 210
#define DOWLOAD_FILE_FAILURE_NOT_FOUND_STATUS 1001

#define GET_FILE_NAMES_OP 202
#define GET_FILE_NAMES_SUCCESS_STATUS 211
#define GET_FILE_NAMES_FAILURE_NO_FILES_FOR_USER 1002

#define UPLOAD_FILE_OP 202
#define UPLOAD_FILE_SUCCESS_STATUS 211

#define GENERAL_FAILURE_STATUS 1003

#define MAX_FILE_NAME_LENGTH 255
#define MAX_PAYLOAD_SIZE_BYTES 1024*1024*10

#define FILE_REPOSITORY_FOLDER "data"

#define BUFFER_SIZE 1000

#define PATH_SEPERATOR '/'

#endif /* CONSTANTS_H_ */
