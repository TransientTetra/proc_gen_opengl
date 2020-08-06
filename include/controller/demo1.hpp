#ifndef DEMO1_HPP
#define DEMO1_HPP


#include "application.hpp"

class Demo1 : public Application
{
private:
protected:
public:
	Demo1(const std::string &title, int height, int width);

	void run() override;
};


#endif //DEMO1_HPP
