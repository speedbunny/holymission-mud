/* Qclxxiv's Jackpot   july, nov 1992
*/
#include "naming.h"
#define VERSION "4.0"
#define PLAYERNAME this_player()->query_name()
id(str) { return str == "jackpot"; }

string roll1, roll2, roll3;
int prizes1, prizes2, prizes3;
int pos1, pos2, pos3;
int rolllen;
int specialgain;
int factor;

set_factor(n) { factor = n; }

short() { return "a robust jackpot, model "+VERSION
						+"  -  "+factor+" coin type"; }
long()  { 
	int i, j;
	write(NAME+"'s jackpot machine. It has three rolls. Pays out GREAT!\n");
	write(
" ----------------------------------------------------------------------\n");
	write("            This is model "+VERSION +" - "+factor+" COIN TYPE.\n");
	write(
" ----------------------------------------------------------------------\n");
	i = 0;
	j = (rolllen/2);
	write( " | "
			  +roll1[i]+roll2[i]+roll3[i] + " : " + prizes3[i] + " | "
			  +roll1[j]+roll2[j]+roll3[j] + " : " + prizes3[j] + " | "
		      +roll1[i]+roll2[i]+" _ "    + " : " + prizes2[i] + " | "
		      +roll1[j]+roll2[j]+" _ "    + " : " + prizes2[j] + "  | "
			  +"\n" );
	for (i=1; i<(rolllen/2); i++) {
		j = i + (rolllen/2);
		write( " | "
			  +roll1[i]+roll2[i]+roll3[i] + " : " + prizes3[i] + "  | "
			  +roll1[j]+roll2[j]+roll3[j] + " : " + prizes3[j] + " | "
		      +roll1[i]+roll2[i]+" _ "    + " : " + prizes2[i] + "  | "
		      +roll1[j]+roll2[j]+" _ "    + " : " + prizes2[j] + "  | "
			  +"\n" );
	}
	write(" | "+roll1[rolllen-1]+" _  _  : "+prizes1[rolllen-1]+ 
		"           PRICES ARE PAID OUT MULTIPLIED BY STAKES.  |\n");
	write(
" ----------------------------------------------------------------------\n");
	write("   play / "+factor+" coins. >>>>> |" 
		+ roll1[pos1] + "|" + roll2[pos2] + "|" + roll3[pos3] +"| ");
	write("<<<<< Type: play jackpot.\n");
	write(
" ----------------------------------------------------------------------\n");
}

get()	{ return 0; }

reset(arg) {
	if (!arg) specialgain=50;
	else specialgain += 7;	/* starts at 50 */
	if (specialgain>200) specialgain=200;
	if (arg) return;
	factor = 100;
	return 1;
}

init()  { 
	rolllen = 10;
	roll1 = ({"*1*"," 7 ","BAR"," Q "," $ "," * ","  :"," ^ "," # "," % ",});
	roll2 = ({"*7*"," 7 ","BAR"," Q "," $ "," * "," = "," ^ "," # "," % ",});
	roll3 = ({"*4*"," 7 ","BAR"," Q "," $ "," * ",")  "," ^ "," # "," % ",});
	/* last field of rolls should be the kinf=d that gives prize at X-- */
/*
	prizes1=({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 });
	prizes2=({ 20, 12, 12, 10, 10, 8, 8, 5, 5, 4 });
	prizes3=({ 200, 120, 120, 100, 100, 80, 80, 50, 50, 10 });
*/    /* above yielded 193.6   rather than close to 100 %  miscalculated..*/
/* adjust to 99.9:    (not happy with     vv though  ought to be 2! */
	prizes1=({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 });  			/* *9/100 */
	prizes2=({ 10, 7, 6, 5, 5, 4, 4, 3, 2, 2 }); 	 		/* *9/1000 */
	prizes3=({ 100, 75, 60, 50, 50, 40, 40, 30, 20, 12 });  /* *1/1000 */
							/* 9/100 + 48*9/1000 + 477*1/1000 = 999/1000 */
	pos1 = 0;
	pos2 = 0;
	pos3 = 0;
	add_action("do_play", "play" );
}

do_play(str) {
	object ob;
	int gain, hascoin;
	if ((!str) || (str != "jackpot")) { return 0; }
	hascoin = 0;
	ob = first_inventory(this_player());
	while(ob) {
		if (call_other(ob,"id","q174silvercoin")) {
			hascoin = 1;
			if (factor!=100)
				write("Try the silver coin in a 100 coin type jackpot.\n");
			break;
		}
		ob = next_inventory(ob);
	}
		
	if (hascoin && factor==100) {
		destruct(ob);
		write("You throw in the silver 100 coin piece.\n" );
		write("You just won the special jackpot.\n" );
		write("The rolls stop at: |" 
			+ "*JA" + "|" + "CKP" + "|" + "OT*"+"|.\n");
    	say(PLAYERNAME+" plays the jackpot, the rolls stop at: |"
			+ "*JA" + "|" + "CKP" + "|" + "OT*"+"|.\n");
		say("That's the special jackpot!\n" );
		gain = specialgain;
		specialgain = 50;  /* next jackpot is minimum again */
	}
	else
	{
		if ( this_player()->query_money() < factor ) {
			write("You don't have "+factor+" coins.\n");
			return 0;
		}
		if (PLAYERNAME!=IFULLNAME) 
    		this_player()->add_money(-factor); /* testing got too expensive:-)*/
		pos1 += random(rolllen);
		pos2 += random(rolllen);
		pos3 += random(rolllen);
		pos1 = pos1 % rolllen;
		pos2 = pos2 % rolllen;
		pos3 = pos3 % rolllen;
		if (PLAYERNAME==IFULLNAME) 
			if (random(7)==0) { pos1 = 0; pos2 = 0; pos3 = 0; }
		write("The rolls stop at: |" 
			+ roll1[pos1] + "|" + roll2[pos2] + "|" + roll3[pos3] +"|.\n");
    	say(PLAYERNAME+" plays the jackpot, the rolls stop at: |"
			+ roll1[pos1] + "|" + roll2[pos2] + "|" + roll3[pos3] +"|.\n");
		gain = 0; 
		if ((pos1==pos2) && (pos2==pos3)) 
			gain = prizes3[pos1];
		else if (pos1==pos2) 
			gain = prizes2[pos1];
		else gain = prizes1[pos1];
	}
	if (gain>0) {
		if (factor) {
			gain = gain*factor;
    		this_player()->add_money(gain);
			write("You just won " + gain + " coins.\n");
			say("" + PLAYERNAME + " just won " + gain + " coins.\n");
		}
		else {
			write( "You just won "+gain
				+" times your stakes, which was 0. You gain 0 coins.\n");
 			at_0_prize( this_player() );
		}
	}
	return 1;
}

at_0_prize(tp) { }
