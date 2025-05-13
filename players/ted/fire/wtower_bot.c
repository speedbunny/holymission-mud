inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Tower Stairs";
    long_desc =
"A set of stone stairs curves up the side of the tower.\n"+
"You can hear the wind whistling through the tower\n"+
"above you.\n";
    dest_dir = ({
"players/ted/fire/wtower_top", "up",
"players/ted/fire/whall4", "north"
    });
    items = ({
"stair","The stairs look well used. They are cut from the wall of the\n"+
        "tower. They wind up out of sight",
"stairs","The stairs look well used. They are cut from the wall of the\n"+
         "tower. They wind up out of sight"
    });
  }
}
