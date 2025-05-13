inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Complete newbie area";
   long_desc = 
"    Torches are another simple matter. They allow you to see in places "+
"that are too dark to otherwise, but only if they are lit. Lighting a "+
"torch is not as easy as it sounds on Holy Mission, first you need a flame "+
"or another source of light. Matchboxes are available with matches and "+
"most rooms that are lit by a flame will be able to light your torch.\n"+
"    You will be able to light it here because off in the corner is a "+
"fireplace that is keeping this room lit. So now you have to 'light "+
"torch'. You will need it pretty soon and you may not be able to light it "+
"later, so now is your chance.\n"+
"    When you feel that you will no longer need your torch (there is enough "+
"light available to see without it ) you can use the 'extinguish' command. "+
"This will save your torch for use later when you will need it.\n\n"+
"	When you have finished lighting the torch, exit lesson 6.\n";

  items = ({ "fireplace", "A warm cosy fireplace" });
  property = ({ "has_fire", "no_tport_in", "no_tport_out", "no_steal" });
  no_obvious_msg = "";
  smell = "You smell the wonderous smell of a roaring fireplace";
 return ;
 }
}

init(){
::init();
  add_action("next", "lesson"); 
  add_action("leave", "leave");
}

int leave(){
  write("You have left the complete newbie area.\n");
  write("Please mail Airborne with any comments or suggestions");
  this_player()->move_player("after stopping the lessons#players/airborne/new/station");
  return 1; 
}

int next(string str){
  if(!str){ 
    notify_fail("What lesson?\n"); 
    return 0; 
    }
  if(str=="6"){
    this_player()->move_player("lesson 6#players/airborne/new/newbie7");
    return 1; 
    }
  else {
    notify_fail("You are not ready for that lesson.\n");
    return 0; 
    }
}
