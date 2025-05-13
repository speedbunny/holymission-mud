/* Make drinks non-portable - Moonchild 191092 */

#include "abbey.h"
inherit "room/room";


reset(arg) {
  if (!arg) {
     set_light(1);
     property = "no_teleport";
     short_desc="The Rose Abbey Winery";
     long_desc=
"This is the famous Rose Abbey Winery.  You see huge barrels and\n"+
"vintage-stamped bottles.  Here you can taste the vintner's art\n"+
"and heal your soul as well as your body.  You can purchase drinks\n"+
"here, and you see a coffee urn in one corner.\n\n"+
" A pale golden Ale     : 12 coins\n"+
" Chateau le Abbe' wine : 80 coins\n"+
" Le Hermitage Cognac   : 135 coins\n"+
" Dark-Roast Coffee     : 70 coins\n\n";

     dest_dir=({ PATH+"/c16","north" });
  }
}

init() {
  ::init();
  add_action("buy","buy");
  add_action("north","north");
}

north() {
  if("room/pub2"->has_drink(this_player())) {
    tell_object(this_player(), "You are not allowed to leave with drinks!\n");
    return 1;
  }
  this_player()->move_player("north#" + PATH + "/c16");
  return 1;
}

buy(str) {
object ob;
string name,short_desc,mess;
int value,strength,heal;

  switch(str) {
  case "ale":
	short_desc="a bottle of golden ale";
	mess="The best you've ever tasted!";
	heal=0; value=12; strength=2;
	break;

  case "wine":
	short_desc="a bottle of wine";
	mess="A tingling feeling goes through your body";
	heal=10; value=80; strength=8;
	break;

  case "cognac":
	short_desc="a bottle of cognac";
	mess="A shock wave runs through your body";
	heal=15; value=135; strength=12;
	break;

  case "coffee":
	write("Sorry, the Coffee'O'Mat is broken.\n");
	return 1;

  default:
    write("Buy what ?\n");
    return 1;
  }
  if (this_player()->query_money()<value) {
     write("Thats costs "+value+" gold coins, which you don't have.\n");
     return 1;
  }
  ob=clone_object("obj/drink");
  if (!ob->set_value(str+"#"+short_desc+"#"+mess+"#"+
		    heal+"#"+value+"#"+strength)) {
     write("Error creating drink.\n");
     destruct(ob);
     return 1;
  }
  if (transfer(ob,this_player())) {
     write("You can't carry any more.\n");
     destruct(ob);
     return 1;
  }
  ob->set_pub();
  this_player()->add_money(-value);
  write("You pay "+value+" coins for a "+str+".\n"+
	"You get "+short_desc+".\n");
  say(this_player()->query_name()+" orders a "+str+".\n");
  return 1;
}
