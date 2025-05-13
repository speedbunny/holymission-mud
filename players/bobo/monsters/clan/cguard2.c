inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("cenote guard");
   set_alias("guard");
   set_level(15);
   set_wc(20);
   set_ac(6);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Cenote Guard");
   set_long("This young guard looks as though he is not very well equiped\n"+
            "for battle.  He does look fleet footed and agile however.\n");
}
