/* 12.08.93 Airborne: Changed format to use clone_list and replace_program */

inherit "/room/room";
#include "../cellar.h"

reset(arg) {
  set_light(0);
  short_desc= "In a cellar";
  long_desc=
   	"You have entered the dark cellar of the Mages Tower.\n"+
	"It's cold and wet here, but the smell of fresh cheese\n"+
	"really makes you hungry. The vault smells after bad wood.\n"+
	"There is a wall to the west. The little corridor leads\n"+
	"further to the east.\n";
  dest_dir = ({ ROOM+"c1","east", });
  items = ({ "vault","An old oak-wooden vault",
	"wall","A grey stone wall",
	"walls","Grey stone walls",
	"bottom","A dark stone bottom" });
  clone_list = ({ 1, 4, "rat", "players/llort/guild/cellar/monster/rat", 0 });  


::reset();
replace_program("room/room");
}
