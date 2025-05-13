inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "path3";
  long_desc = 
      	"You are travelling on a dirt path.\n"
        "You see small foot prints in the soft dirt.\n"
        "Barking noises can be heard from the north.\n";
  dest_dir = ({ "players/jake/path4.c","north",
        "players/jake/path2.c","east" });

replace_program("room/room");
}
