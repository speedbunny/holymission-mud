inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;

    set_name("baby nordel");
    set_alt_name("baby");
  set_alias("baby nordel");
  set_level(1000);
  set_short("A baby nordel");
  set_long("A small, blood-thirsty nordel.\n");
  set_gender(1+random(2));
  set_race("nordel");
  set_aggressive(1);
  set_ac(1);
 set_al(-10000);
  set_wc(1);
  set_hp(1);
  add_money(1000000);

return 1;
  }
