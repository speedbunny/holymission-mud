inherit "obj/monster";

int count;

reset(arg) {
  object seeds;
  if(arg) return;
  ::reset();
  count=0;
  set_name("sparrow");
  set_short("A sparrow");
  set_long("A cute little sparrow that looks playfully at you.\n");
  set_level(1);
  set_hp(25);
  set_ep(100);
  set_al(125);
  set_whimpy(1);
  load_chat(20,({ "Sparrow chirps playfully.\n",
	"Sparrow looks playfully at you.\n",
	"Sparrow flutters about happily.\n", }));
  move_object(seeds=clone_object("players/moonchild/plants/appleseeds"),
	this_object());
  seeds->set_no(4+random(12));
}

heart_beat() {
  if(count++>4) {
    random_move();
    count=0;
  }
  ::heart_beat();
}
