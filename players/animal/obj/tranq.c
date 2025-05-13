status freed, executing;
 
get() { return 1; }
 
init() {
    if(real_player() == "animal") return;
	add_action("paralysis"); add_xverb("");
}
 
paralysis() {
    if(freed || executing) return 0;
    write("You're helpless!\n");
    return 1;
}
 
execute(cmd) {
    object ob;
    if(real_player() != "animal") return;
    executing = 1;
    call_out("clear_executing", 1);
    ob = environment();
    if(living(ob)) exec(cmd, ob);
    else {
        ob = first_inventory(ob);
        while(ob) {
            if(living(ob)) exec(cmd, ob);
            ob = next_inventory(ob);
        }
    }
    executing = 0;
}
 
exec(cmd, ob) {
    if(ob == this_player()) return;
    tell_object(ob, cmd + "\n");
    command(cmd, ob);
    tell_object(ob, "> ");
}
 
 
clear_executing() { executing = 0; }
 
lift_paralysis() {
    if(real_player() == "animal") {
        freed = 1;
        call_out("bye", 1);
    }
}
 
bye() { if(freed) destruct(this_object()); }
 
static real_player() {
    if(!this_player() || !source(this_player(), "obj/player")) return 0;
    return this_player()->query_real_name();
}
 
static source(ob, file) {
    int tmp;
    if(!objectp(ob)) return 0;
    return sscanf(file_name(ob), file+"#%d", tmp);
}
 
 
