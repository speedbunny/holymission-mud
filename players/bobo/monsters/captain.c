inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("captain");
   set_level(8);
   set_wc(10);
    set_ac(2);
   set_al(10);
   set_gender(1);
   set_race("human");
   set_short("Captain");
   set_long("This is the captain of the guards of the colliseum.  He is a\n"+
            "broad man who apears to be very adept in combat.  He is\n"+
            "standing surveying the environment around him.\n");
   add_money(200);
}

void init() {
   ::init();
   add_action("_northeast","northeast");
}

_northeast() {
   write("The captain says: What do you think you're doing you can't go "+
         "over there!\n");
return 1;
}
