#include <stdio.h>
#include "client.h"

int hello_init(void)
{
	printf("this is hello client\n");
	return 0;
}

int hello_send(char *email, char *password, char *bpm_mac, int sys, int dia, int hb)
{
	char url[512];
	sprintf(url, "{\"email\":\"%s\",\"password\":\"%s\",\"bpm_mac\":\"%s\",\"sys\":%d,\"dia\":%d,\"hb\":%d}", email, password, bpm_mac, sys, dia, hb);
	printf("%s\n", url);
	return 0;
}

int hello_halt(void)
{
	return 0;
}

client_t hello = {
  .name = "hello",
  .init = hello_init,
  .send = hello_send,
  .halt = hello_halt,
};
