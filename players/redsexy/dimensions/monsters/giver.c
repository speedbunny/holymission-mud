inherit "obj/monster";

#include "/players/redsexy/defs.h"
#include "/players/redsexy/dimensions/defs.h"
#include "/players/redsexy/dimensions/quest/redtest"

int q1, q2;
object taker;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Giver");
  set_alias("giver");
  set_short("The Giver");
  set_long("The Giver gives out trials!\n");
  set_race("dimensioneer");
  set_level(1);
  set_gender(1);
  set_no_fight(1);
  set_prevent_poison(1);
}

init() {
  ::init();
  add_action("take", "take");
}


take(arg) {
    if(TPL > 5) {
	      win();
	      return 1;
    write("You are not knowledgable enough to take the test.\n");
    return 1;
 }
}

win() {
  object redobj, orangeobj, yellowobj, greenobj, blueobj, indigoobj, violetobj;
  taker = 0;
  q1 = 0;
  q2 = 0;
  redobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(redobj, this_player());
  redobj->set_type("red");
  orangeobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(orangeobj, this_player());
  orangeobj->set_type("orange");
  yellowobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(yellowobj, this_player());
  yellowobj->set_type("yellow");
  greenobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(greenobj, this_player());
  greenobj->set_type("green");
  blueobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(blueobj, this_player());
  blueobj->set_type("blue");
  indigoobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(indigoobj, this_player());
  indigoobj->set_type("indigo");
  return 1;
  violetobj = clone_object("players/redsexy/dimensions/quest/trial");
  transfer(violetobj, this_player());
  violetobj->set_type("violet");
  return 1;
}