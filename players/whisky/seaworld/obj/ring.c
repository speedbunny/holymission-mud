inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
 if(arg) return;
    set_name("ring");
    set_alias("platinum ring");
    set_short("A platinum ring");
    set_long("A little platinum ring.\n");
    set_ac(1);
    set_size(2);
    set_type("ring"); 
    set_value(300);
    set_weight(1);
}
