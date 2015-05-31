#include "types.h"
#include <string>
#include <vector>

namespace zex
{

    void p(const char* str);
	void p(const std::string& str);
    void pl (const char* str);
	void pl(const std::string& str);
    void pd (const int num);
    void p_ver(const char* str);
    void write_demo(const char* str);

    void zex_strcat(char* dest, char* src);
    std::string inttostr (int num);

	std::string strtoupper (const std::string& str);

	std::vector<RequestParams> parse_http(const char* buf);
	void parse_url_query(const std::string& url, struct zex_serv_params& prms);
	void parse_request_cookie(const std::string& cookiestr, std::vector<RequestParams*>& cookies);


}

