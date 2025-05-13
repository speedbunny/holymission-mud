#define TELCMDS
#define TELOPTS
#define	CONPORT	23

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/ioctl.h>
#include	<fcntl.h>
#include	<sgtty.h>
#include	<netinet/in.h>
#include	<netdb.h>
#include	<sys/socket.h>
#include	<sys/param.h>
#include	<arpa/telnet.h>


int cto_host();
void io_read();
void tt_read();

static int s;

main() {
char sl[255];
char ch;
int i;

   if ((s=cto_host())==-1) return;
   /*
     fcntl(stdin, F_SETOWN, getpid());
     fcntl(stdin, F_SETFL, FNBIO | FASYNC);
   */
   signal(SIGIO,   io_read, -1);
#if 0
   echo_off(1);
#endif
   for(;;) {
#if 1
	gets(sl);
	i=strlen(sl);
	sl[i]='\n';
	sl[++i]='\0';
	for (i=0;i<strlen(sl);i++)
	    if (sl[i]=='a') sl[i]='b'; else
	    if (sl[i]=='b') sl[i]='a';

	write(s,sl,strlen(sl));
#else
	getc(ch);
	write(s,ch,1);
#endif
   }
}

void tt_read() {
  printf("tt_read.\n");
}

void io_read()
{
static char cwont[3] = { IAC, WONT, 0 };
static char cwill[3] = { IAC, WILL, 0 };
static char   cdo[3] = { IAC, DO,   0 };
static char cdont[3] = { IAC, DONT, 0 };

static unsigned char c[1024];
static int pos;
static int nr=0;
int i;

	nr=read(s,c,1024);	/* refill buffer */
	pos=0;
printf("[io_read] %d\n",nr);
	if (nr<1) {
	   printf("Connection breakdown.\n");
	   exit();
	}
    /* printf("nr read: %d, pos %d\n",nr,pos); */
    c[nr]=0;
    /* printf("%s\n",c); */
#if 0
    for (i=0;i<nr;i++) printf("[%x] ",(u_short)c[i]);
#endif

/* 'parse' line ... */
 for (pos=0;pos<nr;) {
    while (c[pos]==IAC) { 
	/* printf("%d %s\n",pos,telcmds[IAC-SE]); */
	pos++;
	/* printf("%s\n",telcmds[c[pos]-SE]); */
	switch (c[pos]) {
	case DO:
	  pos++;
	  printf("Please, you DO %s [%x]\n",telopts[c[pos]],c[pos]);
	  if (c[pos]==TELOPT_ECHO) {
	     cwill[2]=c[pos];
	     send(s,cwill,3,0);
	     printf(">Yes, I WILL do that.\n");
	  }
	  else {
	     cwont[2]=c[pos];
	     send(s,cwont,3,0);
	     printf(">No, I WONT do that.\n");
	  }
	break;
	case DONT:
	  pos++;
	  printf("Please, you DONT %s [%x]\n",telopts[c[pos]],c[pos]);
	break;
	case WILL:
	  pos++;
	  printf("Remote host WILL %s\n",telopts[c[pos]]);
	  if (c[pos]==TELOPT_ECHO) {	/* He will ECHO, turn off our local */
	    cdo[2]=c[pos];		/* Allright, DO that */
	    send(s,cdo,3,0);
	    printf(">Allright, DO that.\n");
	    echo_off(1);
	  }
	break;
	case WONT:
	  pos++;
	  printf("Remote host WONT %s\n",telopts[c[pos]]);
	  if (c[pos]==TELOPT_ECHO) {	/* He wont ECHO, turn on our local */
	    printf(">Allright, if you WONT then I'll DO it !\n");
	    echo_on(1);
	  }
	break;
	case SB:
	case GA:
	case EL:
	case EC:
	case AYT:
	case AO:
	case BREAK:
	case DM:
	case NOP:
	case SE:
	case EOR:
	  pos++;
	  printf("%s\n",telopts[c[pos]]);
	  break;
	case IP:
	   printf("interrupt process--permanently\n");
	   printf("Remote host has closed the connection.\n");
	   exit();
	}
	pos++;
    }
    printf("%c",c[pos]);
    pos++;
}
    /* printf("%s",(char *)(&c+pos)); */
    fflush(stdout);
#if 0
    printf("<\n");
#endif
}

int cto_host() {
int s,tmp;
char hostname[MAXHOSTNAMELEN];
struct hostent *hp;
struct sockaddr_in sin;
struct in_addr haddr;

/* Currently compiled for localhost ... */

    if (gethostname(hostname,MAXHOSTNAMELEN)==-1) {
	perror("gethostname");
	exit();
    }

#if 0
    hp=gethostbyname(hostname);
#else
    hp=gethostbyname("localhost");
#endif
    if (!hp) {
	printf("gethostbyname: unknown host %s\n",hostname);
	exit();
    }

    printf("%s at %s\n",hostname,inet_ntoa(hp->h_addr_list[0]),
				hp->h_addr_list[0]);
    haddr.s_addr=inet_addr(inet_ntoa(hp->h_addr_list[0]));

    memset((char *)&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(CONPORT);
    memcpy((char *)&sin.sin_addr,&haddr,sizeof(struct sockaddr_in));
    if ((s=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
	perror("socket");
	exit();
    }
    if (connect(s, (char *)&sin, sizeof(sin)) == -1) {
	perror("connect");
	exit();
    }
    tmp=1;
#if 0
    if (ioctl(s, FIONBIO, &tmp) == -1) {
	perror("ioctl");
	exit();
    }
#endif
#if 0
   if (fcntl(s, F_SETFL, FASYNC | FNBIO | FNDELAY) == -1) {
#else
   if (fcntl(s, F_SETFL, FASYNC) == -1) {
#endif
	perror("fcntl: F_SETFL");
	exit();
   }
    if (fcntl(s, F_SETOWN, getpid()) == -1) {
	perror("fcntl: F_SETOWN");
	exit();
    }
    printf("connection established...\n");
    return s;
}

#if 0
set_cbreak()
{
    struct termio termio;

    if (ioctl(1, TCGETA, &termio) == -1) {
	perror("ioctl TCGETA failed in set_cbreak.");
	exit();
    }
    termio.sg_flags |= CBREAK;
    if (ioctl(1, TCSETA, &termio) == -1) {
	perror("ioctl TCSETA failed in set_cbreak.");
	exit();
    }
} /* set_cbreak */
#endif

echo_off(fd)
int fd;
{
    struct sgttyb sgttyb;
    
    fflush(stdout);

    if (ioctl(fd, TIOCGETP, &sgttyb) == -1)
	perror("ioctl TIOCGETP failed in echo_off.");
    sgttyb.sg_flags &= ~ECHO;
    if (ioctl(fd, TIOCSETP, &sgttyb) == -1)
	perror("ioctl TIOCSETP failed in echo_off.");
} /* echo_off */

echo_on(fd)
int fd;
{
    struct sgttyb sgttyb;
    
    if (ioctl(fd, TIOCGETP, &sgttyb) == -1)
	perror("ioctl TIOCGETP failed in echo_on.");
    sgttyb.sg_flags |= ECHO;
    if (ioctl(fd, TIOCSETP, &sgttyb) == -1)
	perror("ioctl TIOCSETP failed in echo_on.");
} /* echo_on */
