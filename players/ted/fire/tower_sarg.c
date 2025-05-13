inherit "room/room";

object seargent, weapon, arrow;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Small Room";
    long_desc =
"This is a small cramped room. A hard cot takes up almost all of"+
"the north wall. The only other thing in the room is a short "+
"wooden stool in the corner. All in all, very uninteresting.\n";
    dest_dir = ({
"players/ted/fire/tower3", "west"
    });
  }
  if(!present("fire giant seargent")) {
    seargent = clone_object("players/ted/monsters/fire_giant_seargent");
    move_object(seargent, this_object());
    weapon = clone_object("players/ted/weapons/fire_giant_longsword");
    move_object(weapon, seargent);
    seargent->init_command("wield sword");
    seargent->set_wc(23);
  }
}
