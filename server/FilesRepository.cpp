/*
 * FilesRepository.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#include "FilesRepository.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Constants.h"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/algorithm/string.hpp>
#include "GeneralException.h"
#include "FileNotFoundException.h"
#include "FileByteBuffer.h"

namespace fs = boost::filesystem;

/*
 * Checks if the directory exists and if not creates it.
 * Assumes the path is relative to current working dir
 */
void createDirectoryIfNotExists(std::string path)
{
	path = fs::current_path().string() + std::string(PATH_SEPERATOR) + path;
	std::cout << "Validating directory exists " << path << std::endl;
	fs::path dir_path(path);
	if (fs::exists(dir_path) && fs::is_directory(dir_path))
	{
		std::cout << "Folder exists" << std::endl;
	}
	else
	{
		std::cout << "Folder does not exist, creating it now..." << std::endl;
		bool success = fs::create_directories(dir_path);
		if (!success)
		{
			throw GeneralException("Was unable to create the directory");
		}
		else
		{
			std::cout << "Folder created" << std::endl;
		}
	}
}

/*
 * Deletes a file if it exists. If it does not exist a FileNotFound exception will be thrown
 */
void deleteFileIfExists(std::string path)
{
	path = fs::current_path().string() + std::string(PATH_SEPERATOR) + path;
	std::cout << "Checking if file exists " << path << std::endl;
	fs::path file_path(path);
	if (fs::exists(file_path) && fs::is_regular_file(file_path))
	{
		std::cout << "File exists, deleting..." << std::endl;
		bool success = fs::remove(file_path);
		if (!success)
		{
			throw GeneralException("Was unable to delete the file");
		}
		else
		{
			std::cout << "File deleted" << std::endl;
		}
	}
	else
	{
		std::cout << "File not found" << std::endl;
		throw FileNotFoundException();
	}
}

/*
 * Reads a file and returns it
 */
ByteBuffer* readFile(std::string path)
{
	path = fs::current_path().string() + std::string(PATH_SEPERATOR) + path;
	std::cout << "Checking if file exists " << path << std::endl;
	fs::path file_path(path);
	if (fs::exists(file_path) && fs::is_regular_file(file_path))
	{
		std::cout << "File exists, returning it..." << std::endl;
		return new FileByteBuffer(path);
	}
	else
	{
		std::cout << "File not found" << std::endl;
		throw FileNotFoundException();
	}
}

/*
 * Writes a file
 */
void writeFile(std::string path, ByteBuffer *buffer)
{
	path = fs::current_path().string() + std::string(PATH_SEPERATOR) + path;
	std::cout << "Writing to file: " << path << std::endl;
	std::ofstream dest_file;
	dest_file.open(path, std::ios::binary);
	buffer->sendToStream(dest_file);
	dest_file.close();
}

/*
 * Lists the files in a directory
 */
std::list<std::string> listFilesInDir(std::string path)
{
	path = fs::current_path().string() + std::string(PATH_SEPERATOR) + path;
	std::cout << "Listing all files in directory " << path << std::endl;

	std::list<std::string> result;

	for (fs::directory_iterator itr(path); itr != fs::directory_iterator();
			++itr)
	{
		if (fs::is_regular_file(itr->status()))
		{
			std::cout << "Found file: " << itr->path().filename() << std::endl;
			result.push_back(itr->path().filename().string());
		}
	}
	return result;
}

/*
 * Validates the file-name to avoid security issues
 */
std::string validateFileName(std::string fileName)
{
	boost::trim(fileName);

	if (fileName.size() == 0)
	{
		throw GeneralException("File-name is empty");
	}

	if (fileName.find('*') != std::string::npos
			|| fileName.find('/') != std::string::npos
			|| fileName.find('\\') != std::string::npos
			|| fileName.find("..") != std::string::npos)
	{
		throw GeneralException("Invalid chars detected in file name, aborting");
	}

	return fileName;
}


FilesRepository::FilesRepository()
{
	createDirectoryIfNotExists(FILE_REPOSITORY_FOLDER);
}

FilesRepository::~FilesRepository()
{
}

FilesRepository *FilesRepository::singleInstance = NULL;

FilesRepository* FilesRepository::getInstance()
{
	if (FilesRepository::singleInstance == NULL)
	{
		singleInstance = new FilesRepository();
	}
	return singleInstance;
}

std::string FilesRepository::saveFile(unsigned int userId, std::string fileName,
		ByteBuffer *dataBuffer)
{
	fileName = validateFileName(fileName);
	std::string userDir = std::string(FILE_REPOSITORY_FOLDER)
			+ std::string(PATH_SEPERATOR) + std::to_string(userId);
	createDirectoryIfNotExists(userDir);

	if (dataBuffer == NULL)
	{
		throw GeneralException("Cannot upload file without payload");
	}

	writeFile(userDir + std::string(PATH_SEPERATOR) + fileName, dataBuffer);
	return fileName;
}

void FilesRepository::deleteFile(unsigned int userId, std::string fileName)
{
	fileName = validateFileName(fileName);
	std::string userDir = std::string(FILE_REPOSITORY_FOLDER)
			+ std::string(PATH_SEPERATOR) + std::to_string(userId);
	createDirectoryIfNotExists(userDir);
	deleteFileIfExists(userDir + std::string(PATH_SEPERATOR) + fileName);
}

ByteBuffer* FilesRepository::getFile(unsigned int userId, std::string fileName)
{
	fileName = validateFileName(fileName);
	std::string userDir = std::string(FILE_REPOSITORY_FOLDER)
			+ std::string(PATH_SEPERATOR) + std::to_string(userId);
	createDirectoryIfNotExists(userDir);
	return readFile(userDir + std::string(PATH_SEPERATOR) + fileName);
}

std::list<std::string> FilesRepository::getFileNames(unsigned int userId)
{
	std::string userDir = std::string(FILE_REPOSITORY_FOLDER)
			+ std::string(PATH_SEPERATOR) + std::to_string(userId);
	createDirectoryIfNotExists(userDir);
	return listFilesInDir(userDir);
}
