string pretitle;

id(string str) {
	return(str=="test");
	}

init() {
	add_action("test","test");
	add_action("sett","sett");
}

sett(string str) {
	if(!str) str="";
	pretitle=str;
        if(str=="none") pretitle=0;
	return 1;
	}

test() {
	if(pretitle) write("There is a pretitle\n");
	if(!pretitle) write ("There is no pretitle\n");
	if(pretitle=="") write("The pretitle is an empty string\n");
	return 1;
}
