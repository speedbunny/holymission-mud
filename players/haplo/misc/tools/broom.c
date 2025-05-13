// Changed by Ethereal Cashimor. Now only able to be used by
// level 35 and higher. Do not copy this file... Banishment can
// follow... */
// 13-SEP-93 Galadriel: changed 'lower' to 'higher' in above comment.
//           moved checking code from init() to reset() as it caused
//           bugs at login of wiz below 35.

//	Saurons One Ring
//	by Sauron (Tubmud, 130.149.9.20 7680)
//	query_real_name() { return Juergen Weiss; }
//	email: sauron@opal.cs.tu-berlin.de
	
//	credits to junky

#define VERSION		"2.6"
#define TH 		 this_player()
#define TRN 		this_player()->query_real_name()
#define QRN 		query_real_name()
object owner;
int alarm,home;
int intox,look_flag;
object OBJ,my_inv;
int x,y,pro;
string find_name,v;
int version,finder;
int nr,flag ,echo_on;
int copy,all_move,z;
object tp;
int sorted;
string ver;
object invent,this;
string in_msg,out_msg;
string *banned_obj;

query_auto_load() {
   return "/players/haplo/misc/tools/broom:"+v;
}

short() {
  string s;
  if(owner && TH)
    if((owner->QRN!=TRN) && owner->query_level()>=TH->query_level())
		    tell_me("*** "+TH->QRN+" checked your inventory !***\n");
  s="An old witch-broom";
 	return s;
}

reset(arg) {
  first();
  if (arg) return;
  if(this_player()->query_level()<35) {
    destruct(this_object());
    return;
  }
  OBJ=this_object();
  sorted=1;
  alarm=1;
  call_out("version",2,OBJ);
  banned_obj=({
    "pcurse",
  });
}
long() {
	write("Lila's Broom (stolen from Sauron@tubmud !)\n");
	write("Type 'help broom' for more infos.\n");
}
init_arg(arg)	{
		v=arg; 
		sscanf(v,"%sXxX%sXxX%s",ver,in_msg,out_msg);
		}

init() {
	if (TH == environment(OBJ))
	{
	if (owner && alarm==1)
	/* check names not objects, so no throw out alarms the broom */
	if (TH->query_real_name() != owner->query_real_name() || 
		TH->query_npc())
		return alarm();
	add_action("in_msg","in_msg");
	add_action("out_msg","out_msg");
	add_action("mygoto","-",1);	
	add_action("mycom","command");
	add_action("set_alarm","alarm");
	add_action("list_peoples","People");
	add_action("finder","scan");
	add_action("dnet","dnet");
	add_action("secr","secretarian");
	add_action("disco","tell");
	add_action("intox","sober");
	add_action("look","look");
	add_action("steal","steal");
	add_action("bring","bring");
	add_action("dir","Ls");	
	add_action("lookflag","nolook");
 	add_action("copy","copy");
	add_action("echo_room","emo");
	add_action("move","move");
	add_action("all_move","transfer");
	add_action("check_snoop","check");
	add_action("inv","inventory");
	add_action("help","help");
	add_action("plist","plist");
	add_action("ide","invdestruct");
	add_action("inv","i");
	}
	if (TRN !=
	environment(OBJ)->QRN)
		{
		tell_me(
		"\n****ATTENTION****\n"+
		TRN+
		" entered your inventory !!!\n");
	tell_me("Filename:"+file_name(TH)+"\n");
		check_broom_env();	
		}
}

id(str) {
		return str =="broom" || str =="witch-broom";
}


query_weight() { return 0; }


query_value() { return 5; }
get()
	{
	if (!TH->query_immortal())
	{
	write("The Broom flies away from you.\n");
	return 0;
	}
	return 1;
}
look(str)
	{
	string s,s1,space;
	string p1;
	object ob;
	inspect_inv();	
	if (str) return 0;
	if (look_flag==1) return 0;
	invent=allocate(30);
	flag=1; /* for destruct 'inv()' */
	nr=0;
	ob=first_inventory(environment(TH));
	while(ob)
	{
	if (ob !=TH)
	{
	s=ob->short();
	if (!s && living(ob) && !ob->query_npc())   /* invis someone */
		s="("+ob->QRN+")";
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	
	if (shadow(ob,0)) s=s+" *S*";
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	p1=get_filename(ob);
	write(s1+"("+nr+") < "+p1+" >\n");
	invent[nr]=ob;
	if (nr == 29) break;
	if (nr<29) nr++;
	}
	ob=next_inventory(ob);
	}
	nr--;
	write("\n");
	return 0;
	}

get_filename(ob)
	{
	string s,s1;
	s=file_name(ob);
	if (s) sscanf(s,"players/%s",s1);
	if (s1) s="~"+s1;
	else
	s="/"+s;
	return s;
	}
inv(str)
	{
	string s,s1,space;
	string p1;
	object ob;

	if (str) return 0;
	first();  /* move broom up */
	inspect_inv();	
	invent=allocate(30);
	nr=0;
	flag=2;
	if (str) return 0;
	ob=first_inventory(TH);
	while(ob)
	{
	s=ob -> short();
	if (!s && living(ob) && !ob->query_npc())
		s="("+ob->QRN+")";
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	if (shadow(ob,0)) s=s+" *S*";
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	p1=get_filename(ob);
	write(s1+"("+nr+") < "+p1+" >\n");
	invent[nr]=ob;
	if (nr==29) break;
	if (nr<29) nr++;
	ob=next_inventory(ob);
	}
	nr--;
	return 1;
}
ide(str)
	{
	int ob;
	if (!str) return 0;
	ob=str[0]-'0';
	if (strlen(str)==2)
	{
	ob=((str[0]-'0') * 10) + str[1]-'0';
	}
	if (ob < 0 || ob > nr)
	{ write("Error, no such number !\n"); return 1; }
	if (invent[ob] ==this_object()) flag=0;
	write("- Object ");
	if (invent[ob]->short()) write(invent[ob]->short());
	else
	write("#"+ob);
	write(" destructed.\n\n");
	destruct(invent[ob]);
	if (flag==2)
	{
	inv();
	}
	return 1;
	}
plist()
{
	cat("/SORT_LEVEL");
	return 1;
}
help(str)
	{
	if (!id(str)) return 0;
	TH -> more("/players/lila/obj/broom.doc");
	/*
	cat("/players/lila/obj/broom.doc");
	*/
	return 1;
	}
drop(silently)
	{
	if (query_verb()=="quit") return 1;
	if (!silently)
	write("You cannot drop the broom.\n");
	call_out("reset",1,0);
	return 1;
	}

check_snoop(str)
{
	object pl,ob;
	if (!str) return 0;
	pl = find_living(str);
	if (!pl)
		{
		write("No such player.\n");
			return 1;
		}

	ob = query_snoop(pl);
	if (!ob)
		{
		write("Not snooped.\n");
		return 1;
		}
	write("Snooped by:" + ob -> QRN + ".\n");
	return 1;
}

