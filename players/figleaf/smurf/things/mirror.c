inherit "/obj/treasure";

void reset(int arg){

  ::reset(arg);
   if (arg)return;
    set_name("mirror");
    set_short("Vanity smurf's mirror");
    set_long("A small hand mirror with a pink wooden handle.\n");
    set_value(39);
    set_weight(1);
}
