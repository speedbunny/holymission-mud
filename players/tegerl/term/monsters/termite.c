
 inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("termite");
  set_alias("hungry termite");
  set_short("A little hungry termite");
  set_long("A little hungry termite searching for some wood,\nthis evil thing surely will destroy all buildings!\n"); 
  set_level(1 + random(2));
  set_size(1);
  set_hp(8 + random(4));
  set_aggressive(0);
  set_al(-1000);
 }
}

