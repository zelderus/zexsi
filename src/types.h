#include <string>
#include <vector>

#define ZEX_VER			"0.2"

#define ZEX_RET_SERVSUCC	0
#define ZEX_RET_FRMCLIENT 	-3

namespace zex
{

	class RequestParams
	{
		public:
			int num;
			std::string name;
			std::string val;			

		private:

	};

	typedef struct zex_response_t
	{
		int num;
		char* str;
		int size;
	} ZexResp;

	typedef struct zex_serv_params
	{
		std::vector<RequestParams*> params;
		std::string url;
		std::string method;
		std::vector<RequestParams*> queries;
		std::vector<RequestParams*> cookies;

	} ZexParams;

	typedef struct zex_responser_head
	{
		int success;
		std::string status;
		std::string content_type;
	} ZexRespHead;


	

}
