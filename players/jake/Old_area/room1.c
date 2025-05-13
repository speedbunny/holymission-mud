inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "room1";
  long_desc = 
        "You are deafened by loud music as you enter this room.\n"
        "There are heavy metal rock group posters all over the walls.\n"
 	"A rather large stereo sits in the corner.\n";
  items = ({ "posters", "Posters of Guns N' Roses, Metallica, and Megadeth",
     "stereo",
     "This stereo is HUGE!  The speakers are as big as the walls themselves"});
  dest_dir = ({ "players/jake/2hall", "west" });
  clone_list = ({ 1, 1, "walkman", "players/jake/monster/walkman", 0 });

::reset();
replace_program("room/room");
}

