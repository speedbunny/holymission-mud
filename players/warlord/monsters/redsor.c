inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("sorceror");
  set_short("Red Sorceror");
  set_long("This man looks awfully busy. I wouldn't bother him!!!!\n");
  set_level(18);
  set_al(0);
  add_money(1200);
  return 1;
  }