find_dest(str) {
    string thing2,where;
    object dest;
    if (dest=present(str,environment(OBJ))) return dest;
    if (dest=present(str,environment(environment(OBJ)))) return dest;
    if (str=="here") return environment(environment(OBJ));
    if (str=="me") return environment(OBJ);
    if (find_living(str)) return find_living(str);
    if (find_object(str)) return find_object(str);
    return;
}
echo(str) {
    int a;
    echo_on=1;
    a=echo_room(str);
    echo_on=0;
    if (a) return 1; else return;
}
echo_room(str) {
    string a,b,name,rname,list;
    object room,ob;
    if (!str) return;
    sscanf(str,"%s %s",a,b);
    room=find_dest(a);
    if (!room) {
      if (echo_on) return;
      if (sscanf(a,"%s/%s",b)) write("Room not found.\n");
      else write("Object not found.\n");
      return 1;
      }
    if (living(room)) room=environment(room);
	name=TH->query_name();
    if (echo_on) tell_room(room,b+"\n");
    else tell_room(room,name+" says from above: "+b+"\n");
    ob=first_inventory(room);
    write("Listeners : ");
    while (ob) {
      if (rname=call_other(ob,"query_real_name")) {
        if (list) list+=", "+capitalize(rname);
        else list=capitalize(rname);
        }
      ob=next_inventory(ob);
      }
    write(list+".\n");
    return 1;
}
all_move(str) {
    all_move=1;
    move(str);
    all_move=0;
    return 1;
}
move(str) {
    int a;
    string what, from, from2, where, where2, obj;
    object thing, nthing, dest1, dest2;
    if (!str) return;
    if (sscanf(str,"%s from %s to %s",what,from,where)!=3) {
      if (sscanf(str,"%s to %s",what,where)!=2) return;
      from=0;
      dest1=environment(OBJ);
      }
    if (!dest1) {
      dest1=find_dest(from);
      if (!dest1) {
        write("Destination 1 not found.\n");
        return 1;
        }
      }
    if (!(thing=find_thing(what,dest1))) return 1;
    dest2=find_dest(where);
    if (!dest2) {
      write("Destination 2 not found.\n");
      return 1;
      }
    z=1;
    while(thing) {
      nthing=next_inventory(thing);
      if (x<=z) {
        obj=call_other(thing,"short");
        if (all_move) move_object(thing,dest2);
        else a=transfer(thing,dest2);
        if (a==0||all_move) write(obj+": transfered.\n");
  else {
          if (a==1) write(obj+": too heavy.\n");
          if (a==2) write(obj+": can't be dropped.\n");
          if (a==6) write(obj+": can't get.\n");
          }
        }
      z++;
      if (y<z) break;
      thing=nthing;
      }
    x=0;y=0;
    return 1;
}

find_thing(what,dest) {
    object thing;
    object thing2,where;
    thing=present(what,dest);
    if (!thing&&environment(dest)) {
      thing=present(what,environment(dest));
      }
    if (what=="me") {
      thing=environment(OBJ);
      }
    if (what=="all") {
      thing=first_inventory(dest);
      y=1000;
      }
        if (!thing) {
          if (sscanf(what,"%d-%d",x,y)==2) {
            if (x>=y) {
              write("Wrong numbers given.\n");
              return 0;
              }
            }
          if (!sscanf(what,"%d",x)) {
 write(what+" is not there.\n");
            return 0;
            }
          }
      if (!y||y==0) y=x;
    if (!thing) return first_inventory(dest); else return thing;
}

intox()
	{
	tp=TH;
	tp->clear_intoxication();
	write("You are not drunk anymore.\n");
	say(tp->query_name()+" suddenly does not look drunk anymore.\n");
	return 1;
	}
/*	for muds without clear_intox function:
	intox=1;
	set_heart_beat(1);
	write("Ok, cleaning your intoxination.\n");
	write("This will take a while.\n");
	return 1;
	}
*/
heart_beat()
	{
	int busy;
	if (pro==1)
		busy=irq1();
/*
	if (intox==1)
		busy=busy+irq2();
*/
	if (finder)
		busy=busy+irq3();
	inspect_inv();	
	if (busy==0)	set_heart_beat(0);
	}
irq1()
	{
	if (!find_inventory("checker",environment(environment(OBJ))))
		pro();
	return 1;
	}
irq2()
	{
	if (tp->query_intoxination()>0)
		{
		tp->add_intoxination(- tp->query_intoxination()/10);
		tell_object(tp,"Cleaning...\n");
		return 1;
		}
	else
		{
		intox=0;
		return 0;
		}
    }

/*
	find_inventory(searched_object,search_where_object)
*/
find_inventory(ob,room)
	{
	object t;
	
	t=first_inventory(room);
	while(t)
		{
		if (t -> id(ob))	break;
		t=next_inventory(t);
		}
	if (!t) return 0;
	if (t->id(ob))	return 1;
	return 0;
	}
first()
	{
	if (environment(this_object()))
	move_object(this_object(),environment(this_object()));
	/* move broom up */
	}
query_prevent_shadow()	{ return 1;	}
disco(str)
	{
	object ob;
	inspect_inv();	
	if (query_verb()=="tell")
		return disco2(str);
 /*	ob=first_inventory(environment(TH));
	while(ob)
		{
		if (living(ob) && !ob->query_npc() &&
			!query_ip_number(ob) && ob->query_real_name())
		write("ATTENTION: "+ob->query_name()+" is disconnected.\n");
		ob=next_inventory(ob);
		}
	*/		
	return 0;
	}
disco2(str)
	{
	object ob;
	string s,s1;
	sscanf(str,"%s %s",s,s1);
	ob=find_living(s);
	if (!ob) return 0;
	if (living(ob) && !ob->query_npc() && !query_ip_number(ob))
		write("ATTENTION: "+ob->query_name()+" is disconnected.\n");
	return 0;
	}
disabled()
	{
	write("This function of the broom is disabled at the moment.\n");
	return 1;
	}
secr()
	{
	object ob;
	ob=clone_object("players/lila/obj/secr");
	ob->set_owner(TRN);
	move_object(ob,environment(TH));
	write("Ok.\n");
	return 1;
	}
version(o)
	{
	if (!environment(o)) return;
	if (owner)	if (check_cheat(environment(o))) return;
	tell_object(environment(o),
	"Lila's Broom ("+VERSION+") appears in your hand.\n");
	owner=environment(o); /* save, so broom cannot be stolen */
	if (ver != VERSION) tell_me("--Your broom has some new features--\n"+
		               "--type 'help broom' for inform.   --\n");	
	get_inv();
	if (!in_msg)	in_msg=capitalize(owner->QRN)+" "+owner->query_mmsgin();
	if (!out_msg)  out_msg=capitalize(owner->QRN)+" "+owner->query_mmsgout();
	home=0;
	call_out("start_check",1);
	make_v();
	}

check_cheat(o)	{
	if (	o->query_npc()	||
		!query_ip_number(o)	||
		!o->QRN
	   )
	{
	tell_me("*** ATTENTION ***\n");
	tell_me("--"+o->query_name()+"/"+o->QRN+" tried to steal and\n"+
	"reset your broom.\n"+
	"--Thiefs destination:");
	if (environment(o)) 
		if (file_name(o)) tell_me(file_name(o)+"\n");
		else
		tell_me("[no_file_name]\n");
	else
	tell_me("[no_environment]\n");
	tell_me("--Ring moved back to you--\n");
	move_object(OBJ,owner);
	return 1;
}
}
	
make_v()	{	v=VERSION	+"XxX"+in_msg	+"XxX"+out_msg; }
in_msg(str)	{
		if(!str)	{
		write("Your current in message is:\n"+in_msg+".\n");
		return 1;
				}
		in_msg=str;
		write("Your in message is now set to:\n"+in_msg+".\n");
		make_v();
		return 1;
	}
out_msg(str)	{	
		if(!str)	{
		write("Your current out message is:\n"+out_msg+".\n");
		return 1;	}

		out_msg=str;
		write("Your out message is now set to:\n"+out_msg+".\n");
		make_v();
		return 1;
	}
dnet() {
	string who,p1,p2;
	int i;
	string desc, name;
	who = users();
write("Name		 Host					 Path\n");
	for (i = 0; i< sizeof(who); i++) {
		desc = who[i]->short();
		name = capitalize(who[i]->QRN);
		if (desc != 0)
			write(ladjust(name,16)+" ");
		else
			write(ladjust("("+name+")",16)+" ");
		write(ladjust(query_ip_name(who[i]),40));
		p1=0; p2=0;
		if (who[i]->query_immortal()) {
		p1=who[i]->query_path();
		if (p1) sscanf(p1,"players/%s",p2);
		if (p2) p1="~"+p2;
		else p1="/"+p1;
						}
		if (p1) write(ladjust(p1,20));
		write("\n");
		}
	return 1;
	}

ladjust(str, n) {
        return extract(str+"                                  ",0,n-1);
        }

lookflag()
	{
	if (look_flag==0) look_flag=1; else look_flag=0;
	write("Brooms 'look' changed.\n");
	return 1;
	}

copy(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp)	return 1;
	show_i(tp);
	write("Copy #:");
	input_to("copy2");
	return 1;
	}
