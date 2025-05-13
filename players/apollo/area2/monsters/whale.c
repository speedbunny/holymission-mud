

inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if (arg) return;

     set_name("whale");
     set_alias("animal");
     set_race("animal");
     set_short("A big whale");
     set_long("You see a big whale waiting for some ships to come.\n"+
              "It looks harmless, but very powerful.\n"); 
     set_level(28);
     set_has_gills();
     set_size(5);
     set_al(-250);
     set_wc(20);
     set_ac(5);
    add_money(500);

}

monster_died(ob) {
  this_player()->add_exp(-1);
  return 0;
}
