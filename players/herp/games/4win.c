/* 920415 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/*
 +------------------------------------------------+
 | Vier gewinnt.                                  |
 | Version fuer zwei menschliche Spieler.         |
 | Die Computergegner-version folgt ein andermal. |
 +------------------------------------------------+ */

#if 0
#define BACK	"players/herp/workroom"
#else
#define BACK	"room/pub2"
#endif
#define HELP	"players/herp/games/helpdir"
#define	DEFNUM	4				/* Vier gewinnt */

#define	HOME	"[2J[1;1H"

#define TP	this_player()
#define TO	this_object()
#define env(x)	environment(x)
#define TPN	TP->query_name_true()
#define TPRN	TP->query_real_name()
#define TPARCH	(TP->query_archwiz())

#define SAY(x)	tell_room(TO,x)

object op1,op2;					/* Object of players */ 
string n1,n2,rn1,rn2;				/* Name of players */
string hline;					/* just a hor.line */
string who_won;
int who_moves,xs,ys;
int num;
int arr;					/* Game Matrix */
int fill;					/* vector */

int is_quest;					/* play for fun or quest ? */

inherit "/room/room";

id(str) { return str=="4win" || str=="puzzle" || str=="game"; }

short() { return "Another weird puzzle"; }

get() { return 1; }

enter(str) {
  if (env(TO)==TP) {
     write("You can't do this when you carry the puzzle.\n");
     return 1;
  }
  if (env(TP)==TO) {
     write("You already are in the puzzle.\n");
     return 1;
  }
  if (id(str)) {
     TP->move_player("into the puzzle",this_object());
     return 1;
  }
}

do_exit() {
object ob;

  ob=environment(this_object());
  if (ob && ob->query_real_name()) ob=environment(ob); /* player carries us */
  if (!ob) TP->move_player("the puzzle#"+BACK);
  else TP->move_player("the puzzle",ob);
  return 1;
}

long(silent,rt) {
object ob;
string msg,rn;
int i,j,k,f;

  msg="";
  if (!silent) {
    msg=HOME+"You've entered another weird game from Herp the Hacker.\n\n";
    if (!arr) {
       msg+="The game has no dimensions ...\n" +
	    "Adjust it's size using the 'make' command.\n";
       write(msg);
       return 1;
    }
    msg+=show_register();
  }
  msg+="\n";
  for (i=xs-1;i>-1;i--) {
    msg+=" ";
    for (j=0;j<ys;j++) {
#if 0
write("long: i "+i+" j "+j+"\n");
#endif
      k=arr[i][j];
      (k?(k==1?(msg+="| OO "):(msg+="| XX ")):(msg+="|    "));
    }
    msg+="|\n";
#if 0
write("long: msg "+msg+"\n"); 
#endif
  }
  msg+=hline;
  for (i=1;i<=ys;i++)
     (i<10?(msg+="   "+i+" "):(msg+="  "+i+" "));

  if (rt) return msg;		/* we need to do this coz command() doesn't */
  else write(msg+"\n\n");
  if (query_verb()=="look") write("To the west is the pub.\n");

  if (who_moves) {ob=op1;rn=rn1;}
  else {ob=op2;rn=rn2;}
  if((!ob && rn) || (ob && ob->query_linkdeath())) notify_linkfail();
}
  
reset(arg) 
{
    ::reset(arg);
    if (!arg) set_light(1);
    if (!arr) make("6 8");
}

init() {
  ::init();
  add_action("register","register");
  add_action("make","make");
  add_action("enter","enter");
  add_action("do_exit","exit");
  add_action("do_exit","leave");
  add_action("do_exit","west");
  add_action("do_exit","escape");
  add_action("help","help");
  add_action("chk_dest","destruct");
  add_action("giveup","giveup");
  add_action("move","",1);
  add_action("save","sp");
}

chk_dest(str) {
object *ob;
int i,w;

  if (id(str)) {
     ob=all_inventory(this_object());
     for (i=0;i<sizeof(ob);i++)
       if (living(ob[i]) && find_player(ob[i]->query_real_name())) {
          w=1;
          break;
       }
     if (w) write("Don't destruct the game, there are players in it !\n");
     else destruct(this_object());
     return 1;
  }
}

save() { save_object("players/herp/games/4win"); return 1; }

show_register() {
string msg;
  msg="Player 1 (O): ";
  if (n1) msg+=n1+".\n";
  else msg+="not registered.\n";
  msg+="Player 2 (X): ";
  if (n2) msg+=n2+".\n";
  else msg+="not registered.\n";
  if (n1 && op2)
     if (who_moves==255) msg+=who_won+" has won the game.\n";
     else if (who_moves==-1) msg+="The game ended even.\n";
     else if (who_moves) msg+="It's "+n2+" to move.\n";
     else msg+="It's "+n1+" to move.\n";
  msg+="\n";
  return(msg);
}

