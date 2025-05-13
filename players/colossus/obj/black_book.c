inherit "obj/treasure";

string *criminal_list;
object criminal;
int guards_chasing;

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_name("book");
    set_alias("black book");
    set_short("Black book");
    criminal_list=({});
    set_long("Black book keeping track of those who have been naughty and nice.\n");
    call_out("decrease_chase", 100);
    set_weight(0);
    set_value(0);
}

decrease_chase(){
    if(guards_chasing)
	guards_chasing -=50;
    call_out("decrease_chase", 50);
}

query_chasing(){ return guards_chasing; }

add_criminal(object criminal){
    criminal_list +=({criminal->query_real_name() });
}

query_criminal(object suspect){
    return member_array(suspect->query_real_name(),
      criminal_list)!=1;
}

list_criminals(){
    int i;
    for(i=0;i<sizeof(criminal_list);i++)
	if(criminal_list[i])
	    write(criminal_list[i]+"\n");
}

object criminal_present(object location){
    object *people;
    int i;
