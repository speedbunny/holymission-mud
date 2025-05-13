/* 062395 Colossus: Check for no_fight done */
inherit "obj/weapon";

int charges;

reset(arg) {
    if(arg) return;
    set_name("poison dagger");
    set_alias("dagger");
    set_short("A poison dagger");
    set_class(11);
    set_hit_func(this_object());
    set_type(2);
    charges=8;
}

long(str) {
  write("A poison dagger. ");
  switch(charges) {
  case 0:
    write("It looks as if there is no poison on it.\n");
    break;
  case 1..3:
    write("It looks as if there is some poison left on it.\n");
    break;
  case 4..6:
    write("It looks pretty well smeared with poison.\n");
    break;
  default:
    write("It looks a superb weapon, but only if you're a thief!\n");
    break;
  }
}

query_value() { return 500 + charges * 3; }

weapon_hit(ob) {
  if(!charges || random(4) || wielded_by->query_guild()!=1) return;
  if(environment(ob)->query_property("no_fight")){
    write("You cannot use the weapon's ability here.\n");
    return 0;
  }
  charges--;
  write("You sneak past " + ob->query_name() + "'s defences and stab him with the dagger!\n");
  ob->add_poison(5);
  return 50+random(charges*15);
}
