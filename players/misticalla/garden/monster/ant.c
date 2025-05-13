inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("ant");
  set_alias("forest ant");
  set_short("A little forest ant");
  set_long("A little ant crawling up and down the tree searching for some food\n");
  set_level(1);
  set_size(1);
  set_hp(8);
  set_aggressive(0);
 }
}
