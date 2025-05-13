inherit "/obj/monster";

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

  set_name("Urk-barr, chieftain of the kobolds");
  set_race("kobold");
  set_alias_list(({ "urk-barr", "chieftain", "kobold chief",
    "Urk-barr", "Urkbarr", "urkbarr" }));
  set_alias("kobold");
  set_alt_name("chieftain");
  set_size(2);
  set_level(25);
  set_str(22 + random(5));
  set_dex(25 + random(5));
  set_con(20 + random(5));
  set_int(22 + random(5));
  set_wis(23 + random(5));
  set_chr(23 + random(5));
  set_short("Urk-barr, chieftain of the kobolds");
  set_long("This is Urk-barr, chieftain of the kobolds. This " +
    "fierce and mighty warrior looks as though he has " + 
    "experienced many a battle. He looks tough and " +
    "cruel, and smiles as you gaze upon him.\n");
  set_gender(1);
  set_al(-250);
  set_aggressive(1);
  add_money(5000 + random(2000));
  add_property("NO_FEAR", 40);
  add_property("NO_AWE", 40);
  add_property("NO_STEAL", 40);
}

int allowed_attack(object ob) {
  if(lower_case(ob->query_race()) == "kobold" && ob->query_npc())
    return 0;
  return 1;
}

