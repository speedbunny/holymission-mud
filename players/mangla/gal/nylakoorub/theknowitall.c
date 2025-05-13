/* The Know it all  Tool */
/* made by nylakoorub */

object *online;


int id(string str) {
    return str == "knowitall" ||
    str == "infotool";
}
string short() {
    return "The Know It All Tool";
}


void long() {
    write(
      "\n");
}

int get() { return 1; }
int drop() { return 1; }


init() {
    object *u;
    int i,j;
    if(!online) {
	online = ({ });
	u = users();
	j = sizeof(u);
	for(i=0;i<j;i++) {
	    online += ({ u[i]->query_real_name() });
	}
	tell_object(environment(),
	  "THE KNOW IT ALL: Inital Users added.\n");
    }
    add_action("who_is_online","online");
    call_out("start_heart_beat", 0);
}


start_heart_beat() {
    tell_object(environment(),
      "Starting heart beat.\n");
    set_heart_beat(1);
}


who_is_online() {
    int i,j;
    j = sizeof(online);
    tell_object(environment(),
      "\n"+
      "THE KNOW IT ALL: Users Online: \n");
    for(i=0;i<j;i++) {
	tell_object(environment(),
	  capitalize(online[i]) );
	tell_object(environment(),
	  " ");
    }
    tell_object(environment(),
      "\n");
    return 1;
}




do_users_update() {
    object *u;
    int o,m;
    int i,j;
    u = users();
    j = sizeof(u);
    for(i=0;i<j;i++) {
	if(member_array(u[i]->query_real_name(), online) == -1) {
	    online += ({ u[i]->query_real_name() });
	    tell_object(environment(),
	      "THE KNOW IT ALL: "+
	      capitalize(u[i]->query_real_name()) +
	      " is logged on.\n");
	}
    }
    o = sizeof(online);
    for(m=0;m<o;m++) {   
	if(!find_living(online[m])) {
	    tell_object(environment(),
	      "THE KNOW IT ALL: "+
	      (online[m]) +
	      " has logged off.\n");
	    online -= ({ online[m] });
	}
    }
    tell_object(environment(),
      "THE KNOW IT ALL: Nothing New.\n");
    return 1;
}



void heart_beat() {
    int count;
    if(count>10) {
	do_users_update();
	count = 0;
    } else {
	count += 1;
    }
}



