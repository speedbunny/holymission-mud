/* notify.c (C) mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanth */

#define	who	"herp"
#define cwho	capitalize(who)
#define TP	this_player()
#define TO	this_object()
#define TPN	TP->query_name()
#define TPRN	TP->query_real_name()
#define TPVIS	!TP->query_invis()
#define TPPRO	TP->query_pronoun()
#define env(x)	environment(x)
#define SAY(x); if (me) tell_object(me,x+"\n");

init() {
  enable_commands();
}

reset(arg) { if (!arg) move_object(this_object(),"room/church"); }

catch_tell(str) {
object me;
string msg,name;
int i;

#if 0
  me = find_living(who);
  i= sscanf(str,"%s enters the game.",name); 
  SAY("str ["+str+"]"); 
  SAY("i ["+i+"]");
  SAY("name ["+name+"]");
  SAY("TPRN ["+TPRN+"]");
  SAY("TPVIS ["+TPVIS+"]");
  SAY("is(env(TP)==env(TO)) ? ["+(env(TP)==env(TO))+"]");
#endif
  
  if (TP && TPRN==who && env(TP)==env(TO) &&
     (sscanf(str,"%s enters the game.\n",name)==1) && cwho==name && TPVIS) {

     msg=TPN+" enters the game.\n";
     switch (random(4)) {
     case 0 : msg+="You are mad with fear about that fact !\n"; break;
     case 1 : msg+="You wonder how "+TPPRO+" manages to look like Mick Jagger.\n"; break;
     case 2 : msg+=cwho+" shouts: HAIL, AND WELL MET, CYBERPUNX\n"; break;
     case 3 : msg+="You hear 'Sympathy for the Devil' being played\non a fucked-up 20 year old Marshall amplifier.\n";
     }
     shout(msg);
  }
}

    



