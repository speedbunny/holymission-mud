/*Code by Arthur for Holy Mission 140.78.3.1 Date done 12.23.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;
 int get_me,sthb,whb;

reset (arg) {
if (arg) return;
   set_id("A Snowball");
   set_short("A Snowball");
   set_alias("snowball");
   set_long("This is a well hardened snow-ball, if you wish you can throw it at players.\n E.G. 'throw snowball at <player>'.\n");
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
   tell_object(environment(this_object()),"The snowball melts into nothingness.\n");
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

  if(sscanf(str,"snowball at %s",player) !=1)
    return 0;
  
  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}
  say(TP()->query_name()+" hurls a snowball at "+capitalize(player)+".\n");

  tell_object(plyr, "Splatt!\nYou are pegged in the face with a snowball!\n"+
  "You hear "+TP()->query_name()+" laughing at you!\n");

  tell_object(TP(), "You hit "+capitalize(player)+" dead center in the face.\n");
  destruct(this_object());
  return 1;}
