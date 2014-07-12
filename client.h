
typedef struct client_s {
	char *name;
	int (*init)(void);
	int (*send)(char *email, char *password, char *bpm_mac, int sys, int dia, int hb);
	int (*halt)(void);
} client_t;
