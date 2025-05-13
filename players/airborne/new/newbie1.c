inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "Complete newbie area";
  long_desc = "You have entered Airborne's complete newbie area! This area is especially designed for people who have never played an LpMUD before and want to learn the basic commands. This area might get dull for people who have played before so at any time, you can type 'leave' to leave the lessons.\n"+
"  	To begin the newbie lessons type 'lesson 1'.\n\n";
  dest_dir = ({ "players/airborne/new/station", "west" });
  property = ({"no_teleport", "no_sneak", "no_steal"});
}

init() {
  ::init();
    add_action ("leave", "leave");
    add_action ("lesson", "lesson");
}

int leave(){
  write("You stop the lesson and leave Airborne 's newbie area.\n");
  write("Please mail Airborne  with any suggestions or complaints.\n");
  this_player()->move_player("after stopping the lessons#players/airborne/new/station");
  return 1;
}

int lesson(string str){
  if(!str){
    notify_fail("What lesson?\n");
    return 0; 
    }
  if(str =="1"){
    this_player()->move_player("lesson 1#players/airborne/new/newbie2.c");
    return 1; 
    }
  else {
    notify_fail("You are not ready for that lesson yet.\n");
    return 0; 
    }
}
