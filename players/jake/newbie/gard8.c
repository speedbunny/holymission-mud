inherit "room/room";
#include "/players/jake/defs.h"
object squirrel,stick;
reset (arg) {
if (!squirrel) {
squirrel=clone_object("obj/monster");
squirrel->set_name("squirrel");
squirrel->set_short("squirrel");
squirrel->set_long("A cute and cuddly little squirrel.\n");
squirrel->set_level(2);
squirrel->set_align(20);
squirrel->set_aggressive(0);
squirrel->add_money(50);
stick=clone_object("obj/treasure");
stick->set_id("stick");
stick->set_short("A stick");
stick->set_long("A little wooden stick.\n");
stick->set_value(5);
stick->set_weight(0);
move_object(stick,squirrel);
move_object(squirrel,this_object());
}
if (arg) return;
set_light(3);
short_desc = "gard8";
long_desc = "You have ventured east into Jake's garden.\n"
+ "This area is very pretty and peaceful.\n"
+ "The grass is green, the trees are green, in fact, everything is green!\n"
+ "Except a little squirrel.\n"
+ "He sits there nibbling on a little stick.\n"
+  "Smurf village is to the east.\n";
items = ({"tree","GREEN trees","grass","GREEN grass"});
 DD = ({
 NEW + "gard9","west",
 NEW + "gard7","east",
 NEW + "gard6","north",
});
}
