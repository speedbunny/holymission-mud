id(str) { return str == "gold bar" || str == "bar" 
				|| str == "q174goldbar"; }
short() { return "A gold bar"; }
long() {  write("A gold bar. It looks heavy and very valuable.\n"); }
get()	{ return 1; }
query_weight() { return 5; }
query_value() { return 7000; }

