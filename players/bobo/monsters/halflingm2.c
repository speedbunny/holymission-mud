inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling man");
   set_alias("man");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("halfling");
   set_short("Man");
   set_long("The halfling man is hunched over a worktable tinking with\n"+
            "something or another, he doesn't even notice you.\n");
   add_money(80);
}
