inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("sloth");
   set_level(9);
   set_wc(11);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("sloth");
   set_short("Sloth");
   set_long("The sloth is a big animal with thick brown fur.  It is very\n"+
            "slow but the large hooklike claws attatched to each of its\n"+
            "feet make it a formidable opponent.\n");
}