bring(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp) return 1;
	this=tp;
	show_i(TH);
	write("Bring #");
	input_to("bring2");
	return 1;
	}
steal(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp) return 1;
	show_i(tp);
	write("Steal #");
	input_to("steal2");
	return 1;
	}
copy2(n)
	{
	string s,s1;
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
		{
		write("Skipped.\n");
		return 1;
		}
	write("Copying "+invent[n]->short()+".\n");
	
	sscanf(file_name(invent[n]),"%s#%s",s,s1);
	move_object(clone_object(s),TH);

	return 1;
}
steal2(n)
	{
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
		{
		write("Skipped.\n");
		return 1;
		}
	write("Stealing "+invent[n]->short()+".\n");
	move_object(invent[n],TH);
	return 1;
	}
bring2(n)
	{
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
	{
		write("Skipped.\n");
		return 1;
	}
	write("Bringing "+invent[n]->short()+".\n");
	move_object(invent[n],this);
	return 1;
	}
fl(s)
	{
	return find_player(s);
	}
show_i(tp)
	{
	string s,s1,space;
	object ob;
	if (!tp) return 0;
	invent=allocate(30);
	nr=1;
	ob=first_inventory(tp);
	while(ob)
	{
	s=ob->short();
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	write(s1+"("+nr+") < "+file_name(ob)+" >\n");
	invent[nr]=ob;
	if (nr == 29) break;
	if (nr<29) nr++;
	ob=next_inventory(ob);
	}
	nr--;
	write("\n");
	
	

	return 1;
	}

scan(i)
	{
	int a;
	sscanf(i,"%d",a);
	return a;
	}

finder(str)
	{
	string s,s1,s2;
	if (!str) {
		write("Scanner turned off.\n");
		finder=0;
		return 1;	}
	if (str=="?") {  write(query_scan()); return 1; }
	if (sscanf(str,"%s,%s,%s",s,s1,s2) !=3)
		if (sscanf(str,"%s,%s",s,s1) !=2)  s=str;
	if (!s1) s1="0";
	if (!s2) s2="0";
	find_name=({s,s1,s2});
	finder=1;
	set_heart_beat(1);
	write("Scanning System for "+str+".\n");
	return 1;
	}
query_scan()
	{
	int i;
	string st;
	string s,s1,s2;
	if (!find_name) return "Scanner is Off.\n";
	s=find_name[0];
	s1=find_name[1];
	s2=find_name[2];
	if (s=="0" && s==s1 && s==s2) 
		{
		finder==0;
		return "Scanner is Off.\n";
		}
	if (s !="0" && s) st=capitalize(s);
	if (s1 && s1 !="0") st=st+"\n"+capitalize(s1);
	if (s2 !="0") st=st+"\n"+capitalize(s2);
	return "Scanning System for:\n"+st+"\n";
	}
irq3()
	{
	int i;
	for (i = 0; i < 3; i++)
		{
		if (find_name[i] !="0" && find_name[i])
			if (fl(lower_case(find_name[i])))
			{
		if (query_ip_number(fl(lower_case(find_name[i])))) {	
			is_here(find_name[i]);
				find_name[i]="0";
							}
			}
		}
	if (find_name[0] !="0" || find_name[1] !="0" || find_name[2] !="0")
		return 1;
	finder=0;
	tell_me("--Scanner turned off--\n");
	return 0;
	}
is_here(s)
	{	tell_me("--"+capitalize(s)+" is here now--\n");	 
	}
tell_me(str)
	{
	if (!owner) return;
	tell_object(owner,str);
	}

list_peoples() {
    object list;
    string p1,p2;	/* added by sauron */
    string idle	;
    int sec,min,hour,idtime;
    int i, a;
	inspect_inv();
    list = sorted_users();
    write("There are now " + sizeof(list) + " players");
    for (i=0, a=0; i < sizeof(list); i++)
	if (query_idle(list[i]) >= 5 * 60)
	    a++;
    if (a)
	write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    for(i=0; i<sizeof(list); i++) {
	string name;
	name = list[i]->query_real_name();
	if (!name)
	    name = list[i]->query_name();
	if (!name)
	    name = "logon";
	name = capitalize(name);
	if (list[i]->short() == 0)
	    name = "(" + name + ")";
	if (strlen(name) < 8)
	    name = name + "\t";
	write(query_ip_number(list[i]) + "\t" + name + "\t" +
	      list[i]->query_level() + "\t");
	a = list[i]->query_age();
	if (a / 43200 > 9)
	    write(a / 43200 + " D");
	else if (a / 43200 > 0)
	    write(a / 43200 + "  D");
	else if (a / 1800 > 9)
	    write(a / 1800 + " h");
	else if (a / 1800 > 0)
	    write(a / 1800 + "  h");
	else if (a / 30 > 9)
	    write(a / 30 + " m");
	else
	    write(a / 30 + "  m");
	idtime=query_idle(list[i]);
	if (idtime>30) {
		sec=idtime % 60; idtime=idtime /60;
		min=idtime % 60; idtime=idtime /60;
	       hour=idtime % 60;
		if (hour<10) idle="0"; else idle="";
		idle=idle+hour+":";
		if (min<10) idle=idle+"0";
		idle=idle+min+":";
		if (sec<10) idle=idle+"0";
		idle=idle+sec;
		}
	else
	idle="     ";
	write(" "+idle);
/*
	if (query_idle(list[i]) >= 5 * 60)
	    write(" I\t");
	else
*/
	write("\t");
	if (environment(list[i]))

	/* following 6 lines added by sauron */

	{
		p1=0;p2=0;
	    p1=file_name(environment(list[i]));
	   if (p1) sscanf(p1,"players/%s",p2);
	   if (p2) p1="~"+p2;
		else
	   p1="/"+p1;
	write(p1);
	}
	/* write(file_name(environment(list[i])));   */
	write("\n");
    }
    return 1;
}

alarm()
	{
	if (!owner) return;
	tell_me("*** ATTENTION ***\n"+
	capitalize(TRN)+" did steal your broom !!!!!\n"+
	"Ring moved back to you.\n");
	move_object(OBJ,owner);
	tell_object(TH,"** THIEF **\n");
	return 1;
	}
static set_alarm()
	{
	alarm=!alarm;
	if (alarm==1) write("Alarm ON.\n");
	else
	write("Alarm OFF.\n");
	return 1;
	}
myquit()	{
	string s,s1;
	if (sscanf(file_name(environment(TH)),"%sworkroom%s",s,s1) ==2)
			return 0;
	s=TH->query_mmsgout();
	say(TH->query_name()+" "+s+".\n");
	write("You leave home and quit.\n");
	if (file_size("/players/"+TRN+"/workroom.c") <=0)
	write("You have no home, so you quit here.\n");
	else
	move_object(TH,"/players/"+TRN+"/workroom.c");
	return 0;
	}
mycom(str)
	{
	object ob;
	string s,s1;
	if (!str) return 0;

	if (sscanf(str,"%s %s",s,s1) !=2)	{
		write("Wrong 'command' syntax.\n");
		return 1;			}
	if (s=="lila") {
	write("Your broom is not mighty enough to command Lila.\n");
	return 1;
			}
	ob=find_living(s);
	if (!ob)	{
		write("No such living thing.\n");
		return 1;
			}
	command(s1,ob);
	write("You command "+capitalize(s)+" to "+s1+".\n");
	return 1;
	}
	
	
	 
