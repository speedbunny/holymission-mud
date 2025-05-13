/* some patches for string handling */

string upperchars;
string uppertemp;

reset(arg) {
	if (arg) return;
	upperchars = ({" ", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", 
		",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", 
		"8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", 
		"D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", 
		"P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", 
		"\\", "]", "^", "_", "`", "A", "B", "C", "D", "E", "F", "G", 
		"H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", 
		"T", "U", "V", "W", "X", "Y", "Z", "{", "|", "}", "~", ""
	});

}

uppercase(arg) { return upper_case(arg); }

upper_case(arg) {
	int t; t=0;
	if (stringp(arg)) {
		uppertemp = "";
		while (arg[t]!=0) {
			uppertemp += upperchars[ arg[t] - 32];
			t++;
		}
		return uppertemp;
	}
	return 0;
}

/* sizeof_str is obsolete...strlen happened to be there after all:-) */
sizeof_str(str) {
	int t;
	t = 0;
	while (str[t++]!=0);
	return t-1;
}
