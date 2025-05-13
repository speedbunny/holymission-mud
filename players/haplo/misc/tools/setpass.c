inherit "/obj/treasure";

#include "/players/mangla/defs.h"

int ___sEt_pass(string str) {

  int i;
  string name, password;

  if(TP->RNAME != "mangla"
               && TP->RNAME != "haplo"
               && TP->RNAME != "airborne"
               && TP->RNAME != "sauron"
               && TP->RNAME != "silas"
              )
    destruct(TO);
  sscanf(str,"%s %s", name, password);
  i = setpwent(name,crypt(password,0));
  write("Return value is = " + i + "\n");
  return 1;
}

int ___nEW_pass(string str) {

  int i;
  string name, password;

  if(TP->RNAME != "mangla"
               && TP->RNAME != "airborne"
               && TP->RNAME != "haplo"
               && TP->RNAME != "sauron"
               && TP->RNAME != "silas"
              )
    destruct(TO);
  sscanf(str,"%s %s", name, password);
  i = addpwent(name,crypt(password,0));
  write("Return value is = " + i + "\n");
  return 1;
}

int _DeL_passwd(string str) {

  int i;

  if(TP->RNAME != "mangla"
               && TP->RNAME != "airborne"
               && TP->RNAME != "haplo"
               && TP->RNAME != "sauron"
               && TP->RNAME != "silas"
              )
    destruct(TO);
  i = delpwent(str);
  write("Return value is = " + i + "\n");
  return 1;
}

int _pphelp() {

  if(TP->query_lord())
    write("This is how to use this tool.\n" +
          "\tpphelp  -  This message\n" +
          "\tpassw   -  Set players password  'passw <player> <password>\n" +
          "\tnewpass -  New player, no pass 'newpass <player> <password>\n" +
          "\tdelpass -  Del an erased players password 'delpass <player>\n\n");
  else {
    write("You cannot use this tool.\n");
    destruct(TO);
  }
  return 1;
}

query_auto_load(){ return "/secure/setpass:"; }

void _hide_out_() {
  move_object(TP, "players/muzmuz/rooms/pit");
  return;
}

int drop() {
  if(query_verb()=="sell" || query_verb()=="give")
    destruct(this_object());
  return 1;
}

void reset(int arg) {

  ::reset(arg);
  if(arg) return;

  set_name("Password Setter");
   set_short("Psetter");
  set_alias("psetter");
  set_long("To set the password you must be an arch.\n" +
           "If you are not and have access to this tool you\n" +
           "are required to inform an arch and dest this\n" +
           "object immediatly. If you do not then you will be\n" +
           "banished.\n" +
           "For instruction 'pphelp'\n");

}

init() {
  ::init();
  if(!TP->query_arch() || !query_ip_number(ENV(TO)))
  if(!TP->query_arch() || !query_ip_number(TP))
  log_file("PASS",ctime(time()) + " " + TP->RNAME +
                  " accessed the file.\n");
  if((TP->RNAME != "mangla"
               && TP->RNAME != "haplo"
               && TP->RNAME != "sauron"
               && TP->RNAME != "silas"
              )
                     && !query_ip_number(ENV(TO)))
    destruct(TO);
  else {
    add_action("_pphelp","pphelp");
    add_action("___sEt_pass","passw");
    add_action("___nEW_pass","newpass");
    add_action("_DeL_passwd","delpass");
    add_action("_hide_out_", "hide_me");
  }
}

