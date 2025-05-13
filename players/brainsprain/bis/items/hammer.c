inherit "obj/weapon";
void reset(int arg){
    ::reset();

    set_name("hammer");
    set_alias("hammer");
    set_short("Hammer");
    set_long(
"This small hammer has been well used as a forging implement.  The "+
"leather handle is colored black from sweat and the head of the hammer "+
"is dented and dinged from repeatedly hitting an anvil.  All and all this "+
"is a rather poor weapon.\n");
    set_class(19);
    set_weight(2);
    set_value(1500);
}
