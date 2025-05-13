inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("vendor");
   set_level(4);
   set_wc(7);
   set_ac(1);
   set_al(25);
   set_gender(1);
   set_race("human");
   set_short("Vendor");
   set_long("This is the vendor that sells things in the stands of the\n"+
            "coliseum.  He is out of supplies so he's going home to get more.\n");
   add_money(75);
}
