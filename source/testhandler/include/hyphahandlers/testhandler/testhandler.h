// Copyright (c) 2015-2016 Hypha

#pragma once

#include <map>
#include <string>

#include <hypha/handler/hyphahandler.h>

namespace hypha {
namespace handler {
namespace testhandler {
class TestHandler : public HyphaHandler {
 public:
  explicit TestHandler();
  ~TestHandler();
  static TestHandler *instance();
  void doWork();
  const std::string name() { return "testhandler"; }
  const std::string getTitle() { return "Test Handler"; }
  const std::string getVersion() { return "0.1"; }
  const std::string getDescription() { return "Handler for Testing."; }
  const std::string getConfigDescription() {
    return "{"
           "\"confdesc\":["
           "{\"name\":\"message\", \"type\":\"string\",\"value\":\"Hello "
           "World!\",\"description\":\"Message for Testing:\"}"
           "]}";
  }
  void loadConfig(std::string config);
  std::string getConfig();

  void parse(std::string message);
  HyphaHandler *getInstance(std::string id);

  void receiveMessage(std::string message);
  std::string communicate(std::string message);

 protected:
  std::string m_message = "";
};
}
}
}
