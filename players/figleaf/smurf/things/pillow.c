inherit "/obj/treasure";

void reset(int arg){

  ::reset(arg);
   if (arg)return;
    set_name("pillow");
    set_short("Lazy smurf's pillow");
    set_long("A big, soft pillow. It looks really comfy.\n");
    set_value(22);
    set_weight(1);
}
