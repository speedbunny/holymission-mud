inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("gibnut");
   set_level(4);
   set_wc(7);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("rodent");
   set_short("Gibnut");
   set_long("This is an extremely large rodent.  It is nearly four feet\n"+
            "long and has dark black lines of fur running down the length\n"+
            "of its body.  It also has a long snout.\n");
}
