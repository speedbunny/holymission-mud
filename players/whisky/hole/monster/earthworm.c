inherit "/obj/monster";

 reset(arg) {
  ::reset(arg);
  if(arg) return 1;
  set_name("earthworm");
  set_alias("worm");
  set_short("A long earthworm");
  set_long("A long brown earthworm.\n");
  set_race("insect");
  set_level(1);
  set_size(1);
  set_al(10);
  set_hp(10);
  set_ep(50);
  set_ep(200);
  set_wc(1);
 return 1;
}
