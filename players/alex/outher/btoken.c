inherit "/obj/treasure";
 
reset(arg) {
    if(arg) return;
    set_name("token");
    set_alias("btoken");
    set_short ("A token");
    set_long ("This token was given to all of the now late elven kings commanders\n");
 
    set_weight(1);
    set_value(0);
}
init() {
add_action("drop_token","drop_token");
add_action("give_token","give_token");
add_action("g","get token");
::init();
}
drop_token(arg) {
write("As you try to drop it the token crumbles away.\n");
return 1;
}
 
 
give_token(arg) {
write("As you try to give the token away it crumbles to nothing.\n");
return 1;
}
 
 
g(){
 
if(present("guard")){
write("The last guard screams as he sees you trying to take the crown\n"+
        "and rushes to stop you.\n");
return 0;
}
else
return 1;
}
