inherit "/obj/monster";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  load_chat(12,({
    "Dagobert looks around.\n",
    "Dagobert sharps his claws.\n",
    "Dagobert sends a bright spark to heaven.\n",
    "Dagobert looks confused at you.\n",
    "Dagobert leaves south.\n",
    "Dagobert struts proudly.\n",
    "Dagobert finds a herb and eats it.\n",
    "Dagobert tries to go west but fails.\n",
    "Dagobert leaves down.\n",
    "Dagobert tries to go through the field but fails.\n",
  }));
 
  load_a_chat(40,({
    "Dagobert throws a ball of fire at you !\n",
    "Dagobert gazed you with its claw.\n",
    "Dagobert hits you with it's tail !\n",
    "Dagobert leaves down\n",
    "Dagobert leaves west\n",
    "Dagobert leaves east\n",
    "Dagobert leaves up.\n",
    "Dagobert flames you to ashes !\n",
    "Dagobert massacres you to hash .\n",
    "Dagobert tries to hit you with it's claw but fails !\n",
    "Dagobert tries to hit you with it's tail but fails !\n",
    "Dagobert tries to flame you, but fails !\n",
    "Dagobert tries to go through the field but fails !\n",
  }));
 
  set_name("dagobert");
  set_alias("dragon");
  set_alt_name("sea dragon");
  set_short("Dagobert, the sea dragon");
  set_long("A 50 foot tall, friendly-looking sea dragon. "+
    "He seems like he is searching for someone to play.\n");
  set_level(35);
//  set_has_gills(); NO LONGER VALID, use next line instead
  set_own_env("water");
  set_hp(1800);
  set_wc(35);
  set_spell_mess1("Dagobert throws a ball of fire !");
  set_spell_mess2("Dagobert throws a ball of fire at you !");
  set_spell_dam(80+random(40));
  set_chance(8);
  set_gender(1);
  set_whimpy();
  set_al(-100);
}
 
int catch_tell(string str) {
  string who, where;
 
  if(sscanf(str, "%s leaves %s.\n", who, where) == 2) {
    call_out("next_move", 1, where);
    return 1;
  }
  return 0;
}
 
void next_move(string str) {
  switch(str) {
    case "north" :
    case "south" :
    case "east" :
    case "west" :
    case "northeast" :
    case "northwest" :
    case "southeast" :
    case "southwest" :
    case "down" :
    case "up" :
      command(str, this_object());
      return;
  }
}
