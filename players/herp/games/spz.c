/* 920414 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/*
 * When a player has to solve the quest, he can be moved to a special
 * exit. The exit must be defined via
 *
 * set_exit      ...	parm: str , the exit str.
 * set_2nd_exit  ...	parm: str , the 2nd exit. If a player has not solved it.
 * set_player    ...	parm: ob , the player who's solving the puzzle
 * set_dimension ...    parm: h, w : height and width of the puzzle
 *
 */

#define TP	this_player()
#define TO	this_object()
#define TPN	TP->query_name()
#define TPRN	TP->query_real_name()
#define TPOBJ	TP->query_objective()
#define TPWIZ	TP->query_wizard()
#define TPARCH	!(TP->query_level()<50)		/* I HATE CONSTANTS */

#define	HOME	"[2J[1;1H"
#define BACK	"players/herp/workroom"
#define HELP	"players/herp/games/helpdir"

#define inform(x);	tell_room("players/herp/games/hall",x);

string special_exit;	/* special exit   */
mixed second_exit;	/* to get back	  */
object pl;		/* who's solving  */
int xs,ys;		/* X/Y Dimension  */
int nx,ny;		/* Where is 0 ?   */
int arr;		/* holding puzzle */
int num_moves;		/* how many moves */
int is_quest;		/* quest or fun ? */

string hline;		/* hor.line */

id(str) { return str=="spz" || str=="puzzle" || str=="game"; }

short() { return "Weird Puzzle"; }

get() { return 1; }

set_exit(str) { special_exit=str; }

set_2nd_exit(mix) { second_exit=mix; }

set_player(ob) { pl=ob; }

help(str) {
  if (id(str)) {
     cat("/"+HELP+"/spz");
     return 1;
  }
}

long(silent) {
string msg;
int x,i,j;

  msg="";
  if (!(silent==1)) {
    msg+=HOME;
    if (this_object()==environment(this_player()))
       msg+="You are inside the puzzle.\nI wonder if you ever can escape ...\n\n";
    else 
       msg+="This is a "+xs+" x "+ys+" puzzle.\nI wonder if you dare to enter ...\n\n" +
	  "It looks like this:\n\n";
  }
  if (!arr) {
     msg+="The game has no dimensions ...\n" +
           "Adjust it's size with the 'make' command.\n";
     write(msg);
     return 1;
  }

  msg+=hline;
  for (i=0;i<xs;i++) {
    for (j=0;j<ys;j++) {
	x=arr[i][j];
	(x==0?(msg+=" |   "):(x<10?(msg+=" |  "+x):(msg+=" | "+x)));
    }
    msg+=" |\n";
    msg+=hline;
  }
  if (!(silent==1)) (num_moves?
			(msg+="\nYou have moved "+num_moves+" times yet.\n"):
		        (msg+="\nYou haven't moved yet ...\n"));
  write(msg);
  return;
}

init() {
  add_action("make_puzzle","make");
  add_action("enter","enter");
  add_action("do_exit","out");
  add_action("do_exit","exit");
  add_action("do_exit","leave");
  add_action("do_exit","escape");
  add_action("do_exit","surrender");
  add_action("help","help");
  add_action("chk_dest","destruct");
  add_action("dump","dump");
  add_action("no_move","move");
  add_action("no_quit","quit");
  add_action("move","north");
  add_action("move","south");
  add_action("move","east");
  add_action("move","west");
}

reset(arg) {
  if (!arg) {
    set_light(1);
    enable_commands();
  }
}

catch_tell(str) { log_file("spz",str); }

query_no_teleport() { return 1; }

dump() {
  if (!TPWIZ) return;
  write("nx "+nx+" ny "+ny+" xs "+xs+" ys "+ys+"\n");
  write("special_exit: "+special_exit+"\n");
  write("pl ");
  write(pl);
  write("\n");
  return 1;
}

no_move(str) {

  if (!str) write("In which direction would you like to move ?\n");
  else write("Use one of the 4 directions ...\n");
  return 1;
}

