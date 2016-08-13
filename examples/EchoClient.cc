#include "../inc/base/Logger.h"
#include "../inc/tcp/TCPClient.h"
#include "../inc/tcp/TCPStream.h"

using namespace collie;
using namespace collie::tcp;

int main(void) {
  Logger::Init();

  TCPClient::Connect("127.0.0.1", 8081, [](TCPStream& stream) {
    stream.Write("Hello,world");
    auto msg = stream.Read();
    LOG(INFO) << "Read: " << msg.Length() << msg << " From "
              << stream.PeerAddress()->ToString();
  });

  return 0;
}
