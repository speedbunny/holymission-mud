inherit "obj/weapon";

int dr;

reset (arg) {
    ::reset();
    set_name("flaming Sword (left hand)");
    set_alt_name("sword");
    set_class(30);
    set_weight(1);
    set_value(1);
    set_short("Flaming Sword (left hand)");
    set_long("A mighty sword prefered by demons.\n");
    set_hit_func(this_object());
    dr=0;
}

weapon_hit(ob) {
  if (random(100) < 50) {
     write("The sword burns your oponent.\n");
     tell_object(ob,
        "The flaming sword engulfs you with incredible heat!! ARGHH \n");
     return 100;
  }
  return 0;
}

drop()
{
   if(dr) return 1;
   dr=1;
   write("The flaming sword disappears as it is separated from the Balor.\n");
   say("The flaming sword disappears as it is separated from the Balor.\n");
   return 1;
}

weapon_class()
{
   if(environment() &&
      environment()->id("tana-ri")) return 100;
   return ::weapon_class();
}
