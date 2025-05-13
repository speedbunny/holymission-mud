/* 12.05.93 Airborne: Rewritten to use "room/room" and replace_program */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Dining room";
  long_desc =   
      "This is the dining room. The dinner has not been served yet,\n" 
      "but you hear some sounds from the kitchen to the south, indicating\n" 
      "that the cook is busy at work. A door leads east to the main hall.\n";
  items = ({ "door", "An ordinary door" });
  dest_dir = ({ "players/padrone/inside/main_hall", "east",
	 "players/padrone/inside/kitchen", "south" });

replace_program("room/room");
}         
