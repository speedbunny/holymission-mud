inherit "obj/treasure";

reset(arg){
    ::reset(arg);
    set_name("manual");
    set_alias("paper");
    set_short("The knight manual");
    set_long("A manual that describes control of the knights. Please read.\n");
    set_weight(0);
    set_value(0);
}
init(){
    add_action("read", "read");
    ::init();
}
read(str){
    if(!str) return 0;
    if(str=="manual"){
	cat("/players/colossus/knights/dispmanual");
	return 1;
    }
}
