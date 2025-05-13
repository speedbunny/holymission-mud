inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("high guard");
   set_alias("guard");
   set_level(25);
   set_wc(35);
   set_ac(16);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("High Guard");
   set_long("The guard in front of you looks powerful and agile.  He knows\n"+
            "everything that goes on around him and has come through many\n"+
            "battles unscathed.  Only powerful warriors dare challenge him\n");
}
