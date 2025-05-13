/* ____________________________________________________________________________
 
Thanks to Blackmoon, for some useful routines!
(especially the saveroutine for the adverbs...)
 
______________________________________________________________________________
*/
/* ____________________________________________________________________________
 
	EXTENDED SOUL, Copyright by: Ereborn, the Master of Mirkwood
 
	Please do NOT change without asking me.
	For questions ask: ereborn@opal.cs.tu-berlin.de
 
	Latest Change: 15.04.1993
        Ethereal Cashimor: Some pronouns repaired, which had a hardcoded
                           gender.
 
______________________________________________________________________________
*/
 
#define ADV   60
#define ABR_BEG 50
#define CREATOR_DIR "/tools/exsoul/exsoul"
#define SOULROOM "/tools/exsoul/soulroom"
#define FEELINGS "/tools/exsoul/feelings.c"
#define EMOTE "/tools/exsoul/emote.c"
#define DOC1 "/tools/exsoul/exsoul.doc1"
#define DOC2 "/tools/exsoul/exsoul.doc2"
#define DOC3 "/tools/exsoul/exsoul.doc3"
 
 
object me, soulroom, glob_who;
string cap_name, his, him, title;
int trites, wshout_enable, hide;
string advlist, abrlist;
string glob_adv, glob_per;
#include EMOTE
#include FEELINGS
 
 
reset(arg) {
	if (arg) {
		call_out("dest_oldsoul", 2, this_object());
	    return 1;
	}
	if (!arg) {
		trites=1;
		soulroom = find_object(SOULROOM);
		advlist = allocate(ADV);
		abrlist = allocate(ADV);
		set_adv();
		call_out("dest_oldsoul", 2, this_object());
		return;
	}
}
 
set_trite(str) {
	if (str!="on" && str!="off") return 0;
	if (str=="on") {
		write("The standard adverbs are now enabled.\n");
		trites=1;
		return 1;
	}
	write("The standard adverbs are now disabled.\n");
	trites=0;
	return 1;
}
is_soul() {
	return 2301;
	/* My test routine, if this is one of my souls... */
}
init_arg(str) {
    string temp, temp2;
    int i;
    string abbrev, adverbs;
 
    sscanf(str,"%dex_var_hide%s",hide, temp2);
    if (!temp2) return 0;
    temp=explode(temp2, ";");
 
    for (i=0; i<sizeof(temp); i++)
	{
	if (!temp[i])
	    return 0;
	if (sscanf(temp[i], "%s#%s", adverbs, abbrev)!=2) {
	    say ("ERROR while reading abreviations (exsoul)!\n");
	    return 999;
	}
	abrlist[ABR_BEG + i] = abbrev;
	advlist[ABR_BEG + i] = adverbs;
    }
    return 0;
}
 
query_auto_load() {
    int i;
    string temp;
 
    temp="";
    for (i=ABR_BEG; (i<sizeof(abrlist)) && (abrlist[i]!="xxx"); i++) {
	temp=temp+advlist[i]+"#"+abrlist[i]+";";
    }
    return CREATOR_DIR+":"+hide+"ex_var_hide"+temp;
}
get() {
    me = this_player();
    cap_name = call_other(this_player(), "query_name", 0);
/*  if (title) cap_name = capitalize(title) + " " + cap_name; */
    return 1;
}
destroy(str) {
object oldsoul;
	if (str!="extended soul" && str!="exsoul" && str!="nsoul")
		return 0;
	oldsoul=clone_object("obj/soul");
	move_object(oldsoul, environment(this_object()));
	write("Original soul reinstalled...\n");
	write("Extended soul removed...\n");
	write("Done. If you want to repurchase it, go to the shop in Mirkwood!\n");
	destruct(this_object());
	return 1;
}
 
id(str) {
    return str=="extended soul" || str=="exsoul" || str=="exsoul";
}
 
long() {
	cat(DOC1);
}
 
