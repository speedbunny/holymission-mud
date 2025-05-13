/* Qclxxiv, copyright 1992, 1993 */
/* dont remove my name in any adaptation of this file please */
/* next include part is common for mud lpc object and c++ test program */
/*#include "/players/qclxxiv/qquest/qmast.1" */
/* included hard now: */

/* common part of qmast.c, and qmast.cxx (test on qmast.c) */
#include "c_lpc_diff.h"
#include "qq_active.h"

#define NR_LOCKS 12
#define OPERATORSEQ_LEN 4
#define NR_OPERATORS 12
#define MAX_KEYS NR_OPERATORS

int nr_locks;
int operatorseq_len;

#ifndef CXX
string nr_keys;
string operatorseqs;
init_arrays() {
	nr_keys = allocate(5);
	nr_keys =
#else
INT nr_keys[NR_LOCKS] =  
#endif
		ARRLBAR 6, 8, 9, 8, 10, 10, 14, 8, 8, 8, 8, 5 ARRRBAR;
#ifndef CXX
	operatorseqs = allocate(NR_OPERATORS);
	operatorseqs =
#else
CHARPTR operatorseqs[NR_OPERATORS] = 
#endif
		ARRLBAR "++++", "-+-+", "^^^^",
				 "^+-^", "^-+^", "^^+-",
				 "^^-+", "^+^-", "-^+^",
				 "++-^", "+-+^", "-++^"
		ARRRBAR;

/* operatorseqs have been hussled   so this is not really used in HolyM */
/* In each mud you can hussle them again:-) */
/* so a player will have different quest in your region in different mud */
#ifndef CXX
}
#endif

#ifdef CXX
VOID write( char* str) { printf( str ); }
CHARPTR lower_case( CHARPTR str ) {
	int t;
	for (t=0; t<strlen(str); t++) str[t] = tolower(str[t]);
	return str;
}
#endif

INT operat( INT lhs, CHAR Operator, INT rhs ) {
	switch( Operator ) {
		case '+' : return (lhs + rhs);
		case '-' : return (lhs - rhs);
		case '^' : return (lhs ^ rhs);
		default: write( "Illegal Operator char in operat().\n");
	}
	return -1;
}

/* given a locknr (subquestnr) (0..NR_LOCKS-1) and a name generates
// a keynumber for the lock/subquest-name comb. (0..nr_keys[locknr]-1)
*/
INT lock_name2key( INT locknr, CHARPTR name ) {
	int t, i, s, n;
	if (!QQ_ACTIVE) return -1;
	name = lower_case( name );
	if (locknr>=nr_locks) {
		write("Lock nr. too high in lock_name2key.\n");
		return -1;
	}
	t = i = s = 0;
	while ( (n = name[i]) ) {
		s = operat( s, operatorseqs[locknr][t], n );
		i++; 
		t = (t+1) % operatorseq_len;
	}
	if (s<0) s = -s;
	return s % nr_keys[locknr];
}

/* end of included part */


id(str) { return str == "qmast"; }
short() { return "The qmast"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }
init()  { 
	add_action("testname", "testname" ); 
}

reset(arg) {
	if (arg) return;
	nr_locks = NR_LOCKS;
	operatorseq_len = OPERATORSEQ_LEN;
	init_arrays();
}

testname( arg ) {
	int locknr;
	string name;
	if (sscanf(arg, "%d %s", locknr, name)==2) 
		write(lock_name2key(locknr, name)+"\n");
	else if (sscanf(arg, "%s", name)==1) {
		for (locknr=0; locknr<nr_locks; locknr++ ) 
			write(lock_name2key(locknr, name)+"\t");
		write("\n");
	}
	else write("usage: testname [locknr] <name>\n");
	return 1;
}
