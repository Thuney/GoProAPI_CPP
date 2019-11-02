#include "HTTPRequest.h"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;				// From <boost/beast.hpp>
namespace http	= beast::http;				// From <boost/beast/http.hpp>
namespace net	= boost::asio;				// From <boost/asio.hpp>
using tcp		= net::ip::tcp;				// from <boost/asio/ip/tcp.hpp>



void HTTPRequest::Init()
{
		
}

bool HTTPRequest::Send()
{

}