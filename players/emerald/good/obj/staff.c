#define TPN this_player()->query_name()
inherit "obj/weapon";
reset(arg) {
  set_name("staff");
  set_alias("staff of beating");
  set_short("staff of beating");
  set_long("This staff has the word 'prince' imprinted on it.\n");
  set_class(6);
  set_weight(3);
  set_value(5000);
  set_hit_func(this_object());
}

weapon_hit(attacker)  {
  if(attacker->query_name("prince")) {
    tell_room(environment(attacker), attacker->query_name() +
     " is hit hard by the staff of beating.\n");
     return random(20)+14;
  }
  else {
    return 12;
  }
}
