inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

    set_name("baby drake");
    set_alt_name("drake");
  set_alias("baby drake");
  set_level(4);
  set_short("A baby drake");
  set_long("A cute little baby drake.\n");
  set_gender(1+random(2));
  set_race("drake");
  set_aggressive(1);
 set_al(-10);

return 1;
  }
