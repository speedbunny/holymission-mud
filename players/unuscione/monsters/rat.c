inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("rat");
   set_level(1);
   set_hp(15);
   set_ep(25);
   set_al(0);
   set_gender(1);
   set_race("rat");
   set_short("A disgusting rat");
   set_long("A little rat that is the pet of a kender\n");
   set_wc(0);
   set_ac(0);
   set_aggressive(0);
   set_size(1);
   load_chat(10, ({"squeeek\n","The rat scurries around.\n"}));
   return;
}
