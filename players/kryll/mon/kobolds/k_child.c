inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Kobold Child");
  set_level(3);
  set_hp(70 + random(20));
  set_alias_list(({ "child", "kobold child", "Kobold child" }));
  set_short("Kobold Child");
  set_race("kobold");
  set_size(2);
  set_al(-50);
  if(!random(2))
    set_gender(2);
  else
    set_gender(1);
  set_long("This is a cowardly, sadistic humanoid that is " +
    "2 feet tall with scaly dark brown hide. With " +
    "their rat-like tail and raggedy garb, they " +
    "don't look like much of a threat, especially as "+
    "a child.\n");
  set_wimpy(10);
}

int allowed_attack(object ob) {
  if(lower_case(ob->query_race()) == "kobold" && !ob->query_player())
    return 0;
  return 1;
}

int attack(object ob, int val) {
  object *all;
  int    i, sz, ret;

  if(ret = ::attack(ob, val)) {
    all = all_inventory(environment(this_object()));
    for(i=0, sz=sizeof(all); i<sz; i++) {
      if(all[i]->query_living() && all[i]->id("kobold") &&
         all[i]->query_npc()) {
        all[i]->attack_object(attacker_ob);
        attacker_ob->change_attacker(all[i]);
      }
    }
  }
  return ret;
}
