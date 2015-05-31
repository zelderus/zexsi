//#include "types.h"
#include "responser.h"
#include "help.h"

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>




using namespace std;

namespace zex
{
	namespace responser
	{
		//
		// непосредственно генерация ответа
		//
		ZexRespHead 
		check_request ( std::string& out, const ZexParams& prms)
		{
			ZexRespHead head;
			// TODO: working..
			head.success = 1;	// 1=ok, 0=error
			head.status = "200 OK";
			head.content_type = "text/html;charset=utf-8";
			// TODO: set cookies, etc..
			// content
			if (head.success)
			{
				out = "<html><div>reeeesp yeaaaahhhh</div><form action='/form'><input type='text' name='inp1' value='vvvvv1'/><input type='submit' value='go' /></form></html>";
			}
			return head;
		}

		//
		// на основе модели ответа - собирает заголовки в поток ответа
		//
		void 
		get_header( std::string& out, const ZexRespHead& head, int content_size, const ZexParams& prms )
		{
			out += ("HTTP/1.0 " + head.status + "\n");
			out += ("Server: zex/" + string(ZEX_VER) + "\n");
			out += ("Content-Type: " + head.content_type + "\n");
			out += ("Status: " + head.status + "\n");
			// TODO: other headers from head
			out += ("Content-Length: " + inttostr(content_size) + "\n");
			out += "\n";
		}
	}

	//
	// на основе параметров запроса - строит заголовки и тело для ответа
	//
	ZexResp
	resp_get_response( std::string& outstr, ZexParams prms )
	{
		ZexResp resp;
		string& response = outstr;	
		// request content
		string resp_content = "";
		ZexRespHead head = responser::check_request(resp_content, prms);
		int content_size = resp_content.size();
		// header
		responser::get_header(response, head, content_size, prms);
		response += resp_content;
		response += "\r\r";
		// send
		resp.num = 83;
		resp.str = &response[0];
		resp.size = response.size();
		return resp;
	}

}










