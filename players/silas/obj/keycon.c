/*  8.6.92 changes by Llort */
/* i built in a weight to carry and open close */

int value, max_weight, local_weight, my_weight, is_open, can_close, can_get;
string name_of_container ,cap_name ,alt_name ,alias_name;
string short_desc, long_desc,lid_name;
string read_msg;

long() {
    write(long_desc);
    if (first_inventory(this_object()))
	write("There is some keys on it.\n");
    else
	write("You can put keys on it.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0; 
    my_weight = 0;
    is_open = 1;
    can_get = 1;
}

query_container() { return 1; }

query_weight() { return my_weight+(local_weight+1)/2; }

query_max_weight() { return max_weight; }

add_weight(w) {
    if (local_weight + w > max_weight)
	return 0;
    local_weight+=w;
    return 1;
}

update_weight(w) {
    int ow,nw;

    ow=local_weight/2;
    nw=(local_weight+w)/2;

    return nw-ow;
}

short() { return short_desc; }

id(str) {
   return str == name_of_container || str == alt_name || str == alias_name;
}

query_value() { return value; }

can_put_and_get(a) { 
    if(can_close && is_open!=1 && !a) {
        tell_object(this_player(),"You have to open it first.\n");
    }    
    return is_open; 
}

get() { return can_get; }

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are keys in the " + name_of_container + ".\n");
	return 1;
    }
    return 0;
}

set_weight(w) { my_weight = w; }

set_max_weight(w) { max_weight = w; }

set_value(v) { value = v; }

set_name(n) {
    name_of_container = n;
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = cap_name +"\n";
}

set_alt_name(n) { alt_name = n; }

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n"; }

set_long(lo) { long_desc = lo; }

set_read(str) {
    read_msg = str;
}

set_can_close(a) { 
    can_close=a;
    if(can_close && !is_open) is_open=-1;
    else if(!can_close && is_open==-1) is_open=0; 
}

set_closed(a) { 
    if(a) is_open=-1;
    is_open = 0;
}

set_opened() { is_open=1; }

set_lid_name(ln) { 
    lid_name=ln;
}

set_can_get(c) { can_get = c; }

init() {
    add_action("close", "close");
    add_action("open", "open");
    add_action("dump","dump");
    if (read_msg) add_action("read", "read");
}

read(str) {
    if (str != name_of_container &&  str != alt_name && str != alias_name)
        return 0;
    write(read_msg);
    return 1;
}

close(arg) {
string ln;
    if(lid_name) ln=lid_name; else ln=short();
    if(can_close && id(arg)) {
        if(is_open==1) {
            tell_object(this_player(),"You close the "+ln+".\n");
            say(this_player()->query_name()+" closes the "+ln+".\n",
                this_player());
            is_open=-1;
        } else {
            tell_object(this_player(),"The "+ln+" is already closed.\n");
        }
        return 1;
    }
}

open(arg) {
string ln;
    if(lid_name) ln=lid_name; else ln=short();
    if(can_close && id(arg)) {
        if(is_open!=1) {
            tell_object(this_player(),"You open the "+ln+".\n");
            say(this_player()->query_name()+" opens the "+ln+".\n",
                this_player());
            is_open=1;
        } else {
            tell_object(this_player(),"The "+ln+" is already open.\n");
        }
        return 1;
    }
}

dump() {
  write("W:"+local_weight+"\n");
  write("CC:"+can_close+"\n");
  write("IO:"+is_open+"\n");
  return 1;
}