helpfeel(str) {
    if (id(str)) {
	cat(DOC1);
	return 1;
    }
    if (str=="exsoul page 2") {
	cat(DOC2);
	return 1;
    }
    if (str=="exsoul page 3") {
	cat(DOC3);
	return 1;
    }
    if (str=="feelings") {
	disp_verb();
	return 1;
    }
	return 0;
}
 
 
short() {
	if (hide) return;
	if (environment(this_object())->query_real_name())
	return capitalize(environment(this_object())->query_real_name())
	    + "'s extended soul";
	else return "an extended soul";
}
 
drop(silently) {
	if (query_verb()=="quit") return 1;
	  if (!silently) {
		write("It is not prepared for drop. " +
		"Type 'destroy exsoul' to destroy it.\n");
	} /* silently */
	return 1;
}
 
ghost() {
string verb;
	verb=query_verb();
	soulroom = find_object(SOULROOM);
	if (soulroom)
	soulroom->add_usage(verb);
	if (this_player()->query_level() > 19)  {
		if (soulroom) soulroom->add_wusage(verb);
	}
	me = this_player();
	his = me->query_possessive();
	him = me->query_objective();
    cap_name = me->query_name();
/*
    if (living(this_player())) {
	if (this_player()->query_pretitle())
		title=this_player()->query_pretitle();
	else title=0;
    }
    if (title) cap_name = capitalize(title) + " " + cap_name;
 
    return call_other(me, "query_ghost");
*/
}
frog() {
	return call_other(this_player(), "query_frog");
}
 
init() {
    if(this_player() !=environment()) return 0;
	me = this_player();
	call_out("dest_oldsoul", 2, this_object());
	cap_name = me->query_name();
		/* COMMANDS */
	add_action("disp_users", "exusers");
	add_action("disp_adv", 	"adverb");
	add_action("disp_adv", 	"adverbs");
	add_action("disp_verb", "verb");
	add_action("disp_verb", "verbs");
	add_action("set_trite", "standard");
	add_action("destroy", 	"destroy");
	add_action("helpfeel", 	"help");
	add_action("hide", "hide");	/* Make the soul invisible */
	add_action("show", "show");	/* Make it visible again */
		/* FEELINGS */
 
	add_action("admire", 	"admire");
	add_action("apologize", "apologize");
	add_action("applaud", 	"applaud");
	add_action("bang", 	"bang");
	add_action("trite", 	"blush");
	add_action("trite", 	"bounce");
	add_action("bow", 	"bow");
	add_action("trite", 	"burp");
	add_action("trite", 	"cackle");
	add_action("trite", 	"chuckle");
	add_action("trite", 	"clap");
	add_action("trite", 	"cheer");
	add_action("comfort", 	"comfort");
	add_action("complain", 	"complain");
	add_action("trite", 	"cough");
	add_action("trite", 	"cry");
	add_action("cuddle", 	"cuddle");
/*	add_action("curse", 	"curse");      */
	add_action("curtsey", 	"curtsey");
	add_action("dance", 	"dance");
        add_action("trite",	"die");
	add_action("excuse",	"excuse");
	add_action("fail", 	"fail");
	add_action("trite", 	"fart");
/*	add_action("fear", 	"fear");   */
/*	add_action("finger", 	"finger"); */
	add_action("trite", 	"flip");
	add_action("fondle", 	"fondle");
	add_action("french", 	"french");
	add_action("tog_frog", 	"frog");
	add_action("trite", 	"frown");
	add_action("trite", 	"gasp");
	add_action("trite", 	"giggle");
	add_action("glare", 	"glare");
	add_action("trite", 	"grin");
	add_action("trite", 	"groan");
	add_action("grope", 	"grope");
	add_action("verb_adv_at_per", "growl");
	add_action("trite", 	"hiccup");
	add_action("hug", 	"hug");
	add_action("ignore", 	"ignore");
	add_action("kick", 	"kick");
	add_action("kiss", 	"kiss");
	add_action("knee", 	"knee");
	add_action("trite", 	"laugh");
	add_action("lick", 	"lick");
	add_action("look", 	"look");
	add_action("love", 	"love");
	add_action("emo", 	"me");
	add_action("mercy", 	"mercy");
	add_action("trite", 	"moan");
	add_action("nibble", 	"nibble");
	add_action("no", 	"no");
	add_action("trite", 	"nod");
	add_action("nose", 	"nose");
	add_action("pale", 	"pale");
	add_action("pat", 	"pat");
	add_action("trite", 	"point");
	add_action("poke", 	"poke");
	add_action("trite", 	"pout");
	add_action("puke", 	"puke");
	add_action("praise", 	"praise");
	add_action("trite", 	"protest");
	add_action("trite", 	"purr");
	add_action("puzzle", 	"puzzle");
	add_action("relax", 	"relax");
	add_action("roll",	"roll");
	add_action("ruffle", 	"ruffle");
	add_action("scratch", 	"scratch");
	add_action("trite", 	"scream");
	add_action("shake", 	"shake");
	add_action("shame", 	"shame");
	add_action("shiver", 	"shiver");
	add_action("trite", 	"shrug");
	add_action("trite", 	"sigh");
	add_action("sing", 	"sing");
	add_action("slap", 	"slap");
	add_action("trite", 	"smile");
	add_action("verb_adv", 	"smirk");
	add_action("snap", 	"snap");
	add_action("trite", 	"sneeze");
	add_action("verb_adv",  "snicker");
	add_action("verb_adv", 	"sniff");
	add_action("trite", 	"snore");
	add_action("snuggle", 	"snuggle");
	add_action("verb_adv", 	"sob");
	add_action("spit", 	"spit");
	add_action("squeeze", 	"squeeze");
	add_action("stare", 	"stare");
	add_action("trite", 	"strut");
	add_action("sulk", 	"sulk");
	add_action("sweat", 	"sweat");
        add_action("trite",	"tap");
	add_action("thank", 	"thank");
	add_action("throat", 	"throat");
	add_action("tickle", 	"tickle");
	add_action("tongue", 	"tongue");
	add_action("twiddle", 	"twiddle");
	add_action("trite", 	"wait");
	add_action("wave", 	"wave");
	add_action("trite", 	"whistle");
	add_action("wiggle", 	"wiggle");
	add_action("wink", 	"wink");
	add_action("wipe", 	"wipe");
	add_action("trite", 	"yawn");
}
 
 
 
