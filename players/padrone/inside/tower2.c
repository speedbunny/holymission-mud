inherit "room/room";

reset(arg){
  set_light(0);
  short_desc =  "Staircase in the watchtower";
  long_desc = "You are standing on a dark, narrow staircase in the watchtower.\n" 
	 "You can go further up the tower, and you can go down.\n";
  dest_dir = ({ "players/padrone/inside/tower3", "up",
	 "players/padrone/inside/tower1", "down" });

replace_program("room/room");
}
