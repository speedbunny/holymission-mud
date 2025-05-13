inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("bear");
   set_level(6);
   set_wc(8);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("bear");
   set_short("Bear");
   set_long("This is a giant brown bear.  It looks as though it hasn't been\n"+
            "fed in a long time and has gone insane.  It is wild and is\n"+
            "attacking everything that it sees.\n");
   set_aggressive(1);
}
