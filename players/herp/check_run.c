#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>


/* this was lifted directly from the code in comm1.c in the lpmud source */
/* this basically tries to open a socket with the specified port number  */
/* and if port is in use, returns 1, if not in use, returns 0, if any    */
/* other error occurs, exit immediately 				 */
/* 	written by Oliver Weiler, University of California, Riverside	 */
int prepare_ipc(port_num)
int port_num;
{
    struct sockaddr_in sin;
    struct hostent *hp;
    int tmp,s;
    char host_name[100];

    if (gethostname(host_name, sizeof host_name) == -1) {
        perror("gethostname");
	exit(1);
    }
    hp = gethostbyname(host_name);
    if (hp == 0) {
	(void)fprintf(stderr, "gethostbyname: unknown host.\n");
	exit(1);
    }
    memset((char *)&sin, '\0', sizeof sin);
    memcpy((char *)&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(port_num);
    sin.sin_family = hp->h_addrtype;
    sin.sin_addr.s_addr = INADDR_ANY;
    s = socket(hp->h_addrtype, SOCK_STREAM, 0);
    if (s == -1) {
	perror("socket");
	abort();
    }
    tmp = 1;
    if (setsockopt (s, SOL_SOCKET, SO_REUSEADDR,
		    (char *) &tmp, sizeof (tmp)) < 0) {
	perror ("setsockopt");
	exit (1);
    }
    if (bind(s, &sin, sizeof sin) == -1) {
	if (errno == EADDRINUSE) {
	    return(1);		/* basically the only change here */
			/* this was to tell main() what's going on OJW */
	} else {
	    perror("bind");
	    abort();
	}
    }
    if (listen(s, 5) == -1) {
	perror("listen");
	abort();
    }
    tmp = 1;
#ifdef sun
    if (ioctl(s, FIONBIO, &tmp) == -1) {
	perror("ioctl socket FIONBIO");
	abort();
    }
#else /* sun */
    if (fcntl(s, F_SETFL, FNDELAY) == -1) {
	perror("ioctl socket FIONBIO");
	abort();
    }
#endif /* sun */
    signal(SIGPIPE, SIG_IGN);
}

main(argc,argv)
int argc;
char *argv[];
{
int port_num;
int interactive;
char *str;


	str = (char *)malloc(sizeof(str)*80);
	if (argc < 2) {
		interactive = 1;
		printf("port number?: ");
		gets(str);
		port_num = atoi(str);
		fflush(stdin);
	} else {
		interactive = 0;
		port_num = atoi(argv[1]);
	}
	if (port_num == 0) {
		fprintf(stderr,"not a valid port number\n");
		exit(1);
	}
	/* prepare ipc returns 1 if address is in use */
	if (prepare_ipc(port_num) == 1) {
		if (interactive)
			printf("address in use (game is running)\n");
		exit(1);
	} else {
		if (interactive)
			printf("address not in use (game is NOT running)\n");
		exit(0);	
	}
}
