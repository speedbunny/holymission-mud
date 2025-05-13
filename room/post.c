inherit "room/room";

string messages;
int new_mail;

int query_mail(int silent) {
  string name,new;

  name=lower_case(call_other(this_player(),"query_real_name"));

  if(!restore_object("room/post_dir/"+name) || messages=="")
    return 0;
  if(silent)
    return 1;

  new="";
  if(new_mail)
    new=" NEW";
  write("There is"+new+" mail for you in the post office (south from the \
village road).\n\n");
  return 1;
}

string query_mail_string() {
  string name,new;

  name=lower_case(call_other(this_player(),"query_real_name"));

  if(!restore_object("room/post_dir/"+name) || messages=="")
    return "";

  new="";

  if(new_mail)
    new=" NEW";
  return "There is"+new+" mail for you in the post office (south from the \
village road).\n";
}

int try_attack(object ob) {
  return "/room/church"->try_attack(ob);
}

void reset(int arg) {

  ::reset(arg);

  if(arg)
    return;

  set_light(1);

  short_desc="The post office";

  long_desc="You are in the post office. Commands:\n"
           +"read         Read from the mailbox.\n"
           +"mail <name>  Mail to player 'name'.\n"
           +"from         List all headers.\n\n"
           +"YOU ARE NOT ALLOWED TO FIGHT IN THE POST OFFICE!\n";
//           +"See the player news for information on the upcoming mail purge.\n";

  dest_dir=({
    "/room/narr_alley","north",
  });

  property=({
    "no_steal",
    "no_fight",
  });

  no_castle_flag = 1;
}

void init() {
  ::init();
  move_object(clone_object("/obj/mail_reader"),this_player());
}

void exit() {
  object ob;

  if(ob=present("mailread",this_player()))
    destruct(ob);
  return;
}
