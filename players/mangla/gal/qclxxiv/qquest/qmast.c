#include "/players/qclxxiv/qquest/qmast.1"

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
