inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Tower Hall";
    long_desc =
"This is a small north-south hall. A large window opens on the\n"+
"west wall. A door leads east and the hall continues south.\n";
    dest_dir = ({
"players/ted/fire/tower1", "north",
"players/ted/fire/tower3", "south",
"players/ted/fire/tower_room", "east"
    });
    items = ({
"windows","Out the window you can see a large forest of petrified trees",
"window","Out the window you can see a large forest of petrified trees",
"door","This is a small wooden door. It is slightly ajar"
    });
  }
}
