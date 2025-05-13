inherit "room/room";

string messages;
int new_mail;

reset(arg) {
    if (arg)
	return;
    property=({ "no_steal","no_fight" });
    set_light(1);
    dest_dir = ({ "players/topaz/rooms/cont/main_street2", "north",
                  "players/topaz/rooms/cont/sheriff", "east",
           });
    short_desc = "The post office";
    long_desc = "You are in the post office. Commands:\n" +
	"read         Read from the mailbox.\n" +
	"mail <name>  Mail to player 'name'.\n" +
	"from         List all headers.\n"+
	"\nYOU ARE NOT ALLOWED TO FIGHT IN THE POST OFFICE\n";
    no_castle_flag = 1;
}

init() {
    ::init();
    move_object(clone_object("obj/mail_reader"), this_player());
}

exit() {
    object ob;
    if (ob = present("mailread", this_player()))
	destruct(ob);
}

query_mail(silent) {
    string name;
    string new;

    name = lower_case(call_other(this_player(), "query_real_name"));
    if (!restore_object("room/post_dir/" + name) || messages == "") return 0;
    if (silent) return 1;
    new = "";
    if (new_mail)
	new = " NEW";
    write("\nThere is" + new + " mail for you in the post office\n"+
        "   (south from main street).\n\n");
    return 1;
}

try_attack(ob) { return "players/topaz/rooms/cont/main_street2"->try_attack(ob); }
