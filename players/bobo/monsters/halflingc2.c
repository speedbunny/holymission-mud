inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling child");
   set_alias("child");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(50);
   set_race("halfling");
   set_short("Child");
   set_long("This little child seems to be cleaner than most of the others\n"+
            "in the warren.  It is happy playing by itself in the corner.\n");
   add_money(10);
}

