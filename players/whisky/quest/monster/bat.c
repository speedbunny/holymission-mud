
inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("bat");
    set_short("A big bat bat");
    set_long("An big bat flying around your head.\n");
    set_race("bat");
    set_level(1);
    set_size(1);
    set_al(-10);
    set_aggressive(1);
  }
}

 init() {
  call_out("dest",(40+random(800)));
  ::init();
  }
  dest() {
   tell_room(environment(),"Suddenly the bat leaves.\n");
   destruct(this_object());
   return 1;
   }
