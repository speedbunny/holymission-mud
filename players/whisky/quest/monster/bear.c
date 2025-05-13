inherit "/obj/monster";

  reset(arg) {
  ::reset(arg);
  if (!arg) {
 
   set_name("bear");
   set_level(24);
   set_size(4);
   set_alias("brown bear");
   set_short("A dangerous brown bear");
   set_long("It looks very strong.\n");
   set_spell_mess1("A bear hits you with it's claw");
   set_spell_mess2("A bear bits you");
   set_chance(20);
   set_aggressive(1);
   set_spell_dam(20);
}
}
 init() {
   call_out("dest",80);
   ::init();
  }
  dest() {
   tell_room(environment(),"Suddenly the bear leaves.\n");
   destruct(this_object());
   return 1;
  }
