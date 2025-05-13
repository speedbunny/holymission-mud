/* 030595 Colossus: Changed to guild/guild_room */
// 6-4-97 Kryll : removed the cost command (not sure why it was
//                listed yet not implemented)
inherit "guild/guild_room";

#include "/players/brainsprain/guild/headers.h"
#define COST_FOR_JOIN   1000
 
int query_property(string arg){
  switch(arg){
  case "no_fight":return 1;
  }
}

void reset(int arg)
{
    ::reset(arg);
    if (arg)
        return;
    set_light(1);
    set_guild(1);
    short_desc = "Thieves guild";
    long_desc =
      "You stand in the thieves guild.\n"+
      "The lighting is so bad you wonder how anyone but "+
      "a thief could see here.  This is where guild members "+
      "congregate to discuss new techniques and methods, plot "+
      "against enemies, and the like.  It is also where the "+
      "innocent come to learn the ways of thieving. "+
      "A pair of doors lead west from here.\n\n"+
      "Commands: advance, list, list [number], or join.\n";

    dest_dir = ({
      DIR + "/tavern", "north",
      "/players/apollo/thieves/rooms/sewer03","east",
      DIR + "/fence", "west",
      "room/sunalley2", "up",
      DIR + "/temple","south",
    });
}

void init()
{
    ::init();
      add_action("_north","north");
      add_action("_west","west");
      add_action("_south","south");
}

status _north() {
    if(!present("thiefsoul",this_player()))
        write("You are not allowed there!\n");
    else
        TP->move_player("north#"+ROOMDIR+"tavern");
    return 1;
}
status _south() {
    if(!present("thiefsoul",this_player()))
      write("You are not allowed there!\n");
    else
      TP->move_player("south#"+ROOMDIR+"temple");
  return 1;
}

status _west() {
    if(!present("thiefsoul",this_player()))
      write("You are not allowed there!\n");
    else
      TP->move_player("west#"+ROOMDIR+"fence");
  return 1;
}

do_join()
{

    if (::do_join()) {
    write("You may not join this guild.\n");
        return 1;
    }

    if (this_player()->query_size() > 3)
        return notify_fail("You realize you are simply too large and "
          + "conspicuous to be an effective thief.\n");

    if (this_player()->query_money() < COST_FOR_JOIN) {
        write("You don't have enough gold coins.\n" +
          "Prove you've any talent, and steal " + COST_FOR_JOIN + ".\n");
        return 1;
    }


    this_player()->add_money(-COST_FOR_JOIN);
    this_player()->set_guild(1);
    write("A thin, non-descript man smiles slyly and says,\n"
      + "'The price of tools has gone through the roof but ... "
      + "five hundred gold\nshould do it.'\n");
    write("\nYou suddenly have a desire for gold and lots of it.\n");
    say(this_player()->query_name()
      + " looks a little less trustworthy.\n");
    log_file("GUILD.JOIN", this_player()->query_real_name()
      + " joins the thieves guild on " + ctime(time()) + "\n");
    return 1;
}

int query_maxhp(int level) {
    int retval;

    retval = (level * 17 + 45);
    if (retval < (this_player()->query_con()*14))
        retval = (this_player()->query_con()*14);
    return retval;
}
