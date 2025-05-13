inherit "obj/treasure";
reset(arg) {
    if (arg) return 1;
set_name("soul giver");
    set_short("Soul giver");
    set_long("Just type soul and you shall have one.\n");
}
init() {
    add_action("soul","soul");
    ::init();
}
soul( string str) {
object ob;
ob=find_player(str);
move_object("/obj/rsoul",ob);
    return 1;
}
