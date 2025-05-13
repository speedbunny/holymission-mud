inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Top of Tower Stairs";
    long_desc =
"You are at the top of the stairway. A short hallway leads south\n"+
"and the stairs descend into darkness.\n";
    dest_dir = ({
"players/tamina/teds/fire/wstairs","down",
"players/tamina/teds/fire/tower2","south"
    });
    items = ({
"stairs","A hot wind blows by your face, cooling the sweat on your brow"
    });
  }
}
