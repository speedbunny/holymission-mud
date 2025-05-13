inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Intersection";
    long_desc =
"Here a north-south hall intersects a east hall. It is illuminated\n"+
"by torches set high on the walls. Some unusual sounds come from\n"+
"a door to the south.\n";
    dest_dir = ({
"players/ted/fire/whall1", "north",
"players/ted/fire/wguard", "south",
"players/ted/fire/whall4", "east"
    });
    items = ({
"door", "It is open. Maybe you should go in?",
"south door", "It is open. Maybe you should go in?"
    });
  }
}
