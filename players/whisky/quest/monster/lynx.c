inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("lynx");
     set_alias("big lynx");
     set_short("A big lynx");
     set_long("It's stares at you with glowing eyes. It looks very stong and\ndangerous.\n");
     set_spell_mess1("The Lynx spits: CHHHHHHHH !!!");
     set_spell_mess2("The Lynx spits: CHHHHHHHH !!!");
     set_chance(12);
     set_race("cat");
     set_level(16);
     set_size(2);
     set_al(-400);
     set_wc(8);
     set_ac(2);
     set_aggressive(1);
  }
}
init() {
  call_out("dest",(40+random(800)));
  ::init();
  }
 dest(){
  tell_room(environment(),"Suddenly the lynx leaves.\n");
  destruct(this_object());
  return 1;
  }
 
 
