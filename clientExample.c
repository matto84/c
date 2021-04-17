/*
UDPCLIENT.C
===========
*/
int main(int argc, char *argv[]) {
/* dichiarazione variabili */
/* creazione della socket e relativa bind al SO */
/* trasmissione dati */
rc = sendto(sd, argv[i], strlen(argv[i])+1, 0,
(struct sockaddr *) &remoteServAddr,
sizeof(remoteServAddr));
if(rc<0) {
printf("impossibile trasmettere dati“);
close(sd);
exit(1);
}
}
/* ricezione dati (tramite recvfrom()) */
return 1;
}

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define REMOTE_SERVER_PORT 7000
#define MAX_MSG 100
int sd, rc, i;
/* socket, .................................... */
struct sockaddr_in cliAddr, remoteServAddr; /* indirizzi del client e
del server */
struct hostent *h;
/* info sull’host */


/* socket creation */
sd = socket(AF_INET,SOCK_DGRAM,0);
if (sd<0)
{
printf("%s: impossibile aprire la socket \n",argv[0]);
exit(1);
}
/* bind any port */
cliAddr.sin_family = AF_INET;
cliAddr.sin_addr.s_addr = htonl(INADDR_ANY);
cliAddr.sin_port = htons(0);
rc = bind(sd, (struct sockaddr *) &cliAddr, sizeof(cliAddr));
if(rc<0)
{
printf("%s: impossibile aprire la porta\n", argv[0]);
exit(1);
}
---------------------------------------------------------------------
/*
UDPSERVER.C
===========
*/
int main(int argc, char *argv[]) {
/* dichiarazione variabili */
/* creazione della socket e relativa bind al SO*/
while(1) {
/* ricezione messaggio */
cliLen = sizeof(cliAddr);
n = recvfrom(sd, msg, MAX_MSG, 0,
(struct sockaddr *) &cliAddr, &cliLen);
if (n<0) {
printf("%s: impossibile ricevere dati \n",argv[0]);
continue;
}
/* trasmissione dati (tramite sendto()) */
}
return 0;
}


#include
#include
#include
#include
#include
#include
#include
#include
(include
e variabili)
<sys/types.h>
<sys/socket.h>
<netinet/in.h>
<arpa/inet.h>
<netdb.h>
<stdio.h>
<unistd.h> /* close() */
<string.h> /* memset() */
#define LOCAL_SERVER_PORT 7000
#define MAX_MSG 100
int sd, rc, n, cliLen;
struct sockaddr_in cliAddr, servAddr;
char msg[MAX_MSG];
/* socket, ........................... */
/* address del server
e del client */
/* buffer di ricezione */

/* socket creation */
sd = socket(AF_INET, SOCK_DGRAM, 0);
if(sd<0)
{
printf("%s: errore nell'apertura dell socket.\n",argv[0]);
exit(1);
}
/* bind local server port */
servAddr.sin_family = AF_INET;
servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
servAddr.sin_port = htons(LOCAL_SERVER_PORT);
rc = bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
if(rc<0)
{
printf("%s: errore nella bind %d \n",
argv[0], LOCAL_SERVER_PORT);
exit(1);
}




