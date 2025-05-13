inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("slave");
   set_level(2);
   set_al(15);
   set_gender(1);
   set_race("human");
   set_short("Slave");
   set_long("This slave looks relatively well fed.  Instead of taking this\n"+
            "chance to escape to his freedom he is helping his master find\n"+
            "his little boy.\n");
   add_money(15);
}

