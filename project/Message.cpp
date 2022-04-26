#include "Message.h"

Message::Message(int id) {
	this->messageId = id;
	this->messageBuffer = NULL;
	this->messageType = 0;
}

void Message::parseMessage()
{
}

void Message::parseBack()
{
}

void Message::print()
{
}


unsigned char* Message::getMessageBuffer() {
	return this->messageBuffer;
}

Message::Message() {
	if (this->messageBuffer != NULL)
		free(this->messageBuffer);
}


