inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
     set_name("dragon slayer");
     set_short("A Dragon Slayer");
     set_alias("slayer");
     set_long("This fine blade is engraved with magic runes and two words\n"+
              "\tDraconis Executis\n");
    set_class(14);
     set_weight(4);
     set_value(4500);
     set_hit_func(this_object());
}


weapon_hit(target) {
 if(target->id("dragon")) {
   return 10;
 }
 return 5;
}
