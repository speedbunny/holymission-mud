inherit "/obj/weapon";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("black catsword");
  set_alias("catsword");
  set_alt_name("sword");
  set_short("Black catsword");
  set_long("This sword looks evil. The sword is gold and black and you "+
    "can make out a few runes imprinted in dried blood.\n");
  set_class(19);
  set_weight(5);
  set_value(30000);
  set_hit_func(this_object());
}
 
void init() {
  ::init();
  add_action("_read","read");
}
 
status _read(string str) {
  switch(str) {
    case "catsword" :
    case "runes" :
    case "sword" :
      write("You read, 'EVIL rules the earth!'.\n");
      return 1;
    default :
      notify_fail("Read what?\n");
      return 0;
  }
}
 
weapon_hit(attacker) {
  if(random(100) > 20)
    return 0;
  tell_room(environment(attacker), attacker->query_name()+" is hit by "+
            "a blast of pure evil!\n");
  return (1+random(5));
}
