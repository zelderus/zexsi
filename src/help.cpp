#include "help.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <locale>
#include <errno.h>
#include <stdlib.h>
#include <sstream>


namespace zex
{

    void p (const char* str)
    {
        printf("%s\n", str);
    }
	void p(const std::string& str)
	{
		p(str.c_str());
	}
    void pl (const char* str)
    {
        printf("%s", str);
    }
	void pl(const std::string& str)
	{
		pl(str.c_str());
	}
    void pd (const int num)
    {
        printf("%d\n", num);
    }
    void p_ver (const char* ver)
    {
        printf("version: %s\n", ver);
    }

	std::string strtoupper (const std::string& str)
	{
		std::string out;
		std::locale loc;
		for (std::string::size_type i=0; i<str.length(); ++i)
		out += std::toupper(str[i],loc);

		return out;
	}

	std::vector<std::string> &split(const std::string& s, char delim, std::vector<std::string> &elems)
	{
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim))
		{
			elems.push_back(item);
		}
		return elems; 		
	}
	
	std::vector<std::string> split(const std::string &s, char delim)
	{
		std::vector<std::string> elems;
		split(s, delim, elems);
		return elems;
	}

    void zex_strcat(char* dest, char* src)
    {
        strcat(dest, src);
        return;
		/*
        size_t len1 = strlen(dest);
        size_t len2 = strlen(src);

        //p("========");
        //pd(len1);

        char*s = malloc(len1 + len2 + 1);

        memcpy(s, dest, len1);
        memcpy(s + len1, src, len2 + 1);

        //dest = malloc(strlen(s));
        dest = s;
        //len1 = strlen(dest);
        //pd(len1);
        //p(dest);
        */

    	//p(dest);
    	//p("--------");
    }


    std::string inttostr (int num)
    {
        char intStr[30] = "";
        sprintf(intStr, "%d", num);
        //itoa(num, intStr, 10);
        return std::string(intStr);
    }

	// разбор строки запроса
	int parse_param(const std::string &str, RequestParams *prm)
	{
		// по стандарту строка вида, например 'Cookie: p1=aaa'
		// разбиваем ее, на имя (капсом) и на значение
		// parse line
		std::vector<std::string> blocks = split(str, ' ');
		if (blocks.size() <= 1) return 0;
		//- name
		std::string name = blocks.at(0);
		char ch = *name.rbegin();
		if (ch == ':') name = name.substr(0, name.size()-1);
		name = strtoupper(name);
		//- val
		std::string val = blocks.at(1);
		//- to model
		prm->name = name;
		prm->val = val;
		return 1;
	}

	// разбор запроса
	std::vector<RequestParams> parse_http(const char* buf)
	{
		std::vector<RequestParams> elems;
		std::string str = std::string(buf);
		// lines
		std::vector<std::string> lines;
		//lines = split(str, '\n');
		char delim = '\n';
		std::stringstream ss(str);
		std::string item;
		int linenum = 0;
		// разбиваем поток текста на строки
		while (std::getline(ss, item, delim))
		{
			lines.push_back(item);
			RequestParams prm;
			prm.num = linenum;
			// to model
			if (parse_param(item, &prm))
				elems.push_back(prm);

			linenum++;
		}
		return elems;
	}

	// разбор url на наличие параметров
	void parse_url_query(const std::string& url, struct zex_serv_params& prms)
	{
		// TODO: parse url for query (like '/docurl?p1=aa')

		//prms.queries.push
		
	}

	void parse_request_cookie(const std::string& cookiestr, std::vector<RequestParams*>& cookies)
	{
		// http://en.wikipedia.org/wiki/HTTP_cookie
		// TODO: parse cookies
		
	}



    void write_demo(const char* str)
    {
        int fd;
        // file opts
        char fname[] = "./kii.txt";
        int fflags = O_CREAT | O_APPEND | O_RDWR;
        mode_t fmode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
        // open
        errno = 0;
        fd = open(fname, fflags, fmode);
        if (fd == -1)
        {
            // err
            printf("E: file open err -> %s\n", strerror(errno));
            return;
        }
        printf("M: file opened with fd=%d\n", fd);
        // write
        ssize_t nr;
        errno = 0;
        nr = write(fd, str, strlen(str));
        if (nr == -1)
        {
            printf("E: file '%d' write err -> %s\n", fd, strerror(errno));
        }

        // close
        if (close(fd) == -1)
        {
            printf("E: file close err\n");
            return;
        }
    }



}
