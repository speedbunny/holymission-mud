inherit "/obj/treasure";

void reset(status arg){
 set_short("Test");
 set_long("test");
 set_weight(500);
 set_value(0);
 set_name("test");
}

init(){
 ::init();
 tell_object(find_player("goldsun"),"INIT called by "+this_player()->query_name()+"\n");
}


