inherit "obj/monster";
reset(arg) {
  ::reset(arg);
   if(arg) return 1;
   
    set_name ("man");
    set_race ("human");
    set_alias ("man");
    set_short ("man");
    set_long ("HP man");
    set_level (100);
     set_hp(3000);
   /* 1 hp is assinine and kinda dumb  */
    set_al (-100000);

return 1; }
