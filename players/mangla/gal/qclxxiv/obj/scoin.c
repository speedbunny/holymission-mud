id(str) { return str == "silver coin" || str == "coin" 
				|| str == "q174silvercoin"; }
short() { return "A silver coin"; }
long()  { write("A silver 100 coin piece\n"); }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 100; }

