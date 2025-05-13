
inherit "obj/weapon";

  reset(arg) {
   ::reset(arg);
 if (arg) return;

  set_name("dragontail");
  set_alias("tail");
  set_class(20);
  set_weight(5);
  set_value(2000);
  set_short("A Dragontail");
  set_long(
  "You see the wonderful, wet, stiff tail of a big dragon.\n"+
  "It looks round at its one end and good to hold on the other end.\n"+
  "It looks somehow tasty, but now eatable at all **lick**\n");
  set_hit_func(this_object());
}
weapon_hit(ob) {
  if (ob->query_race() == "dragon") {
     write("You lead the dragon by it's tail.\n");
     say(this_player()->query_name()+" leads the dragon by it's tail.\n");
  return (50 + random(40));

  }
}

