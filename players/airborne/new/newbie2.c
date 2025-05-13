inherit "room/room";

reset(arg) {
 if(arg) return;
  set_light(1);
  short_desc = "Complete newbie area";
  long_desc = 
"The next command to examine is the 'look' command. By itself it will show you "+
"what is in the room. For example, if you type 'look' in this room, you will "+
"see this message again. It is a good idea to use look when you forget what "+
"room you are in or if you want to examine the description more closely. In "+
"many rooms the description gives little hints as to what you are able to "+
"do.\n"+
"     Look is also used to view your fellow players. You can see their full "+
"title, description, and what they are carrying with them. To do this, you "+   
"type look at <player's name>.\n"+
"     You can also use look to look at an item that is in the description. "+
"For instance, if I told you there is a picture hanging on the wall, you "+
"could expect to be able to look at the picture as well as looking at the "+
"wall. To look at the picture you would type: look at picture.\n\n"+
"        When you are ready, exit lesson 2.\n";

	no_obvious_msg = "";
  items = ({ "wall", "An ordinary wall",
	"picture", "A picture of Airborne, the wizard who created this newbie area" });
  property = ({ "no_teleport", "no_sneak", "no_steal" });
}

init(){
  ::init();
    add_action("leave", "leave");
    add_action("next", "lesson");	
}

int leave() {
  write("You stop the newbie lessons.\n");
  write("Please mail Airborne with any complaints or suggestions");
  this_player()->move_player("after stopping the lesson#players/airborne/new/station");
  return 1;
}

int next(string str){
  if(!str){
    notify_fail("What lesson?\n");
    return 0; 
    }
  if(str == "2"){
    this_player()->move_player("lesson 2#players/airborne/new/newbie3");
    return 1; 
    }
  else {
    notify_fail("You are not ready for that lesson yet.\n");
    return 0; 
    }
}
