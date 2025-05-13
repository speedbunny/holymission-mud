inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("boa constrictor");
   set_alias("boa");
   set_alt_name("constrictor");
   set_level(10);
   set_wc(12);
   set_ac(3);
   set_al(-20);
   set_gender(1);
   set_race("snake");
   set_short("Boa Constrictor");
   set_long("This is a twelve foot long snake with a large opening for a\n"+
            "mouth and has large fangs.  It kills its prey by squeezing\n"+
            "it to death.\n");
}
