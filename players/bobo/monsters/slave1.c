inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("slave");
   set_level(2);
   set_wc(6);
   set_al(-50);
   set_gender(1);
   set_race("human");
   set_short("Slave");
   set_long("This slave is clothed in rags and is emaciated nearly beyond\n"+
            "comprehension.  He is very angry.\n");
   add_money(10);
   set_aggressive(1);
}
