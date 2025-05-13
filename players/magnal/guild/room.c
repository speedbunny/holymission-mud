/*
   Guild room for the adventurer's guild which will include
   Jedi, Vagabond and Ranger classes. -Kryll
*/
 
inherit "guild/guild_room";
 
#include "/obj/lw.h"
#include "/players/mangla/defs.h"
 
#define LGF             "GUILD.JOIN"
 
int _guild_info() {
  TP->more_string(read_file("/players/magnal/guild/help.txt"));
  return 1;
}
 
 
int do_advance(string arg) {
  int rc;
 
  rc = ::do_advance(arg);
  if(rc == 1) return 1;
  CD->do_chat(9,"[* Test *] "+CAP(TP->RNAME)+
                " is now level "+TP->LEVEL+".\n");
  return 1;
}
 
 
int _do_join() {
 
  if(::do_join())
    return 1;
 
  "sys/chatd.c"->do_chat(9, lw("[Test] " +
               CAP((string)TP->RNAME)+
               " misguidingly joins the company!\n"));
 
  TP->set_guild(9);
/*
  log_file(LGF, (string)this_player()->query_name() +
           " joins the Adventurer's guild at " + ctime(time()) + "\n");
*/
  return 1;
}
 
 
int _testjoin() {
 
  _do_join();
  return 1;
}
 
 
int query_maxsp(int level,int leg_lev) {
  int retval;
 
  retval = ((level * 17) + 90 + (leg_lev * 5));
  if( retval > 600) retval = 600 + (leg_lev * 5);
  return retval;
}
 
 
int query_maxhp(int level, int leg_lev) {
  int retval;
 
  retval = ((level * 20) + 140 + (leg_lev * 8));
  if( retval > 600) retval = 700 + (leg_lev * 8);
  return retval;
}
 
 
void reset(int arg) {
  object board;
 
  if(arg)
    return 0;
 
  set_light(1);
  set_guild(9);
  short_desc = "Entryway to the Adventurer's guild";
  long_desc =
    "You have entered a room of mystic proportions. It seems to " +
    "fade into a black oblivion in all directions except for a tiny "+
    "point of light to the south. From the power you feel " +
    "radiating through your body, you know that you have stepped " +
    "into a chamber of the Adventurer guild.\n" +
    RED +
    "\n    Here are some commands you may use in this room.\n" +
    "           list, list all, list [number], \n" +
    "           list long, advance, cost, join,\n" +
    "           guildinfo\n" +
    ""+RESET;
  dest_dir = ({
    "/players/mangla/guild/inner","down",
    "/room/deep_forest1", "south",
  });
 
  MOVE(clone_object("boards/jedi"),TO);
 
  property = ({"no_sneak", "no_steal", "has_fire" });
 
  ::reset(arg);
}
 
 
void init() {
  ::init();
  add_action("_guild_info", "guildinfo");
  add_action("_testjoin", "join");
}
 
