inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    if(arg) return 1;
     set_name ("mouse");
     set_alias ("mouse");
     set_race ("rodant");
     set_short ("A tiny mouse");
     set_long ("A tiny white mouse, it is searching for food.\n");
     set_level(1);
     set_hp (1000000);

return 1;

}
