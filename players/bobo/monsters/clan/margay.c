inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("margay");
   set_level(7);
   set_wc(9);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("cat");
   set_short("Margay");
   set_long("The margay is a two foot long cat who lives in trees.  It is\n"+
             "very quick, and looks like a miniature jaguar with a long "+
            "tail.\n");
}