mygoto(str)	{
	string p1,p2,p3;
	if (sscanf(query_verb(),"-%s",p1) !=1 || str)	{
		write("Wrong syntax.\n");
		return 1;
						}
	str=p1;
	if (goto_player(str)) return 1;
	p1="/room/";
	p2="/"+TH->query_path()+"/";
	p3="/players/"+TH->QRN+"/";	

	if (file(p2+str+".c")>0)	  return tele(p2+str);
	if (file(p3+"room/"+str+".c")>0)  return tele(p3+"room/"+str);
	if (file(p3+"rooms/"+str+".c")>0) return tele(p3+"rooms/"+str);
	if (file(p3+"R/"+str+".c")>0)	  return tele(p3+"R/"+str);
	if (file(p3+"G/"+str+".c")>0)	return tele(p3+"G/"+str);
	if (file(p3+str+".c")>0)          return tele(p3+str);
	if (file(p1+str+".c")>0)          return tele(p1+str);
	if (file("/players/"+str+".c")>0) return tele("/players/"+str);

	write("No such destination found.\n");
	return 1;
}
file(s)	{	return file_size(s);	}
tele(s)	{	return teleport(s); }
goto_player(s)	{
		object o;
		o=find_living(s);
		if (o)	{
			return tele("/"+file_name(environment(o)));
			}
		return 0;
		}

get_inv()	{	my_inv=all_inventory(owner);	}

start_check()	{
  inspect_inv();
  call_out("start_check",120);
}

inspect_inv() {
	 object ob;
  string fname;                 
	 int i,j;	
	 if(!owner) return;	
  tell_me("--Checking your inventory --\n");  
	 ob=first_inventory(owner);
	 while(ob)	{
  	 for(i=0;i<sizeof(my_inv);i++)	{
	     if(ob==my_inv[i]) {
        i--;
        break;
      }
    }
    if(i!=-1 && ob!=OBJ) {
	     if(creator(ob)!=owner->QRN)	 
/*
	       tell_me("--Something did change in your inventory !--\n"+  
	               "--This object is new: "+file_name(ob)+".\n");
*/
      for(j=0;j<sizeof(banned_obj);j++) {
        if(ob->id(banned_obj[j])) {
	         tell_me("--This object is on the banned list: "+file_name(ob)
                 +".\n--Destructing.....\n");
          destruct(ob);
        }
        else
          continue;
      }
    }
	  ob=next_inventory(ob);
  }
 	get_inv();	
//  if(OBJ) move_object(OBJ,owner); // move broom up
 	check_broom_env();	
// 	check_shadow();
 	check_idle();	
  return 1;
}

check_shadow()	{
	object o;
	if (owner) {
		o=shadow(owner,0); 
		return;
		if (o)	{
			tell_me("*** ATTENTION ***\n"+
			"*** You are shadowed.\n");
			tell_me("*** Filename:"+file_name(o)+"\n");
			destruct(o);
			tell_me("*** Shadow destructed.\n");
			}
		}}

check_broom_env()	{
	if (owner && alarm==1)
	if (environment(OBJ) != owner)	{
		tell_me("*** ATTENTION ***\n"+
		"--Your broom is not by you !--\n"+
		"--Ring destination:");
		if (file_name(environment(OBJ)))
			tell_me(file_name(environment(OBJ))+"--\n");
		else
			tell_me("[no_file_name]--\n");
		tell_me("--Ring moved back to you--\n");
		move_object(OBJ,owner);
		}
	}

teleport(dest) {
    object ob;
    if (!dest) {
        write("Goto where ?\n");
        return 1;
    }
/*

            ob->long();
        ob = first_inventory(ob);
        while(ob) {
            if (ob != owner) {
                string short_str;
                short_str = ob->short();
                if (short_str)
                    write(short_str + ".\n");
            }
            ob = next_inventory(ob);
        }
        return 1;
*/
    dest = owner->valid_read(dest, owner);
    if (!dest || file_size("/" + dest + ".c") <= 0) {
        write("Invalid monster name or file name: " + dest + "\n");
        return 1;
    }
 	if (owner->short()) owner->tell_others(out_msg+".\n"); 
	if (owner->short()) tell_room(dest,in_msg+".\n"); 
	move_object(owner,dest); 
	command("look",owner);
    return 1;
}
check_idle()	{
	if (owner && home==0)
		if (!query_ip_number(owner))  /* disconnected */
		{
		tell_room(environment(owner),
		"--"+capitalize(owner->QRN)+" is disconnected !\n"+
		"--Leaving home.\n");
		owner->move_player("home#/players/"+owner->QRN+"/workroom");
		home=1;
		}
}
	

string names;
object players;
int size;

sort(l,r)
{
  int m,a,b;
  object t;
  a=l;b=r;
  m=names[(l+r)/2];
  for (;;)
  {
    while (names[a]<m && a<b) a++;
    while (names[b]>m && a<b) b--;
    if (a==b)
      break;
    if (names[a]==names[b])
    {
      a++;
      continue;
    }
    t=names[a];
    names[a]=names[b];
    names[b]=t;
    t=players[a];
    players[a]=players[b];
    players[b]=t;
  }
  if (l<a-1) sort(l,a-1);
  if (r>b+1) sort(b+1,r);
}

sorted_users()
{
  int i;
  players=users();
  if (sorted)
  {
    size=sizeof(players);
    names=allocate(size);
    for (i=0;i<size;i++)
      names[i]=players[i]->query_real_name();
    sort(0,size-1);
  }
  return players;
}

do_people()
{
    object list;
    string p1,p2;       /* added by sauron */
    string idle ;
    int sec,min,hour,idtime;
    int i, a;

    list = sorted_users();
    write("There are now " + sizeof(list) + " players");
    for (i=0, a=0; i < sizeof(list); i++)
        if (query_idle(list[i]) >= 5 * 60)
            a++;
    if (a)
        write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    for(i=0; i<sizeof(list); i++) {
        string name;
        name = list[i]->query_real_name();
        if (!name)
            name = list[i]->query_name();
        if (!name)
            name = "logon";
        name = capitalize(name);
        if (list[i]->short() == 0)
            name = "(" + name + ")";
        if (strlen(name) < 8)
            name = name + "\t";
        write(query_ip_number(list[i]) + "\t" + name + "\t" +
              list[i]->query_level() + "\t");
        a = list[i]->query_age();
        if (a / 43200 > 9)
            write(a / 43200 + " D");
        else if (a / 43200 > 0)
            write(a / 43200 + "  D");
        else if (a / 1800 > 9)
            write(a / 1800 + " h");
        else if (a / 1800 > 0)
            write(a / 1800 + "  h");
        else if (a / 30 > 9)
            write(a / 30 + " m");
        else
            write(a / 30 + "  m");
        idtime=query_idle(list[i]);
        if (idtime>30) {
                sec=idtime % 60; idtime=idtime /60;
                min=idtime % 60; idtime=idtime /60;
               hour=idtime % 60;
                if (hour<10) idle="0"; else idle="";
                idle=idle+hour+":";
                if (min<10) idle=idle+"0";
                idle=idle+min+":";
                if (sec<10) idle=idle+"0";
                idle=idle+sec;
                }
        else
        idle="     ";
        write(" "+idle);
            write("\t");
        if (environment(list[i]))

        /* following 6 lines added by sauron */

        {
                p1=0;p2=0;
            p1=file_name(environment(list[i]));
           if (p1) sscanf(p1,"players/%s",p2);
           if (p2) p1="~"+p2;
                else
           p1="/"+p1;
        write(p1);
        }
        /* write(file_name(environment(list[i])));   */
        write("\n");

    }
    return 1;
}


static dir(s)	{
	string files,path;
	int c,t,i;
	path="/"+owner->query_path();
	if (s) if (s[strlen(s)] !="/") {
		path=s;
		s=s+"/.";
		if (file_size(path) !=-2)	{
			write("Bad directory.\n");
			return 1;
			}
		}
	if (!s) s="/"+path+"/.";

	files=allocate(sizeof(get_dir(s)));
	files=get_dir(s);
	write(sizeof(files)+" files in directory: "+path+"\n");
	for (i=0; i<sizeof(files);i++)	{
		s=files[i];	
		t=file_size(path+"/"+s);
		if (t==-2) s=s+"/";
		s=resize(s,15);
		write(s);
		if (t>0) write(resize(t,6)); 
		else
		write(resize(" ",6));
		write("   |");
		if (i>290)	{
			write("*** EXECUTION ABORTED !\n");
			break;
			}
		c++;
		if (c==3)	{c=0; write("\n");	}

	}
	write("\n");
	return 1;
}

