inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("misericorde");
    set_alias("dagger");
    set_alt_name("inscription");
    set_short("A beautiful misericorde");
    set_class(6);
    set_hit_func(this_object());
    set_long("This is a long thin dagger, which is very effective\n"
           + "against people wearing heavy armour. There is a orange\n"
           + "gem shining on it, and the blade is filled with a\n"
           + "rune-like inscription.\n");
    set_read("Belongs to the collection of Ianthe.\n");
    set_value(350);
    set_weight(1);
  }
}

weapon_hit(who) {
int amount;

  amount=(who->query_ac())/2;
  if(amount>14) amount=14;
  return amount;
}
