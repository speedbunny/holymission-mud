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
   set_long("The halfling child in front of you is strangely silent.  He\n"+
            "seems to be just sitting on the floor not doing much.\n");
   add_money(10);
}

