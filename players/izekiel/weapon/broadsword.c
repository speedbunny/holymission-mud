
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("broadsword");
  set_alias("sword");
  set_class(11);
  set_value(400);
  set_weight(2);
  set_two_handed();
  set_short("Broadsword");
  set_long(
   "A broadsword made of bronze, which glistens as you hold it in the light.\n"+
   "The various nicks in it's edge tell you that it has killed many an\n"+
  "adventurer. Care must be taken in wielding this massive sword.\n");
}
