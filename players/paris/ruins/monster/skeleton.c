#pragma strict-types
inherit "/obj/monster";

void reset(int arg) {
  object o;

  ::reset(arg);
  if (arg)
    return;
  set_race("undead");
  set_name("skeleton");
  set_level(35);
  set_ac(10);
  set_wc(20);
  /*
   * Time for some old equipment
   */
  o = clone_object("/obj/armour");
  o->set_name("shield");
  o->set_short("an old battered shield");
  o->set_size(3);
  o->set_ac(4);
  o->set_type("shield");
  transfer(o, this_object());
  init_command("wear shield");
  o = clone_object("/obj/weapon");
  switch(random(4)) {
  case 0:
    o->set_name("sword");
    o->set_type("sword");
    o->set_short("a long rusty falchion");
    break;
  case 1:
    o->set_name("short sword");
    o->set_type("sword");
    o->set_short("a long battered dagger");
    break;
  case 2:
    o->set_name("bastard sword");
    o->set_type("sword");
    o->set_short("a chipped and rusted bastard sword");
    break;
  case 3:
    o->set_name("spear");
    o->set_type("spear");
    o->set_short("an old, slightly bent spear");
    break;
  }
  o->set_class(7);
  o->set_weight(4);
  transfer(o, this_object());
  init_command("wield "+o->query_name());
}
    
