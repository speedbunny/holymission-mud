inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("owl");
     set_alias("big owl");
     set_short("A big owl");
     set_long("A big brown owl\n");
     set_race("bird");
     set_level(4);
     set_size(1);
     set_al(-100);
     set_aggressive(1);
  }
}
init() {
  call_out("dest",(40+random(800)));
  ::init();
  }
 dest() {
  tell_room(environment(),"Suddenly the owl leaves.\n");
  destruct(this_object());
  return 1;
  }
 
 
