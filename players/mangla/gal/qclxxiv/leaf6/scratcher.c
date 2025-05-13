#define MAXLEFT 20
#define MAXHIT 20
#define MAXWEIGHT 3
#define MAXVALUE 100
int _maxleft, _maxhit, _maxweight, _maxvalue;
int nleft, scratchon;
string shortstr;

id(str) { return str == "scratcher"; }
short() { return shortstr; }
long()  { write(
"A scratcher can be used as an additional weapon in fights. Just type scratch\n"
+"when in fight and your (first) attacker will be scratched. To attack with\n"
+"the scratcher just type: scratch <someone>. You can scratch just a number\n"
+"of times before the scratcher crumbles to dust.\n"); }
get()	{ return 1; }
query_weight() { return _maxweight*(nleft/_maxleft); }
query_value() { return _maxvalue*(nleft/_maxleft); }

reset(arg) {
	if (arg) return;
	set_maxleft(MAXLEFT);
	set_maxhit(MAXHIT);
	set_maxvalue(MAXVALUE);
	set_maxweight(MAXWEIGHT);
	set_short("A scratcher" );
	scratchon = 1;
	return 1;
}

set_maxhit(i) {_maxhit=i;}
set_maxleft(i) {_maxleft=i; nleft=_maxleft; }
set_maxvalue(i) {_maxvalue=i;}
set_maxweight(i) {_maxweight=i;}
set_short(s) {shortstr=s;}

init()  { add_action("scratch", "scratch" ); }

scratch(str) {
    string who;
	object ob;
	if (!environment(this_object())==this_player()) return 0;
	if (!scratchon) {
		write("You have to wait a sec. before scratching again.\n");
		return 1;
	}
	if (!str) ob = this_player()->query_attack();
    else if (sscanf(str, "%s", who) == 1) 
			ob = present( who, environment(this_player()));
	if (ob) {
		write( "You scratch "+ob->query_name()+" badly.\n");
		tell_object(ob, this_player()->query_name()+" scratches you badly.\n");	
		ob->hit_player(MAXHIT);
		nleft--;
		if (nleft<=0) {
			write("Your scratcher crumbles to dust.\n");
			destruct( this_object() );
		}
		else call_out( "rescratch", 1 ); 
		scratchon = 0;
	}
	else if (str) write(str+" is not here.\n");
		 else write("You are not fighting currently!\n");
	return 1;
}

rescratch() { return (scratchon = 1); }
