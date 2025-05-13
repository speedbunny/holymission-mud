inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling caregiver");
   set_alias("caregiver");
   set_alt_name("nanny");
   set_level(7);
   set_wc(9);
   set_ac(2);
   set_al(20);
   set_gender(2);
   set_race("halfling");
   set_short("Caregiver");
   set_long("This halfling woman serves as nanny for all of the children in\n"+
            "the warren that aren't being taken care of in their own homes.\n"+
            "She is big and looks stern.\n");
   add_money(75);
}
