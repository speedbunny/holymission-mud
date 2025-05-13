
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("dolphin");
    set_short("A little dolphin");
    set_long("A cute little dolphin, splashing happily\n");
    set_race("animal");
    set_al(200);
    set_hp(120);
    set_level(6);
    set_has_gills();
}
