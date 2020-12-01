#ifndef PROC_GEN_OPENGL_HEIGHT_MAP_FILE_OPERATOR_HPP
#define PROC_GEN_OPENGL_HEIGHT_MAP_FILE_OPERATOR_HPP


#include <string>
#include "height_map.hpp"

class HeightMapFileOperator
{
private:
protected:
public:
	HeightMapFileOperator();

	virtual ~HeightMapFileOperator();

	HeightMap loadHeightMap(const std::string& filename);
	void saveHeightMap(const std::string& filename, const HeightMap& heightMap);
};


#endif //PROC_GEN_OPENGL_HEIGHT_MAP_FILE_OPERATOR_HPP
