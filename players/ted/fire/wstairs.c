inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
"A set of stone stairs curves up the side of the tower.\n"+
"A chill breeze drys the sweat from your brow.\n";
    dest_dir = ({
"players/ted/fire/tower1", "up",
"players/ted/fire/whall1", "south"
    });
    items = ({
"stair","The stairs look well used. They are cut from the wall of the\n"+
        "tower. They wind up out of sight",
"stairs","The stairs look well used. They are cut from the wall of the\n"+
         "tower. They wind up out of sight"
    });
  }
}
