inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("owl");
     set_alias("aggressive owl");
     set_short("An aggressive owl");
     set_long("A big brown owl\n");
     set_race("bird");
     set_level(2);
     set_size(1);
     set_al(-100);
     set_aggressive(1);
  }
}
 
 
