#ifndef AUTH_H

#define AUTH_H
#include <libssh/libssh.h>
// for UINT64
#include <stdint.h>
#define MAXBUF 100

struct connection {
    ssh_session session;
    ssh_message message;
    char client_ip[MAXBUF];
    char con_time[MAXBUF];
    const char *user;
    const char *pass;
    const char *banner;
    const char *cipher_out;
    const char *cipher_in;
    int protocol_version;
    int openssh_version;
    uint64_t session_id;
    int number;
};

int handle_auth(ssh_session session);
int log_con1_mysql(struct connection *c);
int log_con2_mysql(struct connection *c);
int log_con_end_mysql(struct connection *c);
int log_attempt_mysql(struct connection *c, const char *username, const char* password);

#endif