resize(s,t)	{
	return extract(s+"               ",0,t-1);
}
/* Changed by Ethereal Cashimor. Now only able to be used by
   level 35 and higher. Do not copy this file... Banishment can
   follow... */
/* 13-SEP-93 Galadriel: changed 'lower' to 'higher' in above comment.
             moved checking code from init() to reset() as it caused
             bugs at login of wiz below 35.
*/
/* 04.04.96 Airborne: Changed to work with new level system. */
/*
			Saurons One Ring
			by Sauron (Tubmud, 130.149.9.20 7680)
		query_real_name() { return Juergen Weiss; }
		email: sauron@opal.cs.tu-berlin.de
	
			credits to junky
*/
#define VERSION		"2.6"
#define TH 		this_player()
#define TRN 		this_player()->query_real_name()
#define QRN 		query_real_name()
object owner;
int alarm,home;
int intox,look_flag;
object OBJ,my_inv;
int x,y,pro;
string find_name,v;
int version,finder;
int nr,flag ,echo_on;
int copy,all_move,z;
object tp;
int sorted;
string ver;
object invent,this;
string in_msg,out_msg;
query_auto_load() 
        { return "tools/broom:"+v;}
short() {
	string s;
	if (owner && TH)
	if ((owner->QRN != TRN) && owner->query_level()>=TH->query_level())
		{
		tell_me("*** "+TH->QRN+" checked your inventory !***\n");
		}

	if (environment(OBJ)->QRN=="lila")
		s="An shining new broom(mounted)";
	else 
		s="An old witch-broom";
	return s;
}

reset(arg)
	{
	first();
	if (arg) return;
        if(this_player()->query_level()<160) {
          destruct(this_object());
          return;
        }
	OBJ=this_object();
	sorted=1;
	alarm=1;
	call_out("version",2,OBJ);
	}
long() {
	write("Lila's Broom (stolen from Sauron@tubmud !)\n");
	write("Type 'help broom' for more infos.\n");
}
init_arg(arg)	{
		v=arg; 
		sscanf(v,"%sXxX%sXxX%s",ver,in_msg,out_msg);
		}

init() {
	if (TH == environment(OBJ))
	{
	if (owner && alarm==1)
	/* check names not objects, so no throw out alarms the broom */
	if (TH->query_real_name() != owner->query_real_name() || 
		TH->query_npc())
		return alarm();
	add_action("in_msg","in_msg");
	add_action("out_msg","out_msg");
	add_action("mygoto","-",1);	
	add_action("mycom","command");
	add_action("set_alarm","alarm");
	add_action("list_peoples","People");
	add_action("finder","scan");
	add_action("dnet","dnet");
	add_action("secr","secretarian");
	add_action("disco","tell");
	add_action("intox","sober");
	add_action("look","look");
	add_action("steal","steal");
	add_action("bring","bring");
	add_action("dir","Ls");	
	add_action("lookflag","nolook");
 	add_action("copy","copy");
	add_action("echo_room","emo");
	add_action("move","move");
	add_action("all_move","transfer");
	add_action("check_snoop","check");
	add_action("inv","inventory");
	add_action("help","help");
	add_action("plist","plist");
	add_action("ide","invdestruct");
	add_action("inv","i");
	}
	if (TRN !=
	environment(OBJ)->QRN)
		{
		tell_me(
		"\n****ATTENTION****\n"+
		TRN+
		" entered your inventory !!!\n");
	tell_me("Filename:"+file_name(TH)+"\n");
		check_broom_env();	
		}
}

id(str) {
		return str =="broom" || str =="witch-broom";
}


query_weight() { return 0; }


query_value() { return 5; }
get()
	{
	if (!TH->query_immortal())
	{
	write("The Broom flies away from you.\n");
	return 0;
	}
	return 1;
}
look(str)
	{
	string s,s1,space;
	string p1;
	object ob;
	inspect_inv();	
	if (str) return 0;
	if (look_flag==1) return 0;
	invent=allocate(30);
	flag=1; /* for destruct 'inv()' */
	nr=0;
	ob=first_inventory(environment(TH));
	while(ob)
	{
	if (ob !=TH)
	{
	s=ob->short();
	if (!s && living(ob) && !ob->query_npc())   /* invis someone */
		s="("+ob->QRN+")";
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	
	if (shadow(ob,0)) s=s+" *S*";
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	p1=get_filename(ob);
	write(s1+"("+nr+") < "+p1+" >\n");
	invent[nr]=ob;
	if (nr == 29) break;
	if (nr<29) nr++;
	}
	ob=next_inventory(ob);
	}
	nr--;
	write("\n");
	return 0;
	}

get_filename(ob)
	{
	string s,s1;
	s=file_name(ob);
	if (s) sscanf(s,"players/%s",s1);
	if (s1) s="~"+s1;
	else
	s="/"+s;
	return s;
	}
inv(str)
	{
	string s,s1,space;
	string p1;
	object ob;

	if (str) return 0;
	first();  /* move broom up */
	inspect_inv();	
	invent=allocate(30);
	nr=0;
	flag=2;
	if (str) return 0;
	ob=first_inventory(TH);
	while(ob)
	{
	s=ob -> short();
	if (!s && living(ob) && !ob->query_npc())
		s="("+ob->QRN+")";
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	if (shadow(ob,0)) s=s+" *S*";
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	p1=get_filename(ob);
	write(s1+"("+nr+") < "+p1+" >\n");
	invent[nr]=ob;
	if (nr==29) break;
	if (nr<29) nr++;
	ob=next_inventory(ob);
	}
	nr--;
	return 1;
}
ide(str)
	{
	int ob;
	if (!str) return 0;
	ob=str[0]-'0';
	if (strlen(str)==2)
	{
	ob=((str[0]-'0') * 10) + str[1]-'0';
	}
	if (ob < 0 || ob > nr)
	{ write("Error, no such number !\n"); return 1; }
	if (invent[ob] ==this_object()) flag=0;
	write("- Object ");
	if (invent[ob]->short()) write(invent[ob]->short());
	else
	write("#"+ob);
	write(" destructed.\n\n");
	destruct(invent[ob]);
	if (flag==2)
	{
	inv();
	}
	return 1;
	}
plist()
{
	cat("/SORT_LEVEL");
	return 1;
}
help(str)
	{
	if (!id(str)) return 0;
	TH -> more("/players/lila/obj/broom.doc");
	/*
	cat("/players/lila/obj/broom.doc");
	*/
	return 1;
	}
drop(silently)
	{
	if (query_verb()=="quit") return 1;
	if (!silently)
	write("You cannot drop the broom.\n");
	call_out("reset",1,0);
	return 1;
	}

check_snoop(str)
{
	object pl,ob;
	if (!str) return 0;
	pl = find_living(str);
	if (!pl)
		{
		write("No such player.\n");
			return 1;
		}

	ob = query_snoop(pl);
	if (!ob)
		{
		write("Not snooped.\n");
		return 1;
		}
	write("Snooped by:" + ob -> QRN + ".\n");
	return 1;
}

