inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("elite guard");
   set_alias("guard");
   set_level(30);
   set_wc(40);
   set_ac(21);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Elite Guard");
   set_long("This guard looks like he could kill the average person without\n"+
            "breaking a sweat.  His thick hard body is well trained and\n"+
            "meticulously maintained.\n");
}
