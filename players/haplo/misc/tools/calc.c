/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* 19921128, now with verbose german result message ! ("set german") */

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

static int language;		/* 0 = digits, 1 = german */

id(str) { return str=="calc" || str=="calculator"; }
short() { return "A calculator"; }
long() { write(short()+".\nUse with '? <expression>'\n\n" +
	"Syntax:\n\n" +
	"expr       = term   { (\"+\" | \"-\") term }\n" +
	"term       = factor { (\"*\" | \"/\") factor }\n" +
	"factor     = [ \"+\"|\"-\" ] (const | \"(\" expr \")\")\n");
	}
#if 0
	"factor     = value  [ \"^\" pos_value ]\n" +
	"value      = [ (\"+\" | \"-\") ] abs_value\n" +
	"pos_value  = [ \"+\" ] abs_value\n" +
	"abs_value  = (const | \"(\" expression \")\")\n");
	}
#endif

reset(arg) {
  if (!arg) language=1;
}

init() {
  add_action("calc","?");
  add_action("set","set");
}

set(str) {
  if (str=="german") language=1;
  else if (str=="digits") language=0;
  write("Ok.\n");
  return 1;
}

calc(str) {
int i;

  l=str;	/* reset getsym */
  x=0;
  ef=0;
  perr=0;
  c=0;

  newsym();
  expr();
  if (!perr) {
    if (language) write(in_worten(c));
    else write(c);
    write("\n");
  }
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
#if DEBUG
write("-- factor: c = "+c+"\n");
#endif
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
  default: perr=1; return; 
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
#define return break
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
#undef return
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

string in_worten(int z)
{
string *wlaut;
string *plaut;
int *dig_a;
int i,j,k,z1,z2,z3;		/* Hilfsvariable */
int max;

string worten;

  wlaut=({	"null",
		"ein", "zwei", "drei",
		"vier", "fuenf", "sech",
		"sieb", "acht", "neun",
		"zehn", "elf", "zwoelf" });

  plaut=({ "null", "tausend", "million", "milliarde" });

  /* Erst mal in einzelne Ziffern zerlegen */

  dig_a=allocate(15);		/* sollte genuegen ! */
  i=1;
  while (z>0) {
    dig_a[i]= z%10;
    z=z/10;
    i++;
  }
  max=i-1;

  i=((max-1) / 3)+1;		/* Hunderter/Tausender/Millionen/etc...*/
  j=i*3;			/* auf stellen in dig_a ausrichten */
  worten="";
  while(j>0) {
    z1=dig_a[j]; z2=dig_a[j-1]; z3=dig_a[j-2];
    if (z1>0) {
	worten+=wlaut[z1];
	if (z1==6) worten+="s";
	else if (z1==7) worten+="en";
	worten+="hundert";
    }
    k=z2*10+z3;
    if ((k<=12) && (k>0)) {
	worten+=wlaut[k];
	if(k==6) worten+="s";
	else if (k==7) worten+="en";
    }
    else {
	if (z3>0) worten+=wlaut[z3];
	if (z3==6) worten+="s";
	else if (z3==7) worten+="en";
	if (z2>0) {
	   if (k>=20) {
	      if (z3>0) worten+="und";
	      if (z2==2) worten+="zwan";		/* zwanzig */
	      else worten+=wlaut[z2];
	      if (z2==3) worten+="ssig";		/* dreissig */
	      else worten+="zig";
	   }
	   else worten+=wlaut[10];
	}
    }
    k+=z1*100;
    i--;
    if (k==1)
	if (i>1) worten+="e";		/* eine statt ein */
	else if (i==0) worten+="s";	/* eins statt ein */
    if ((k>0) && (i>0)) {
       worten+=plaut[i];				/* potenzwortlaut */
       if (k>1) {
	  if (i==2) worten+="en";			/* millionen */
	  else if (i==3) worten+="n";		/* milliarden */
       }
    }
    j-=3;
  }
  return worten; 
}
