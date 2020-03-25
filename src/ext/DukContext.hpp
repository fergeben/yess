#pragma once

#include <string>
#include <vector>

#include "../db/Entities/Event.hpp"
#include "IContext.hpp"
#include "Poco/Dynamic/Var.h"
#include "Poco/JSON/Object.h"
#include "duktape.h"

namespace yess
{
namespace db
{
struct Event;
} // namespace db
} // namespace yess

namespace yess::ext
{
class DukContext : public IContext
{
  public:
    DukContext();
    ~DukContext();
    virtual Poco::JSON::Object::Ptr
    callProjection(const std::string &fnName,
                   const std::vector<db::Event> &events,
                   Poco::Dynamic::Var initState);
    void read(const std::string &body);
    duk_context *getDukContext();

  private:
    duk_context *m_pCtx;
};
} // namespace yess::ext
