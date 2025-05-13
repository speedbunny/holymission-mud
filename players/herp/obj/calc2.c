/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

#define DEBUG 0

#define UNDEFSY	       -1
#define	EOFSY		0
#define	PLUSSY		1
#define	MINUSSY		2
#define	MULSY		3
#define DIVSY		4
#define LBRACKSY	5
#define RBRACKSY	6
#define CONSTSY		7

static string l;		/* used in getsym */
static int x;			/* too */
static int ef;			/* error-flag */
static int c;			/* current constant */
static int sy;			/* symbol */
static int perr;		/* parser error */

id(str) { return str=="calc" || str=="calculator"; }
short() { return "A calculator"; }
long() { write(short()+".\nUse with '? <expression>'\n\n" +
	"expr    = term   { (\"+\" | \"-\") term }\n" +
	"term    = factor { (\"*\" | \"/\") factor }\n" +
	"factor  = [(\"+\" | \"-\")] (const | \"(\" expression \")\")\n");
	}
init() { add_action("calc","?"); }

calc(str) {
int i;

  l=str;	/* reset getsym */
  x=0;
  ef=0;
  perr=0;
  c=0;

  newsym();
  expr();
  if (!perr) write(c+"\n");
  else write("syntax error\n"); 
  return 1;
}

/* ##########	expr   ########## */

expr() {
int i;

#if DEBUG
 write("enter expr.\n");
#endif

  term();
  if (perr) return;
  i=c;

  while(sy!=EOFSY && sy!=RBRACKSY && !perr) {
    switch(sy) {
    case PLUSSY :
#if DEBUG
 write("-- expr: PLUSSY\n");
#endif
      newsym();
      term();
      if (perr) return;
      i+=c;
      break;
    case MINUSSY :
      newsym();
      term();
      if (perr) return;
      i-=c;
      break;
    default :
#if DEBUG
  write("-- expr: default\n");
#endif
      perr=1; return;
    }
  }
  c=i;
#if DEBUG 
write("f1: i = ["+i+"]\n");
#endif
}

/* ##########	term ########## */

term() {
int i;

#if DEBUG
  write("enter term.\n");
#endif

  factor();
  i=c;
  if (perr) return;

  /* newsym(); */

  while (!perr) { 
    switch(sy) {
    case MULSY :
#if DEBUG
 write("-- term: case MULSY\n");
#endif
      newsym();
      factor();
      if (perr) return;
      i = i*c;
#if DEBUG
write("-- term: MULSY, i = ["+i+"]\n");
#endif
      break;
    case DIVSY :
#if DEBUG
 write("-- term: case DIVSY\n");
#endif
      newsym(); 
      factor();
      if (perr) return;
      i = i/c;
      break;
    default :
#if DEBUG
 write("-- term: default (return)\n");
#endif
      c=i;
      return; 
    }
  }
}

/* ##########	factor	########## */

factor() {
int sign;
#if DEBUG
  write("enter factor.\n");
#endif

  switch(sy) {				/* Optional ("+"|"-") */
  case PLUSSY:
    newsym();
    sign=0;
    break;
  case MINUSSY: 
    newsym();
    sign=1; 
    break;
  }
  switch(sy) {
  case UNDEFSY:
  case EOFSY:   perr=1; return;
  case CONSTSY:
#if DEBUG
write("-- factor: CONSTSY\n");
#endif
    if (sign) c=-c;
    newsym(); return;
  case LBRACKSY :
#if DEBUG
write("-- factor: LBRACKSY\n");
#endif
    newsym();
    expr();
#if DEBUG
write("-- factor: expr says "+perr+"\n");
#endif
    if (perr) return;
#if DEBUG
write("-- factor: return from expr() with ptoken = ");
ptoken();
write("\n");
#endif
    if (sy!=RBRACKSY) { perr=1; return; }
    if (sign) c=-c;
    newsym();
    return;
  }
}
    
newsym() {
string s1,ch;
int len;

#if DEBUG
  write("enter newsym.\n");
#endif

  if (!l) { sy=EOFSY; return; }
  len=strlen(l);
  if (x==len) { sy=EOFSY; return; }

  ch=extract(l,x,x);
  x++;
#define return; break;
  switch (ch) {
  case "(": sy=LBRACKSY; return;
  case ")": sy=RBRACKSY; return;
  case "+": sy=PLUSSY;   return;
  case "-": sy=MINUSSY;  return;
  case "*": sy=MULSY;    return;
  case "/": sy=DIVSY;    return;
  default :
    
    s1=ch+extract(l,x,len);
    if(sscanf(s1,"%d",c)!=1) { sy=UNDEFSY; return; }	/* empty */
    else { x+=strlen(""+c)-1;				/* oh well ... */
      sy=CONSTSY;
  /*    return; */
    }
  }
#if DEBUG
  ptoken(); write("\n");
#endif
}   
#undef return;
ptoken() {
  switch(sy) {
  case LBRACKSY : write("LBRACKSY"); break;
  case RBRACKSY : write("RBRACKSY"); break;
  case PLUSSY   : write("PLUSSY"); break;
  case MINUSSY  : write("MINUSSY"); break;
  case MULSY    : write("MULSY"); break;
  case DIVSY    : write("DIVSY"); break;
  case CONSTSY  : write("CONSTSY ["+c+"]"); break;
  case UNDEFSY  : write("UNDDEFSY"); break;
  case EOFSY	: write("EOFSY"); break;
  }
}
