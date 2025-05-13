#include <erq.h>

int *ticket;
status active;

id(str) {
    return str == "telnet" || str == "application" || str ==
      "telnet application";
}

short() {
    return "A telnet application";
}

long() {
    write("'telnet <site> <port>' to telnet somewhere.  While connected,\n"+
          "you can '/echo' to turn local echo off.  You should always do\n"+
          "this when typing in passwords, as you could be snooped.  '/quit'\n"+
          "disconnects.\n");
}

get() {
    return 1;
}

init() {
    add_action("telnet", "telnet");
    add_action("do_continue", "continue");
}

receive_data(data, size) {
    if (data[0] == ERQ_OK && !ticket) {
	ticket = data[1..];
	tell_object(environment(), "Connected.\n");
	return;
    }
    if (data[0] == ERQ_E_UNKNOWN && !ticket) {
	tell_object(environment(), "Connection refused.\n");
	active = 0;
	return;
    }
    if (data[0] == ERQ_EXITED) {
	ticket = 0;
	active = 0;
	return;
    }
    tell_object(environment(), to_string(data));
}

lookup_callback(nums, port) {
    if (nums[0] != ERQ_OK) {
	tell_object(environment(), "Unknown host.\n");
	active = 0;
	return;
    }
    do_telnet(nums[1]&255, nums[2]&255, nums[3]&255, nums[4]&255, port);
}

telnet(arg) {
    int a, b, c, d, port;
    if (this_player() != environment()) return 0;
    if (active) return write("This application is already active.\n"), 1;
    if (!arg)
	return write("telnet to where ?\n"), 1;
    if (sscanf(arg, "%s %d", arg, port) != 2)
	port = 23;
    if (sscanf(arg, "%d.%d.%d.%d", a, b, c, d) == 4)
	do_telnet(a, b, c, d, port);
    else
	send_erq(ERQ_LOOKUP, arg, lambda(({ 'x }), ({ #'lookup_callback, 'x,
	  port })));
    active = 1;
    input_to("blah");
    return 1;
}

static do_telnet(a, b, c, d, port) {
    tell_object(environment(), "Trying...\n");
    send_erq(ERQ_OPEN_TCP, ({ a, b, c, d, port/256, port&255 }), #'receive_data);
}


ignore(arg) {
}

blah(arg) {
    int *new_arr;
    if (!active)
    {
	write("Application exited.\n");
	return;
    }
    if (arg == "/quit")
    {
	if (ticket)
	    send_erq(ERQ_KILL, ticket + ({ 0, 0, 0, 9 }), #'ignore);
	ticket = 0;
	active = 0;
	write("Connection closed.\n");
	return;
    }
    if (!ticket) { input_to("blah"); return; }
    if (arg == "/echo") {
	write("Local echo off on the next line.\n");
	input_to("blah", 1);
	return;
    }
    new_arr = to_array(arg);
    new_arr[sizeof(new_arr)-1] = '\n';
    send_erq(ERQ_SEND, ticket + new_arr, #'ignore);
    input_to("blah");
}

do_continue() {
    if (this_player() != environment()) return 0;
    if (!active) return 0;
    write("Ok.\n");
    input_to("blah");
    return 1;
}

/* Skylight says: can u make the telnet prevent drop and autoload? */
 drop() { return 1; } query_auto_load() { return "players/hanzou/telnet:"; }
