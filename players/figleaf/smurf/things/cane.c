inherit "obj/weapon";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("cane");
    set_short("Papa smurf's cane");
    set_long("A small but surprisingly sturdy walking cane.\n");
    set_class(5);
    set_weight(1);
    set_value(47);
}

