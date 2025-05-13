inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("wild boar");
 set_alias("boar");
 set_race("pig");
 set_long("This is a huge wild pig. Its sharp tusks and thick hide help protect it.\n");
 set_level(8);
 set_hp(250);
 set_wc(10);
 set_ac(4);
}