verb_adv_at_per(str, split) {
string adv, per, verb; object who; int i;
    verb=query_verb();
    if (!split) split = " at ";
    ghost();
    if (!str) {
	write("You " + verb + ".\n");
	say(cap_name + " " + verb + "s.\n");
	return 1;
    }
    i=pers_verb(str);
    if (i<1) return 0;
    adv=glob_adv; per=glob_per; who=glob_who;
    if (i==1) {
        write("You " + verb + " " + adv +".\n");
        say(cap_name + " " + verb + "s " + adv + ".\n");
        return 1;
    }
    if (i==2) {
        write("You " + verb + split + per +".\n");
        say(cap_name + " " + verb + "s" + split + per +".\n",who);
        tell_object(who, cap_name + " " + verb + "s" + split + "you.\n");
		return 1;
	}
    if (i==3) {
        write("You " + adv + " " + verb + split + per +".\n");
        say(cap_name + " " + adv + " " + verb + "s" + split
			+ per +".\n",who);
        tell_object(who, cap_name + " " + adv + " " + verb + "s" + split +
			"you.\n");
		return 1;
    }
}
 
verb_adv(str) {
    object who;
    string verb, adv, gadv;
    verb=query_verb();
    ghost();
    if (!str) {
	write("You " + verb + ".\n");
	if (verb=="blush") verb="blushe";
	say(cap_name + " " + verb + "s.\n");
	return 1;
    }
    if (sscanf(str, "%s %s", gadv, adv) ==2) {
	write("This verb is 'verb adverb' only. Please enter only one"+
		" adverb.\n");
	return 1;
    }
    adv=get_adv(str);
    if (!adv) {
	write("Sorry, but I don't know the adverb for " + str + ".\n");
	return 1;
    }
    write("You " + verb + " " + adv + ".\n");
		if (verb=="blush") verb="blushe";
    say(cap_name + " " + verb + "s " + adv + ".\n");
    return 1;
}
 
 
pron(ob) {
	if (ob->query_gender()==1) return "him";
	if (ob->query_gender()==2) return "her";
	return "it";
}
 
