#include "Status.h"

void Status::parseMessage() {
	if (this->messageBuffer != NULL)
		return;
	this->messageBuffer = (unsigned char*)malloc(14 * sizeof(char));
	if (this->messageBuffer == NULL)
		return;
	memcpy(this->messageBuffer, &(this->messageType), sizeof(this->messageType));
	memcpy((this->messageBuffer + sizeof(this->messageType)), &(this->status1), sizeof(this->status1));
}

void Status::parseBack() {
	if (this->messageBuffer == NULL)
		return;
	memcpy(&(this->messageType), this->messageBuffer, sizeof(this->messageType));
	memcpy(&(this->status1), (this->messageBuffer + sizeof(this->messageType)), sizeof(this->status1));
}

void Status::print() {
	std::cout << "messageType:" << this->messageType << " status:" << this->status1;
}

Status::Status(unsigned char* massege, int id) :Message(id) {
	this->messageBuffer = (unsigned char*)malloc(14 * sizeof(char));
	if (this->messageBuffer != NULL)
		memcpy(this->messageBuffer, massege, 14 * sizeof(char));
	this->status1 = 0;
}

Status::Status(short status, int id) :Message(id) {
	this->status1 = status;
	this->messageType = 1;
}

