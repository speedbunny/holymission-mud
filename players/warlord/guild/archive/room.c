
#include "std.h"
#define GUILD_NAME	"cleric"		/* clerics guild	*/ 
#define GM		"guild/master"

inherit "guild/room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here		 */
/* All the pretitles, titles and exp levels for a thief. */
/*-------------------------------------------------------*/


#define MAXLVL		30
#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)
#undef  EXTRA_RESET	
#define EXTRA_RESET	::reset(); extra_reset(arg);
#undef  EXTRA_INIT
#define EXTRA_INIT	::init();
#undef  EXTRA_MOVE1
#define EXTRA_MOVE1	if (!chk_leave())
#undef  EXTRA_MOVE2
#define EXTRA_MOVE2\
  if (TP->query_guild()!=guild) {\
     write("Only clerics may go there !\n");\
     return 1;\
  }

int	guild;			/* guild # (reset get's it from obj/guild */

TWO_EXIT("/room/mine/tunnel_room","east",
	 "players/warlord/guild/clerichome","south",
	 "Clerics guild",
         "This is the humble guild of the clerics.\n"+
	 "Commands: cost, advance [levels, stats],\n" +
	 "          spend, points, list, list [number],\n" +
	 "          or join.\n",1)

extra_reset(arg) {
  if (arg) return;
  guild=GM->query_number(GUILD_NAME);
  set_guild(guild);
}

do_join() {
object ob;

 if (!::do_join()) return 1;	/* Joining not possible */

 if(TP->query_wis() < 7) {
    write("Sorry but you are not strong enough to be a Cleric.\n");
      return 1;
  }

  write("Welcome to the Clerics Guild.\n");
  ob = clone_object("players/warlord/guild/soul.c");
  move_object(ob,this_player());
  this_player()->set_guild(guild);
  write("Type help guild for any info.\n");
  return 1;
}

/* changed by Llort 050592 */
query_maxhp(lvl) {
  return(44+6*lvl);  /* con 1 = 50, con 30 = 224 */
}

query_maxsp(lvl) {
  return(36+14*lvl);   /* int 1 = 50, int 30 = 456 */
}

