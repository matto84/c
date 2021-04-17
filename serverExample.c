/*
TCPSERVER.C
==========
*/
#include <signal.h>
int main(int argc, char *argv[]) {
int list_s;
int conn_s;
/*listening socket*/
/*connection socket*/
ParseCmdLine(argc, argv, &endptr);
/* creazione della socket */
while ( 1 )
{
/* attesa di connessione */
Readline(conn_s, buffer, MAX_LINE-1);
printf("server: il client ha scritto\n\t%s\n",buffer);
Writeline(conn_s, buffer, strlen(buffer));
/* chiusura socket del client */
}
/* chiususa socket del server */
}

if ( (list_s = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{
fprintf(stderr, "server: errore nella creazione della socket.\n");
exit(EXIT_FAILURE);
}
memset(&servaddr, 0, sizeof(servaddr));
servaddr.sin_family
= AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port
= htons(port);
if ( bind(list_s, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 )
{
fprintf(stderr, "server: errore durante la bind.\n");
exit(EXIT_FAILURE);
}
if ( listen(list_s, LISTENQ) < 0 )
{
fprintf(stderr, "server: errore durante la listen.\n");
exit(EXIT_FAILURE);
}

* Wait for a connection, then accept() it */
sin_size = sizeof(struct sockaddr_in);
if ( (conn_s = accept(list_s, (struct sockaddr *)&their_addr, &sin_size) ) < 0 )
{
fprintf(stderr, "server: errore nella accept.\n");
exit(EXIT_FAILURE);
}
printf("server: connessione da %s\n", inet_ntoa(their_addr.sin_addr));
/* Close the connected socket */
if ( close(conn_s) < 0 )
{
fprintf(stderr, "server: errore durante la close.\n");
exit(EXIT_FAILURE);
}


