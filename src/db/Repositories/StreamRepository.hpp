#pragma once

#include <optional>
#include <string>
#include <vector>

#include "../Entities/Event.hpp"
#include "../Entities/Stream.hpp"
#include "Poco/Data/Session.h"

namespace yess::db
{
class StreamRepository
{
  public:
    StreamRepository(std::string connectorKey, std::string connectionString);
    ~StreamRepository();
    std::vector<Stream> all();
    Stream get(int id);
    void create(Stream stream);
    void initDB();
    void attachEvent(Event event);
    std::vector<Event> getEvents(int streamId);
    std::vector<Event> getEvents(std::string streamType);
    std::optional<Event> getLastEvent(int streamId);
    Poco::Data::Session makeSession();

  private:
    std::string m_connectorKey;
    std::string m_connetctionString;
};
} // namespace yess::db
