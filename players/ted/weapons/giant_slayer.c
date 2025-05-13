inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
     set_name("giant slayer");
     set_short("A Giant Slayer");
     set_alias("slayer");
     set_long("This fine blade is engraved with magic runes\n");
     set_class(15);
     set_weight(4);
     set_value(2500);
     set_hit_func(this_object());
}


weapon_hit(target) {
 if(target->id("giant")) {
  return 10;
 }
 return 0;
}