register() {
  if (!arr) {
     write("The game has no dimension ...\n" +
     	   "Adjust it's size using the 'make' command.\n"+
	   "(You can always type 'help game')\n");
     return 1;
  }
  if (!op1) {
     n1=TPN;
     rn1=TPRN;
     op1=TP;
     write("You have registered to the game.\n" +
	   "You are the first to move.\n" +
	   "You play the 'O' symbol.\n");
     say(TPN+" has registered to the game and plays the 'O' Symbol.\n");
     return 1;
  }
  if (!op2) {
     if (rn1==TPRN) {
	write("You are a split person ...\n" +
	      "You are already registered.\n");
	return 1;
     }
     n2=TPN;
     rn2=TPRN;
     op2=TP;
     write("You have registered to the game.\n" +
	   "You are to move after "+n1+".\n" +
	   "You play the 'X' Symbol.\n");
     say(TPN+" has registered to the game and plays the 'X' Symbol.\n");
     return 1;
  }
  write("Sorry, "+n1+" and "+n2+" are already playing against each other.\n");
  return 1;
}

help(str) {
  if (id(str)) {
    cat("/"+HELP+"/4win");
    return 1;
   }
}

hard_make(p1,p2,p3,p4,p5,p6)
{ xs=p1; ys=p2; num=p3; op1=p4; op2=p5; 
  n1=op1->query_name(); rn1=op1->query_real_name();
  n2=op2->query_name(); rn2=op2->query_real_name();
  is_quest=p6;
}

make(str) {
int i;
#define r1 return 1;

  if (!str) return;

  if (rn1 && op1 && !op1->query_linkdeath() && 
      rn2 && op2 && !op2->query_linkdeath() &&
      who_moves!=255 && who_moves!=-1 && !TPARCH) {
     write("You have to wait until "+n1+" and "+n2+" finish their game.\n");
     return 1;
  }
  if (rn1 && op1 && !op1->query_linkdeath() && !rn2 && !op2 && !TPARCH) {
     write("You have to wait until "+n1+" gets "+op1->query_objective()+"self a partner.\n");
     return 1;
  }
  if (sscanf(str,"%d %d %d",xs,ys,num)!=3) {
     if (sscanf(str,"%d %d",xs,ys)!=2) return;
     num=DEFNUM;
  }
  if (!xs || !ys ||!num || xs<num || ys<num) {
     write("Will you enter values that make sense, please ?\n");
     say(TPN+" looks dull playing this game.\n");
     return 1;
  }

  say(TPN+" changed the game's size into "+xs+" x "+ys+", where "+num+" in a row wins.\n");
  write("You changed the game's size into "+xs+" x "+ys+", where "+num+" in a row wins.\n");
  op1=0; op2=0; n1=0; n2=0; rn1=0; rn2=0; who_moves=0;

  arr=allocate(xs);				/* Allocate Game Matrix */
  for (i=0;i<xs;i++) {
     arr[i]=allocate(ys);
  } 

  fill=allocate(ys);

  hline=" |----";				/* Define horline now */
  for (i=1;i<ys;i++) hline+="+----";
  hline+="|\n";	

  return 1;


}

