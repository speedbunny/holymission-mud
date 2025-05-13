#define NAME "kbl"
#define DEST "/players/kbl/workroom"
object taliesin;
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
   write("This is Kbl's Castle!\n"+
         "He is very proud of it!\n"+
	 "How do I know?? This is Sunshine writing his castle descript!\n"+
	 "And I love him so I know it is good...\n"+
	 "Ok, Ok, I'm a little biased....\n"+
	 "So, why don't you just enter the castle and see for yourself!\n"+
	 "				-Sunshine (the future RL Mrs. Kbl!)\n");
}

make_quest()
{
  object qobj;

  qobj = clone_object("obj/quest_obj");
  qobj->set_weight(50);
  qobj->set_name("AnySlayer");
  qobj->set_short_hint("Find AnySlayer sword");
  qobj->set_hint("AnySlayer sword was forged when the world was young and\n"+
                 "stolen upon creation by a Demon Of Chaos called Zesranotae.\n"+
                 "It is rumored that a Old man on a clifftop knows how to\n"+
                 "get to the PP of C but the way is not easy.\n"+
                 "This quest is solvable above levels 18. Some deciphering\n"+
                 "and key observations are needed to survive the Demons Of\n"+
                 "Chaos.\n");
  qobj->set_killing(8);
  qobj->add_quest();
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
  this_player()->move_player("into Kbls' castle#players/kbl/kblroom");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    transfer(this_object(), DEST);
/* Uglymouth 940127: Kbl takes over guild from Qwerty (banished) */
    if(!taliesin)
    {
    taliesin = clone_object("players/turbo/guild/obj/taliesin");
      transfer(taliesin,"room/pub2");
      log_file("kbl.taliesin","Taliesin created and moved at "+ctime(time())+" ***\n");
    }
}
