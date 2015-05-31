
namespace zex
{

    int zex_serv(void);
    int zex_serv_child(int sock);
    struct zex_serv_params zex_serv_getparams(const char* buf);

}