find_dest(str) {
    string thing2,where;
    object dest;
    if (dest=present(str,environment(OBJ))) return dest;
    if (dest=present(str,environment(environment(OBJ)))) return dest;
    if (str=="here") return environment(environment(OBJ));
    if (str=="me") return environment(OBJ);
    if (find_living(str)) return find_living(str);
    if (find_object(str)) return find_object(str);
    return;
}
echo(str) {
    int a;
    echo_on=1;
    a=echo_room(str);
    echo_on=0;
    if (a) return 1; else return;
}
echo_room(str) {
    string a,b,name,rname,list;
    object room,ob;
    if (!str) return;
    sscanf(str,"%s %s",a,b);
    room=find_dest(a);
    if (!room) {
      if (echo_on) return;
      if (sscanf(a,"%s/%s",b)) write("Room not found.\n");
      else write("Object not found.\n");
      return 1;
      }
    if (living(room)) room=environment(room);
	name=TH->query_name();
    if (echo_on) tell_room(room,b+"\n");
    else tell_room(room,name+" says from above: "+b+"\n");
    ob=first_inventory(room);
    write("Listeners : ");
    while (ob) {
      if (rname=call_other(ob,"query_real_name")) {
        if (list) list+=", "+capitalize(rname);
        else list=capitalize(rname);
        }
      ob=next_inventory(ob);
      }
    write(list+".\n");
    return 1;
}
all_move(str) {
    all_move=1;
    move(str);
    all_move=0;
    return 1;
}
move(str) {
    int a;
    string what, from, from2, where, where2, obj;
    object thing, nthing, dest1, dest2;
    if (!str) return;
    if (sscanf(str,"%s from %s to %s",what,from,where)!=3) {
      if (sscanf(str,"%s to %s",what,where)!=2) return;
      from=0;
      dest1=environment(OBJ);
      }
    if (!dest1) {
      dest1=find_dest(from);
      if (!dest1) {
        write("Destination 1 not found.\n");
        return 1;
        }
      }
    if (!(thing=find_thing(what,dest1))) return 1;
    dest2=find_dest(where);
    if (!dest2) {
      write("Destination 2 not found.\n");
      return 1;
      }
    z=1;
    while(thing) {
      nthing=next_inventory(thing);
      if (x<=z) {
        obj=call_other(thing,"short");
        if (all_move) move_object(thing,dest2);
        else a=transfer(thing,dest2);
        if (a==0||all_move) write(obj+": transfered.\n");
  else {
          if (a==1) write(obj+": too heavy.\n");
          if (a==2) write(obj+": can't be dropped.\n");
          if (a==6) write(obj+": can't get.\n");
          }
        }
      z++;
      if (y<z) break;
      thing=nthing;
      }
    x=0;y=0;
    return 1;
}

find_thing(what,dest) {
    object thing;
    object thing2,where;
    thing=present(what,dest);
    if (!thing&&environment(dest)) {
      thing=present(what,environment(dest));
      }
    if (what=="me") {
      thing=environment(OBJ);
      }
    if (what=="all") {
      thing=first_inventory(dest);
      y=1000;
      }
        if (!thing) {
          if (sscanf(what,"%d-%d",x,y)==2) {
            if (x>=y) {
              write("Wrong numbers given.\n");
              return 0;
              }
            }
          if (!sscanf(what,"%d",x)) {
 write(what+" is not there.\n");
            return 0;
            }
          }
      if (!y||y==0) y=x;
    if (!thing) return first_inventory(dest); else return thing;
}

intox()
	{
	tp=TH;
	tp->clear_intoxication();
	write("You are not drunk anymore.\n");
	say(tp->query_name()+" suddenly does not look drunk anymore.\n");
	return 1;
	}
/*	for muds without clear_intox function:
	intox=1;
	set_heart_beat(1);
	write("Ok, cleaning your intoxination.\n");
	write("This will take a while.\n");
	return 1;
	}
*/
heart_beat()
	{
	int busy;
	if (pro==1)
		busy=irq1();
/*
	if (intox==1)
		busy=busy+irq2();
*/
	if (finder)
		busy=busy+irq3();
	inspect_inv();	
	if (busy==0)	set_heart_beat(0);
	}
irq1()
	{
	if (!find_inventory("checker",environment(environment(OBJ))))
		pro();
	return 1;
	}
irq2()
	{
	if (tp->query_intoxination()>0)
		{
		tp->add_intoxination(- tp->query_intoxination()/10);
		tell_object(tp,"Cleaning...\n");
		return 1;
		}
	else
		{
		intox=0;
		return 0;
		}
    }

/*
	find_inventory(searched_object,search_where_object)
*/
find_inventory(ob,room)
	{
	object t;
	
	t=first_inventory(room);
	while(t)
		{
		if (t -> id(ob))	break;
		t=next_inventory(t);
		}
	if (!t) return 0;
	if (t->id(ob))	return 1;
	return 0;
	}
first()
	{
	if (environment(this_object()))
	move_object(this_object(),environment(this_object()));
	/* move broom up */
	}
query_prevent_shadow()	{ return 1;	}
disco(str)
	{
	object ob;
	inspect_inv();	
	if (query_verb()=="tell")
		return disco2(str);
 /*	ob=first_inventory(environment(TH));
	while(ob)
		{
		if (living(ob) && !ob->query_npc() &&
			!query_ip_number(ob) && ob->query_real_name())
		write("ATTENTION: "+ob->query_name()+" is disconnected.\n");
		ob=next_inventory(ob);
		}
	*/		
	return 0;
	}
disco2(str)
	{
	object ob;
	string s,s1;
	sscanf(str,"%s %s",s,s1);
	ob=find_living(s);
	if (!ob) return 0;
	if (living(ob) && !ob->query_npc() && !query_ip_number(ob))
		write("ATTENTION: "+ob->query_name()+" is disconnected.\n");
	return 0;
	}
disabled()
	{
	write("This function of the broom is disabled at the moment.\n");
	return 1;
	}
secr()
	{
	object ob;
	ob=clone_object("players/lila/obj/secr");
	ob->set_owner(TRN);
	move_object(ob,environment(TH));
	write("Ok.\n");
	return 1;
	}
version(o)
	{
	if (!environment(o)) return;
	if (owner)	if (check_cheat(environment(o))) return;
	tell_object(environment(o),
	"Lila's Broom ("+VERSION+") appears in your hand.\n");
	owner=environment(o); /* save, so broom cannot be stolen */
	if (ver != VERSION) tell_me("--Your broom has some new features--\n"+
		               "--type 'help broom' for inform.   --\n");	
	get_inv();
	if (!in_msg)	in_msg=capitalize(owner->QRN)+" "+owner->query_mmsgin();
	if (!out_msg)  out_msg=capitalize(owner->QRN)+" "+owner->query_mmsgout();
	home=0;
	call_out("start_check",1);
	make_v();
	}

check_cheat(o)	{
	if (	o->query_npc()	||
		!query_ip_number(o)	||
		!o->QRN
	   )
	{
	tell_me("*** ATTENTION ***\n");
	tell_me("--"+o->query_name()+"/"+o->QRN+" tried to steal and\n"+
	"reset your broom.\n"+
	"--Thiefs destination:");
	if (environment(o)) 
		if (file_name(o)) tell_me(file_name(o)+"\n");
		else
		tell_me("[no_file_name]\n");
	else
	tell_me("[no_environment]\n");
	tell_me("--Ring moved back to you--\n");
	move_object(OBJ,owner);
	return 1;
}
}
	
make_v()	{	v=VERSION	+"XxX"+in_msg	+"XxX"+out_msg; }
in_msg(str)	{
		if(!str)	{
		write("Your current in message is:\n"+in_msg+".\n");
		return 1;
				}
		in_msg=str;
		write("Your in message is now set to:\n"+in_msg+".\n");
		make_v();
		return 1;
	}
out_msg(str)	{	
		if(!str)	{
		write("Your current out message is:\n"+out_msg+".\n");
		return 1;	}

		out_msg=str;
		write("Your out message is now set to:\n"+out_msg+".\n");
		make_v();
		return 1;
	}
dnet() {
	string who,p1,p2;
	int i;
	string desc, name;
	who = users();
write("Name		 Host					 Path\n");
	for (i = 0; i< sizeof(who); i++) {
		desc = who[i]->short();
		name = capitalize(who[i]->QRN);
		if (desc != 0)
			write(ladjust(name,16)+" ");
		else
			write(ladjust("("+name+")",16)+" ");
		write(ladjust(query_ip_name(who[i]),40));
		p1=0; p2=0;
		if (who[i]->query_immortal()) {
		p1=who[i]->query_path();
		if (p1) sscanf(p1,"players/%s",p2);
		if (p2) p1="~"+p2;
		else p1="/"+p1;
						}
		if (p1) write(ladjust(p1,20));
		write("\n");
		}
	return 1;
	}

ladjust(str, n) {
        return extract(str+"                                  ",0,n-1);
        }

lookflag()
	{
	if (look_flag==0) look_flag=1; else look_flag=0;
	write("Brooms 'look' changed.\n");
	return 1;
	}

copy(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp)	return 1;
	show_i(tp);
	write("Copy #:");
	input_to("copy2");
	return 1;
	}
