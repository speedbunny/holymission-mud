inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Guard");
  set_level(15);
  set_short("Kobold Guard");
  set_race("kobold");
  set_alias_list(({ "guard", "kobold guard", "Kobold guard" }));
  set_size(2);
  set_al(-125);
  if(!random(3))
    set_gender(2);
  else
    set_gender(1);
  set_long("This is a cowardly, sadistic humanoid that is " +
    "3 feet tall with scaly dark brown hide. With " +
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat. This one is "+
    "a protector of its race.\n");
  add_money(100 + random(30));
}
