inherit "obj/armour";
reset(arg){
     ::reset(arg);
     if (arg) return;
     set_name("Wizard helmet");
     set_ac(1);
     set_weight(0);
     set_value(0);
     set_alias("helmet");
     set_type("helmet");
     set_short("Wizards helmet");
     set_long("a metal helmet\n");
}
init(){
     ::init();
}
