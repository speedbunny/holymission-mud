inherit "/obj/treasure";

reset(arg){
    ::reset(arg);
    if(arg) return 1;
    set_name("saffyrose");
    set_alias("rose");
    set_short("A beautiful red saffyrose");
    set_long("A beautiful red saffyrose pick from Saffrin's garden.\n");
    set_value(20);
    set_weight(1);
}
