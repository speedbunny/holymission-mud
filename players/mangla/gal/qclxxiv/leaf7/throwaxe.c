#define MAXLEFT 40
#define MAXHIT 15 
#define MAXWEIGHT 5
#define MAXVALUE 200
int _maxleft, _maxhit, _maxweight, _maxvalue;
int nleft;
string shortstr;

id(str) { return str == "axe" || str == "throwaxe"; }
short() { return shortstr; }
long()  { write("A dwarfen throwaxe. They can be thrown many times, and can\n"
				+"do a lot of damage to your opponents. To use: throw axe\n"
				+"if in fight, or throw axe at <name> to start a fight.\n" ); }
get()	{ return 1; }
query_weight() { return _maxweight*(nleft/_maxleft); }
query_value() { return _maxvalue*(nleft/_maxleft); }

reset(arg) {
	if (arg) return;
	set_maxleft(MAXLEFT);
	set_maxhit(MAXHIT);
	set_maxvalue(MAXVALUE);
	set_maxweight(MAXWEIGHT);
	set_short("A dwarfen throwaxe" );
	return 1;
}

set_maxhit(i) {_maxhit=i;}
set_maxleft(i) {_maxleft=i; nleft=_maxleft; }
set_maxvalue(i) {_maxvalue=i;}
set_maxweight(i) {_maxweight=i;}
set_short(s) {shortstr=s;}

init()  { add_action("throw", "throw" ); }

throw(totstr) {
    string str,who;
	object ob;
	int i;
	if (!environment(this_object())==this_player()) return 0;
	if (!sscanf(totstr, "axe at %s", str))
			sscanf(totstr, "axe %s", str);

	if (!str) ob = this_player()->query_attack();
	else ob = present( str, environment(this_player()));
	if (ob) {
		write( "You throw your axe at "+ob->query_name()+".\n");
		tell_object(ob,this_player()->query_name()+" throws an axe at you.\n");	
		i = random(30);
		if (i>=20) {
			ob->hit_player(2*MAXHIT);
			write( "Good throw! You made a maximal hit.\n");
			tell_object(ob,"You are hit badly by the axe.\n");	
		}
		else if (i>=10) {
			ob->hit_player(MAXHIT);
			write( "The axe hits your opponent.\n");
			tell_object(ob,"You are hit by the axe.\n");	
		}
		else {
			write( "The axe misses your opponent, but it was near a thing.\n");
			tell_object(ob,"The axe misses you, but it was near a thing.\n");	
		}
		move_object(this_object(), environment(this_player()));
		nleft--;
		if (nleft<=0) {
			write("The axe crumbles to dust as it hits the ground.\n");
		    tell_object(ob,"The axe crumbles to dust as it hits the ground.\n");
			destruct( this_object() );
		}
		else {
			write( "Axe hits the ground.\n");
			tell_object(ob, "Axe hits the ground.\n");
		}
	}
	else if (str) write(str+" is not here.\n");
		 else write("You are not fighting currently!\n");
	return 1;
}

