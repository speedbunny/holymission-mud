
inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bat");
    set_short("A vampire bat");
    set_alias("vampire bat");
    set_long("An vampire bat flying around your head.\n");
    set_race("bat");
    set_level(1);
    set_wc(6);
    set_whimpy(50);
    set_size(1);
    set_al(-10);
  }
}
 init() {
   if (set_light(0) > 0 && !this_player()->query_immortal()) {
      tell_room(environment(),"The bat gets angry !!!\n");
      attack_object(this_player());
     }
   ::init();
   }

