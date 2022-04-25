#include "Buffer.h"
#include "Cammera.h"

void Buffer::addToBuffer(char* m) {

	if (this->buffer == NULL) {
		this->buffer = (char**)malloc(sizeof(Message));
		buffer[0] = m;
	}
	else {
		this->buffer = (char**)realloc(buffer,sizeof(Message)+1);
		buffer[index] = m;		
	}
	index = index + 1;
}
char** Buffer::getBuffer() {
	return this->buffer;
}
void Buffer::cleanBuffer() {
	for (int i = 0; i < index; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
	index = 0;
}
