inherit "/obj/monster";

int attack(object ob, int val) {
  int ret;

  if(ret = ::attack(ob, val)) {
    if(random(50) < query_dex())
      ret = ::attack(ob, val);
    if(random(100) < query_dex())
      ret = ::attack(ob, val);
  }
  return ret;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Fighter");
  set_level(20);
  set_short("Kobold Fighter");
  set_race("kobold");
  set_alias_list(({ "fighter", "kobold fighter", "Kobold fighter" }));
  set_size(2);
  set_al(-120);
  set_dex(25 + random(5));
  set_str(18);
  set_con(18);
  set_int(20);
  set_wis(20);
  set_chr(15);
  if(!random(3))
    set_gender(2);
  else
    set_gender(1);
  set_long("This is a cowardly, sadistic humanoid that is " +
    "3 feet tall with scaly dark brown hide. With " +
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat. Unlike most other "+
    "kobolds, this one looks skilled with his weapon.\n");
  set_aggressive(1);
  set_move_at_reset();
  add_money(1000 + random(401));
}

int allowed_attack(object ob) {
  if(lower_case(ob->query_race()) == "kobold" && ob->query_npc())
    return 0;
  return 1;
}

