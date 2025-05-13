inherit "obj/armour";
#include "/obj/lw.h";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("outfit");
    set_short("A wedding outfit");
    set_long(lw("This is a weddingoutfit, consisting of a purple jacket, black "
              + "pants and a yellow shirt.\n"));
    set_ac(1);
    set_type("armour");
    set_value(750);
    set_weight(1);
    set_info(lw("This was worn by Ethereal Cashimor when he married."));
  }
}

extra_look() {
  if(!worn) return;
  return lw(capitalize(worn_by->query_pronoun())+" is wearing a yellow shirt, "
          + "with intricate designs on it, which are even more eluding because "
          + "of a purple jacket that is worn over it. Black pants complete the "
          + "outfit");
}


