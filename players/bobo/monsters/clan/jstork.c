inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("jabiru stork");
   set_alias("stork");
   set_level(8);
   set_wc(10);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("bird");
   set_short("Jabiru Stork");
   set_long("This massive bird stands almost five feet tall and has a wing\n"+
            "span of eight feet.  It is white with a black head.  It has a\n"+
            "long bill for catching fish and other small animals.\n");
}
