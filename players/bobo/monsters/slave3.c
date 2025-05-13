inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("slave");
   set_level(1);
   set_wc(5);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Slave");
   set_long("The slave is a wreck and looks as though he's been beaten badly\n"+
            "recently.  He is taking this chance to flee his master.\n");
   add_money(10);
}

