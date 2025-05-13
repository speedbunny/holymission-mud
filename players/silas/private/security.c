/*  Thanx to Sonja for the basic code... this code will not only check to see 
if the person entering is you, but also checks against an access list file,
which is defined for LIST.  Also, you can define the person's destination,
DEST, to which they will be moved if they try to enter.  (The emote and echo
codes are mine, however. :^)  --Anthrax */

int secure;
extra_init(){
	string nom, nom2, ok;
	int count, size;
	size=sizeof(grab_file(LIST));
	if(size<=0) size=1;
	count=1;
	ok="no";
        add_action("secure","secure");
        add_action("eject","eject");
	nom=this_player()->query_real_name();
	while(count <= size && ok == "no")
		{
		nom2=read_file(LIST, count);
		if(nom2==nom+"\n") ok="yes";
		count += 1;
		}
if(secure==1 && nom!="anthrax" && ok=="no"){
	   write("The door is locked right now.  Anthrax does not wish to be disturbed.\n");
	   tell_room(this_object(),capitalize(nom)+" tried to enter.\n");
           call_out("moveem", 0, this_player());
           return 1;
        }
	add_action("emote","emote");
	add_action("emote");
	add_xverb(":");
	add_action("echo","ech");
	add_action("echo");
	add_xverb("/");
}

moveem(ob){
	ob->move_player(DEST);
        return 1;
}
secure(str){
        string nom;
        nom=this_player()->query_real_name();
	if(nom!="anthrax"){
	    write("Sorry, but only Anthrax can secure this room.\n");
           return 1;
           }
        if(!str && secure==0) secure=1;
        else if(!str && secure==1) secure=0;
        else if(!sscanf(str, "%d", secure)) return 0;
	else if(secure<0 || secure>1) return 0;
	if(secure==0) tell_room(this_object(),"Security system deactivated.\n");
	else tell_room(this_object(),"Security system activated.\n");
        return 1;
}
eject(str) {
        object offndr;
	   if(this_player()->query_real_name() != "anthrax")
	   {write("Only Anthrax can eject people from this room.\n");
           return 0; }
           offndr=present(str); if(!offndr) { write("They're not here.\n");
           return 0; }
           call_other(offndr, "move_player","rapidly#/room/common");
           return 1;
}

emote(str)
	{
	object who;
	string targ, mess;
	if(!str)
		{
		write("Emote what?\n");
		return 1;}
	if(sscanf(str,"%s:%s", targ, mess) != 2)
		{
		write("You emote: "+this_player()->query_name()+" "+str+"\n");
		say(this_player()->query_name()+" "+str+"\n");
		return 1;}
	who=present(lower_case(targ),environment(this_player()));
	if(!who)
		{
		write("Emote to who?\n");
		return 1;}
	write("You emote to "+capitalize(targ)+" the message:\n");
	write(this_player()->query_name()+" "+mess+"\n");
	tell_object(who,this_player()->query_name()+" "+mess+"\n");
	return 1;
	}

echo(str)
	{
	object who;
	string targ, mess;
	if(!str)
		{
		write("Echo what?\n");
		return 1;}
	if(sscanf(str,"%s/%s", targ, mess) !=2)
		{
		write("You echo: "+str+"\n");
		say(str+"\n");
		return 1;}
	who=present(lower_case(targ), environment(this_player()));
	if(!who)
		{
		write("Echo to who?\n");
		return 1;}
	write("You echo to "+capitalize(targ)+" the message:\n");
	write(mess+"\n");
	tell_object(who,mess+"\n");
	return 1;
	}
