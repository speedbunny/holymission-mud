inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("guard");
   set_level(4);
set_wc(7);
set_ac(1);
   set_al(20);
   set_gender(1);
   set_race("human");
   set_short("Guard");
   set_long("Standing before you is stadium guard.  He is  not as strong\n"+
            "as a gladiator but he is holding the animals at bay.\n");
   add_money(75);
}

