inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("dog");
    set_short("Dog");
    set_long("Generic monster for testing.\n");
    set_level(3);
    set_race("monster");
    set_gender(1);
}
