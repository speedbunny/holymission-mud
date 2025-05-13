inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("guard");
    set_short("Guard");
    set_long("Generic monster for testing.\n");
    set_level(3);
    set_race("monster");
    set_gender(1);
}
