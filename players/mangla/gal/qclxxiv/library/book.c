string bookfile;
string page;
string shelfcolor; /* so librarian can put it back if set */
int npages;			/* first bookline shoudl contain nr. pages + lines/page */
int linesperpage;
int nlines; /* total lines in book */
int maxlines;

int pageno, opened;	
int firstopened; /* if firstopened == 0 the book has not yet been opened */
string covertext, color;
int secretpage, secretkey, secretlock;
string openfind;
int open2dest;

get()	{ return 1; }
query_weight() { return 0; }	/* had to make it 0 cuz of librarian bug */
query_value() { return 1; }

set_openfind(s) {openfind = s; }
set_secretpage(i) { secretpage=i; }
set_secretkey(i) { secretkey=i; }
set_secretlock(i) { secretlock=i; }
set_color(str) { color = str; }
set_covertext(str) { covertext = str; }
set_maxlines(i) { maxlines = i; }
set_bookfile(name) {bookfile = name; }	/* use this XOR next func */
set_pages(arrofstr) { 
	page = arrofstr;
	nlines = npages = sizeof(arrofstr); 
	linesperpage = 1;
}
set_open2dest(i) { open2dest = i; }
set_shelfcolor(s) { shelfcolor = s; }
query_shelfcolor() { return shelfcolor; }

reset(arg) {
	if (arg) return;
	firstopened = 0;   /* so open knows it still has to read file */
	nlines = npages = 0;
	maxlines = 100;
	linesperpage=1;	/* for array-defined use. Normally higher with file use */
	covertext = "U.N.Known - A dummy book.\n";
	color = "red";
	secretpage = -1;
}

id(str) { return str=="book" || str == color+" book" || str == "qlib_book"; }

/*
short() { return "A "+color+" book: "+covertext; }
long() { 
	if (!opened) write("A "+color+" book. On its cover you read:\n"+covertext);
	else write( short()+". It lies open on some page.\n");
}
*/
short() { return "A "+color+" book"; }
long() { 
	if (!opened) write("A "+color+" book. On its cover you read:\n"+covertext);
	else write( short()+". It lies open on some page.\n");
}

init() {
	add_action("read","read");
	add_action("turn","turn");
	add_action("open","open");
	add_action("close","close");
	add_action("exa", "examine");
	add_action("exa", "exa");
	add_action("look", "look");
}

look(arg) {
	if (!opened || arg!="at page") return 0;
	write("A page with some text written on it.\n");
	return 1;
}

exa(arg) {
	if (!opened || arg!="page") return 0;
	write("A page with some text written on it.\n");
	return 1;
}

read(arg) {
	if (arg=="cover") {
		write("On the cover you read:\n"+covertext);
		return 1;
	}
	if (!id(arg) && arg!="page") return 0;
	if (environment(this_object())!=this_player()) return 0;
	if (!opened) write("The book is closed.\n");
	else if (pageno==secretpage) {
		/* if ....! lock-key-player match */
		if ( "/players/qclxxiv/qquest/qmast"->lock_name2key(secretlock,
					this_player()->query_real_name()) == secretkey )
			writepage(pageno);
		else write("The entire page is unreadable to you.\n");
	}
	else writepage(pageno);
	return 1;
}

writepage(i) {
	int first, last, n;
	first= i*linesperpage;
	last= first+ linesperpage - 1;
	for (n=first; n<=last; n++)
		write(page[n]+"\n");
}

turn(arg) {
	if (arg=="back" || arg=="page back" || arg=="back page") {
		if (environment(this_object()) != this_player()) return 0;
		if (!opened) {
			write("The book is closed.\n");
			return 1;
		}
		if (pageno==0) 
			write("You reach the cover, and turn back to the first page.\n");
		else {
			pageno--;
			write("You turn to the previous page.\n");
		}
		say(this_player()->query_name()+" pages through a book.\n",
				this_player());
		return 1;
	}
	if (arg=="page" || arg=="page over") {
		if (environment(this_object()) != this_player()) return 0;
		if (!opened) {
			write("The book is closed.\n");
			return 1;
		}
		if (pageno==npages-1) 
			write("You reach the cover, and turn back to the last page.\n");
		else {
			pageno++;
			write("You turn to the next page.\n");
		}
		say(this_player()->query_name()+" pages through a book.\n",
				this_player());
		return 1;
	}
	return 0;
}
read_book(name) {
	string line, book, rest, nrest;
	int narg, toadd;
    book = read_file(name);
	rest = book;
	nlines = 0;
	while ( narg=sscanf(rest,"%s\n%s",line,nrest) ) {
		page[nlines] = line;
		nlines++;	
		if (narg==1) break;
		rest = nrest;
	}
	linesperpage = 8;
	npages = nlines / linesperpage;	/* MUST BE DONE BETTER :-) */
	if ((linesperpage*npages) < nlines) {
		npages++;
		toadd = (linesperpage*npages)-nlines;
		for (narg=1; narg<= toadd; narg++) {
			page[nlines] = " ";
			nlines++;
		}
	}
}

open(arg) {
	object obj;
	if (!id(arg)) return 0;
	if (environment(this_object())!=this_player()) return 0;
	if (opened) write("The book is already open.\n");
	else {
		opened=1;
		pageno = 0;
		write("You open the book.\n");
		say(this_player()->query_name()+" opens a book.\n", this_player());
		if (openfind) {
			write("something falls out of it.\n");	
			obj = clone_object(openfind);
			openfind = 0;
			if (obj) move_object( obj, environment(this_player()));
		}
		if (!firstopened) {
			firstopened = 1;
			if (bookfile) {
				page = allocate(maxlines);
				/* page = */ read_book(bookfile);	
			}
			else {
				page = ({ 
						"Lots of unreadable texts.\n", 
						"Lots of unreadable texts.\n", 
						"Lots of unreadable texts.\n", 
						"Lots of unreadable texts and some numbers.\n", 
						"Lots of unreadable texts.\n", 
						"Lots of unreadable texts and formulas.\n", 
						"Lots of unreadable texts.\n", 
						});
				npages = 7;
			}
		}
		if (open2dest) call_out("self_dest", open2dest);
	}
	return 1;
}

self_dest() {
	write("A book crumbles to dust.\n");
	destruct(this_object());
}

close(arg) {
	if (!id(arg)) return 0;
	if (environment(this_object())!=this_player()) return 0;
	if (!opened) write("The book is already closed.\n");
	else {
		opened=0;
		write("You close the book.\n");
		say(this_player()->query_name()+" closes a book.\n",this_player());
	}
	return 1;
}
