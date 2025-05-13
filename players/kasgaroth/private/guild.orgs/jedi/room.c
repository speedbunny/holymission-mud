/* 920414 mud@alijku05.edvz.uni-linz.ac.at Siegfried Huber */

#include "std.h"
#define GUILD           "jedi"
#define GM              "guild/master"
#define LGF             "GUILD.JOIN"
#define TP              this_player()
#define TPN             TP->query_name()
#define RACES           ({ "elf","half-elf","human","hobbit", }) 

#undef EXTRA_RESET
#define EXTRA_RESET     ::reset(arg); extra_reset(arg);
#undef EXTRA_INIT
#define EXTRA_INIT      ::init();
#undef EXTRA_MOVE1
#define EXTRA_MOVE1     if (!chk_leave())
#undef EXTRA_MOVE2
#define EXTRA_MOVE2\
 if (TP->query_guild()!=guild) {\
    write("You are not allowed in the inner sanctuarium.\n");\
    return 1;\
 }

inherit "guild/room";

/*------------------------------------*/
/* Do join, advance and many more ... */
/*------------------------------------*/

int guild;              /* set this at reset */
string races;           /* races allowed to join the jedi */

TWO_EXIT("room/crop","west",
	 "players/kelly/guild/inner","south",
	 "The Jedi's Guild",
	 "You are in the Jedi's guild\n" +
	 "This room is brightly lit.\n" +
	 "To the south lies the guild sanctuarium, where only members " +
	 "are allowed.\n" +
	 "Commands: cost, advance,\n" +
	 "          list, list [number],\n" +
	 "          or join.\n",1)

extra_reset(arg) {
object board;

  if (arg) return;
  guild=GM->query_number(GUILD);
  set_guild(guild);

  board=clone_object("obj/board");
  board->set_name("jedi");
  board->set_file(GM->query_dir(guild)+"/board");
  board->set_short("the public board of the Jedi guild");
  move_object(board,this_object());
  
}

do_join() {

  if (!::do_join()) return 1;   /* Joining not possible */
  if(!check_race(TP)) {
     write("Sorry, you are not allowed to become a Jedi.\n");
     return 1; 
  }
  if(TP->query_alignment()>-100 && TP->query_alignment()<100) {
     write("You should decide for one side.\n");
     return 1;
  }
  TP->set_guild(guild);
  write("You have joined the famous Jedi Knights.\n");
  say(TPN+" has joined the famous Jedi Knights.\n");
  log_file(LGF,TPN+" joins the "+GUILD+"'s guild at "+
	   ctime(time())+"\n");
  return 1;
}

check_race(tp) {
  int i;
 
  for(i=0;i<sizeof(RACES);i++)
    if(tp->query_race()==RACES[i]) return 1;

  return 0;
}
