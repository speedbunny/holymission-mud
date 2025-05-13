inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("crocodile");
   set_level(15);
   set_wc(20);
   set_ac(6);
   set_al(-25);
   set_gender(1);
   set_race("reptile");
   set_short("Crocodile");
   set_long("This crocodile is huge, and measures over fourteen feet long.\n"+
            "His long snout tapers to a rounded edge at the end and his\n"+
            "back has two rows of spines running down it.\n");
}
