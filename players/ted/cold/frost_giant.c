inherit "room/room";

object giant, sword;
int i;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Forest";
    long_desc =
"The remains of a freshly dead mammoth lie here.\n"+
"most of the meat has been wraped in ice packed\n"+
"leather skins.\n";
    dest_dir = ({
"players/ted/cold/frozen_forest", "south",
"players/ted/frost/base", "north"
    });
  }
  if(!present("giant")) {
  i = 0;
    while(i < 2) {
    i = i + 1;
    giant = clone_object("players/ted/monsters/frost_giant");
    move_object(giant, this_object());
    sword = clone_object("players/ted/weapons/sword_of_frost");
    move_object(sword, giant);
    call_other(giant,"init_command","wield sword");
  }
  i = 0;
  while(i < 1) {
    i = i + 1;
    giant = clone_object("players/ted/monsters/young_frost_giant");
    call_other("players/ted/random_treasure","make_item",giant,14);
    move_object(giant, this_object());
  }
 }
}
