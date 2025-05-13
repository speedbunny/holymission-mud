/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.15.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"
 
 object plyr;
 int get_me,sthb,whb;

reset (arg) {
if (arg) return;
   set_id("Egg");
   set_short("An Egg");
   set_alias("egg");
   set_long("This is a dinosour egg. You have the feeling that there are many uses for\n"+
   "uses for it.\n");
   set_value(300);
   set_weight(1);
}
get() {
     
     if(!get_me){
     sthb=0;
     whb = 0;
     get_me = 1;
     set_heart_beat(1);
     return 1;}
     
     return 1;
     }

heart_beat() {
     object spegg;

     if (CO(environment(this_object()), "id", "bagger")) {
     whb+=1;
     }
     
     else {
     sthb +=1;
     }
   
   if(sthb == 10) {
     move_object(clone_object("/players/arthur/area/items/egg"),environment(this_object()));
     destruct(this_object());
     }
   if(whb == 20) {
     move_object(clone_object("/players/arthur/area/items/cane"),environment(this_object()));
     destruct(this_object());
     }
   }

init() {
   add_action("throw", "throw");
   add_action("smell", "smell");
   ::init();
   }

smell(str) {
  if(str != "egg") return 0;
  write("The egg smells very fresh.\n");
  return 1;
}

throw(str) {
 string player; 

  if (!str) 
    return 0;

  if(sscanf(str, "egg at %s",player) != 1)
    return 0;
  
  plyr = find_living(lower_case(player));
    
    if (!plyr) {
        write("No player with that name.\n");
        return 1;}

  shout(capitalize(TP()->query_real_name())+" hurls a giant egg into the sky!\n"+
  "Splatt! "+capitalize(player)+" is hit dead center in the face by the egg.\n");

  tell_object(plyr,"Splatt!\nYou are hit in the face with a giant egg.\n"+
  "Your face is now covered in egg yolk.\n"+
  "You hear "+capitalize(TP()->query_real_name())+" laughing at you!\n");
  transfer(clone_object("/players/arthur/area/items/yolk.c"),plyr);

  tell_object(TP(),"You hit "+capitalize(player)+" dead center in the face\n"); 
  return 1;}
