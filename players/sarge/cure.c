inherit "obj/treasure";
reset(arg) {
        if (arg) return;
        set_short("cure");
        set_long("A cure for the flu\n");
}

init() { 
        ::init();
        check(); 
}

check(){
if(present("flu_q174")){
destruct("flu_q174");
}
}
