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
#include "GeneralException.h"
#include "FileNotFoundException.h"
#include "FileByteBuffer.h"

namespace fs = boost::filesystem;

void createDirectoryIfNotExists(std::string path)
{
	path = fs::current_path().string() + PATH_SEPERATOR + path;
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

void deleteFileIfExists(std::string path)
{
	path = fs::current_path().string() + PATH_SEPERATOR + path;
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
		throw FileNotFoundException();
	}
}

ByteBuffer* readFile(std::string path)
{
	path = fs::current_path().string() + PATH_SEPERATOR + path;
	std::cout << "Checking if file exists " << path << std::endl;
	fs::path file_path(path);
	if (fs::exists(file_path) && fs::is_regular_file(file_path))
	{
		std::cout << "File exists, returning it..." << std::endl;
		return new FileByteBuffer(path);
	}
	else
	{
		throw FileNotFoundException();
	}
}

void writeFile(std::string path, ByteBuffer *buffer)
{
	path = fs::current_path().string() + PATH_SEPERATOR + path;
	std::cout << "Writing to file: " << path << std::endl;
	std::ofstream dest_file;
	dest_file.open(path, std::ios::binary);
	buffer->sendToStream(dest_file);
	dest_file.close();
}

std::list<std::string> listFilesInDir(std::string path)
{
	path = fs::current_path().string() + PATH_SEPERATOR + path;
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

void validateFileName(std::string fileName)
{
	if (fileName.find('/') != std::string::npos
			|| fileName.find('\\') != std::string::npos
			|| fileName.find("..") != std::string::npos)
	{
		throw GeneralException("Invalid chars detected in file name, aborting");
	}
}

std::string FilesRepository::saveFile(unsigned int userId, std::string fileName,
		ByteBuffer *dataBuffer)
{
	validateFileName(fileName);
	std::string userDir = FILE_REPOSITORY_FOLDER + PATH_SEPERATOR + userId;
	createDirectoryIfNotExists(userDir);
	writeFile(userDir + PATH_SEPERATOR + fileName, dataBuffer);
	return fileName;
}

void FilesRepository::deleteFile(unsigned int userId, std::string fileName)
{
	validateFileName(fileName);
	std::string userDir = FILE_REPOSITORY_FOLDER + PATH_SEPERATOR + userId;
	createDirectoryIfNotExists(userDir);
	deleteFileIfExists(userDir + PATH_SEPERATOR + fileName);
}

ByteBuffer* FilesRepository::getFile(unsigned int userId, std::string fileName)
{
	validateFileName(fileName);
	std::string userDir = FILE_REPOSITORY_FOLDER + PATH_SEPERATOR + userId;
	createDirectoryIfNotExists(userDir);
	return readFile(userDir + PATH_SEPERATOR + fileName);
}

std::list<std::string> FilesRepository::getFileNames(unsigned int userId)
{
	std::string userDir = FILE_REPOSITORY_FOLDER + PATH_SEPERATOR + userId;
	createDirectoryIfNotExists(userDir);
	return listFilesInDir(userDir);
}
