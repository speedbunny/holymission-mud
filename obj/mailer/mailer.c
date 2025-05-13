// Intermud Mailer by Huthar@portals

#include <mailer.h>
// #include <config.h>
#define MAILDIR	"obj/mailer"
#define MAILER_D "obj/mailer"

#define QUERY_NAME query_real_name

static string owner;
static string *tto, *tcc;
static string tfrom, tsubject, tmessage;
static int tdate;
static int cmsg;
static int startup;
static int *delete;
static int start_flag;
static int in_mailer;
static int quitmailflag;

mixed to, cc;
string *from, *subject, *message;
int *date, *ref_cnt;
int *flags;

void do_groups(string args);
void do_reply(string cmd, string numstr);
void delete_mail(string arg);
void undelete_mail(string str);
string *expand_to(string *arr);
void read_mail(int num);
void do_header(string arg);
void mail(string cmd);
void get_to(string cmd);
void do_mail(string arg);
void headers(int start);
void do_help(string arg);
void get_cc(string arg);

void create()
{
// seteuid(ROOT_UID);
   delete = to = cc = flags = from = date = subject = ref_cnt = message = ({});
}

init()
{
   int i;
   int *exclude;

   if(in_mailer)
   {
      write(query_short()+" dissappears as it leaves your grasp.\n");
      destruct(this_object());
      return 1;
   }

   delete = to = cc = flags = from = date = subject = ref_cnt = message = ({});
   owner = (string)this_player()->QUERY_NAME();
   restore_object(MAILDIR+owner+"-mbox");
   if(!sizeof(cc) || !cc)
   {
      cc = allocate(sizeof(to));
      for(i = 0; i < sizeof(cc); i++)
         cc[i] = ({});
   }

   if(!sizeof(to)) { cmsg = 0; return; }

   exclude = ({});
   for(i = 0,cmsg = -1; i < sizeof(to); i++)
   {
      if(flags[i] & OWNERDELETED)
         exclude += ({ i });
   }
   for(i = sizeof(exclude) - 1; i >= 0; i--)
   {
      to = exclude_array(to,exclude[i]);
      cc = exclude_array(cc,exclude[i]);
      from = exclude_array(from,exclude[i]);
      subject = exclude_array(subject,exclude[i]);
      message = exclude_array(message,exclude[i]);
      date = exclude_array(date,exclude[i]);
      ref_cnt = exclude_array(ref_cnt,exclude[i]);
      flags = exclude_array(flags,exclude[i]);
   }
   for(i = 0,cmsg = -1; i < sizeof(date); i++)
   {
      if(!(flags[i] & MAIL_READ))
      {
         cmsg = i;
         break;
      }
   }
   delete = allocate(sizeof(to));
   if(cmsg == -1)
   {
      cmsg = sizeof(to) - 1;
      if((cmsg = sizeof(to) - 1) < 0)
         cmsg = 0;
   }
}

int inccmsg()
{
   if(!sizeof(to))
   {
      cmsg = 0;
      return 0;
   }
   if(++cmsg >= sizeof(to))
      cmsg = sizeof(to) - 1;
   return cmsg;
}

int start_mail(string arg)
{
   start_flag = 0;
   init();
   write("Intermud Mailer v2.0  [? for help]\n");
   //eaders(0);
   do_mail(arg);
   return 1;
}

varargs do_mail(string cmd)
{
   in_mailer = 1;
   if(cmd)
   {
      quitmailflag = 1;
      get_to(cmd);
      return 1;
   }
   write("& ");
   input_to("parse_mailcmd");
}

void do_quit()
{
   int i,num;

   for(i = 0; i < sizeof(to); i++)
   {
      if(delete[i])
      {
         num += 1;
         MAILER_D->remove_message(owner,subject[i],date[i]);
      }
      else
         MAILER_D->set_flags(owner,subject[i],date[i],flags[i]);
   }
   write(num+" messages deleted.\n");
   MAILER_D->flush_files();
   in_mailer = 0;
   destruct(this_object());
   return;
}

void parse_mailcmd(string cmd)
{
   string arg;
   string verb;
   int num;
   string ocmd;

   ocmd = cmd;

   if(cmd == "")
   {
      if(start_flag && cmsg == inccmsg())
         ocmd = "-1";
      else
         ocmd = (cmsg+1)+"";  /* Ugly kludge! :) */
   }
   else
   {
      if(strlen(cmd) == 1)
         arg = "";
      else
         if(cmd[1] == ' ')
         {
            if(strlen(cmd) == 2)
            {
               arg = "";
               cmd = cmd[0..0];
            }
            else
            {
               arg = cmd[2..strlen(cmd) - 1];
               cmd = cmd[0 .. 0];
            }
         }
         else
         {
            arg = cmd[1..strlen(cmd) - 1];
            cmd = cmd[0 .. 0];
         }
   }

   switch(cmd)
   {
      case "g":
         do_groups(arg);
         break;
      case "R":
      case "r":
         do_reply(cmd,arg);
         return;
      case "?":
         do_help(arg);
         break;
      case "q":
         do_quit();
         return;
      case "m":
         mail(arg);
         return;
      case "u":
         undelete_mail(arg);
         break;
      case "d":
         delete_mail(arg);
         break;
      case "h":
         do_header(arg);
         break;
      default:
         if(ocmd && sscanf(ocmd,"%d", num) && num > 0 && num <= sizeof(to))
         {
            cmsg = num - 1;
            start_flag = 1;
            read_mail(num - 1);
         }
         else
            write("Invalid Command.\n");
   }
   do_mail();
}

