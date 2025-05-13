inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("green iguana");
   set_alias("lizard");
   set_alt_name("iguana");
   set_level(7);
   set_wc(9);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("lizard");
   set_short("Green Iguana");
   set_long("The iguana is over seven feet lon and has a tough spiny green\n"+
            "hide.  Its massive tail and sharp claws are useful for defense\n");
}
