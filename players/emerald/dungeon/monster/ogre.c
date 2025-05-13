inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("ogre");
    set_race("ogre");
    set_long("Not terribly handsome, as ogres go.\n");
    set_level(50);
    set_al(-400);
    set_ac(18);
    set_wc(15);
    add_money(324);
    set_aggressive(1);
}
