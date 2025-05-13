inherit "room/room";

reset(arg){
  set_light(1); 
  short_desc = "Main hall of the Castle of Padrone";
  long_desc = "You are in the main hall of the Castle of Padrone.\n" 
	  "Through the open north door you can see the courtyard,\n" 
	  "and you think you just caught a glimpse of a pair of\n" 
	  "very big and dangerous giants there...\n" 
	  "Maybe they are guarding the Castle against people who\n" 
	  "have sneaked in without paying for a ticket,\n" 
	  "and maybe there are other guards around here too?\n" 
	  "The stairs are south, the dining room is west,\n" 
	  "and the Wizard's consultation room is east.\n";
  dest_dir = ({ "players/padrone/inside/courtyard", "north",
	  "players/padrone/inside/stairs1", "south",
	  "players/padrone/inside/dining_room", "west",
	  "players/padrone/inside/waitingroom", "east" });

replace_program("room/room");
}
