
// mailer_d.c - The intermud mailer daemon
//
// Written by: Huthar@portals

#include <config.h>
#include <mailer.h>

// Make QUERY_NAME == the function you use to get a players real name
#define QUERY_NAME query_name

/* The following are the variables that will be saved as the datafiles */
mixed *to;
string *from, *subject, *message;
mixed *cc;
int *date, *ref_cnt, *flags;
static string file;
static string maildir;


int valid_access(string frm)
{
   string accessor;
   string tmp;
   string *owner;

// Let root do as he/she/it pleases
   if(geteuid(previous_object()) == ROOT_UID)
      return 1;

// Next two ifs check to see if this is a trusted mailer
   if(sscanf(file_name(previous_object()),"%s#%*s",tmp))
      accessor = tmp;
   if(member_array(accessor,TRUSTED_MAILERS) >= 0)
      return 1;

// If a frm == 0 then this is a read operation. If the player may
// always read mail if he is the owner of the box.
   if(file)
   {
      owner = explode(file,"/");
      sscanf(owner[sizeof(owner)-1],"%s-mbox",owner[sizeof(owner)-1]);
      if((string)this_player(1)->QUERY_NAME() == owner[sizeof(owner)-1] && !frm)
         return 1;
   }

// If frm != 0 then make sure that frm == this_player(1) to prevent
// forgeries...
   if(frm == (string)this_player(1)->QUERY_NAME())
      return 1;

   return 0; // Not a legal operation!
}

create()
{
   seteuid(ROOT_UID);
   maildir = MAILDIR;
   cc = to = flags = from = subject = message = date = ref_cnt = ({});
   file = "";
}

void update_mbox(string owner)
{
   int i;

   if(file != MAILDIR + owner + "-mbox")
   {
  if (file && file != ".")
         save_object(file);
      file = MAILDIR + owner + "-mbox";
      to = cc = flags = from = subject = message = date = ref_cnt = ({});
      restore_object(file);
      if(!sizeof(cc) || !cc)
      {
         cc = allocate(sizeof(to));
         for(i = 0; i < sizeof(cc); i++)
            cc[i] = ({});
      }
   }
}

int get_mail_number(string lsub, int ldate)
{
   int mn,i;

   if((mn = member_array(ldate,date)) < 0)
      return -1; /* Invalid date - Message doesn't exist! */
   if(subject[mn] != lsub) // Ouch! Subjects don't match!
   {
      for(i = 0, mn = -1; i < sizeof(date); i++)
         if(date[i] == ldate && subject[i] == lsub)
         {
            mn = i;
            break;
         }
   }
   return mn;
}

void remove_message(string owner, string lsub, int ldate)
{
   int mn;
   int i;
   string flag;

   update_mbox(owner);

   if(!valid_access(0))
   {
      write("Illegal access attempt to mailer_d.\n");
      return;
   }

   if((mn = get_mail_number(lsub, ldate)) < 0)
      return;

   if(pointerp(to[mn]))
      flags[mn] |= OWNERDELETED;

   if(--ref_cnt[mn] > 0)
   {
      return; /* Someone still hasn't read it! */
   }

   /* Delete it! */
   if(!pointerp(to[mn]))  // This is a pointer message
      flag = to[mn];
   to = exclude_array(to,mn);
   cc = exclude_array(cc, mn);
   from = exclude_array(from, mn);
   date = exclude_array(date, mn);
   subject = exclude_array(subject, mn);
   ref_cnt = exclude_array(ref_cnt, mn);
   flags = exclude_array(flags, mn);
   message = exclude_array(message, mn);


   if(flag)
      remove_message(flag,lsub,ldate);
}

int add_message(string owner, mixed lto, mixed lcc, string lfrom, string lsubject,
                 int ldate, int lref_cnt, int lflags, string lmessage)
{
   string own,mud;

   if(sscanf(owner,"%s@%s",own,mud) == 2)
   {
      MAIL_SERVER->remote_mail(own,mud,lto,lcc,lfrom,lsubject,ldate,lmessage);
      return 1;
   }

   update_mbox(owner);

   if(!valid_access(lfrom))
   {
      write("Illegal access attempt to mailer_d.\n");
      return 0;
   }

   to += ({ lto });
   cc += ({ lcc });
   from += ({ lfrom });
   subject += ({ lsubject });
   date += ({ ldate });
   ref_cnt += ({ lref_cnt });
   flags += ({ lflags });
   message += ({ lmessage });

   return user_exists(owner);
}

mapping get_message(string owner, string subjs, int dates)
{
   int mn;
   int i;
   mixed tmp;

   update_mbox(owner);

   if(!valid_access(0))
   {
      write("Illegal access attempt to mailer_d.\n");
      return ([]);
   }

   if((mn = get_mail_number(subjs, dates)) < 0)
      return ([]);

   if(pointerp(to[mn]))
      tmp = to[mn] + ({});
   else
      tmp = to[mn];
   return ([ "to" : tmp, "cc" : cc[mn], "from" : from[mn], "subject" : subject[mn],
      "date" : date[mn], "ref_cnt" : ref_cnt[mn], "flags" : flags[mn],
      "message" : message[mn]]);
}

