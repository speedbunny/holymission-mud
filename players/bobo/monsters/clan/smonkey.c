inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("spider monkey");
   set_alias("monkey");
   set_level(7);
   set_wc(9);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("monkey");
   set_short("Spider Monkey");
   set_long("This monkey is gray in color and has long legs.  It uses its\n"+
            "prehensile tail for many things and oddly doesn't have an\n"+
            "opposable thumb.\n");
}
