inherit "obj/container";
object money;

reset(arg) {

  ::reset(arg);
  if (!arg) { 
     set_name("rucksack");
    set_alias("sack");
     set_read("What will a woodchuck do if a woodchuck chucks some wood.\n");
     set_max_weight(15);
     set_short("A rucksack");
     set_long("What will a woodchuck do if a woodchuck chucks some wood.\n");
     set_value(40);
     set_weight(1);
     transfer(clone_object("players/whisky/garden/obj/ring"),this_object());

  }
}
