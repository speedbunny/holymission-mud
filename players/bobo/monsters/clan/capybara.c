inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("capybara");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("rodent");
   set_short("Capybara");
   set_long("This is an extremely large rodent.  It is nearly four feet\n"+
            "long.  It is surprisingly agile and powerful.\n");
}
