################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./ByteBuffer.cpp \
./CommunicationManager.cpp \
./CommunicationSerilizationHelper.cpp \
./ConfigurationFileReader.cpp \
./DeleteFileHandler.cpp \
./DownloadFileHandler.cpp \
./FileByteBuffer.cpp \
./FileNotFoundException.cpp \
./FilesRepository.cpp \
./GeneralException.cpp \
./GetFilesListHandler.cpp \
./Request.cpp \
./RequestHandler.cpp \
./RequestHandlerFactory.cpp \
./RequestReader.cpp \
./Response.cpp \
./ResponseWriter.cpp \
./SocketByteBuffer.cpp \
./StrByteBuffer.cpp \
./TcpStorageServer.cpp \
./UploadFileHandler.cpp 

OBJS += \
./ByteBuffer.o \
./CommunicationManager.o \
./CommunicationSerilizationHelper.o \
./ConfigurationFileReader.o \
./DeleteFileHandler.o \
./DownloadFileHandler.o \
./FileByteBuffer.o \
./FileNotFoundException.o \
./FilesRepository.o \
./GeneralException.o \
./GetFilesListHandler.o \
./Request.o \
./RequestHandler.o \
./RequestHandlerFactory.o \
./RequestReader.o \
./Response.o \
./ResponseWriter.o \
./SocketByteBuffer.o \
./StrByteBuffer.o \
./TcpStorageServer.o \
./UploadFileHandler.o 

CPP_DEPS += \
./ByteBuffer.d \
./CommunicationManager.d \
./CommunicationSerilizationHelper.d \
./ConfigurationFileReader.d \
./DeleteFileHandler.d \
./DownloadFileHandler.d \
./FileByteBuffer.d \
./FileNotFoundException.d \
./FilesRepository.d \
./GeneralException.d \
./GetFilesListHandler.d \
./Request.d \
./RequestHandler.d \
./RequestHandlerFactory.d \
./RequestReader.d \
./Response.d \
./ResponseWriter.d \
./SocketByteBuffer.d \
./StrByteBuffer.d \
./TcpStorageServer.d \
./UploadFileHandler.d 


# Each subdirectory must supply rules for building sources it contributes
./%.o: ./%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I$(BOOST_SRC_DIR) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


