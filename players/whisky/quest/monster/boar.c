
inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("boar");
    set_alias("wild boar");
    set_short("A boar");
    set_long("An brown wild boar.\n");
    set_race("boar");
    set_level(12);
    set_size(2);
    set_al(-100);
    set_aggressive(1);
  }
}
 init() {
  call_out("dest",400);
  ::init();
  }
  dest() {
   tell_room(environment(),"Suddenly the boar leaves.\n");
   destruct(this_object());
   return 1;
  }
