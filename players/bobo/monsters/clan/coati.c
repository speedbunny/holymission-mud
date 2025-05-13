inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("coatis");
   set_level(12);
   set_wc(14);
   set_ac(14);
   set_al(0);
   set_gender(1);
   set_race("coati");
   set_short("Coatis");
   set_long("This is a large group of Coatis.  Singling one out you can\n"+
            "see that it looks similar to a large raccoon with a more\n"+
            "rounded race and a long tail.  There appears to be at least\n"+
            "two dozen coatis in this group.\n");
}