set_adv() {
int i;
 
	for (i=0; i<sizeof(advlist); i++) {
	    advlist[i]="unused";	abrlist[i]="xxx";
	}
	advlist=({ 	"amusedly",		"angrily",
			"appreciatively",	"badly",
			"bitterly",		"broadly",
			"charmingly",		"coldly",
			"contemptuously",	"contentedly",
			"dangerously",		"deeply",
			"demonically",		"dirtily",
			"dreamily",		"evilly",
			"firmly",		"friendly",
			"gleefully",		"happily",
			"hopefully",		"inanely",
			"in astonishment",	"impatiently",
			"innocently",		"inwardly",
			"ironically",		"knowingly",
			"longingly",		"loudly",
			"lovingly",		"merrily",
			"naturally",		"patiently",
			"perfectly",		"politely",
			"proudly",		"questioningly",
			"quickly",		"rudely",
			"sadly",		"seductively",
			"seriously",		"shamelessly",
			"slowly",		"softly",
			"tenderly",		"tightly",
			"wholeheartedly",	"wickedly",
			"unused", 		"unused",
			"unused",               "unused",
			"unused",               "unused",
			"unused",               "unused",
			"unused",               "unused" });
 
	abrlist=({	"amu","ang","app","bad","bit","bro","cha","col",
			"con","ctd","dan","dee","dem","dir","dre","evi",
			"fir","fri","gle","hap","hop","ina","ast","imp",
			"inn","inw","iro","kno","lon","lou","lov","mer",
			"nat","pat","per","pol","pro","que","qui","rud",
			"sad","sed","ser","sha","slo","sof","ten","tig",
			"who","wic","xxx","xxx","xxx","xxx","xxx","xxx",
			"xxx","xxx","xxx","xxx" });
	return;
}
 
disp_adv(str) {
int i;
 if(str) {
	add_adv(str);
	return 1;
 }
 write("Adverbs___________Abrev. Adverbs___________Abrev. Adverbs");
    write("___________Abrev.\n");
    for (i=0; i<((ADV/3)); i++) {
	write(extract(advlist[i] + "_________________", 0, 17) +
	    extract(abrlist[i] + "      ", 0, 5) + " ");
	write(extract(advlist[i+20] + "_________________", 0, 17) +
	    extract(abrlist[i+20] + "      ", 0, 5) + " ");
	write(extract(advlist[i+40] + "_________________", 0, 17) +
	    extract(abrlist[i+40] + "      ", 0, 5) + "\n");
    }
    return 1;
}
 
