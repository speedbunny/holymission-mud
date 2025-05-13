id(str) { return str == "allplayer"; }
short() { return 0; }
long()  { write(
"allplayer/ganja <txt> allplayersay/ganjasay <txt> allplayercmd/ganjacmd <cmd>\n"); 
	write("ganjawho/fluwho/religions,  onlyplayer/onlyplayercmd <txt>\n");
	write("onlyroom <txt>\n");
}
get()	{ return 1; }
query_weight() { return 0; }

init()  { 
	add_action("allplayer", "allplayer" );
	add_action("onlyplayer", "onlyplayer" );
	add_action("onlyroom", "onlyroom" );
	add_action("allplayersay", "allplayersay" );
	add_action("allplayercmd", "allplayercmd" );
	add_action("onlyplayercmd", "onlyplayercmd" );
	add_action("ganja", "ganja" );
	add_action("ganjasay", "ganjasay" );
	add_action("ganjacmd", "ganjacmd" );
	add_action("ganjawho", "ganjawho" );
	add_action("fluwho", "fluwho" );
	add_action("religions", "religions" );
}

ganja(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
	 if ( (r=present("qganjasoul",u[i])) )
	    tell_object(u[i], str+"\n");
     return 1;
  } 
  return 0; 
}

onlyroom(str) {
  if (str) {
	tell_room(environment(this_player()), str+"\n");
     return 1;
  } 
  return 0; 
}

ganjawho(str) {
  object u,r; 
  int i;
  u=users();
  for (i=0; i<sizeof(u); i++)
  if ( (r=present("qganjasoul",u[i])) )
	  tell_object(this_player(), u[i]->query_name()+"\n");
  return 1;
}

fluwho(str) {
  object u,r; 
  int i;
  u=users();
  for (i=0; i<sizeof(u); i++)
  if ( (r=present("flu_q174",u[i])) )
	  tell_object(this_player(), u[i]->query_name()+"\n");
  return 1;
}

ganjasay(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
	 if ( (r=present("qganjasoul",u[i])) )
	    tell_object(u[i],capitalize(this_player()->query_name())
		      + " says: "+str+"\n");
     return 1;
  } 
  return 0; 
}

ganjacmd(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
	 if ( (r=present("qganjasoul",u[i])) )
		command(str,u[i]); 
     return 1;
  } 
  return 0; 
}

allplayer(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
	    tell_object(u[i], str+"\n");
     return 1;
  } 
  return 0; 
}

onlyplayer(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
		if (u[i]->query_level()<30)
	    	tell_object(u[i], str+"\n");
     return 1;
  } 
  return 0; 
}

allplayersay(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
	    tell_object(u[i],capitalize(this_player()->query_name())
		      + " says: "+str+"\n");
     return 1;
  } 
  return 0; 
}

allplayercmd(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
		command(str,u[i]); 
     return 1;
  } 
  return 0; 
}

onlyplayercmd(str) {
  object u,r; 
  int i;
  if (str) {
     u=users();
     for (i=0; i<sizeof(u); i++)
		if (u[i]->query_level()<30)
			command(str,u[i]); 
     return 1;
  } 
  return 0; 
}

religions(str) {
  object u,r; 
  int i;
  u=users();
  for (i=0; i<sizeof(u); i++)
	  tell_object(this_player(), u[i]->query_name() + " "
					+ u[i]->query_religion()+"\n");
  return 1;
}

