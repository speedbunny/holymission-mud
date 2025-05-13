inherit "obj/weapon";

object fiend;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("longsword");

  set_id("sword");
  set_alt_name("sword");
  set_short("A Paladin's Longsword");
  set_long("This finely crafted sword has the symbol of Illumitar "+
           "engraved into the hilt.  It bears the name 'FiendsBane'.\n");
  set_read("You cannot decipher the runes, but they look to be runes of power.\n");
  set_class(10);
  set_weight(4);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
   if(attacker->query_race() == "demon") {
 write("The Paladin Sword flashes with holy vengance!!\n");
  return 10;
    }
    else {
  fiend=attacker;
    call_out("dest",1,0);
    return 0;
    }


 }
