inherit "room/room";

object steel_dragon, sword;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Huge Cavern";
    long_desc =
"This huge cavern has been dug out of the solid\n"+
"rock. Huge gouge marks can been seen where\n"+
"steel claws have ripped out chunks of rock.\n";
    dest_dir = ({
"players/ted/cold/ice_drag", "east"
    });
  }
  if(!present("steel dragon")) {
    steel_dragon = clone_object("players/ted/monsters/steel_dragon");
    move_object(steel_dragon, this_object());
    sword = clone_object("players/ted/weapons/giant_slayer");
    move_object(sword, steel_dragon);
  }
}
