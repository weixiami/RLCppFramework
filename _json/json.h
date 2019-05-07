#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <json/json.h>

#include "path.h"

namespace rcf
{


/* string to json */
static Json::Value strToJson(const std::string &str)
{
	Json::Reader reader;
	Json::Value root;
	if (str.empty()) return root;
	reader.parse(str, root);
	return root;

	/*
	Json::CharReaderBuilder reader;
	Json::Value root;
	if (str.empty()) return root;
	std::unique_ptr<Json::CharReader> const jsonReader(reader.newCharReader());
	JSONCPP_STRING errs;
	jsonReader->parse(str.c_str(), str.c_str() + str.size(), &root, &errs);
	return root;
	*/
}

static Json::Value fileToJson(const std::string &strPath)
{
    if (!rcf::isPathExist(strPath)) strToJson("");
	
	std::ifstream t(strPath);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string strCfg = buffer.str();
	t.close();

	return strToJson(strCfg);
}

/* json to string */
static std::string jsonToStr(const Json::Value &root)
{
	if (root.empty()) return "";
	Json::ValueType type = root.type();
	Json::StyledWriter styled_writer;
	return styled_writer.write(root);

	/* 
	if (root.empty()) return "";
	Json::StreamWriterBuilder writerBuilder;
	std::ostringstream os;
	std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
	jsonWriter->write(root, &os);
	return os.str();
	*/
}

// fix style
static std::string fixStyle(const std::string &str)
{
	if (str.empty()) return "";
	return jsonToStr(strToJson(str));
}


}