
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("wolf");
    set_alias("black wolf");
    set_short("A big black wolf");
    set_long("He looks at you with glowing eyes.\n");
    set_race("animal");
    set_level(20);
   set_race("hellhound");
   set_hp(20000);
   set_wc(60);
    set_size(2);
    set_al(-100);
    set_aggressive(1);
  }
}
init() {
 call_out("dest",(40+random(800)));
 ::init();
 }
 dest() {
  tell_room(environment(),"Suddenly the wolf leaves.\n");
  destruct(this_object());
  return 1;
  }
