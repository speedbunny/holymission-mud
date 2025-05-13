inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Male");
  set_race("kobold");
  set_alias_list(({ "male", "kobold male", "Kobold male" }));
  set_aggressive(1);
  set_size(2);
  set_level(9);
  set_short("Kobold Male");
  set_long("This is a cowardly, sadistic humanoid that is " +
    "3 feet tall with scaly dark brown hide. With " + 
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat.\n");
  set_gender(1);
  set_al(-100);
  add_money(random(30));
}
