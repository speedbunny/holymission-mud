/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

#define	TELCMDS
#define	TELOPTS

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

/* declare procs */

void io_avail();

/* +-------------------------+
   |    rslv_host()          |
   +-------------------------+ */

struct in_addr rslv_host(hname)
char *hname;
{
struct hostent *hp;
struct in_addr iaddr;

#if 1
printf("enter rslv_host: %s\n",hname);
#endif
    if (isalpha(*hname)) {			/* hostname specified */
	if (!(hp=gethostbyname(hname))) {
	    printf("%s: unknow host\n",hname);
	    exit();
	}
    }
    else if (isdigit(*hname)) {				/* hostip specified */
	if (!(hp=gethostbyaddr(hname,4,AF_INET))) {	/* laugh, trusted */
	    printf("%s: Host is unreachable\n",hname);
	    exit();
	}
    }
    else {
	printf("%s: Hu?\n",hname);
	exit();
    }

    iaddr.s_addr=inet_addr(inet_ntoa(hp->h_addr_list[0]));
printf("[rslv_host]: done.\n");
    return iaddr;
}

/* +-----------+
   | neg_gfx() |
   +-----------+ */

void neg_gfx(fd0,fd1)
int fd0;		/* Telnet Connection */
int fd1;		/* Grafix Connection */
{
    struct sockaddr_in name;
    int tmp;

    tmp=sizeof(name);
    if (getsockname(fd0, &name, &tmp)==-1) {
	perror("neg_gfx: getpeername");
	exit();
    }
    tmp=sizeof(name);
printf("sending %d bytes\n",tmp);
    send(fd1,(unsigned char *)&name,tmp,0);
}


/* +------------------+
   | prepare_ipc()    |
   +------------------+ */

int prepare_ipc(hname,port)
char *hname;
int port;
{
int fd;
struct sockaddr_in mud_addr;
struct sockaddr_in laddr;
struct in_addr iaddr;
char *p;
int i;

#if 1
printf("[prepare_ipc] %s %d\n",hname,port);
#endif

    iaddr=rslv_host(hname);

    mud_addr.sin_family=AF_INET;
    mud_addr.sin_port=htons(port);	/* frown, WHO uses 386? */
    mud_addr.sin_addr.s_addr=iaddr.s_addr;

    if ((fd=socket(AF_INET,SOCK_STREAM,0))==-1) {
	perror("socket");
	exit();
    }

    /* now, connect to it */

printf("[prepare_ipc] connecting....\n");
    if (connect(fd, mud_addr, sizeof(struct sockaddr_in))==-1) {
	    printf("no serive available for %d\n",port);
	    perror("connect");
	    exit();
    }
printf("[prepare_ipc]: getsockame.\n");
    i=sizeof(laddr);
    if (getsockname(fd, &laddr, &i)==-1) {
	    perror("getsockname");
	    exit();
    }
printf("[prepare_ipc]: getsockname local port is ");
    printf("%d\n",laddr.sin_port);
    
    /* setup async IO. main() will do nothing but read from keyboard */

    if (fcntl(fd,F_SETOWN,getpid())==-1) {
	perror("fcntl: F_SETOWN");
	exit();
    }
    if (fcntl(fd,F_SETFL,FASYNC)==-1) {
	    perror("fcntl: F_SETFL");
	    exit();
    }


     
printf("[prepare_ipc]: done.\n");
    return fd;
}

/* --------- test only -------------- */

echo_off(i)
int i;
{
    struct sgttyb sgttyb;
    
    fflush(stdout);

    if (ioctl(i, TIOCGETP, &sgttyb) == -1)
	perror("ioctl TIOCGETP failed in echo_off.");
    sgttyb.sg_flags &= ~ECHO;
    if (ioctl(i, TIOCSETP, &sgttyb) == -1)
	perror("ioctl TIOCSETP failed in echo_off.");
} /* echo_off */

echo_on(i)
int i;
{
    struct sgttyb sgttyb;
    
    if (ioctl(i, TIOCGETP, &sgttyb) == -1)
	perror("ioctl TIOCGETP failed in echo_on.");
    sgttyb.sg_flags |= ECHO;
    if (ioctl(i, TIOCSETP, &sgttyb) == -1)
	perror("ioctl TIOCSETP failed in echo_on.");
} /* echo_on */