mixed mail_status(string owner)
{
   int cnt,i;
   int *exclude;

   update_mbox(owner);

   exclude = ({});
   for(i = 0; i < sizeof(to); i++)
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
   for(i = 0; i < sizeof(date); i++)
   {
      if(!(flags[i] & MAIL_READ))
         cnt++;
   }
   file = ""; // Force a reload (We messed with the structures. :))
   return ([ "unread" : cnt, "total" : sizeof(date) ]);
}

void edit_message(string owner, string osubject, int odate, mixed lto, mixed lcc,
   string lfrom, string lsubject, int ldate, int lref_cnt, int lflags,
   string lmessage)
{
   int mn;
   int i;
   string flag;

   update_mbox(owner);

   if(!valid_access(lfrom))
   {
      write("Illegal access attempt to mailer_d.\n");
      return;
   }

   if((mn = get_mail_number(osubject, odate)) < 0)
      return;

   to[mn] = lto;
   cc[mn] = lcc;
   from[mn] = lfrom;
   subject[mn] = lsubject;
   date[mn] = ldate;
   ref_cnt[mn] = lref_cnt;
   flags[mn] = lflags;
   message[mn] = lmessage;

}

void flush_files()
{
  if (file != ".") save_object(file);
}

void set_flags(string owner, string lsubject, int ldate, int lflags)
{
   int mn;
   int i;
   string flag;

   update_mbox(owner);

   if(!valid_access(0))
   {
      write("Illegal access attempt to mailer_d.\n");
      return;
   }

   if((mn = get_mail_number(lsubject, ldate)) < 0)
      return;

   flags[mn] = lflags;
}

void biff(string str, string lfrom, string lsubject)
{
   string grp;
   string *grparr;
   object ob;
   int i;

   if(sscanf(str, "(%s)", grp))
   {
      grparr = ((mapping)GROUP_OB->query_groups())[grp];
      for(i = 0; i < sizeof(grparr); i++)
         biff(grparr[i],lfrom,lsubject);
      return;
   }

   if(ob = find_player(str))
   {
      tell_object(ob,">>> New mail has arrived from: "+capitalize(lfrom)+".\n");
      tell_object(ob,">>> Subject: "+lsubject+"\n");
   }
}

string *expand_to(mixed str)
{
   string grp, *rtn;
   int i;
   mapping grps;
   string t1,t2;

   rtn = ({});
   for(i = 0; i < sizeof(str); i++)
   {
      if(!str[i])
         continue;
      if(sscanf(str[i],"%s@%s",t1,t2) == 2)
      {
         rtn += ({ str[i] });
         continue;
      }
      if(sscanf(str[i],"(%s)",grp))
      {
         grps = (mapping)GROUP_OB->query_groups();
         if(sizeof(grps[grp]))
            rtn += expand_to(grps[grp]);
         else
            write("Group: "+grp+" doesn't exist.\n");
      }
      else
         if(user_exists(str[i]))
            rtn += ({ str[i] });
         else
            write("User: "+str[i]+" not found.\n");
   }
   return rtn;
}

string *send_mail(string *lto, string *lcc, string lfrom, string lsubject, int ldate,
               string lmessage)
{
   int i, lref_cnt;
   string *tmpto;
   mapping tmp;
   string *rtn;

   if(!valid_access(lfrom))
   {
      write("Illegal access attempt to mailer_d.\n");
      return ({});
   }

   tmp = ([ "to" : lto, "cc" : lcc, "from" : lfrom, "subject" : lsubject, "date" : ldate, "message" : lmessage ]);
   tmpto = uniq_array( expand_to(lto) + expand_to(lcc) );
   rtn = filter_array(tmpto,"remote_mail",this_object(),tmp);
   tmpto = tmpto - rtn;

   if(!(lref_cnt = sizeof(tmpto)))
      return rtn;

   rtn += tmpto;

   lref_cnt = sizeof(tmpto);

   add_message(tmpto[0],lto,lcc,lfrom,lsubject,ldate,lref_cnt,0,lmessage);
   biff(tmpto[0],lfrom,lsubject);

   for(i = 1; i < sizeof(tmpto); i++)
   {
      add_message(tmpto[i],tmpto[0],({}),lfrom,lsubject,ldate,1,0,"");
      biff(tmpto[i],lfrom,lsubject);
   }
   return rtn;
}

int remote_mail(string rcvr, mapping data)
{
   string own, mud;

   if(sscanf(rcvr,"%s@%s",own,mud) != 2)
      return 0;

   MAIL_SERVER->remote_mail(own,mud,data["to"],data["cc"],data["from"],
     data["subject"],data["date"],data["message"]);
   return 1;
}

int valid_shadow() { return 1; }
