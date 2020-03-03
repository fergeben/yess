#pragma once

#include <string>

#include "Poco/JSON/Object.h"

namespace Leves
{
enum ResponseStatus { OK, Error };
class Response
{
  public:
    Response(ResponseStatus status, std::string message);
    std::string getMessage();
    ResponseStatus getStatus();

  private:
    ResponseStatus m_status;
    std::string m_message;
};
} // namespace Leves