#include "Zene.h"

std::ostream& operator<<(std::ostream& os, const Zene& right)
{
	right.kiIr(os);
	return os;
}


void Zene::kiIr(std::ostream& os) const {
	os << writer.getName() << "|" << writer.getNationality() << "|" << name << "|"
		<< genre << "|" << recorded << "|"
		//az idõt 2 karakter szélesen írja ki, és ha nem kettõ széles, feltólti 0-val
		<< std::setfill('0')<< std::setw(2) << length.getMinutes() << ":" <<std::setfill('0') <<std::setw(2) << length.getSeconds() << "|" << liked<<std::endl;

}

bool Zene::operator==(const std::string eloadoNev) const
{
	if (writer.getName() == eloadoNev)
		return true;
	return false;
}


void Zene::beolvas(std::istream& is)
{
	std::string writerName;
	std::string writerNationality;
	std::string name;
	unsigned recorded = 0;
	std::string genre;
	bool liked = 0;
	unsigned idoSecond = 0;
	unsigned idoMinute = 0;
	std::string buffer;
	char c;

	std::getline(is, writerName, '|');
	this->writer.setName(writerName);

	std::getline(is, writerNationality, '|');
	this->writer.setNationality(writerNationality);

	std::getline(is, this->name, '|');

	std::getline(is, this->genre, '|');

	std::getline(is, buffer, '|');
	this->recorded = (std::stoi(buffer));

	std::getline(is, buffer, ':');
	this->length.setMinutes(std::stoi(buffer));

	std::getline(is, buffer, '|');
	this->length.setSeconds(std::stoi(buffer));

	std::getline(is, buffer);
	this->liked = (std::stoi(buffer));

}



Zene::Zene(std::string pName, std::string pGenre, unsigned timeMinutes, unsigned timeSeconds,  bool pLiked,
	std::string writerName, std::string writerNationality,
	unsigned pRecorded):writer(writerName, writerNationality), 
	length(timeMinutes, timeSeconds), name(pName), genre(pGenre), liked(pLiked), recorded(pRecorded){}



std::string Zene::getName() const
{
	return name;
}



std::string Zene::getGenre() const
{
	return genre;
}


Zene::Zene(const Zene& param)
{
	name = param.name;
	genre = param.genre;
	recorded = param.recorded;
	liked = param.liked;
	length=param.length;
	writer = param.writer;
}

