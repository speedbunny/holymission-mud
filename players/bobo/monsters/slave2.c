inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("slave");
   set_level(2);
    set_wc(6);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Slave");
   set_long("This slave is taking advantage of the fact that his master is\n"+
            "doing other things to gorge himself on any scraps of food\n"+
            "that he can find.\n");
   add_money(10);
}

