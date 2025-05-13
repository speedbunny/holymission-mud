/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Royal garden";
  long_desc = 
    "You are on a wonderful green with some trees standing around. But what kind of\n"+
    "trees are these? You have never seen these kinds of trees before. To the west\n"+
    "and south is a wall, so the only way out is to the north or east.\n";
    items = ({
    "trees", "Strange trees which you have no idea what they are but they are very pretty",
    });
  dest_dir = ({
    "/players/jug/room/garden/garden1", "north",
    "/players/jug/room/garden/garden3", "east",
  });
}
