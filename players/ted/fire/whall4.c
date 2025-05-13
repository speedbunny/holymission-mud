inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Intersecting Hall";
    long_desc =
"This is a small intersection between a north-south hall and\n"+
"a west hall. It is illuminated by torches set high on the walls.\n";
    dest_dir = ({
"players/ted/fire/whall2", "north",
"players/ted/fire/wtower_bot", "south",
"players/ted/fire/whall3", "west",
"players/ted/fire/courtyard", "east"
    });
    items = ({
"torch", "The torches are to high to reach. Anyway, they are almost burt out",
"torches", "The torches are to high to reach. Anyway, they are almost burt out"
    });
  }
}
