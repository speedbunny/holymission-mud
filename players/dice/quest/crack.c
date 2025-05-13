inherit "/obj/thing";

object owner;
reset(arg) {
  if (arg) return 1;
   set_name("A crack");
   set_alias("crack");
    set_short("A small crack in the ceiling");
    set_long("A crack in the ceiling, through which you can see daylight.\n");
  set_value(0);
  set_weight(20000);
  can_get = 0;
  return 1;
  }

init(){
  add_action("enter_crack","enter");
  }
enter_crack(str){
    if(!str){
    notify_fail("Enter what ?\n");
    return 0;
    }
if((str=="crack")||(str=="crack in ceiling")){
   write("You jump up, grab a hold of the edge, and slowly\n"+
         "climb out of the small room.\n"+
         "The owner sees what you're doing and decides to follow you.\n");
   this_player()->move_player("through a crack#players/dice/quest/q14");
   owner=present("owner",environment(this_object()));
   if(owner){
   destruct(owner);
   return 1;
   }
   else{
   return 1;
   }
   }
}
