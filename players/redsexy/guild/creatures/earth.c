inherit "players/redsexy/guild/creatures/attacker";

#include "/players/redsexy/guild/crdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
}

setup() {
  set_name("Earth Element");
  set_short(master->SNAME + "'s Earth Element");
  set_long("It towers over you, a solid mass of pure stone and earth.\n");
  set_alias("earth");
  set_race("element");
  set_level(14);
  set_ac(15);
  set_wc(15);
  set_hp(420 + random(60));
  set_ep(0);
  set_chance(15);
  set_spell_mess1("Earth Element roars and brings down an avalanche!");
  set_spell_mess2("Earth Element hurls an avalanche down upon you!");
  set_spell_dam(30);
  load_a_chat(50, ({
    "Earth Element swings its huge fist.\n",
    "Earth Element beats down mercilessly.\n",
    "Earth Element stomps its feet and causes an earthquake!\n"
  }));
  motion = "steps with an echoing boom";
  bansp = 30;
  reqlevel = 14;
  msg = "Te arcesso de terrae elemento ut facies muem iussum";
  ter = 0;
  return 1;
}
