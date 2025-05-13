inherit "room/room";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  short_desc = "path";
  long_desc = 
        "The path proceeds northward.  Trees surround the area.\n"
         "Off in the distance you see what appears to be some sort of large building.\n"
         "You can also see a large building far off to the west.\n";
  items = ({ "trees", "You see large evergreen trees that surround the area",
 	"large building", "To the north you see the silhouette of a building",
 	"west building", "Kit's place is to the west!" });
  dest_dir = ({
    "/players/bobo/arena/road6","west",
    "players/jake/path1","north",
    "room/forest8","south",
  });

  replace_program("room/room");
}
