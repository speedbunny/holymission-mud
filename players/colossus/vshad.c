object owner;

void start_the_shadow(object ob){
    if(!ob)
	destruct(this_object());
    owner = ob;
    shadow(ob, 1);
    call_out("remove_shadow", 120 + random((int)owner->query_level()));
}
varargs int hit_player(int dam, int kind, mixed elem){
    if(kind < 4){
	tell_object(owner, "You change places with your opponent.\n");
	say((string)owner->query_name()+" changes places with "+
	  (string)this_player()->query_name()+".\n");
	return owner->hit_player(dam/2, kind, elem);
	this_player()->hit_player(dam, kind, elem);
    }
    return owner->hit_player(dam, kind, elem);
}
