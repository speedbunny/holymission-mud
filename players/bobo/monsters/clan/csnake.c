inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("coral snake");
   set_alias("snake");
   set_level(14);
   set_wc(18);
   set_ac(5);
   set_al(0);
   set_gender(1);
   set_race("snake");
   set_short("Coral Snake");
   set_long("This little snake looks like a nice pet to have.  looks can\n"+
            "be decieving though because this three foot long snake is very\n"+
            "venomous and not something to be played with.\n");
}
