inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("kobold child");
   set_level(1);
   set_hp(25);
   set_ep(25);
   set_al(-50);
   set_alias("kobold");
   set_alt_name("child");
   set_gender(1);
   set_race("kobold");
   set_short("A kobold child");
   set_long("A 'innocent' little kobold child\n");
   set_wc(0);
   set_ac(0);
   set_aggressive(0);
   set_size(2);
    set_chat("Yip, yip\n");
   return;

}
