inherit "obj/weapon";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("dumbbell");
    set_short("Hefty smurf's dumbbell");
    set_long("A large dumbbell with about 20 pounds on it.\n");
    set_class(7);
    set_weight(2);
    set_value(76);
}

