#include "Discovery.h"

void Discovery::parseMessage() {
	if (this->messageBuffer != NULL)
		return;
	this->messageBuffer = (unsigned char*)malloc(14 * sizeof(char));
	if (this->messageBuffer == NULL)
		return;
	int place = 0;
	memcpy((this->messageBuffer + place), &(this->messageType), sizeof(this->messageType));
	place += sizeof(this->messageType);
	memcpy((this->messageBuffer + place), &(this->distance), sizeof(this->distance));
	place += sizeof(this->distance);
	memcpy((this->messageBuffer + place), &(this->distance), sizeof(this->angle));
	place += sizeof(this->angle);
	memcpy((this->messageBuffer + place), &(this->distance), sizeof(this->speed));
}

void Discovery::parseBack() {
	if (this->messageBuffer == NULL)
		return;
	int place = 0;
	memcpy(&(this->messageType), (this->messageBuffer + place), sizeof(this->messageType));
	place += sizeof(this->messageType);
	memcpy(&(this->distance), (this->messageBuffer + place), sizeof(this->distance));
	place += sizeof(this->distance);
	memcpy(&(this->distance), (this->messageBuffer + place), sizeof(this->angle));
	place += sizeof(this->angle);
	memcpy(&(this->distance), (this->messageBuffer + place), sizeof(this->speed));
}

void Discovery::print() {
	std::cout << "messageType:" << this->messageType << " distance:"
		<< this->distance << " angle:" << this->angle << " speed:" << this->speed;
}

Discovery::Discovery(unsigned char* massege, int id) :Message(id) {
	this->messageBuffer = (unsigned char*)malloc(14 * sizeof(char));
	if (this->messageBuffer != NULL)
		memcpy(this->messageBuffer, massege, 14 * sizeof(char));
	this->angle = 0;
	this->distance = 0;
	this->speed = 0;
}

Discovery::Discovery(float distance, float angle, float speed, int id) :Message(id) {
	this->angle = angle;
	this->distance = distance;
	this->speed = speed;
	this->messageType = 2;
}
