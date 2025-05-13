/* 12.11.93 Airborne: Change to room/room. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc =  "Between the staircases";
  long_desc = 
	"You are between two long staircases going up and down.\n"
	"Torches on the walls light up the passage.\n"
	"You wonder who keeps the torches lit... The atmosphere somehow seems\n"
	"to become more threatening further down. A sign pointing\n"
	"west says 'Fairyland'\n";
  items = ({ "staircase", "A plain staircase going up and down",
	"stairs", "A plain staircase going up and down",
  	"torch", "A torch on the wall that lights the way",
	"torches", "Torches on the wall that light the way",
	"sign", "A sign pointing west that says: 'Fairyland'" });
  dest_dir = ({ "players/topaz/angmar/stairs","up",
         "players/topaz/angmar/downstairs","down",
         "players/topaz/angmar/magroom","west",
         "players/topaz/angmar/treasury","north" });

replace_program("room/room");
}
