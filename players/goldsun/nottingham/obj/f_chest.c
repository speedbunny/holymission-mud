inherit "/obj/container";

reset(arg){
 ::reset(arg);
if (arg) return;
 set_name("chest");
 set_can_lock(1,"iron","f_school_code");
 set_can_get(0);
 set_max_weight(9);
 set_long("A school chest.\n");
}

