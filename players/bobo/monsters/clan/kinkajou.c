inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("kinkajou");
   set_level(5);
   set_wc(7);
   set_ac(1);
   set_al(25);
   set_gender(1);
   set_short("Kinkajou");
   set_long("This animal is small, agile, and fast.  It is two feet long\n"+
            "and has a loving, soulful look on its face.\n");
}
