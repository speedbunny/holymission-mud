/*=========================================================================
 * BARBARIAN SOUL ---> 4-30-96
 * 970922, Uglymouth: recoded to use bin command structure.
 *=======================================================================*/

#include <lw.h>

#define BIN     "/players/apollo/guild/bin/"
#define FS      file_size
#define CHAT    "/sys/chatd.c"->do_chat
#define CAP     capitalize
#define NAME    query_name()
#define RNAME   query_real_name()
#define LEVEL   query_level()
#define LLEVEL  query_legend_level()


#define GM   "guild/master"
#define CS   "guild/master"->change_skill
#define QN   query_name()
#define QRN  query_real_name()
#define QL   query_level()
#define TP   this_player()
#define E    environment()
#define ENV  environment
#define EQPR (string)environment()->query_pronoun()
#define EQPO (string)environment()->query_possessive()
#define EQOB (string)environment()->query_objective()
#define EGS  environment()->get_skill
#define EQE  environment()->queryenv
#define ESE  environment()->setenv
#define EQN  (string)environment()->query_name()
#define CHK_SP(x) if((int)environment()->query_sp() < x)\
	{ write("You are too braindead to do that.\n"); return 1; }\
	else environment()->restore_spell_points(-x)
#define EQM  environment()->query_melee()
#define CHK_GH if(E->query_ghost()) return 0
#define NF   notify_fail

object shadow,next_throw,next_throw_ob,comb_soul;

closure call, out;  

int gd;
string barbline;

void de_equip();
void send_mess(string str);
void tell_all_but(object ob, string msg);
string parse_string(string str);
string get_word(string str);

int id( string str ) {
  return( str == "barbsoul" || str == "guildsoul" );
}

void reset( int flag ) {
	if( flag == 0 ) {
		call = #'call_other;
		out = #'call_out;
	}
}

int get() { return 1; }

int put() { return 1; }

int drop() { return 1; }

string query_barb_line() { return barbline; }

int set_barb_line( string str ) { barbline = str; }

string extra_look() {
    string tmp;
    CHK_GH;
    tmp=(string)EQE("TATTOO");
    return lw(CAP(EQPR) + " has a bold tattoo " + (tmp ? "of " + tmp + " " : "")
      + "emblazoned on " + (string)EQPO + " " + (string)EQE("TATTOOPOS")
      + (EQM || comb_soul ? ".\n" + CAP(EQPR) + " has a wild look in "
	+ EQPO + " eyes" : ""));
}

void init() {

    set_barb_line( "On" );

    if( TP->query_invis() && TP->query_immortal() ) { }
    else{
	CHAT( 11, "<= Barbarian => " + CAP( TP->RNAME ) + 
		" howls at the world as " + TP->query_pronoun() + 
		" returns to battle!\n" );
    }

    if(!pointerp(EGS("barbarian_combat")))
	CS(E, "barbarian_combat", 1, 100, 11);
    if(!pointerp(EGS("barbarian_melee")))
	CS(E, "barbarian_melee", 1, 100, 11);
    if(!pointerp(EGS("barbarian_fortitude")))
	CS(E, "barbarian_fortitude", 1, 100, 11);
    if(!pointerp(EGS("barb_toughness")))
	CS(E, "barb_toughness", 1 ,100, 11);
    if(!pointerp(EGS("barbarian_speed")))
	CS(E, "barbarian_speed", 1, 100, 11);
    if(!EQE("TATTOOPOS"))
	ESE("TATTOOPOS", "brow");
    if(!shadow) {
	shadow= clone_object("/players/apollo/guild/shadow_archive/shadow");
	shadow->start_the_shadow(E);
    }

    if(TP!=E) return;
    add_action( "_filter", "", 1 );
}

int _filter( string str ) {
  string theverb;

  theverb = query_verb();

  if( theverb[0] == 39 ) return 0;  // ignore history % cmds
  if( theverb == "dest" ) return 0; // Uglymouth: why is this???

  if( FS( BIN +  theverb + ".c" ) > 0 )
    return call_other( BIN + theverb, "main", str );
  if( theverb == "barb/" || theverb == "barb=" )
    return call_other( BIN + "barb", "main", str );
  if( theverb[0..0] == "'" || theverb == "say" || theverb == "shout" ||
      theverb == "whisper" || theverb == "tell" )
    return call_other( BIN + "std_com", "main", str );
  if( theverb == "grunt" || theverb == "howl" || theverb = "growl" )
    return call_other( BIN + "barb_com", "main", str );
  if( theverb == "missile" || theverb == "shock" || theverb == "fireball" )
    notify_fail( "Barbarians cannot cast " + theverb + ".\n" );
  return 0;
}

void de_equip() {
    object *ai;
    int i,j;
    ai=all_inventory(E);
    j=sizeof(ai);
    for(i=0;i<j;i++) {
	if(ai[i]->query_armour() && ai[i]->query_worn()) {
	    E->stop_wearing(ai[i], 1);
	    if(ai[i]->short() && !ai[i]->query_worn())
		write("You remove " + (string)ai[i]->short() + ".\n");
	}
	if(ai[i]->query_weapon() && ai[i]->query_wielded()) {
	    E->stop_wielding(ai[i]);
	    if(ai[i]->short())
		write("You stop wielding " + (string)ai[i]->short() + ".\n");
	}
    }
}

