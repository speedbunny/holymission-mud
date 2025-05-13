/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(-10);
  short_desc = "A cellar room";
  long_desc = 
    "This room seems to be the end of the staircase going down.\n"+
    "It is absolutely silent here, and only magic power can make light here.\n";
  dest_dir = ({
    "/players/jug/room/cellar1.c", "up",
  });
replace_program("room/room");
}
