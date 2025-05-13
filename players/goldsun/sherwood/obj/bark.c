inherit "obj/armour";
reset(arg){
 ::reset(arg);

if (!arg){
 set_name("Tree bark");
 set_alias("bark");
 set_short("A tree  bark");
 set_long("This is bark from the magic tree.\n"
          +"The tree lives in the Sherwood.\n");
 set_type("armour");
 set_size(4);
 set_ac(4);
 set_value(4000);
 set_weight(4);
 }
} 
