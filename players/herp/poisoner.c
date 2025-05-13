inherit "obj/weapon";
#define WOUND 15
#define MSG "The sword bites into "+ vic->query_name()+"'s body and poisons him!\n"

  reset(arg) {
   ::reset(arg);
 if (arg) return;

  set_name("wounder");
  set_class(12);
  set_weight(5);
  set_value(10000);
  set_alias("sword","poisoning","sword of poisoning");
  set_short("Sword of Poisoning");
  set_long("This legendary sword has the power of making your enemies\npoisoned long after the battle is over!!\n");
  set_hit_func(this_object());
}
weapon_hit(vic) {
  tell_room(environment(this_player()),MSG);
  tell_object(vic,"You are poisoned!!\n");
  vic->add_poison(WOUND);
}