no_quit() {
  write("You don't want to leave this cowardly way.\n");
  return 1;
}

move() {
string dir;
int onx,ony,move_ok;

#define BANG_HEAD();\
  write("You bang your head on the "+dir+"ern border of the puzzle.\n");\
  if (!TPWIZ) TP->reduce_hit_point(random(5)+1);\
  return 1;

  if (!arr) {
     write("The game has no dimensions ...\n"
	+  "Adjust it with the 'make' command.\n");
     return 1;
  }

  if (this_object()!=environment(this_player())) return;
  dir=query_verb();
#if 0
write("DIR "+dir+" nx/ny xs/ys "+nx+" "+ny+" "+xs+" "+ys+"\n");
#endif

  move_ok=1;
  onx=nx; ony=ny;	/* save values */
  switch(dir) {
  case "left" : dir="west"; break;
  case "right": dir="east"; break;
  case "up"   : dir="north"; break;
  case "down" : dir="down"; break;
  } 
  switch(dir) {
  case "north" : if (nx+1==xs) { BANG_HEAD(); } xswap(++nx,ny,onx,ony); break;
  case "south" : if (!nx) { BANG_HEAD(); } xswap(--nx,ny,onx,ony); break;
  case "west"  : if (ny+1==ys) { BANG_HEAD(); } xswap(nx,++ny,onx,ony); break;
  case "east"  : if (!ny) { BANG_HEAD(); } xswap(nx,--ny,onx,ony); break;
  default : move_ok=0;
  }

  if (move_ok) {

    if (pl && TP!=pl && !TPARCH) {
	write("You are not allowed to mess in this area.\n");
	return 1;
    }
    num_moves++;
    write(HOME+"You move "+dir+".\n\n");
    say(TPN+" moves "+dir+".\n");
    long(1);

    if (chk_solved()) {

       if (pl) {	/* Rasta man ... :-) */
	   write("\nFinally you find a way out of the maze ...\n\n" +
		 "You find a hidden door leading to the treasury chamber !\n\n");
	   TP->move_player("through a hidden door#"+special_exit);
	   destruct(TO);
	   return 1;
       }
       write("Congratulations, you have solved a quest !\n");
       write("It took you "+num_moves+" moves.\n");
       inform("Herp shouts: "+TPN+" has just solved my puzzle !\n");
       inform("Herp shouts: It took "+TPOBJ+" "+num_moves+" moves.\n");
       do_exit(1);
    }
  }
  else write("What a strange direction ...\n");
  return 1; 
}

chk_solved() {
int i,sz,x,y;

  x=y=0;
  sz=xs*ys-1;
  for (i=0;i<sz;i++) {
#if 0
  write("i "+i+" x "+x+" y "+y+" arr[x][y] "+arr[x][y]+"\n");
#endif
     if (arr[x][y]!=i+1) return 0; /* Not solved */
     y=(y+1)%ys;
     if (!y) x=(x+1)%xs;
  }
  return 1;
}

xswap(nx,ny,ox,oy) {
int t;

  t=arr[ox][oy];
  arr[ox][oy]=arr[nx][ny];
  arr[nx][ny]=t;
}

enter(str) {
  if (this_player()==environment(this_object())) {
     write("You can't do this when you carry the puzzle.\n");
     return 1;
  }
  if (this_object()==environment(this_player())) {
     write("You already are in the puzzle.\n");
     return 1;
  }
  if (id(str)) {
     this_player()->move_player("into the puzzle",this_object());
     return 1;
  }
}

do_exit(force) {
string str;
object ob;

  if (force && force!=1) force=0;
  if (second_exit && !force) {
     write("You give up! You hang your had in shame ...\n");
     this_player()->move_player("the puzzle",second_exit);
     destruct(this_object());
     return 1;
  }
  if (pl && !TPWIZ && !force) {
     write("A strong magical force holds you back.\n");
     return 1;
  }

  if (!special_exit) special_exit=BACK;
  ob=environment(this_object());
  if (ob && ob->query_real_name()) ob=environment(ob);
  if (!ob) TP->move_player("the puzzle#"+special_exit);
  else TP->move_player("the puzzle",ob);
  if (!first_inventory(this_object()) && force) destruct(this_object());
  return 1;

}

