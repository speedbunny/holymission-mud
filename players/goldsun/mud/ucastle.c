#define NAME "uglymouth"
#define DEST "players/uglymouth/workroom"

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

id(str) {
  return str == "castle" || str == "model";
}

short() {
    return "A small scale model of " + capitalize(NAME)
        + "'s Viking area";
}

long() {
/* Boring description. Keeping it for archive reasons.
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");
*/
    write("This is a small scale model of Uglymouth's Viking  area.\n"
      + "It is very detailed. If you 'spy' it carefully, you might\n"
      + "even see miniature players walking around.\n");
}

init() {
    add_action("enter", "enter");
    add_action("spot_players","spy");
}

enter(str) {
    if (!id(str))
	return 0;
   write("You enter the castle to the viking area. \n");
   this_player()->move_player("into the castle#players/uglymouth/vikings/shore1");
    return 1;
}

int max_clock_time;
reset(arg) {
    if (arg)
	return;
    max_clock_time = ("/obj/tick")->qry_timer_value();
    move_object(this_object(), DEST);
}

query_max_clock() {
   return max_clock_time;
   }

make_quest() {
object quest;
   quest=clone_object("/obj/quest_obj");
   quest->set_name("viking");
   quest->set_weight(35);
   quest->set_killing(2);
   quest->set_short_hint("Convince the Vikings to leave Symria");
   quest->set_hint("On a tropical bay, somewhere southeast in this world, a clan of Vikings \n"
      + "has invaded a coastal village, called Symria. The Vikings have proven to be \n"
      + "quite stubborn in negotiations and are now planning to settle in the \n"
      + "village and its surrounding area. \n"
      + "With our diplomats sent back in only their underwear and our armies needed \n"
      + "elsewhere, we need a witty adventurer to get the vikings to leave the area. \n\n"
      + "Note: this quest can be solved without fighting, but if you get into one \n"
      + "prepare to lose some hit points. Good luck. \n\n"
      + "                                 Viking Lord Uglymouth \n");
   quest->add_quest();
   }

int spot_players(string str) {
int i,j;
object *u;
string place,*placetest;
  if(!id(str)) return 0;
  u = users();
  for(i=0;i<sizeof(u);i++) {
    if(environment(u[i])) place = file_name(environment(u[i]));
    placetest = explode(place,"/");
    if(placetest[1] == "uglymouth" && placetest[2] == "vikings") {
      printf("%-10.10s is at %s.\n", u[i]->query_short_name(), place->short());
      j++;
      }
    }
  printf("There %s %d player%s in the viking area.\n", j==1 ? "is" : "are", j, j==1 ? "" : "s");
  return 1;
  }
