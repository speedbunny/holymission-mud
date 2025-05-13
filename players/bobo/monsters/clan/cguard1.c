inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("observatory guard");
   set_alias("guard");
   set_level(10);
   set_wc(12);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Observatory Guard");
   set_long("This mayan is clad scantly for a guard.  He is wearing little\n"+
            "more than a tunic and some sandals.  He appears to be quite\n"+
            "young and as such is probably the least experienced of all of\n"+
            "the mayan guards.\n");
}
