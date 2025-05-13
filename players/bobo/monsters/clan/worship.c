inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("worshipper");
   set_level(13);
   set_wc(16);
   set_ac(5);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Worshipper");
   set_long("This is a worshipper of the sun.  They are not of high enough\n"+
            "ranking to go see the high priest so they come here to listen\n"+
            "to the astonomer and his teachings.\n");
}
