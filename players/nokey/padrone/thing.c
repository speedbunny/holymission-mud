/*
 *   A thing. It can be read, either with a fixed message or a file.
 *   Thomas Padron-McCarthy, padrone@lysator.liu.se, 1990
 *	Clone this object to get a generic thing, then use set_name,
 *	and (optional) set_alias, set_short, set_long, set_read, set_read_file,
 *      set_can_get, set_weight and set_value.
 *   Latest update: January 20, 1991
 */
/* 040794: Nokey: Strict_typing this */

#pragma strict_types
#pragma save_types

/* declaration of functions */
int read(string s);
void set_name(string s);

string name, alias_name, short_desc, long_desc, read_message, read_file;
status can_get;
int weight, value;

string short() {
    return short_desc;
}

void long() {
    if (long_desc)
	write(long_desc);
    else if (read_file || read_message)
	read(name);
    else
	write("You see nothing special.\n");
}

void reset(int arg) {
    if (arg)
	return;
    set_name("thing");
    long_desc = 0;	/* Use read() if no long_desc set! */
    can_get = 1;
    read_message = 0;
    read_file = 0;
    weight = 1;
    value = 1;
}

void init() {
    add_action("read", "read");
}

int id(string str) {
    return str == name || str == alias_name;
}

int read(string str) {
    if (!id(str))
	return 0;
    else if (!read_file && !read_message)
	return 0;
    else {
	say(this_player()->query_name() + " reads the " + name + ".\n");
        if (read_file)
	    cat(read_file);
	else
	    write(read_message);
	return 1;
    }
} /* read */

int get() {
    return can_get;
}

string query_name() { return name; }
int query_weight() { return weight; }
int query_value() { return value; }

void set_name(string n)
  {
  name = n;
  short_desc = capitalize(n);
  }
void set_short(string sh) { short_desc = sh; }
void set_long(string long) { long_desc = long; }
void set_read(string str) { read_message = str; }
void set_read_file(string filename)
  { read_file = filename; }
void set_weight(int w) { weight = w; }
void set_value(int v) { value = v; }
void set_alias(string n) { alias_name = n; }
void set_can_get(int n) { can_get = n; }