int dont_wield(object ob) {
    return EQM || comb_soul;
}

/* Uglymouth edit: set_* and query_*'s added for use with bin command 
 *   structure; cannot address variables directly anymore.
 */
void set_combat_soul( object combat_soul_ob ) {
  comb_soul = combat_soul_ob;
}

void set_next_throw( object next, object next_ob ) {
  next_throw = next;
  next_throw_ob = next_ob;
}

object query_next_throw() {
  return next_throw;
}
/* End Uglymouth edit */

void time_guild_soul() {
    int w;
    string thrnm,monnm;
    if(comb_soul)
	comb_soul->heart();
    if(!next_throw || !next_throw_ob || !present(next_throw, E)
      || !present(next_throw_ob, ENV(E))) {
	next_throw=0;
	return;
    }
    if(next_throw->query_wielded())
	E->stop_wielding();
    if(next_throw->query_worn())
	E->stop_wearing(next_throw, 1);
    w=(int)next_throw->query_weight();
    thrnm=(string)next_throw->QN;
    if(!thrnm)
	thrnm=(string)next_throw->short();
    monnm=(string)next_throw_ob->QN;
    if(random((int)next_throw_ob->query_dex()) > (10 + random(w*4))
      && !transfer(next_throw, next_throw_ob)) {
	tell_object(E, lw("You throw " + thrnm + " at " + monnm + ", but " +
	    monnm + " catches it.\n"));
	tell_object(next_throw_ob, lw(EQN + " throws " + thrnm
	    + " at you, but you catch it.\n"));
	tell_all_but(next_throw_ob, lw(EQN + " throws " + thrnm + " at " + monnm
	    + ", but " + monnm + " catches it.\n"));
	next_throw=0;
	return;
    }
    tell_object(E, lw("You throw " + thrnm + " at " + monnm + ".\n"));
    tell_object(next_throw_ob, lw(EQN + " throws " + thrnm
	+ " at you. Ouch, that hurt!\n"));
    tell_all_but(next_throw_ob, lw(EQN + " throws " + thrnm + " at " + monnm
	+ ".\n"));
    w=w * (1 + (int)EGS("barbarian_combat")[0]/10);
    if(w>100)
	w=100;
    E->add_exp((int)next_throw_ob->hit_player(random(5)*w));
    transfer(next_throw, ENV(E));
    next_throw=0;
}

void tell_all_but(object ob, string msg) {
    object *to;
    int i;
    to=filter_array(all_inventory(ENV(E)), "tell_all_but_filter",
      this_object(), ob);
    for(i=0;i<sizeof(to);i++)
	tell_object(to[i], msg);
}

int tell_all_but_filter(object ob, object ob2) {
    return ob!=E && ob!=ob2;
}

int display_skills(){
    say(TP->query_name()+" grunts: Me skills are:\n");
}

void send_mess(string str) {
    int i,j;
    string *mess;
    object *u;
    u=filter_array(users(), "online_filter", this_object());
    for(i=0;i<sizeof(u);i++)
	tell_object(u[i], str);
}

int levelsort(object p1, object p2) {
    if((string)p1->QRN=="apollo") return 0;
    if((string)p2->QRN=="apollo") return 1;
    return (int)p1->QL < (int)p2->QL;
}

int gd_filter(object ob) {
    return (int)ob->query_guild()==11;
}

int online_filter(object ob) {
    return (int)ob->query_guild()==11 && !ob->queryenv("BARB_OFF");
}

string parse_string(string str) {
    mixed *parse;
    string tmp;
    int i,j,type;
    parse=({ ({}), ({}) });
    type=(str[i..i]>="A" && str[i..i]<="Z") || (str[i..i]>="a" &&
	str[i..i]<="z");
    if(!type)
	parse[1]+=({ "" });
    j=strlen(str);
    tmp="";
    for(i=0;i<j;i++) {
	if(type==((str[i..i]>="A" && str[i..i]<="Z")
	    || (str[i..i]>="a" && str[i..i]<="z")))
	    tmp+=str[i..i];
	else {
	    parse[type]+=({ tmp });
	    type=!type;
	    tmp=str[i..i];
	}
    }
    parse[type]+=({ tmp });
    if(sizeof(parse[0]) < sizeof(parse[1]))
	parse[0]+=({ "" });
    else
    if(sizeof(parse[1]) < sizeof(parse[0]))
	parse[1]+=({ "" });
    tmp="";
    j=sizeof(parse[0]);
    for(i=0;i<j;i++)
	tmp+=get_word(parse[1][i]) + parse[0][i];
    return tmp;
}

string get_word(string str) {
    switch(str) {
    case "I":    return "Me";   break;
    case "i":    return "me";   break;
    case "Am":   return "Is";   break;
    case "am":   return "is";   break;
    case "m":    return "s";    break;
    case "ve":   return "s";    break;
    case "My":   return "Me";   break;
    case "my":   return "me";   break;
    default:     return str;    break;
    }
}

/* Uglymouth: add code for removal of tattoo's and skills...
 */
void guild_changes() {
    object ob;
    while(ob=present("combat_soul", E))
	destruct(ob);
    shadow->remove_the_shadow();
    TP->start_at_guild(0);
    destruct(this_object());
}