add_adv(str) {
int i, j;
string dummy1, dummy2;
string abr, adv;
    if (sscanf(str, "%s %s", abr, adv)!=2) {
	i = member_array(str, abrlist);
	if (i<0) {
	    write("No abreviation found for " + str + ".\n");
	    write("Usage: 'adverb <abreviation> <adverb>' to add an abreviation.\n");
	    write("   or: 'adverb <abreviation>' to erase abreviation.\n");
	    return 1;
	}
	if (i<ABR_BEG) {
		write("You cannot change the standard adverbs.\n");
		return 1;
	}
	write("Removed abreviation " + abrlist[i] + ", removed adverb "
		+ advlist[i] + ".\n");
	if (i==ADV-1) {
		abrlist[i]="xxx"; advlist[i]="unused";
		return 1;
	}
	for (j=i+1; j<sizeof(abrlist) && abrlist[j]!="xxx"; j++) {
	    abrlist[j-1]=abrlist[j];
	    advlist[j-1]=advlist[j];
	}
	abrlist[sizeof(abrlist)-1]="xxx";
	advlist[sizeof(advlist)-1]="unused";
	if (j<sizeof(abrlist)) {
	    abrlist[j-1]="xxx";
	    advlist[j-1]="unused";
	}
	return 1;
    }
    if (strlen(abr) > 6 ) {
	write("Abreviation too long! 6 letters maximum.\n");
	return 1;
    }
    if (abr=="xxx" ||
	adv=="unused" ||
	sscanf (adv, "%s#%s", dummy1, dummy2) ==2     ||
	sscanf (adv, "%s;%s", dummy1, dummy2) ==2     ||
	sscanf (abr, "%s#%s", dummy1, dummy2) ==2     ||
	sscanf (abr, "%s;%s", dummy1, dummy2) ==2)
	{
	write("Illegal character: Neither 'xxx' nor '#' nor ';' allowed"
		+ " in adverbs or abreviations.\n");
	return 1;
	}
    i=member_array(abr, abrlist);
    if (i>-1) {
	if (i<ABR_BEG)
	    {
	    write ("No change of standard adverbs!\n");
	    return 1;
	    }
	write("Changing adverb for " + abrlist[i] + " to " +
		adv + ".\n");
	advlist[i]=adv;
	return 1;
    }
    i=member_array(adv, advlist);
    if (i>-1) {
	if (i<ABR_BEG)
	    {
	    write("No change of standard adverbs!\n");
	    return 1;
	    }
	write("Changing abreviation for " + adv + " to " +
		abr + ".\n");
	abrlist[i]=abr;
	return 1;
    }
    i= member_array("xxx", abrlist);
    if (i<0) {
	write("Sorry, but the adverb table is full." +
	      " Remove an old one first.\n");
	return 1;
    }
    abrlist[i] = abr;
    advlist[i] = adv;
    write("Done.\n");
    return 1;
}
get_adv(str) {
    int index;
 
    index = member_array(str, abrlist);
    if (index<0) {
	index = member_array(str, advlist);
	if (index<0) return 0;
	return advlist[index];
    }
    if (str=="xxx" || advlist[index]=="unused") return 0;
    return advlist[index];
}
 
 
trite(str) {
string verb;
    verb=query_verb();
    ghost();
    if (str || !trites) {
	if(verb=="giggle")	return(verb_adv_at_per(str));
	if (verb=="grin")	return(verb_adv_at_per(str));
	if (verb=="laugh")	return(verb_adv_at_per(str));
	if(verb=="point")	return(verb_adv_at_per(str));
	if (verb=="scream")	return(verb_adv_at_per(str));
	if (verb=="smile")	return(verb_adv_at_per(str));
	if (verb=="whistle")	return(verb_adv_at_per(str));
	if (verb=="blush")	verb_adv(str);
	if (verb=="bounce")	verb_adv(str);
	if (verb=="burp")	verb_adv(str);
	if (verb=="cackle")	verb_adv(str);
	if (verb=="cheer")	verb_adv(str);
	if (verb=="chuckle")	verb_adv(str);
	if (verb=="clap")	verb_adv(str);
	if (verb=="cough")	verb_adv(str);
	if (verb=="cry")	verb_adv(str);
	if (verb=="fart")	verb_adv(str);
	if (verb=="flip")	verb_adv(str);
	if (verb=="frown")	verb_adv(str);
	if (verb=="gasp")	verb_adv(str);
	if (verb=="groan")	verb_adv(str);
	if (verb=="hiccup")	verb_adv(str);
	if (verb=="moan") 	verb_adv(str);
	if (verb=="nod") 	return(verb_adv_at_per(str));
	if (verb=="pout") 	verb_adv(str);
	if (verb=="protest")	verb_adv(str);
	if (verb=="purr")	verb_adv(str);
	if (verb=="shrug")	verb_adv(str);
	if (verb=="sigh")	verb_adv(str);
	if (verb=="sneeze")	verb_adv(str);
	if (verb=="snore")	verb_adv(str);
	if (verb=="strut")	verb_adv(str);
	if (verb=="sweat")	verb_adv(str);
	if (verb=="tap") 	return(verb_adv_at_per(str));
	if (verb=="wait")	verb_adv(str);
	if (verb=="yawn")	verb_adv(str);
	return 1;
    }
    if (verb=="blush") {
	write("Your cheeks are burning.\n");
	say(cap_name + " blushes.\n");
	return 1;
    }
    if (verb=="bounce") {
	write("B O I N G !! You bounce around.\n");
	say(cap_name + " bounces around.\n");
	return 1;
    }
    if (verb=="burp") {
	write("Excuse yourself! You burp rudely.\n");
	say(cap_name + " burps rudely.\n");
	return 1;
    }
    if (verb=="cackle") {
	write("You cackle gleefully.\n");
	say(cap_name + " throws " + his + " head back " +
	    "and cackles with glee!\n");
	return 1;
    }
    if (verb=="cheer") {
	write("You cheer enthusiastically.\n");
	say(cap_name + " cheers enthusiastically.\n");
	return 1;
    }
    if (verb=="chuckle") {
	write("You chuckle politely.\n");
	say(cap_name + " chuckles politely.\n");
	return 1;
    }
    if (verb=="clap") {
	write("You clap briefly.\n");
	say(cap_name + " claps briefly.\n");
	return 1;
    }
    if (verb=="cough") {
	write("Cover your mouth when you do that! You cough noisily.\n");
	say(cap_name + " coughs noisily.\n");
	return 1;
    }
    if (verb=="cry") {
	write("Waaaaah! You burst into tears.\n");
	say(cap_name + " bursts into tears.\n");
	return 1;
    }
    if (verb=="die") {
       write("You act dead.\n");
       say(cap_name+ " does "+this_player()->query_possessive()
         + " best to look dead.\n");
       return 1;
    }
    if (verb=="fart") {
	write("How rude! You let off a real rip-roarer.\n");
	say(cap_name + " lets of a real rip_roarer.\n");
	return 1;
    }
    if (verb=="flip") {
	write("You flip head over heels.\n");
	say(cap_name + " flips head over heels.\n");
	return 1;
    }
    if (verb=="frown") {
	write("Is something wrong? You frown.\n");
	say(cap_name + " frowns.\n");
	return 1;
    }
    if (verb=="gasp") {
	write("You gasp in astonishment.\n");
	say(cap_name + " gasps in astonishment!\n");
	return 1;
    }
    if (verb=="giggle") {
	write("You giggle inanely.\n");
	say(cap_name + " giggles inanely.\n");
	return 1;
    }
    if (verb=="grin") {
	write("You grin evilly.\n");
	say(cap_name + " grins evilly.\n");
	return 1;
    }
    if (verb=="groan") {
	write("You groan loudly.\n");
	say(cap_name + " groans loudly.\n");
	return 1;
    }
    if (verb=="hiccup") {
	write("Hic! You hiccup.\n");
	say(cap_name + " hiccups.\n");
	return 1;
    }
    if (verb=="laugh") {
	write("You fall down laughing.\n");
	say(cap_name + " falls down laughing.\n");
	return 1;
    }
    if (verb=="moan") {
	write("You start to moan.\n");
	say(cap_name + " starts moaning.\n");
	return 1;
    }
    if (verb=="nod") {
	write("You nod solemnly.\n");
	say(cap_name + " nods solemnly.\n");
	return 1;
    }
    if (verb=="point") {
	write("You point at the sky.\n");
	say(cap_name + " points at the sky.\n");
	return 1;
    }
    if (verb=="pout") {
	write("Ah, don't take it so hard. You pout.\n");
	say(cap_name + " pouts.\n");
	return 1;
    }
    if (verb=="protest") {
	write("You protest.\n");
	say(cap_name + " protests!\n");
	return 1;
    }
    if (verb=="purr") {
	write("MMMMEEEEEEEEOOOOOOOWWWWWWW! You purr contentedly.\n");
	say(cap_name + " purrs contentedly.\n");
	return 1;
    }
    if (verb=="scream") {
	write("ARRGGGGGGHHHHHH!!!! You scream loudly.\n");
	say(cap_name + " screams loudly!\n");
	return 1;
    }
    if (verb=="shrug") {
	write("You shrug helplessly.\n");
	say(cap_name + " shrugs helplessly.\n");
	return 1;
    }
    if (verb=="sigh") {
	write("You sigh deeply.\n");
	say(cap_name + " sighs deeply.\n");
	return 1;
    }
    if (verb=="smile") {
	write("You smile happily.\n");
	say(cap_name + " smiles happily.\n");
	return 1;
    }
    if (verb=="sneeze") {
	write("Gazundheit! You sneeze.\n");
	say(cap_name + " sneezes.\n");
	return 1;
    }
    if (verb=="snore") {
	write("Zzzzzzzzzzz... You snore loudly.\n");
	say(cap_name + " snores loudly.\n");
	return 1;
    }
    if (verb=="strut") {
	write("Strut your stuff! You strut proudly.\n");
	say(cap_name + " struts proudly.\n");
	return 1;
    }
    if (verb=="sweat") {
	write("You sweat like a palatinian brook cow.\n");
	say(cap_name + " sweats like a palatinian brook cow.\n");
	return 1;
    }
    if (verb=="tap") {
       write("You tap your foot impatiently on the ground.\n");
       say(cap_name + " taps "+this_player()->query_possessive()
         + " foot impatiently on the ground.\n");
       return 1;
    }
    if (verb=="wait") {
	write("You wait patiently...\n");
	say(cap_name + " waits patiently...\n");
	return 1;
    }
    if (verb=="whistle") {
	write("You whistle appreciatively.\n");
	say(cap_name + " whistles appreciatively.\n");
	return 1;
    }
    if (verb=="yawn") {
	write("My, what big teeth you have! You yawn.\n");
	say(cap_name + " yawns.\n");
	return 1;
    }
}
no_ab() {
	write("No such abreviation found.\n");
	return 1;
}
 
