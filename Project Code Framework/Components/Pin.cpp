#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
	s_Status = LOW;
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::getStatus()
{
	return m_Status;
}

void Pin::setSIMStatus(STATUS r_Status) {
	s_Status = r_Status;
}
STATUS Pin::getSIMStatus() {
	return s_Status;
}