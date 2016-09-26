// Copyright (c) 2015-2016 Hypha

#include "hyphahandlers/testhandler/testhandler.h"

#include <chrono>
#include <sstream>
#include <string>
#include <thread>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <Poco/ClassLibrary.h>
#include <hypha/core/database/database.h>
#include <hypha/core/database/userdatabase.h>
#include <hypha/plugin/hyphaplugin.h>
#include <hypha/plugin/pluginloader.h>
#include <hypha/utils/logger.h>

using namespace hypha::handler;
using namespace hypha::handler::testhandler;
using namespace hypha::plugin;
using namespace hypha::settings;
using namespace hypha::database;
using namespace hypha::utils;

TestHandler::TestHandler() {}

TestHandler::~TestHandler() {}

void TestHandler::doWork() {
  std::this_thread::sleep_for(std::chrono::seconds(3));
  if (m_message != "") sendMessage("{\"say\":\"" + m_message + "\"}");
  m_message = "";
}

void TestHandler::parse(std::string UNUSED(message)) {}

void TestHandler::loadConfig(std::string config) {
  boost::property_tree::ptree ptconfig;
  std::stringstream ssconfig(config);
  boost::property_tree::read_json(ssconfig, ptconfig);

  if (ptconfig.get_optional<std::string>("message")) {
    m_message = ptconfig.get<std::string>("message");
  }
}

std::string TestHandler::getConfig() { return "{}"; }

HyphaHandler *TestHandler::getInstance(std::string id) {
  TestHandler *instance = new TestHandler();
  instance->setId(id);
  return instance;
}

void TestHandler::receiveMessage(std::string UNUSED(message)) {}

std::string TestHandler::communicate(std::string UNUSED(message)) { return ""; }

POCO_BEGIN_MANIFEST(HyphaHandler)
POCO_EXPORT_CLASS(TestHandler)
POCO_END_MANIFEST
