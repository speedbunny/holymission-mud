inherit "obj/weapon";

void reset(int arg){

  ::reset(arg);
  if (arg)return;
    set_name("crutch");
    set_short("Clumsy smurf's crutch");
    set_long("A slightly used wooden crutch with a metal cap on the bottom.\n");
    set_class(6);
    set_weight(1);
    set_value(53);
}

