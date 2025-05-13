inherit "/players/qclxxiv/qtool";
int files;
string spaces_;
query_auto_load() { return "players/qclxxiv/smartinv"+":"; }
query_value() { return 1; }
get()	{ return 1; }
drop() { return 1; }
query_weight() { return 0; }

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("smartinv");
	set_short("A smartinv");
	hidden = 1;
}
init()  { 
	::init();
	add_action("smartinv", "si" ); 		/* summed shorts [of something] */
	add_action("smartinv_e", "esi" ); /* ,, of [something's] environment*/
	add_action("smartinv_f", "sif" ); /* summed filenames [of something] */
	add_action("smartinv_fx", "sifx" ); /* filenames [of something] */
	add_action("smartinv_f_e", "esif" ); /* summed filenames of [sm] env */ 
	add_action("smartinv_f_ex", "esifx" ); /* filenames of [something] env */
	if (!spaces_) {
		spaces_ = allocate(21);
		spaces_ = ({
			""," ","  ","   ","    ","     ","      ","       ","        ",
			"         ","          ","           ","            ",
			"             ","              ","               ",
			"                ","                 ","                  ",
			"                   ","                    ",
		});
		/* write("still have to move spaces() to string.c.\n" );*/
	}
}

smartinv(arg) {
	files = 0;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_i(arg);
	return 1;
}

smartinv_f(arg) {
	files = 1;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_i(arg);
	return 1;
}

smartinv_e(arg) {
	files = 0;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_i_e(arg);
	return 1;
}

smartinv_fx(arg) {
	files = 1;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_ix(arg);
	return 1;
}

smartinv_f_e(arg) {
	files = 1;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_i_e(arg);
	return 1;
}

smartinv_f_ex(arg) {
	files = 1;
	if (!arg) arg = this_player()->query_real_name();
	smartinv_i_ex(arg);
	return 1;
}

smartinv_i(arg) {
	object ob, obj, fobj;
	if (!arg) arg = this_player()->query_real_name();
	if (ob=find_living( lower_case(arg) ) ) {
		obj = all_inventory(ob);
		if (obj) nodup_inv( arg, obj );
		else write(arg+" has no inventory.\n");
	}
/*	else write("Cant' find any "+arg+".\n"); */
	else {
		fobj = find_object(arg);
		if (fobj) obj = all_inventory(fobj);
		else obj = 0;
		if (obj) nodup_inv( arg, obj );
		else write("Can't find any "+arg+" or it has no inventory.\n");
	}
	return 1;
}

smartinv_ix(arg) {
	object ob, obj, fobj;
	if (!arg) arg = this_player()->query_real_name();
	if (ob=find_living( lower_case(arg) ) ) {
		obj = all_inventory(ob);
		if (obj) dup_inv( arg, obj );
		else write(arg+" has no inventory.\n");
	}
/*	else write("Cant' find any "+arg+".\n"); */
	else {
		fobj = find_object(arg);
		if (fobj) obj = all_inventory(fobj);
		else obj = 0;
		if (obj) dup_inv( arg, obj );
		else write("Can't find any "+arg+" or it has no inventory.\n");
	}
	return 1;
}


smartinv_i_e(arg) {
	object ob, obj, fobj;
	if (!arg) arg = this_player()->query_real_name();
	if (ob=find_living( lower_case(arg) ) ) {
		ob = environment(ob);
		if (ob) {
			obj = all_inventory(ob);
			if (obj) nodup_inv( arg, obj );
			else write("It has no inventory.\n");
		}
		else {
			write(arg+" has no environment.\n");
			return 1;
		}
	}
/*	else write("Cant' find any "+arg+".\n"); */
	else {
		fobj = find_object(arg);
		if (fobj) {
			fobj = environment(fobj);
			if (fobj)
				obj = all_inventory(fobj);
			else {
				write("It has no environment.\n");
				return 1;
			}
		}
		else obj = 0;
		if (obj) nodup_inv( arg, obj );
		else write("Can't find it or it has no inventory.\n");
	}
	return 1;
}

smartinv_i_ex(arg) {
	object ob, obj, fobj;
	if (!arg) arg = this_player()->query_real_name();
	if (ob=find_living( lower_case(arg) ) ) {
		ob = environment(ob);
		if (ob) {
			obj = all_inventory(ob);
			if (obj) dup_inv( arg, obj );
			else write("It has no inventory.\n");
		}
		else {
			write(arg+" has no environment.\n");
			return 1;
		}
	}
/*	else write("Cant' find any "+arg+".\n"); */
	else {
		fobj = find_object(arg);
		if (fobj) {
			fobj = environment(fobj);
			if (fobj)
				obj = all_inventory(fobj);
			else {
				write("It has no environment.\n");
				return 1;
			}
		}
		else obj = 0;
		if (obj) dup_inv( arg, obj );
		else write("Can't find it or it has no inventory.\n");
	}
	return 1;
}

nodup_inv( arg, obj ) {
	int i;
	string sh, prevshort;
	int count;
	for (i=0; i<sizeof(obj); i++) {
		/* if (sh = obj[i]->short()) { */
		sh = obj[i]->short();
		if (sh==prevshort) count++;
		else {
			if (count) {
				if (count==1) 
					write(count+ " time: \t");
				else write(count+ " times:\t");
				if (prevshort) 
					write(prevshort+"."+filename(obj[i-1]) );
				else write("Invisible object."+filename(obj[i-1]));
			}
			prevshort = sh;
			count = 1;
		}
		/* } */
	}
	if (count) {
		if (count==1) 
			write(count+ " time: \t");
		else write(count+ " times:\t");
		if (prevshort) 
			write(prevshort+"."+filename(obj[i-1]) );
		else write("Invisible object."+filename(obj[i-1]) );
	}
}

dup_inv( arg, obj ) {
	int i;
	string sh, prevshort;
	for (i=0; i<sizeof(obj); i++) {
		sh = obj[i]->short();
		if (sh) 
			write(sh+"."+filename(obj[i]) );
		else write("Invisible object."+filename(obj[i]));
	}
}

filename(ob) {
	if (files) {
		if (ob) 
			return "\t/"+file_name(ob)+"\n";
	}
	return "\n";
}

trunc20( arg ) {
	int slen;
	string narg;
	int t;
	/*strlen = "/players/qclxxiv/string"->sizeof_str(arg);*/
	slen = strlen(arg);	/* sigh of relief...they had strlen after all*/
	if (slen > 20 ) {
		return arg;
/*		narg= "";
		for (t=0; t<20; t++) {
			narg = narg+arg[t];
		}
*/
	}
	else {
		return arg + spaces(20-slen);
	}
	return narg;
}

spaces(i) {
	return spaces_[i];
}

