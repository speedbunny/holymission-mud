inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "floor6";
  long_desc = 
        "You have entered a rather strange looking room.\n"
 	"The smell of marijuana tickles your nose.\n"
	"There are tye-dyes scattered all over the place.\n"
        "A bowl of incense burns in the middle of the floor.\n"
	"You think you hear the Grateful Dead playing.\n";
  items = ({ "tye-dyes", "Tie died clothes, sheets and all that",
	"bowl", "There are incense in the bowl",
	"incense", "Incense in a bowl" });
  dest_dir =  ({ "players/jake/hall","east" });

replace_program("room/room");
}


