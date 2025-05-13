inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("sharp sword");
    set_alt_name("sword");
    set_alias("sharp_sword");
    set_class(10);
    set_short("A sharp sword");
    set_long("A sword with a sharp scabbard and a diamond in the hilt.\n");
    set_value(300);
    set_weight(2);
    set_hit_func(this_object());
  }
}

weapon_hit(ob) {
  return (wielded_by->query_npc()) ? 5:0;
}
