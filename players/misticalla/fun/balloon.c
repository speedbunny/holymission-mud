/*Code by Arthur for Holy Mission 140.78.3.1 Date done 12.23.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;
 int get_me,sthb,whb;

reset (arg) {
if (arg) return;
   set_id("A Water Balloon");
   set_short("A Water Balloon");
   set_alias("balloon");
   set_long("This little pink balloon is filled with water! Aim and fire
at your favorite person! 'throw balloon at <player>'.\n");
   set_value(0);
   set_weight(1);
}
get() {
     
     if(!get_me){
     sthb=0;
     get_me = 1;
     set_heart_beat(1);
     return 1;}
     return 1;
     }
heart_beat() {
     
     sthb +=1;
   
   if(sthb == 30) {
   tell_object(environment(this_object()),"The balloon explodes in
your hands before you can use it.\n");
     destruct(this_object());
     }
   }

init() {
   add_action("throw", "throw");
   ::init();
   }

throw(str) {
 string player; 

  if (!str) 
    return 0;

  if(sscanf(str,"balloon at %s",player) !=1)
    return 0;
  
  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}
  say(TP()->query_name()+" launches a water balloon at
"+capitalize(player)+" and runs away laughing.\n");

  tell_object(plyr, "Ack! You just got nailed with a big pink water
balloon!\n"+
  "You hear "+TP()->query_name()+" laughing at you!\n");

  tell_object(TP(), "You hit "+capitalize(player)+" in the face!\n");
  destruct(this_object());
  return 1;}
