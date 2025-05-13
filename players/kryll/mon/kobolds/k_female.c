inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Female");
  set_race("kobold");
  set_alias_list(({ "female", "kobold female", "Kobold female" }));
  set_size(2);
  set_level(7);
  set_wc(5);
  set_short("Kobold Female");
  set_long("This is a cowardly, sadistic humanoid that is " +
    "3 feet tall with scaly dark brown hide. With " + 
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat. However, these "+
    "females are very protective of their young.\n");
  set_gender(2);
  set_hp(110 + random(20));
  set_al(-80);
  add_money(10 + random(30));
}
