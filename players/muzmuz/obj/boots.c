inherit "obj/armour";

reset(arg) {
  ::reset();
    if(arg) return;

     set_name ("boots");
     set_alias ("boots");
     set_short ("brown boots");
     set_long ("A pair of brown leather boots.\n");
     set_type ("boots");
     set_size(3);
     set_weight(1);
     set_ac(1);
     set_value(200);

return 1;

}
