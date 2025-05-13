inherit "room/room";

object captain, weapon, key_ob;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Practice Room";
    long_desc =
"This room has wooden swords and shields in neat rows and\n"+
"in shelves along the walls. A round space in the center\n"+
"of the room is covered with leather and looks padded. A\n"+
"large window almost takes up the entire west wall.\n";
    dest_dir = ({
"players/ted/fire/tower3", "east"
    });
    items = ({
"window","Out the window you see a large forest of petrified trees",
"windows","Out the window you see a large forest of petrified trees",
"shelf", "You see on the shelves rows of practice swords and shields.\n"+
         "You have no desire to take them, as they are made of wood",
"shelves", "You see on the shelves rows of practice swords and shields.\n"+
           "You have no desire to take them, as they are made of wood"
    });
  }
  if(!present("fire giant captain")) {
    captain = clone_object("players/ted/monsters/fire_giant_captain");
    move_object(captain, this_object());
    weapon = clone_object("players/ted/weapons/fire_giant_bastardsword");
    move_object(weapon, captain);
    captain->init_command("wield bastardsword");
    key_ob = clone_object("obj/treasure");
    call_other(key_ob, "set_id", "key");
    call_other(key_ob, "set_alias", "fire_key");
    call_other(key_ob, "set_short", "A Red Key");
    call_other(key_ob, "set_weight", 1);
    call_other(key_ob, "set_value", 100);
    move_object(key_ob, captain);
    call_other("players/ted/random_armor","make_item",captain,17);
    call_other("players/ted/random_magic","make_item",captain,17);
    captain->set_wc(30);
    captain->set_ac(6);
  }
}