static unsigned char c[2048];			/* Wot's the maxsize pleez */
#if 1
static char h[100]="mud.edvz.uni-linz.ac.at";
#else
static char h[100]="localhost";
#endif
static int tport= 2001;
static int gport= 2004;

int fd_tel;
int fd_gfx;

/* +-----------------+
   | telnet_handler  |
   +-----------------+ */

void tel_handler(fd,nr)
int fd;
int nr;
{
static char cwill[3] = { IAC, WILL, 0 };
static char cwont[3] = { IAC, WONT, 0 };
static char   cdo[3] = { IAC, DO,   0 };
static char cdont[3] = { IAC, DONT, 0 };

int i,pos,ii;
int b0,b1;

  i=read(fd,c,nr);
#if 1
printf("[tel_handler: i=[%d], nr=[%d]\n",i,nr);
#endif
  for (pos=0;pos<i;) {
	while(c[pos]==IAC) {
	    pos++;				/* That's the command */
	    switch (c[pos]) {
	    case DO:
		pos++;
		if (c[pos]==TELOPT_ECHO) {	/* do ECHO only */
		    cwill[2]=c[pos];
		    send(fd,cwill,3,0);
		    echo_on(1);
		}
		else {
		    cwont[2]=c[pos];
		    send(fd,cwont,3,0);		/* i WONT do that ! */
		}
		break;
	    case WILL:
		pos++;
		if (c[pos]==TELOPT_ECHO) {	/* He WILL echo */
		    cdo[2]=c[pos];		/* OK, do so */
		    send(fd,cdo,3,0);
		    echo_off(1);		/* so we don't */
		}
		break;
	    case WONT:
		pos++;
		if (c[pos]==TELOPT_ECHO) {	/* He WONT echo */
		    cdont[2]=c[pos];		/* OK, you dont */
		    send(fd,cdont,3,0);
		    echo_on(1);			/* so we do */
		}
		break;
	    case IP:
		printf("Remote server has closed connection.\n");
		exit();
	    default:
		pos++;
	    } /* switch */
	} /* while */
	printf("%c",c[pos++]);
    }
    fflush(stdout);
} /* tel_handler */

void gfx_handler(fd,nr)
int fd;
int nr;
{
int i,j;

    i=read(fd,c,nr);
    printf("[GFX] [len=%d] [data=",i);
    for (j=0;j<i;j++)
	printf("%c",c[j]);
    printf("]\n");

    /* Hey Rasta ... HAVE FUN WITH YOUR X-CLIENT :-) */
}

void io_avail() {
int nrb;

    if (ioctl(fd_tel,FIONREAD,&nrb)) {
	perror("ioctl: FIONREAD(1)");
	exit();
    }
    if (nrb) tel_handler(fd_tel,nrb);

    if (ioctl(fd_gfx,FIONREAD,&nrb)) {
	perror("ioctl: FIONREAD(1)");
	exit();
    }
    if (nrb) gfx_handler(fd_gfx,nrb);

}

main() {
char sl[256];
int i;

  signal(SIGIO,io_avail,-1);		/* IO done by ourselves */
  fd_tel=prepare_ipc(h,tport);
#if 1
  fd_gfx=prepare_ipc(h,gport);
  neg_gfx(fd_tel,fd_gfx);		/* Tell the server who we are */
#endif

#if 0
    /* setup async IO. main() will do nothing but read from keyboard */

    if (fcntl(fd_tel,F_SETOWN,getpid())==-1) {
	perror("fcntl: F_SETOWN");
	exit();
    }
    if (fcntl(fd_tel,F_SETFL,FASYNC)==-1) {
	    perror("fcntl: F_SETFL");
	    exit();
    }
#endif

  for (;;) {		/* we stay here forever */
    gets(sl);		/* cooked mode */
    i=strlen(sl);
    sl[i++]='\n';
    sl[i]='\0';
    send(fd_tel,sl,strlen(sl),0);
  }
}
