inherit "room/room";

reset(arg) {
  if(!present("vampire bat")) {
    object b;
    int i;
    for(i=random(5);i<10;i++) {
      move_object(b=clone_object("obj/monster"),this_object());
      b->set_name("vampire bat");
      b->set_race("bat");
      b->set_short("A vampire bat");
      b->set_long("A vampire bat flying about in a flurry of wings and teeth.\n");
      b->set_level(15);
      b->set_hp(150);
      b->set_spell_chance(20);
      b->set_spell_dam(60);
      b->set_spell_mess1("Vampire bat sucks blood!");
      b->set_spell_mess2("Vampire bat sucks your blood!");
      b->set_al(-200);
      b->set_aggressive(1);
    }
  }
  if(arg) return;
  short_desc="Quagmire";
  long_desc="You appear to have stepped into some kind of quagmire.\n"
	+ "You feel yourself gradually slipping into the ground!\n";
  dest_dir=({ "players/moonchild/gnome/idol", "north",
	"players/moonchild/gnome/ghouls", "east",
	"players/moonchild/gnome/dtemple", "south" });
  property=({ "no_teleport" });
}
