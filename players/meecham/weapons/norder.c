inherit "obj/weapon";
reset(arg){
     ::reset(arg);
     if(arg)return;
     set_weight(2);
     set_class(14);
     set_value(2000);
     set_name("norder");
     set_id("norder");
     set_alias("sword");
     set_short("Norder");
     set_long("This is Norder, the deadly sword of the nordel.\n");
}
init(){
     ::init();
}