void mail(string arg)
{
   if(!arg)
   {
      write("To: ");
      input_to("get_to");
      return;
   }
   get_to(arg);
}

void get_to(string arg)
{
   string *tmp, *grparr, grp;
   int i;
   mixed grps;

   if(!arg)
   {
      write("No users/groups specified.\n");
      do_mail();
      return;
   }

   tto = ({});
   tcc = ({});
   tfrom = (string)this_player()->QUERY_NAME();
   tdate = time();
   grparr = keys(grps = (mapping)GROUP_OB->query_groups());
   tto = explode(arg," ");
   write("Subject: ");
   input_to("get_subject");
}

void get_subject(string sub)
{
   int i;
   if(!sub)
      write("Null subject line. Hope that's ok.\n");
   tsubject = sub;
   write("\n\nFrom: "+capitalize(tfrom)+"\n");
   write("To: ");
      for(i = 0; i < sizeof(tto); i++)
         write(capitalize(tto[i])+" ");
   write("\n");
   write("Date: "+ctime(tdate)+"\n");
   write("Subject: "+tsubject+"\n");
   rm("/tmp/"+tfrom+".tmail");
   this_player()->edit("/tmp/"+tfrom+".tmail","get_text",this_object());
}

void abort()
{
   if(quitmailflag)
   {
      destruct(this_object());
      return;
   }
   do_mail();
}

void get_text()
{
   tmessage = read_file("/tmp/"+tfrom+".tmail");
   rm("/tmp/"+tfrom+".tmail");
   if(!this_player()->query_env("mail_no_cc"))
   {
      write("Cc: ");
      input_to("get_cc");
      return;
   }
   get_cc("");
}

void get_cc(string arg)
{
   int i;
   string *rtn;
   string tmpfile;

   if(arg && arg != "")
      tcc = uniq_array( tcc + explode(arg," ") );

   rtn = (string *)MAILER_D->send_mail(tto,tcc,tfrom,tsubject,tdate,tmessage);

   if(sizeof(rtn))
   {
      write("Mailing to: ");
      for(i = 0; i < sizeof(rtn); i++)
         if(stringp(rtn[i]))
            write(capitalize(rtn[i])+" ");
      write("\n");
   }
   else
   {
      tmpfile = TMP_DIR + "/"+owner+".dead-letter";
      write("No recipients found. Appending to: '"+tmpfile+"'\n");
      write_file(tmpfile,tmessage+"\n");
   }

   MAIL_SERVER->flush_mail_queue();

   if(quitmailflag)
   {
      MAILER_D->flush_files();
      destruct(this_object());
   }
   else
   do_mail();
}


void do_header(string arg)
{
   int start;

   if(!arg || arg == "")
      headers(0);
   else
   {
      sscanf(arg,"%d",start);
      if(start <= sizeof(to) && start > 0)
         headers(start - 1);
      else
         write("Mail # out of range.\n");
   }
}

void headers(int start)
{
   int i;

   if(!sizeof(to))
   {
      write("No mail.\n");
      cmsg = 0;
      return;
   }
   for(i = start; i < sizeof(to); i++)
   {
      write(flags[i] & MAIL_READ ? " " : "U");
      if(i == cmsg)
         write(delete[i] ? "< " : "> ");
      else
         write(delete[i] ? "* " : "  ");
      printf("%d %s [%s] \"%s\"\n",i+1,capitalize(from[i]),
         ctime(date[i]),subject[i]);
   }
}

