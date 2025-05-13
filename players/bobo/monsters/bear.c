inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("bear");
   set_level(4);
   set_wc(7);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("bear");
   set_short("Bear");
   set_long("This is a massive bear.  It looks as though it has been in the\n"+
            "arena for a long time.  It has large clumps of fur torn away\n"+
            "from previous battles and dried blood coats most of the rest of"+
            "it's hide.\n");
}
