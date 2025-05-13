inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("king vulture");
   set_alias("vulture");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(-20);
   set_gender(1);
   set_race("bird");
   set_short("King Vulture");
   set_long("This vulture is nearly three feet tall and is white except\n"+
            "for its head and the tips of its wings.  It has a powerful\n"+
            "beak, designed to rip flesh from animals.\n.");
}
