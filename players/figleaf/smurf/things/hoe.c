inherit "obj/weapon";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("hoe");
    set_short("Farmer smurf's hoe");
    set_long("A well-used hoe with a very sharp blade.\n");
    set_class(7);
    set_weight(1);
    set_value(48);
}

