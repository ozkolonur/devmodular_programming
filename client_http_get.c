#include <stdio.h>
#include "client.h"

int http_get_init(void)
{
	printf("this is http-get client\n");
	return 0;
}

int http_get_send(char *email, char *password, char *bpm_mac, int sys, int dia, int hb)
{
	char url[512];
	sprintf(url, "{\"email\":\"%s\",\"password\":\"%s\",\"bpm_mac\":\"%s\",\"sys\":%d,\"dia\":%d,\"hb\":%d}", email, password, bpm_mac, sys, dia, hb);
	printf("%s\n", url);
	return 0;
}

int http_get_halt(void)
{
	return 0;
}

client_t http_get = {
  .name = "http_get",
  .init = http_get_init,
  .send = http_get_send,
  .halt = http_get_halt,
};
