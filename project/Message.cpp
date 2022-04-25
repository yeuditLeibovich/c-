#include "Message.h"

Message::Message(int id) {
	this->messageId = id;
	this->messageBuffer = NULL;
	this->messageType = 0;
}


unsigned char* Message::getMessageBuffer() {
	return this->messageBuffer;
}

Message::Message() {
	if (this->messageBuffer != NULL)
		free(this->messageBuffer);
}

