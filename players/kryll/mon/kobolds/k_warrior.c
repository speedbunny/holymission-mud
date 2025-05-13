inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Warrior");
  set_level(16);
  set_alias_list(({ "warrior", "kobold warrior", "Kobold warrior" }));
  set_short("Kobold Warriorr");
  set_race("kobold");
  set_size(2);
  set_al(-110);
  if(!random(3))
    set_gender(2);
  else
    set_gender(1);
  set_long("This is a cowardly, sadistic humanoid that is "+
    "3 feet tall with scaly dark brown hide. With "+
    "their rat-like tail and raggedy garb, they "+
    "don't look like much of a threat.\n");
  add_money(50 + random(30));
  set_aggressive(1);
}