bring(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp) return 1;
	this=tp;
	show_i(TH);
	write("Bring #");
	input_to("bring2");
	return 1;
	}
steal(str)
	{
	object tp;
	if (!str) return 0;
	tp=fl(str);
	if (!tp) return 1;
	show_i(tp);
	write("Steal #");
	input_to("steal2");
	return 1;
	}
copy2(n)
	{
	string s,s1;
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
		{
		write("Skipped.\n");
		return 1;
		}
	write("Copying "+invent[n]->short()+".\n");
	
	sscanf(file_name(invent[n]),"%s#%s",s,s1);
	move_object(clone_object(s),TH);

	return 1;
}
steal2(n)
	{
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
		{
		write("Skipped.\n");
		return 1;
		}
	write("Stealing "+invent[n]->short()+".\n");
	move_object(invent[n],TH);
	return 1;
	}
bring2(n)
	{
	n=scan(n);
	if (n<0 || !n || n>nr || pointerp(n))
	{
		write("Skipped.\n");
		return 1;
	}
	write("Bringing "+invent[n]->short()+".\n");
	move_object(invent[n],this);
	return 1;
	}
fl(s)
	{
	return find_player(s);
	}
show_i(tp)
	{
	string s,s1,space;
	object ob;
	if (!tp) return 0;
	invent=allocate(30);
	nr=1;
	ob=first_inventory(tp);
	while(ob)
	{
	s=ob->short();
	if (!s) { s="[no_short_name]"; }
	if (strlen(s) > 40)
	{
	s1=extract(s,0,32);
	s=s1;
	}
	
	write(s);
	space="                                        ";
	s1=extract(space,0,40-strlen(s));
	write(s1+"("+nr+") < "+file_name(ob)+" >\n");
	invent[nr]=ob;
	if (nr == 29) break;
	if (nr<29) nr++;
	ob=next_inventory(ob);
	}
	nr--;
	write("\n");
	
	

	return 1;
	}

scan(i)
	{
	int a;
	sscanf(i,"%d",a);
	return a;
	}

finder(str)
	{
	string s,s1,s2;
	if (!str) {
		write("Scanner turned off.\n");
		finder=0;
		return 1;	}
	if (str=="?") {  write(query_scan()); return 1; }
	if (sscanf(str,"%s,%s,%s",s,s1,s2) !=3)
		if (sscanf(str,"%s,%s",s,s1) !=2)  s=str;
	if (!s1) s1="0";
	if (!s2) s2="0";
	find_name=({s,s1,s2});
	finder=1;
	set_heart_beat(1);
	write("Scanning System for "+str+".\n");
	return 1;
	}
query_scan()
	{
	int i;
	string st;
	string s,s1,s2;
	if (!find_name) return "Scanner is Off.\n";
	s=find_name[0];
	s1=find_name[1];
	s2=find_name[2];
	if (s=="0" && s==s1 && s==s2) 
		{
		finder==0;
		return "Scanner is Off.\n";
		}
	if (s !="0" && s) st=capitalize(s);
	if (s1 && s1 !="0") st=st+"\n"+capitalize(s1);
	if (s2 !="0") st=st+"\n"+capitalize(s2);
	return "Scanning System for:\n"+st+"\n";
	}
irq3()
	{
	int i;
	for (i = 0; i < 3; i++)
		{
		if (find_name[i] !="0" && find_name[i])
			if (fl(lower_case(find_name[i])))
			{
		if (query_ip_number(fl(lower_case(find_name[i])))) {	
			is_here(find_name[i]);
				find_name[i]="0";
							}
			}
		}
	if (find_name[0] !="0" || find_name[1] !="0" || find_name[2] !="0")
		return 1;
	finder=0;
	tell_me("--Scanner turned off--\n");
	return 0;
	}
is_here(s)
	{	tell_me("--"+capitalize(s)+" is here now--\n");	 
	}
tell_me(str)
	{
	if (!owner) return;
	tell_object(owner,str);
	}

list_peoples() {
    object list;
    string p1,p2;	/* added by sauron */
    string idle	;
    int sec,min,hour,idtime;
    int i, a;
	inspect_inv();
    list = sorted_users();
    write("There are now " + sizeof(list) + " players");
    for (i=0, a=0; i < sizeof(list); i++)
	if (query_idle(list[i]) >= 5 * 60)
	    a++;
    if (a)
	write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    for(i=0; i<sizeof(list); i++) {
	string name;
	name = list[i]->query_real_name();
	if (!name)
	    name = list[i]->query_name();
	if (!name)
	    name = "logon";
	name = capitalize(name);
	if (list[i]->short() == 0)
	    name = "(" + name + ")";
	if (strlen(name) < 8)
	    name = name + "\t";
	write(query_ip_number(list[i]) + "\t" + name + "\t" +
	      list[i]->query_level() + "\t");
	a = list[i]->query_age();
	if (a / 43200 > 9)
	    write(a / 43200 + " D");
	else if (a / 43200 > 0)
	    write(a / 43200 + "  D");
	else if (a / 1800 > 9)
	    write(a / 1800 + " h");
	else if (a / 1800 > 0)
	    write(a / 1800 + "  h");
	else if (a / 30 > 9)
	    write(a / 30 + " m");
	else
	    write(a / 30 + "  m");
	idtime=query_idle(list[i]);
	if (idtime>30) {
		sec=idtime % 60; idtime=idtime /60;
		min=idtime % 60; idtime=idtime /60;
	       hour=idtime % 60;
		if (hour<10) idle="0"; else idle="";
		idle=idle+hour+":";
		if (min<10) idle=idle+"0";
		idle=idle+min+":";
		if (sec<10) idle=idle+"0";
		idle=idle+sec;
		}
	else
	idle="     ";
	write(" "+idle);
/*
	if (query_idle(list[i]) >= 5 * 60)
	    write(" I\t");
	else
*/
	write("\t");
	if (environment(list[i]))

	/* following 6 lines added by sauron */

	{
		p1=0;p2=0;
	    p1=file_name(environment(list[i]));
	   if (p1) sscanf(p1,"players/%s",p2);
	   if (p2) p1="~"+p2;
		else
	   p1="/"+p1;
	write(p1);
	}
	/* write(file_name(environment(list[i])));   */
	write("\n");
    }
    return 1;
}

alarm()
	{
	if (!owner) return;
	tell_me("*** ATTENTION ***\n"+
	capitalize(TRN)+" did steal your broom !!!!!\n"+
	"Ring moved back to you.\n");
	move_object(OBJ,owner);
	tell_object(TH,"** THIEF **\n");
	return 1;
	}
static set_alarm()
	{
	alarm=!alarm;
	if (alarm==1) write("Alarm ON.\n");
	else
	write("Alarm OFF.\n");
	return 1;
	}
myquit()	{
	string s,s1;
	if (sscanf(file_name(environment(TH)),"%sworkroom%s",s,s1) ==2)
			return 0;
	s=TH->query_mmsgout();
	say(TH->query_name()+" "+s+".\n");
	write("You leave home and quit.\n");
	if (file_size("/players/"+TRN+"/workroom.c") <=0)
	write("You have no home, so you quit here.\n");
	else
	move_object(TH,"/players/"+TRN+"/workroom.c");
	return 0;
	}
mycom(str)
	{
	object ob;
	string s,s1;
	if (!str) return 0;

	if (sscanf(str,"%s %s",s,s1) !=2)	{
		write("Wrong 'command' syntax.\n");
		return 1;			}
	if (s=="lila") {
	write("Your broom is not mighty enough to command Lila.\n");
	return 1;
			}
	ob=find_living(s);
	if (!ob)	{
		write("No such living thing.\n");
		return 1;
			}
	command(s1,ob);
	write("You command "+capitalize(s)+" to "+s1+".\n");
	return 1;
	}
	
	
	 
