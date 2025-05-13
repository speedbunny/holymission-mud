inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("boy");
   set_alias("child");
   set_level(1);
   set_wc(5);
   set_ac(0);
   set_al(100);
   set_gender(1);
   set_race("human");
   set_short("Boy");
   set_long("This little boy is wandering about playing in the refuse.\n"+
            "He has a dirty little grin plastered on his face.\n");
   add_money(10);
}

