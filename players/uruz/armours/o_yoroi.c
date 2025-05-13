inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("armor");
   set_name("o-yoroi");
   set_alias("oyoroi");
   set_ac(6);
   set_short("A set of O-Yoroi armor");
   set_long("The O-Yoroi is a matched set of Do-Maru, Mempo (face mask),\n"+
      "nodawa(neck guard), wakibiki(armpit guards), Sendan-No-Ita, and\n"+
      "hato-wo-no-ita(both guards for the front of the armpits)\n");
   set_value(5000);
   set_weight(8);
   return 1;
}


