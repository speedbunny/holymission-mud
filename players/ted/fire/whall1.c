inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "North-South Hall";
    long_desc =
"This is a north-south hall. It is illuminated by torches.\n"+
"There are no windows or other openings. The sound of your\n"+
"footsteps echo down the hall.\n";
    dest_dir = ({
"players/ted/fire/wstairs", "north",
"players/ted/fire/whall3", "south"
    });
    items = ({
"torch","The torches are almost burnt out here",
"torches","The torches are almost burnt out here"
    });
  }
}
