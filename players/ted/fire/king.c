inherit "room/room";

object king, cloak, ring, guards, armor;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "On Dais";
    long_desc =
"You are standing on the dais that overlooks the throne room.\n"+
"The high domed ceiling adds enough space to give the room\n"+
"a feeling of being outside. It is all quite impressive, including\n"+
"the large ornate throne sitting in the center of the dais.\n";
    dest_dir = ({
"players/ted/fire/throne", "south"
    });
    items = ({
"ornate throne","As you look closely at the throne, you see that it is realy\n"+
         "gold plated, not solid gold. It also seems that all the gems\n"+
         "are made of cut glass. All in all, a rather poor looking throne",
"throne","As you look closely at the throne, you see that it is realy\n"+
         "gold plated, not solid gold. It also seems that all the gems\n"+
         "are made of cut glass. All in all, a rather poor looking throne"
    });
  }
  if(!find_living("fire giant king")) {
    king = clone_object("players/ted/monsters/fire_giant_king");
    move_object(king, this_object());
    cloak = clone_object("players/ted/armors/cloak_of_protection");
    move_object(cloak, king);
    ring = clone_object("players/ted/armors/ring_of_protection");
    move_object(ring, king);
    guards = clone_object("players/ted/armors/steel_boots");
    move_object(guards, king);
    armor = clone_object("players/ted/armors/fire_giant_kings_platemail");
    move_object(armor, king);
    call_other(king,"init_command", "wear armor");
    call_other(king,"init_command", "wear ring");
    call_other(king,"init_command", "wear boot");
    call_other(king,"init_command", "wear cloak");
    call_other("players/ted/random_magic","make_item",king,19);
    call_other("players/ted/random_magic","make_item",king,19);
    king->set_ac(20);
  }
}
