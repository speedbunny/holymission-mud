/* Sauron's Patrolling Monster */
inherit "/obj/mon";

static object clone_room;
static object patrol_leader;
static object *patrol_members;

void set_patrol_leader(object ob) {
    patrol_leader=ob;
}

object query_patrol_leader() {
    return patrol_leader;
}

void add_patrol_member(object ob) {
    if(patrol_leader)
	return;

    if(!patrol_members)
	patrol_members=({});

    if(member_array(ob,patrol_members)==-1)
	patrol_members+=({ob});
}

void remove_patrol_member(object ob) {
    if(patrol_leader || !patrol_members)
	return;

    else if(member_array(ob,patrol_members)!=-1)
	patrol_members-=({ob});
}

object *query_patrol_members() {
    return patrol_members;
}

void set_clone_room(object ob) {
    if(!clone_room)
	clone_room=ob;
}

string random_move() {
    string ret;
    int i;
    object old_env;

    old_env=environment();
    ret=::random_move();
    if(environment()!=old_env) {
	for(i=0;i<sizeof(patrol_members);i++) {
	    if(patrol_members[i] && environment(patrol_members[i])==old_env)
		patrol_members[i]->init_command(ret);
	}
    }
    return ret;
}

int monster_died(object ob) {
    int i,sz;
    object new_leader,tmp,*arr;

    if(patrol_leader) {
	patrol_leader->remove_patrol_member(this_object());
	return 0;
    }
    else if(!patrol_members || !sizeof(patrol_members))
	return 0;
    else {
	arr=({});
	for(i=0;i<sizeof(patrol_members);i++)
	    if(patrol_members[i])
		arr+=({patrol_members[i]});
	patrol_members=arr;
	sz=sizeof(patrol_members);
    }
    if(!sz)
	return 0;
    else if(sz==1) {
	tmp=patrol_members[0];
	tmp->set_walk_chance(walk_chance);
	tmp->set_walk_limit(walk_limit);
	clone_room->set_patrol_leader(tmp);
	return 0;
    }
    else {
	i=random(sizeof(patrol_members));
	while(!patrol_members[i])
	    i=random(sizeof(patrol_members));

	new_leader=patrol_members[i];
	new_leader->set_walk_chance(walk_chance);
	new_leader->set_walk_limit(walk_limit);
	new_leader->set_patrol_leader((object)0);
	clone_room->set_patrol_leader(new_leader);
	patrol_members[i]=(object)0;

	for(i=0;i<sizeof(patrol_members);i++) {
	    tmp=patrol_members[i];
	    if(tmp!=new_leader) {
		tmp->set_patrol_leader(new_leader);
		new_leader->add_patrol_member(tmp);
	    }
	}
	return 0;
    }
}

void reset(int arg) {
    ::reset(arg);
    if(!arg) {
	set_dead_ob(this_object());
    }
}