void read_mail(int num)
{
   mapping msg;
   int i;

   if(!pointerp(to[num]))
      msg = (mapping)MAILER_D->get_message(to[num],subject[num],date[num]);
   else
      msg = ([ "to" : to[num], "cc" : cc[num], "from" : from[num], "date" : date[num],
         "subject" : subject[num], "ref_cnt" : ref_cnt[num],
         "flags" : flags[num], "message" : message[num] ]);

   if(!sizeof(msg))
   {
      write("That message is no longer valid.\n");
      return;
   }

   write("Message #"+(num+1));
   write(delete[num] ? " \t[DELETED]\n" : "\n");
   write("To     : ");
   for(i = 0; i < sizeof(msg["to"]); i++)
      write(capitalize(msg["to"][i])+" ");
   write("\n");
   if(sizeof(msg["cc"]))
   {
      write("Cc     : ");
      for(i = 0; i < sizeof(msg["cc"]); i++)
         write(capitalize(msg["cc"][i])+" ");
      write("\n");
   }
   write("From   : "+capitalize(msg["from"])+"\n");
   write("Date   : "+ctime(msg["date"])+"\n");
   write("Subject: "+msg["subject"]+"\n");
   write("------------------------------------------------------------------------------\n");
   write(msg["message"]+"\n");
   flags[num] |= MAIL_READ;
}

void delete_mail(string str)
{
   int num;

   if(!str || str == "")
      num = cmsg + 1;
   else
      sscanf(str,"%d",num);

   if(num < 1 || num > sizeof(date))
   {
      write("Illegal message value.\n");
      do_mail();
      return;
   }

   num -= 1;

   if(delete[num])
   {
      write("Message #"+(num + 1)+" already deleted.\n");
      return;
   }

   delete[num] = 1;
   write("Message #"+(num + 1)+" marked for deletion.\n");
}

void do_help(string arg)
{
   cat(MAILER_SHORT);
}

void undelete_mail(string str)
{
   int num;

   if(!str || str == "")
      num = cmsg + 1;
   else
      sscanf(str,"%d",num);

   if(num < 1 || num > sizeof(date))
   {
      write("Illegal message value.\n");
      return;
   }

   num -= 1;

   if(!delete[num])
   {
      write("Message #"+(num + 1)+" is noty deleted.\n");
      return;
   }

   delete[num] = 0;
   write("Message #"+(num + 1)+" is restored.\n");
}

void do_reply(string cmd, string numstr)
{
   string *tmp;
   mapping msg;
   int num;
   int i;

   if(numstr == "")
      num = cmsg + 1;
   else
      sscanf(numstr,"%d",num);

   if(num < 1 || num > sizeof(to))
   {
      write("Illegal message number!\n");
      return;
   }

   if(!pointerp(to[--num]))
      msg = (mapping)MAILER_D->get_message(to[num],subject[num],date[num]);
   else
  msg =
 ([ "to" : to[num], "cc" : cc[num], "from" : from[num],
           "date" : date[num],
         "subject" : subject[num], "ref_cnt" : ref_cnt[num],
         "flags" : flags[num], "message" : message[num] ]);

   if(!sizeof(msg))
   {
      write("That message is no longer valid.\n");
      return;
   }

   if(cmd == "r")
   {
      tto = ({ msg["from"] });
      tcc = ({});
   }
   else
   {
      tto = uniq_array( ({ msg["from"] }) + msg["to"] );
      tcc = msg[cc];
   }

   tfrom = (string)this_player()->query_cap_name();
   tdate = time();

   tsubject = msg["subject"];
   if(strlen(tsubject) < 4 || tsubject [0 .. 3] != "RE: ")
      tsubject = "RE: "+tsubject;

   write("\n\nFrom    : "+capitalize(tfrom)+"\n");
   write("To     : ");
      for(i = 0; i < sizeof(tto); i++)
         write(capitalize(tto[i])+" ");
   write("\n");
   if(sizeof(msg["cc"]))
   {
      write("Cc     : ");
      for(i = 0; i < sizeof(msg["cc"]); i++)
         write(capitalize(msg["cc"][i])+" ");
      write("\n");
   }
   write("Date   : "+ctime(tdate)+"\n");
   write("Subject: "+tsubject+"\n");
   rm("/tmp/"+tfrom+".tmail");
   if(1 || this_player()->query_env("mail_use_reply_text"))
   {
      tmp = explode(msg["message"],"\n");
      tmessage = capitalize(msg["from"])+ " writes:\n> "+
         implode(tmp,"\n> ");
      write_file("/tmp/"+tfrom+".tmail",tmessage+"\n");
   }
   this_player()->edit("/tmp/"+tfrom+".tmail","get_text",this_object());
}

void do_groups(string arg)
{
   mapping grps;
   string *groups;
   int i;

   grps = (mapping)GROUP_OB->query_groups();
   if(arg != "")
   {
      if(!sizeof(grps[arg]))
      {
         write("That group does not exist!\n");
         return;
      }
      write("Members for group ("+arg+"):\n");
      for(i = 0; i < sizeof(grps[arg]); i++)
         write("   "+grps[arg][i]+"\n");
      return;
   }
   groups = keys(grps);
   write("\nCurrent active groups:\n");
   for(i = 0; i < sizeof(groups); i++)
      write("   "+groups[i]+"\n");
   write("\n");
}

int valid_shadow() { return 1; }
