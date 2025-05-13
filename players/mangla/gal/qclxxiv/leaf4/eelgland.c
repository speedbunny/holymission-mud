#define MAXLEFT 1
#define MAXHIT 50
#define MAXWEIGHT 1
#define MAXVALUE 200
int _maxleft, _maxhit, _maxweight, _maxvalue;
int nleft, scratchon;
string shortstr;

id(str) { return str == "gland" || str == "eel gland"; }
short() { return shortstr; }
long()  { write(
"An electric eel's electric gland. Just type shock when in fight and your\n"
+"attacker will receive a terrible shock. To attack with the gland just do:\n"
+"shock <someone>.\n"); }
get()	{ return 1; }
query_weight() { return _maxweight*(nleft/_maxleft); }
query_value() { return _maxvalue*(nleft/_maxleft); }

reset(arg) {
	if (arg) return;
	set_maxleft(MAXLEFT);
	set_maxhit(MAXHIT);
	set_maxvalue(MAXVALUE);
	set_maxweight(MAXWEIGHT);
	set_short("An eel gland" );
	scratchon = 1;
	return 1;
}

set_maxhit(i) {_maxhit=i;}
set_maxleft(i) {_maxleft=i; nleft=_maxleft; }
set_maxvalue(i) {_maxvalue=i;}
set_maxweight(i) {_maxweight=i;}
set_short(s) {shortstr=s;}

init()  { add_action("shock", "shock" ); }

shock(str) {
    string who;
	object ob;
	if (!environment(this_object())==this_player()) return 0;
/*	if (!scratchon) {
		write("You have to wait a sec. before scratching again.\n");
		return 1;
	}
*/
	if (!str) ob = this_player()->query_attack();
    else if (sscanf(str, "%s", who) == 1) 
			ob = present( who, environment(this_player()));
	if (ob) {
		write( "You discharge the electric eel gland on "
											+ob->query_name()+".\n");
		tell_object(ob, this_player()->query_name()
						+" discharges an electric eel gland on you.\n");	
		ob->hit_player(MAXHIT);
		nleft--;
		if (nleft<=0) {
			write(
"The electric eel gland starts to shrink and suddenly disappears.\n");
			destruct( this_object() );
		}
		/* else call_out( "rescratch", 1 );  */
		scratchon = 0;
	}
	else if (str) write(str+" is not here.\n");
		 else write("You are not fighting currently!\n");
	return 1;
}

rescratch() { return (scratchon = 1); }
