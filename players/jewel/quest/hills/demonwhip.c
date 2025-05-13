inherit "obj/weapon";

reset (arg) {
    ::reset();
    set_name("demonwhip");
    set_alt_name("whip");
    set_alias("whip of demons");
    set_class(19);
    set_weight(1);
    set_value(3000);
    set_short("Demonwhip");
    set_long("A mighty whip prefered by demons.\n");
    set_hit_func(this_object());
}

weapon_hit(ob) {
  if (random(100) < 25) {
     write("The whip cuts your opponent.\n");
     say("Demonwhip cuts "+ob->query_name()+".\n");
     return 20;
  }
  if (random(100) < 25) {
     tell_object(ob,"It burns like hell as the whip touches your skin!\n");
     ob->add_poison(25);
  }
  return 0;
}

weapon_class()
{
  if(environment() && 
     environment()->id("tana-ri")) return 100;
  return ::weapon_class();
}
