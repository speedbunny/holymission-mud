inherit "obj/weapon";

object darth;

reset(arg) {

  ::reset(arg);
  if(arg) return;

  set_name("longsword");
  set_alias("sword");
  set_id("sword");
  set_alt_name("sword");
  set_short("sword.");
  set_long("This is an ordinary looking sword but you feel there\n"+
           "is something special about it.\n");
  set_class(15);
  set_weight(4);
  set_value(10000);
  set_hit_func(this_object());
  return;
}

int weapon_hit(object attacker) {

  int hphold;
      write("You cleave the meat from Darth's bones!\n");
      darth = attacker;
      hphold = darth->query_hp() - 10;
    attacker->hit_player(hphold, 0);
      attacker->set_ac(0);
      attacker->set_ac(0);
      wielded_by->stop_wielding();
      destruct(this_object());
      return 10000;
    }

