/* PAH1.C - Programmed by Jake */
/* 280693: Ethereal Cashimor: Lizards slowed in growth */

inherit "room/room";

reset(arg) {
 if(arg) return;
  set_light(1);
  short_desc="First part of the path";
  long_desc="You are still on the dirt path. There are trees to your east "
	"and west. The trail splits ahead.\n";
  items = ({ "east", "A thick growth of trees. Too thick to walk through",
	"west", "A dense forest" }); 
  dest_dir = ({ "players/jake/path2","north",
	"players/jake/path","south" });
  smell = "It seems as if some reptiles visit this place frequently.";
  clone_list = ({ 1, 4, "lizard", "players/jake/Old_area/monster/lizard", 0 });

::reset();
replace_program("room/room");
}
