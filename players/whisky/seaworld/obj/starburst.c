inherit "/obj/weapon";

void reset(int arg) {

  if (arg) return;
  set_id("burst");
  set_alias("starburst");
  set_short("The little Starburst");
  set_long("The little sister of the mighty Starburst.\n");
  set_type(2);
  set_light(1);
  set_hit_func(this_object());
  set_weight(1);
  set_value(2000);
}

int weapon_hit(object attacker) {

  write(
        "****************************************************\n"+
        "As you shoot the red star it burns " + attacker->query_name() +
        " badly.\n"+
        "The green star blinds " + attacker->query_name() + " for a moment.\n"+
        "And the blue star hits " + attacker->query_name() +
        " so hard it cries..\n"+
        "*****************************************************\n");

  say(capitalize(this_player()->query_real_name())+
      " throws the little Starburst against "+
      attacker->query_name()+".\n");
  return random(30);
}