mygoto(str)	{
	string p1,p2,p3;
	if (sscanf(query_verb(),"-%s",p1) !=1 || str)	{
		write("Wrong syntax.\n");
		return 1;
						}
	str=p1;
	if (goto_player(str)) return 1;
	p1="/room/";
	p2="/"+TH->query_path()+"/";
	p3="/players/"+TH->QRN+"/";	

	if (file(p2+str+".c")>0)	  return tele(p2+str);
	if (file(p3+"room/"+str+".c")>0)  return tele(p3+"room/"+str);
	if (file(p3+"rooms/"+str+".c")>0) return tele(p3+"rooms/"+str);
	if (file(p3+"R/"+str+".c")>0)	  return tele(p3+"R/"+str);
	if (file(p3+"G/"+str+".c")>0)	return tele(p3+"G/"+str);
	if (file(p3+str+".c")>0)          return tele(p3+str);
	if (file(p1+str+".c")>0)          return tele(p1+str);
	if (file("/players/"+str+".c")>0) return tele("/players/"+str);

	write("No such destination found.\n");
	return 1;
}
file(s)	{	return file_size(s);	}
tele(s)	{	return teleport(s); }
goto_player(s)	{
		object o;
		o=find_living(s);
		if (o)	{
			return tele("/"+file_name(environment(o)));
			}
		return 0;
		}

get_inv()	{	my_inv=all_inventory(owner);	}
start_check()	{	inspect_inv(); call_out("start_check",120);	}
inspect_inv()	{
	object ob;                 
	int i;	
	if (!owner) return;	
	ob=first_inventory(owner);
	while(ob)	{
	for(i=0; i<sizeof(my_inv); i++)	{
	 if (ob==my_inv[i]) { i=-1; break; }
					}
	if (i != -1 && ob != OBJ) {
	if (creator(ob) != owner->QRN)	 
	tell_me("--Something did change in your inventory !--\n"+  
	         "--This object is new: "+file_name(ob)+".\n");
		     }
	
	ob=next_inventory(ob);
			}
	get_inv();	
	/* if (OBJ) move_object(OBJ,owner); */  /* move broom up */
	check_broom_env();	
/*
	check_shadow();
*/
	check_idle();	
return 1;
}

check_shadow()	{
	object o;
	if (owner) {
		o=shadow(owner,0); 
		return;
		if (o)	{
			tell_me("*** ATTENTION ***\n"+
			"*** You are shadowed.\n");
			tell_me("*** Filename:"+file_name(o)+"\n");
			destruct(o);
			tell_me("*** Shadow destructed.\n");
			}
		}}

check_broom_env()	{
	if (owner && alarm==1)
	if (environment(OBJ) != owner)	{
		tell_me("*** ATTENTION ***\n"+
		"--Your broom is not by you !--\n"+
		"--Ring destination:");
		if (file_name(environment(OBJ)))
			tell_me(file_name(environment(OBJ))+"--\n");
		else
			tell_me("[no_file_name]--\n");
		tell_me("--Ring moved back to you--\n");
		move_object(OBJ,owner);
		}
	}

teleport(dest) {
    object ob;
    if (!dest) {
        write("Goto where ?\n");
        return 1;
    }
/*

            ob->long();
        ob = first_inventory(ob);
        while(ob) {
            if (ob != owner) {
                string short_str;
                short_str = ob->short();
                if (short_str)
                    write(short_str + ".\n");
            }
            ob = next_inventory(ob);
        }
        return 1;
*/
    dest = owner->valid_read(dest, owner);
    if (!dest || file_size("/" + dest + ".c") <= 0) {
        write("Invalid monster name or file name: " + dest + "\n");
        return 1;
    }
 	if (owner->short()) owner->tell_others(out_msg+".\n"); 
	if (owner->short()) tell_room(dest,in_msg+".\n"); 
	move_object(owner,dest); 
	command("look",owner);
    return 1;
}
check_idle()	{
	if (owner && home==0)
		if (!query_ip_number(owner))  /* disconnected */
		{
		tell_room(environment(owner),
		"--"+capitalize(owner->QRN)+" is disconnected !\n"+
		"--Leaving home.\n");
		owner->move_player("home#/players/"+owner->QRN+"/workroom");
		home=1;
		}
}
	

string names;
object players;
int size;

sort(l,r)
{
  int m,a,b;
  object t;
  a=l;b=r;
  m=names[(l+r)/2];
  for (;;)
  {
    while (names[a]<m && a<b) a++;
    while (names[b]>m && a<b) b--;
    if (a==b)
      break;
    if (names[a]==names[b])
    {
      a++;
      continue;
    }
    t=names[a];
    names[a]=names[b];
    names[b]=t;
    t=players[a];
    players[a]=players[b];
    players[b]=t;
  }
  if (l<a-1) sort(l,a-1);
  if (r>b+1) sort(b+1,r);
}

sorted_users()
{
  int i;
  players=users();
  if (sorted)
  {
    size=sizeof(players);
    names=allocate(size);
    for (i=0;i<size;i++)
      names[i]=players[i]->query_real_name();
    sort(0,size-1);
  }
  return players;
}

do_people()
{
    object list;
    string p1,p2;       /* added by sauron */
    string idle ;
    int sec,min,hour,idtime;
    int i, a;

    list = sorted_users();
    write("There are now " + sizeof(list) + " players");
    for (i=0, a=0; i < sizeof(list); i++)
        if (query_idle(list[i]) >= 5 * 60)
            a++;
    if (a)
        write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    for(i=0; i<sizeof(list); i++) {
        string name;
        name = list[i]->query_real_name();
        if (!name)
            name = list[i]->query_name();
        if (!name)
            name = "logon";
        name = capitalize(name);
        if (list[i]->short() == 0)
            name = "(" + name + ")";
        if (strlen(name) < 8)
            name = name + "\t";
        write(query_ip_number(list[i]) + "\t" + name + "\t" +
              list[i]->query_level() + "\t");
        a = list[i]->query_age();
        if (a / 43200 > 9)
            write(a / 43200 + " D");
        else if (a / 43200 > 0)
            write(a / 43200 + "  D");
        else if (a / 1800 > 9)
            write(a / 1800 + " h");
        else if (a / 1800 > 0)
            write(a / 1800 + "  h");
        else if (a / 30 > 9)
            write(a / 30 + " m");
        else
            write(a / 30 + "  m");
        idtime=query_idle(list[i]);
        if (idtime>30) {
                sec=idtime % 60; idtime=idtime /60;
                min=idtime % 60; idtime=idtime /60;
               hour=idtime % 60;
                if (hour<10) idle="0"; else idle="";
                idle=idle+hour+":";
                if (min<10) idle=idle+"0";
                idle=idle+min+":";
                if (sec<10) idle=idle+"0";
                idle=idle+sec;
                }
        else
        idle="     ";
        write(" "+idle);
            write("\t");
        if (environment(list[i]))

        /* following 6 lines added by sauron */

        {
                p1=0;p2=0;
            p1=file_name(environment(list[i]));
           if (p1) sscanf(p1,"players/%s",p2);
           if (p2) p1="~"+p2;
                else
           p1="/"+p1;
        write(p1);
        }
        /* write(file_name(environment(list[i])));   */
        write("\n");

    }
    return 1;
}


static dir(s)	{
	string files,path;
	int c,t,i;
	path="/"+owner->query_path();
	if (s) if (s[strlen(s)] !="/") {
		path=s;
		s=s+"/.";
		if (file_size(path) !=-2)	{
			write("Bad directory.\n");
			return 1;
			}
		}
	if (!s) s="/"+path+"/.";

	files=allocate(sizeof(get_dir(s)));
	files=get_dir(s);
	write(sizeof(files)+" files in directory: "+path+"\n");
	for (i=0; i<sizeof(files);i++)	{
		s=files[i];	
		t=file_size(path+"/"+s);
		if (t==-2) s=s+"/";
		s=resize(s,15);
		write(s);
		if (t>0) write(resize(t,6)); 
		else
		write(resize(" ",6));
		write("   |");
		if (i>290)	{
			write("*** EXECUTION ABORTED !\n");
			break;
			}
		c++;
		if (c==3)	{c=0; write("\n");	}

	}
	write("\n");
	return 1;
}

resize(s,t)	{
	return extract(s+"               ",0,t-1);
}
