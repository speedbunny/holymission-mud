inherit "obj/armour";

reset(arg) {
  ::reset();
    if (arg) return;

     set_name ("helm");
     set_alias("helm");
     set_short("horn helm");
     set_long("A horn helm, it looks wealthy and good for protection.\n");
     set_type("helmet");
     set_size(3);
     set_weight(1);
     set_ac(1);
     set_value(300);


return 1;

}
