inherit "room/room";

init() {
 ::init();
 add_action("make"); add_verb("poison");
}

make(str) {
  object stuff;
 if(!present(str,this_player())) {
   write(str+"not present\n");
   return 1;
 }
 stuff = clone_object("players/ted/weapon_shadow");
 stuff->set_weapon(present(str,this_player()));
 stuff->set_bonus(40);
 stuff->start();
 write("Done\n");
 return 1;
}
