inherit "room/room";
reset(arg){
 if(!arg){

  set_light(1);
  short_desc = "Complete newbie area";
  long_desc =
"   In your adventuring, you may come upon doors. Doors, just like in the "+
"real world will bar your way. Some doors will be closed, and some will "+
"be locked as well.\n"+
"   To unlock a door, you will obviously need the right key. When you come "+
"upon a door, you will first need to unlock it and then open it so that you "+
"can go through. The commands to unlock the doors also have other optional "+
"arguments which can be used to differenciate between doors (for example "+
"if there were more than one door in a particular room). The direction is "+
"used to specify which door, and the key type is used to specify which key "+
"(in case you have more than one). The command will be used in the following "+
"manner: unlock <direction of door> with <type of key> key.\n\n"+
"    When you exit lesson 7, you will be tested on a few of the lessons. \n";

   property = ({"no_tport_in", "no_tport_out", "no_steal", });

    no_obvious_msg = "";
	}
}
init(){
::init();
   add_action("leave", "leave");
   add_action("next", "lesson");
	}
next(str){
  if(!str){
    write("What lesson?\n");
    return 1; }
  if(str=="7"){
	this_player()->move_player("lesson 7#players/airborne/new/newbie8");
	return 1; }
  else {
	write("You are not ready for that lesson yet.\n");
	return 1; }
	}
leave(){
   write("You leave the complete newbie area.\n");
   write("Please mail Airborne with any comments or suggestions.\n");
   	this_player()->move_player("after stopping the lessons#players/airborne/new/station");
	return 1; }
