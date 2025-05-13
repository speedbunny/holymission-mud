inherit "obj/monster";
#define TP this_player()
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling guard");
   set_alias("guard");
   set_level(10);
   set_wc(12);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("halfling");
   set_short("Guard");
   set_long("The little halfling guard seems to be resolute in his duty.\n"+
           "He is standing unmoving at his post.\n");
   add_money(100);
}

