/* wrapper around /obj/monster to make making monsters less monstrous 
// yes this file has same function load_match as whisky's wrapper around 
// monster. One would think any sensible person would think such thing out.
// Just like the add_action in /obj/room etc.
// Just the implementation is...well different:-). Thanks anyway Whisky:-)
*/
/* THIS load_match expects as second argument:
//   array with even parity of elements. even nrd are to be quoted func name's
//	 each next odd nrd member should be an array (of types).
//	 these arrays may contain one or more strings, each string optionally
//	 followed by an array of strings (matches).
*/
inherit "obj/monster";

/* TEMP HACK TO KEEP ERRORS AWAY!!!!! */
string name_of_weapon;

reset(arg) {
	::reset(arg);
	if (arg) return;
        set_name("A monster out of whisky's lab");
	set_race("monster");
}

id(str) {
	if (::id(str)) return 1;
        else return str == "monster";
}


/* place_in_this should be used via PLACE_IN_THIS macro: see mymonster.h
// usage: pLACE_IN_THIS(objvarname, filename)  but then with PLACE at start:-)
*/
place_in_this( objname, filname, monstername  )
{
	if (!objname) {
		objname = clone_object(filname);
    	move_object(objname, monstername);
    }
	return objname;
}

/* make_in_this should be used via MAKE_IN_THIS macro: see mymonster.h
// usage: PMAKE_IN_THIS(filename)  (returns objectptr like place_etc,
// but requires no varname).
*/
make_in_this( filname, envname  )
{
	object objname;
	objname = clone_object(filname);
    move_object(objname, envname);
	return objname;
}


lm_error(str) { write("load_match: "+str+"\n"); }

load_match(ob, *arr) 
{
	string functypes, types, matches, functions;
	int nr_funcs, nr_matches, i,j,k; 
	nr_matches = 0; /* yes i know they init to 0 */
	if (sizeof(arr)&1) {
		lm_error("match array must have even members");
		return 0;
	}
	nr_funcs = sizeof(arr)/2;
	for (i=0; i<nr_funcs; i++) {		 	/*  determine_nr_matches(arr); */
		functypes = arr[1+2*i];
		for (j=0; j<sizeof(functypes); j++) 
			if (stringp(functypes[j])) nr_matches++; /* 1 type -> >= 1 match */
			else nr_matches += (sizeof(functypes[j])-1); /* assume it's array*/
	}
    functions=allocate(nr_matches);
    types=allocate(nr_matches);
    matches=allocate(nr_matches);
	if (!functions || !types || !matches)
		 lm_error("fail to alloc matches, functions, or types."); 
	nr_matches = 0;
	for (i=0; i<nr_funcs; i++) {				 /* fill the three arrays */
		functions[nr_matches] = arr[2*i];
		functypes = arr[1+2*i];
		for (j=0; j<sizeof(functypes); j++) 
			if (stringp(functypes[j])) types[nr_matches++] = functypes[j];
			else { /* array of matches for a type */
				nr_matches--; 
				for (k=0; k<sizeof(functypes[j]); k++) 
					matches[nr_matches++] = functypes[j][k];
			}
	}
	set_match(ob, functions, types, matches);
}

