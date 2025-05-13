inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Tower Top";
    long_desc =
"You are on top of the west tower. Just to the east you see\n"+
"the other tower. They both flank the gates, alowing archers\n"+
"to fire their bows at anyone attacking the gate.\n";
    dest_dir = ({
"players/ted/fire/wtower_bot", "down"
    });
    items = ({
"stair","The stairs look well used. They are cut from the wall of the\n"+
        "tower. They wind down out of sight",
"stairs","The stairs look well used. They are cut from the wall of the\n"+
         "tower. They wind down out of sight"
    });
  }
}
