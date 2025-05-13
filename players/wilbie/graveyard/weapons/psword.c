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
  set_weight(2);
  set_value(1000);
  set_hit_func(this_object());
}

// Mangla: Placed this is as an example.
//     The code you had called a non-existant function
//      This one will look for demon and maybe insta-kill
//      or just do extra damage, if the opponent is evil
//      then does some extra damage
//      else does no extra damage.
int weapon_hit(object attacker) {

  if(attacker->query_race() == "demon") {
    if(!random(5)) {
      write("FiendsBane flashes with holy vengence!!\n" +
            "The blade slices cleanly through the demons flesh!\n");
      return attacker->query_hp() - 1;
    }
    else {
      write("FiendsBane Flashes with holy vengence!!\n");
      return 10;
    }
  }
  else if(attacker->query_alignment() < -500) {
    write("FiendsBane glows as you strike!\n");
    return 5;
  }
  return 0;
}

/*
weapon_hit(attacker) {
   if(attacker->query_race() == "demon") {
   if(random(40)) {
 write("FiendsBane flashes with holy vengeance!!\n"+
       "The blade slices cleanly through the demon's flesh!\n");
  return 10;
    }
}
    else {
  fiend=attacker;
    call_out("dest",1,0);
    return 0;
    }


 }
*/
