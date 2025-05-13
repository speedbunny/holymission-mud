inherit "room/room";

object w_guard, weapon, shield;


reset(arg) {
  int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "A Guard Room";
    long_desc =
"This room smells as if a number of unbathed men have spent\n"+
"a very long time here. There are signs of a recently disturbed\n"+
"poker game. Cots and bed rolls lie in one corner of the room.\n";
    dest_dir = ({
"players/ted/fire/whall3", "north"
    });
    items = ({
"cots","These are hard wooden planks covered by a thin layer"+
       "of padding. They look very uncomfortable",
"beds","These are hard wooden planks covered by a thin layer"+
       "of padding. They look very uncomfortable",
 "game","This is a game played with cards. As the cards are delt, the",
        "people playing bet coins on what their cards are.(Very Primitive)"
    });
  }
  if(!present("fire giant guard")) {
    i = 0;
    while(i < 3) {
      i ++;
      w_guard = clone_object("players/ted/monsters/fire_giant_guard");
      move_object(w_guard, this_object());
      weapon = clone_object("players/ted/weapons/fire_giant_longsword");
      move_object(weapon, w_guard);
      shield = clone_object("players/ted/armors/fire_giant_shield");
      move_object(shield, w_guard);
      w_guard->init_command("wield longsword");
      w_guard->init_command("wear shield");
      w_guard->set_wc(20);
      w_guard->set_ac(6);
    }
  }
}
