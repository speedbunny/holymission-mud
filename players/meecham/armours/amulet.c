inherit "obj/armour";

void reset(status arg) {
  set_name("diamond amulet");
  set_type("amulet");
  set_ac(1);
  set_short("Diamond amulet");
  set_long("This amulet is made from diamonds and glitters with great\n" +
    "magical power!\n");
  set_weight(2);
}

void init() {
  ::init();
  add_action("_use", "use");
}

status _use(string str) {
  object shad;

  if (!id(str)) return (0);
  if (!query_worn()) {
    write("You must wear it first!\n");
    return (1);
  }
  if (this_player()->query_sp() < 100) {
    write("You don't have the mental capacity to activate the amulet\n" +
      "right now.\n");
    return (1);
  }
  if (this_player()->spam_shad()) {
    write("The amulet is still active.\n");
    return (1);
  }
  this_player()->restore_spell_points(-100);
  shad = clone_object("/players/meecham/obj/spam_shad");
  shad->start(this_player());
  write("You feel your spellcasting ability expand.\n");
  return (1);
}