chk_dest(str) {
object *ob;
int w,i;

  if (id(str)) {
    ob=all_inventory(this_object());
    w=0;
    for (i=0;i<sizeof(ob);i++)
      if (living(ob[i]) && find_player(ob[i]->query_real_name())) {
         w=1;
         break;
      }
    if (w) write("Don't destruct the puzzle ... there are players in it !\n");
    else destruct(this_object());
    return 1;
  }
}

make_puzzle(str) {
int i,j,k,l,x,y,onx,ony,sz;
int termin;
int bitarr;

  if (!str) return;

  if (pl && !TPWIZ) {
     write("Only wizards are allowed to change the puzzle.\n");
     return 1;
  }

  if (!sscanf(str,"%d %d",i,j)==2 || !i || !j) return;

  if (!arr) write(TPN+" creates a "+i+" x "+j+" puzzle.\n");
  tell_room(this_object(),TPN+" has changed the puzzle's size into "+i+" x "+j+".\n");
  
  set_dimension(j,i);
  return 1;
}

set_dimension(j,i) {
int k,l,x,y,onx,ony,sz;
int termin;
int bitarr;

  if (!intp(i) || !intp(j)) {
     write("set_dimension: BUG. No integer-params for height and width.\n");
     return 1;
  }

  /* Load the globals */

  sz=i*j;
  xs=i;
  ys=j;
  num_moves=0;

  hline=" |----";
  for (i=1;i<ys;i++) hline+="+----";
  hline+="|\n";

#if 0
write("init: sz "+sz+" xs "+xs+" ys "+ys+"\n");
#endif
  bitarr=allocate(sz); for (i=0;i<sz;i++) bitarr[i]=0;
  arr=allocate(xs);
  for (i=0;i<xs;i++) arr[i]=allocate(ys);
#if 0
  write("sizeof bitarr "+sizeof(bitarr)+"\n");
#endif


  /* First, put a solved puzzle there */

  x=y=0;
  for (i=0;i<sz;i++) {
     arr[x][y]=i+1;
     y=(y+1)%ys;
     if (!y) x=(x+1)%xs;
   }
   nx=xs-1; ny=ys-1;
   arr[nx][ny]=0;

   /* randomize the board */

   onx=nx; ony=ny;
   for (i=0;i<700;i++) {
      switch(k=random(4)) {
      case 0 : if (nx+1!=xs) xswap(++nx,ny,onx,ony); break;
      case 1 : if (nx)	     xswap(--nx,ny,onx,ony); break;
      case 2 : if (ny+1!=ys) xswap(nx,++ny,onx,ony); break;
      case 3 : if (ny)      xswap(nx,--ny,onx,ony); break;
      }
      onx=nx; ony=ny;
   }

/********** TOO BAD ... this code works N x O(log N) , but the oder
			can't be always solved .... ****************/
#if 0
  /* Create random order */

  for (i=0;i<sz;i++) {
    k=random(sz);
    l=k;
    k=(k+1)%sz;
    termin=0;
    while (!termin) {
#if 0
write("i "+i+" k "+k+" l "+l+" bitarr[k] "+bitarr[k]+"\n");
#endif
      if (!bitarr[k]) { 	/* free space, use it */
	 arr[x][y]=k;
	 if (!k) { nx=x; ny=y; }
#if 0
write("free "+x+" "+y+" set to "+k+"\n");
#endif
	 y=(y+1)%ys;
	 if (!y) x=(x+1)%xs;
	 bitarr[k]=1;
	 termin=1;
      }
      if (k==l) {
	 write("A mighty wizard probably screwed up.\n" +
	       "You fail to create the puzzle.\n");
	 return 1;
      }
      k=(k+1)%sz;
    }
  }
#endif


  write("Done.\n");
  return 1;
}