dest_oldsoul(ob) {
object soul, dest;
object obj;
    if (!environment(ob)) return 0;
    for (obj=first_inventory(environment(ob)); obj; obj=next_inventory(obj)) {
	if ((obj->id("soul") || obj->id("exsoul")) && (obj!=this_object()) ) {
	    if (me->query_wizard())
		tell_object(me,
		"Old soul found and replaced by the extended soul.\n");
	    dest=obj;
	    destruct(dest);
	    obj=first_inventory(environment(ob));
	}
    }
    return 1;
}
 
pers_verb(str, split) {
string d1, d2, adv;
object per;
 
glob_adv=0;
glob_per=0;
glob_who=0;
	if (!split) split=" ";
	if (sscanf(str, "%s" + split + "%s", d1, d2)==2) {
		adv=get_adv(d2);
		if (!adv) return 0;
		per=present(d1, environment(me));
		if (!per || !living(per)) return 0; /* Moonchild 021192 */
		glob_adv=adv;
/*		if (!living(per)) glob_per=lower_case(per->short()); */
		glob_per=capitalize(per->query_name());
		glob_who=per;
		return 3;
	}
	adv=get_adv(str);
	if (adv) {
		glob_adv=adv;
		return 1;
	}
	per=present(str, environment(me));
	if (per) {
		if (!living(per)) glob_per=lower_case(per->short());
		else
			glob_per=capitalize(per->query_name());
		glob_who=per;	
		return 2;
	}
	return 0;
}
 