move() {
string msg,sym,snb;
string w,l;
object obj;
int slot;

  if (sscanf(query_verb(),"%d",slot)!=1) return;
  slot--;
  if (env(TP)!=TO) {
     write("You have to enter the game first.\n");
     return 1;
  } 

  if (!rn1) {
     write("To play, type 'register'.\n");
     return 1;
  }

  if (TPRN==rn1 && !rn2) {
     write("You need an opponent to play against.\n");
     return 1;
  }

  if (TPRN!=rn1 && TPRN!=rn2) {
     write("You have to wait until "+n1+" and "+n2+" are finished.\n");
     return 1;
  }
  if (slot<0 || slot>ys-1) {
     write("You've enterd an invalid slot number.\n");
     return 1;
  }
  if (who_moves==255 || who_moves==-1) {
     write("The game is over.\n");
     return 1;
  }
  if (who_moves && TPRN==rn1 || !who_moves && TPRN==rn2) {
     write("You have to wait until it's your turn !\n");
     return 1;
  }
  if (fill[slot]==xs) {
     write("The slot is full.\n");
     return 1;
  }
  switch (slot+1) {
  case 1 : snb="st"; break;
  case 2 : snb="nd"; break;
  case 3 : snb="rd"; break;
  default: snb="th"; break;
  }
  (who_moves?(sym="a 'X'"):(sym="an 'O'"));
  msg=" the "+(slot+1)+snb+" slot with "+sym+" symbol.\n";
  write(HOME+"You fill"+msg);
  (who_moves?(msg=n2+" fills"+msg):(msg=n1+" fills"+msg));
  say(HOME+msg);

  arr[fill[slot]][slot]=who_moves+1;
  fill[slot]++;

  switch (chk_win(slot)) {
  case -1 : who_moves=-1; 
	    shout("Herp shouts: "+n1+" and "+n2+" played remi against "+
		  "each other in Connect 4.\n"); back_player();
	    write("Herp tells you: Pitty, noone did win.\n");
	    return 1;
  case 1  : if (who_moves) { w=n2;l=n1; }
	    else { w=n1;l=n2; };
	    who_moves=255; who_won=w;
	    shout("Herp shouts: "+w+" won against "+l+" playing \"Connect "+num+"\".\n");
	    write("Herp tells you: You won! Congrats.\n");
	    back_player(); return 1;
  }

  long(1);

  /* Check if one of them lost their link */

  if (!op1) op1=find_player(rn1);
  if (!op2) op2=find_player(rn2);
  (who_moves?(obj=op1):(obj=op2));
  who_moves=!who_moves;
  if (!obj || obj->query_linkdeath()) notify_linkfail();
  else tell_object(obj,long(1,1)+"\n");
  return 1;
}

notify_linkfail() {
  write("It seems you have lost your partner ...\n" +
	"If you are tired of waiting, use 'exit' to quit the game,\n" +
	"or 'make' to start a new one with a different partner.\n");
}

back_player() {
object *ob;
int i;

/* TESTVERSION .... DONT DESTRUCT FOR NOW

  ob=all_inventory(TO);
  for (i=0;i<sizeof(ob);i++)
      if (living(ob[i])) {
	 tell_object(ob[i],"You are moved to "+BACK->short()+".\n");
	 move_object(ob[i],BACK);
  }
  destruct (TO);
  return 1;
*/
}

/* Checks who won the game.
 *
 *  returns:  -1	...	the game is remi (noone won)
 *	       0	...	no one wins, continue game
 *	       1	...     the current player (who_moves) wins
 */
 
chk_win(slot) {
int i,j,y,f,n;
int w;

  y=fill[slot]-1;		/* Current y pos */
  f=arr[y][slot]; 		/* Color */

  /* Check vertical win */
#if 0
write("y ["+y+"]\n");
#endif
  if (y>=num-1) {			/* don't check vert. if not > num */ 
#if 0
write("check vertical win\n");
#endif
    w=1;
    for (i=y-1;i>y-num && w ;i--) {
#if 0
write("i ["+i+"] arr[slot][i] "+arr[i][slot]+" f ["+f+"]\n");
#endif
	if (arr[i][slot]!=f) {
	   w=0;
	   break;
	}
    }
    if (w) return 1;			/* current player wins */ 
  }

  /* Check horizontal win */

  n=1;					/* This one stone is surely <f> */
  for (i=slot+1;i<ys && arr[y][i]==f;i++)
      n++;
  for (i=slot-1;i>-1 && arr[y][i]==f;i--)
      n++;
  if (n>=num) return 1;			/* We won */

  /* Check diagonal win ( / ) */
#if 0
write("Check diagonal win /\n");
#endif
  n=1;					/* This one stone is surely <f> */
  for (i=slot+1,j=y+1;i<ys && j<xs && arr[j++][i++]==f;) n++;
  for (i=slot-1, j=y-1;i>-1 && j>-1 && arr[j--][i--]==f;) n++;
  if (n>=num) return 1;

  /* Check diagonal win ( \ ) */
#if 0
write("Check diagonal win \\\n");
#endif
  n=1;					/* This one is surely <f> */
  for (i=slot-1,j=y+1;i>-1 && j<xs && arr[j++][i--]==f;) {
#if 0
write("i ["+i+"] j ["+j+"]\n");
#endif
/* arr[j][i] ["+arr[j][i]+"\n"); */
 n++;
}
#if 0
write("...\n");
#endif
  for (i=slot+1,j=y-1;i<ys && j>-1 && arr[j--][i++]==f;) {
#if 0
write("i ["+i+"] j ["+j+"]\n");
#endif
 n++;
}
#if 0
write("n ["+n+"]\n"); 
#endif
  if (n>=num) return 1;

  /* Check if the played remis */
  w=1;
  for (i=0;i<ys;i++)
      if (fill[i]<ys) {
	 w=0;
	 break;
      }
  if (w) return -1;

  return 0;
}
