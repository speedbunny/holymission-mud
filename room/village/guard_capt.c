inherit "obj/monster";

void reset(int arg) {
object ob1,ob2;
  ::reset(arg);
  if(arg) return;

  set_name("guard captain");
  set_alias("guard");
  set_alt_name("captain");
  set_short("The guard captain");
  set_long("This is the captain of the local guard.\n"
    + "He takes his job very serious, so don't mess with him.\n");
  set_level(7);
  set_gender(1);

  ob1 = clone_object("/obj/weapon");
  ob1->set_name("sword");
  ob1->set_short("A captain's sword");
  ob1->set_class(8);
  ob1->set_value(150);
  transfer(ob1,this_object());
  command("wield sword");

  ob2 = clone_object("/obj/armour");
  ob2->set_name("studded leather armour");
  ob2->set_alias("leather_armour");
  ob2->set_type("armour");
  ob2->set_short("Studded leather armour");
  ob2->set_ac(2);
  ob2->set_value(65);
  transfer(ob2,this_object());
  command("wear armour");
}
