inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("unholy mace");
  set_alias("mace");
  set_short("The unholy mace");
  set_long("A heavy iron mace, with deadly spikes.\n");
  set_weight(3);
  set_class(11);
  set_value(1500);
  set_type(2);
  set_hit_func(this_object());
}

int weapon_hit(object vic) {
  if(!random(15) && this_player()->query_alignment() < 0) {
     this_player()->heal_self(20);
     write("You feel better!\n");
     return 60;
  }
  return 0;
}
