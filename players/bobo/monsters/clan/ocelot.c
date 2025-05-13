inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("ocelot");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("cat");
   set_short("Ocelot");
   set_long("This beautiful cat is three feet long and is yellow with spots.\n"+
            "It's long agile legs and it's sharp claws make it an excellent\n"+
            "predator.\n");
}
