inherit "obj/treasure";

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name("soul");
    set_alias("knight soul");
    set_short("Knight soul");
    set_long("The knight soul giving you control over your knight.\n");
    set_weight(0);
    set_value(1);
}
init(){
    ::init();
    add_action("dismiss", "dismiss");
}
drop(){
    write("You cannot release your knight this way.\n");
    return 1;
}
dismiss(){
    write("Your knight soul disappears in a puff of smoke.\n");
    destruct(this_object());
    return 1;
}
