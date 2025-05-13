/*Code by Arthur for Holy Mission - 140.78.3.1 Date 11.4.94 */
/* This object is to prevent  
 * 1: Multipule people doing the quest at one given time
 * 2: ease of searching in certain rooms in the forest.
 * 3: to take care of the rabbit's location, and move him when 
 *    they quit the quest.
 * 4: to let the player quit the quest, when he quits, or wants 
 * to quit the quest*/

inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h";

 int DD,ho,hoa;

reset(arg) 
{
  if (arg) return;
     set_alias("quest_checker");
     set_short(0);
     DD=random(20)+1;
     ho=random(6)+1;
     hoa=random(6)+1;
     set_long("This object Keeps track of the quest items, and lets me\n"+
     "keep track of the time that it takes for people to do the quest to help\n"+
     "prevent people from CHEATING.\n");
     set_value(0);
     set_weight(0);
     enable_commands();
     set_heart_beat(1);
}
init() {
   add_action("E_QUEST", "end");
   add_action("sear", "search");
   ::init();
}
E_QUEST(str) {
 if (!str)
    return 0;
 if (str!="quest")
    return 0;

 else {write("You have quit this quest!\n"); 
 shout("Arthur's Guard shouts: Hahaha Another one bites the dust!\n");
 dti();
 return 1;
 }
}
dti() {
  call_other("/players/arthur/entrance","RST_QUE");
  destruct(this_object()); return 1;
 }
drop() {
  dti();
  return 1;
}
sear() { 
 if (file_name(environment(this_player()))=="players/arthur/quest/forest/forest"+DD)
 {write("You find a ????"); clone_object("/players/arthur/quest/obj/excal"); 
 move_object(this_object(),TP()); return 1;}
 else if (file_name(environment(this_player()))=="players/arthur/area/rooms/houses/hou"+ho+hoa)
 {write("You find a ????"); clone_object("/players/arthur/area/items/??"); 
 move_object(this_object(),TP()); return 1;}
 
 else return 0;}

