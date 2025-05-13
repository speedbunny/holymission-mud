inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("general guard");
   set_alias("guard");
   set_level(20);
   set_wc(30);
   set_ac(11);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("General Guard");
   set_long("This man is well built and looks as if he knows his trade.\n"+
            "The guard is calm in his position and looks light on his feet\n"+
            "from hours of training.\n");
}
