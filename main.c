#include <stdio.h>

/*
void send_measurement_tcp(char *email, char *password, char *bpm_mac, int sys, int dia, int hb)
{
//
//     {"firstName": "John",
//          "lastName": "Smith",
//               "age": 25,
//                    "address":

	char url[512];
	sprintf(url, "{\"email\":\"%s\",\"password\":\"%s\",\"bpm_mac\":\"%s\",\"sys\":%d,\"dia\":%d,\"hb\":%d}", email, password, bpm_mac, sys, dia, hb);
	printf("%s\n", url);
}
*/
typedef struct client_s {
	char *name;
	int (*init)(void);
	int (*send)(char *email, char *password, char *bpm_mac, int sys, int dia, int hb);
	int (*halt)(void);
} client_t;

extern client_t hello;
extern client_t http_get;

static client_t *clients[] = {
	&hello,
	&http_get,
	NULL,
};


int main(int argc, char *argv[])
{
    int sys=120;
    int dia=80;
    int hb=80;
    char email[] = "user@gmail.com";
    char password[] = "123456";
    char bpm_mac[] = "00:1C:A8:12:13:14";
    //send_measurement_tcp((char *)&email, (char *)&password, (char *)&bpm_mac, sys, dia, hb);

	client_t **client;
	for(client = clients; *client; client++)
	{
		printf("current client is %s\n", (*client)->name);
		(*client)->init();
	}
    return 0;
}