disp_verb() {
 
    soulroom = find_object(SOULROOM);
    if (soulroom)	{
		soulroom->disp_verbs();
		return 1;
	}
	write("Sorry, there has to be a bug fixed. Sorry, for the inconvenience.\n");
	return 1;
}
 
disp_users() {
int i;
int sum;
object players;
	if (!this_player()->query_wizard()) return 0;
	players=users();
	sum=0;
	for (i=0; i<sizeof(players); i++) {
	    write("User: ");
	    write(extract(capitalize(players[i]->query_real_name())
		+ "______________________", 0,10));
	    write(extract("(" + players[i]->query_level() + ")   ", 0, 4));
		
	    if (present("exsoul", players[i])) {
		write(" - extended soul\n");
		sum++;
	    }
	    else {
		write(" - other device\n");
	    }
	}
	write("Players: " + sizeof(players));
	write("   Exsoul-users: " + sum + "\n");
	return 1;
}
 
set_presay(str) {
	title = str;
	if (!str) title=0;
	return 1;
}
 
query_presay() {
	return title;
}
 
hide(str) {
	if (!id(str)) return 0;
	if (hide) {
	    write("But is IS already hidden.\n");
	    return 1;
	}
	hide = 1;
	write("Your extended soul is now hidden in your inventory.\n");
	write("To make it visible again, type 'show exsoul'.\n");
	return 1;
}
show(str) {
	if (!id(str)) return 0;
	if (!hide) {
	    write("But it IS visible.\n");
	    return 1;
	}
	hide = 0;
	write("You extended soul is now visible, again.\n");
	return 1;
}
