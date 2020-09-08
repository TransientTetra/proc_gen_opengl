#ifndef DEMO1_HPP
#define DEMO1_HPP


#include <model/world.hpp>
#include "application.hpp"

class Demo1 : public Application
{
private:
	World world;
public:
	Demo1(const std::string &title, int height, int width);

	void run() override;
};


#endif //DEMO1_HPP
