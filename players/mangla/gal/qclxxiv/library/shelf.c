int books;
string color;
object b1, b2, b3, b4, b5;

get()	{ return 1; }
query_weight() { return 1000; }
query_value() { return 1; }

set_color(str) { 
	color = str; 
	if (b1) b1->set_shelfcolor(str);
	if (b2) b2->set_shelfcolor(str);
	if (b3) b3->set_shelfcolor(str);
	if (b4) b4->set_shelfcolor(str);
	if (b5) b5->set_shelfcolor(str);
}

reset(arg) {
	if (arg) return;
	b1 = clone_object("/players/qclxxiv/library/book");
	b1->set_color("red");
	move_object(b1, this_object() );
	b2 = clone_object("/players/qclxxiv/library/book");
	b2->set_color("yellow");
	move_object(b2, this_object() );
	b3 = clone_object("/players/qclxxiv/library/book");
	b3->set_color("green");
	move_object(b3, this_object() );
	b4 = clone_object("/players/qclxxiv/library/book");
	b4->set_color("blue");
	move_object(b4, this_object() );
	b5 = clone_object("/players/qclxxiv/library/book");
	b5->set_color("purple");
	move_object(b5, this_object() );
	books = 5;
	color = "red";
}

id(str) { return str=="shelf" || str == color+" shelf" || str == "qlib_shelf"; }
short() { return "A "+color+" shelf"; }
long() {  
	int i;
	object obj;
	write( "A "+color+" shelf. ");
	if (books>1) write("On it are books.\n");
	else if (books) write("On it is a book.\n");
	else write("All books are taken from it.\n");
	obj = all_inventory(this_object());
	for (i=0; i<sizeof(obj); i++)
		if (obj[i]->short()) write(obj[i]->short()+".\n");
}

init() {
	add_action("putbook","put");
	add_action("getbook","get");
	add_action("getbook","take");
}

putbook(arg) {
	string what, which, sort;
	object o;
	if (sscanf(arg,"%s on %s",what,which)==2) {
		if (!id(which)) return 0;
		if (what=="book" || sscanf(what,"%s book",sort)==1) {
			if (o=present(what,this_player())) {
				move_object(o,this_object());
				books++;
				/* tell_room(environment(this_object()),  */
				write("Ok.\n");
				say( this_player()->query_name()
						+" puts a "+what+" on the "+which+".\n",this_player());
				return 1;
			}
		}
		else if (o=present(what,this_player())) {
			move_object(o,this_object());
			/* tell_room(environment(this_object()),  */
			write("Ok.\n");
			say( this_player()->query_name()
					+" puts "+what+" on the "+which+".\n",this_player());
			return 1;
		}
	}
	return 0;
}

getbook(arg) {
	string what, which, sort;
	object o;
	if (sscanf(arg,"%s from %s",what,which)==2) {
		if (!id(which)) return 0;
		if (what=="book" || sscanf(what,"%s book",sort)==1) {
			if (o=present(what,this_object())) {
				move_object(o,this_player());
				books--;
				/* tell_room(environment(this_object()), */
				write("Ok.\n");
				say( this_player()->query_name()
					+" takes a "+what+" from the "+which+".\n",this_player());
				return 1;
			}
		}
		else if (o=present(what,this_object())) {
			move_object(o,this_player());
			/* tell_room(environment(this_object()),  */
			write("Ok.\n");
			say( this_player()->query_name()
					+" takes "+what+" from the "+which+".\n", this_player());
			return 1;
		}
	}
	return 0;
}

