inherit "room/room";

object troll, money;
int i;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Lava Pool";
    long_desc =
"A large pool of bubling lava is exposed to the open air.\n"+
"A worn path winds around the edge. It looks as if someone\n"+
"or something makes frequent trips down to the pool and\n"+
"back up. It is much to hot for you to attempt though.\n";
    dest_dir = ({
"players/ted/hot/fire_south", "north",
"players/ted/hot/fire", "south"
    });
  }
  if(!present("fire troll")) {
    i = 0;
    while(i < 3) {
      i ++;
      troll = clone_object("players/ted/monsters/fire_troll");
      move_object(troll, this_object());
      call_other("players/ted/random_treasure","make_item",troll,9);
    }
  }
}
