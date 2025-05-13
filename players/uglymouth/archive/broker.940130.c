inherit "room/room";

#define BANKFILE  "room/broker"
#define BROKER_ID "broker_id"
#define IDFILE    "obj/broker_id"
#define TPRNAME   this_player()->query_real_name()
#define TPNAME	  this_player()->query_name()
#define TPPOSSE   this_player()->query_possessive()
#define TPLEVEL	  this_player()->query_level()
#define TPWIZARD  this_player()->query_wizard()

#define id_present present(BROKER_ID,this_player())
#define get_and_save_id \
	move_object(clone_object(IDFILE),this_player());\
	this_player()->save_me(0);


mixed *ctab;	/* customer / cash table */

static string cus_name;
static int amount,idx;
#if 0
int no_of_customers;
string customers;
#endif

init() { 
    ::init();
    add_action("help_bank","help"); 
    add_action("do_account","account"); 
    add_action("do_statement","statement");
    add_action("do_deposit","deposit");
    add_action("do_withdraw","withdraw");
    add_action("reload_bank","reload");
    add_action("save_bank","savebank");
    add_action("show_bank","showbank");
    add_action("do_set","setbank");
    add_action("do_list","listbank");
    add_action("do_clean","cleanbank");
}

reset(arg) {
object ob;
object *u;
int c,y,i,g,d;
string s;

     if(!arg) {
         set_light(1);
         short_desc="The Association Of The Money Brokers";
         long_desc=
    "You are standing inside the extensive building of The Money Brokers.\n"
  + "Some filthy old men are sitting behinds the desk, awaiting your orders.\n"
  + "At the south you notice the entry to the old bank-hall.\n"
  + "If you don't have an account, you should open one !\n\n"
  + "Type 'help bank' to get more information.\n"
  + "    The only obvious exit is east.\n";
         dest_dir=({
             "room/narr_alley","east",
             "room/bank","south",
                  });
         items=({
             "bank","@@short",
             "association","@@short",
               });
         property="no_steal"; 
     }

     if (!restore_object(BANKFILE)) {
        log_file("BROKER", "Restore on reset failed: " + ctime(time())+"\n");
     }
#if 0
     ctab=allocate(2);
     ctab[0]=allocate(no_of_customers);
     ctab[1]=allocate(no_of_customers);
     for (i=0;i<no_of_customers;i++) {
	s=explode(customers[i],":");
	sscanf(s[1],"%d",g);
	ctab[0][i]=s[0];
	ctab[1][i]=g;
     }
#endif
     ctab=order_alist(ctab);
     save_bank();
  

  /* Administering accounts of course costs some cash */


  tell_room(this_object(),
   "The clerk closes the counter.\n"+
   "The clerk says: Now let's see ... how much will our clients pay today ?\n"+
   "The clerk removes 1 % from every account and smiles satisfied.\n");

  /* Note: Only the accounts of players online are decreased, but including
	   linkdead players as well ! */

  return;		/* HERP: this needs to be a loop for users() */


  for (i=0;i<sizeof(ctab[0]);i++) {
    if ((ob=find_player(ctab[0][i]))) {
tell_room(this_object(),ob->query_name()+"\n");
	y=c*99/100;
	if (y<1000) y=c;
	d=c-y;
	if (d) {
	   g+=d;
#if 1
tell_room(this_object(),"debug: name = "+ctab[0][i]+"\n");
#endif
	   tell_room(this_object(),"The clerk removes "+d+" coins from "+
	 		capitalize(ctab[0][i])+"'s account.\n");
	   ctab[1][i]=y;
	   log_file("BROKER","Fee: "+ctab[0][i]+" "+d+" coin(s). Stand: "+y+
		   " coin(s). "+ctime(time())+"\n");
	}
    }
  }
  if (g) tell_room(this_object(),
		"The clerk shouts: Boss, we've earned "+g+" coins toady.\n");
  save_bank();
}

do_clean() {
mixed *ct_new;
object *x;
int i,j,nr;

    ct_new=allocate(2);
    nr=sizeof(ctab[0]);
    ct_new[0]=allocate(0);
    ct_new[1]=allocate(0); 
    for (i=0,j=0;i<nr;i++) {
	/*write(ctab[0][i]+" "+ctab[1][i]);*/
	if  (file_size("/players/"+ctab[0][i]+".o")>=0) {
	    ct_new[0] += ({ ctab[0][i] });
	    ct_new[1] += ({ ctab[1][i] });
	}
    }
    j=sizeof(ct_new[0]);
    write(j+" accounts left, "+(nr-j)+" vanished.\n");
    ctab=order_alist(ct_new);
    save_bank();
    return 1;
}

do_account() {
string account;

/*HERP: cause of bank bug */
#if 0
  if (id_present) {
     write("You already have an account at the Money Brokers Assoc.\n"
	 + "No further account allowed here.\n");
     return 1;
  }
#endif

  if (chk_existing(TPRNAME)) {
     write("You already had an account ... it seems you have lost your card !\n"
	 + "You get your card back.\n");
     if (!id_present) get_and_save_id 
     return 1;
  }

  move_object(clone_object(IDFILE),this_player());
  insert_alist(TPRNAME,0,ctab);
/* 28/11/92 Llort searching for a bug */
/* It seems the bug is in insert_alist *shrug*, the following
   code is only to fix the bank until the bug is fixed */
  if(!chk_existing(TPRNAME)) {
     ctab[0]+=({ TPRNAME });
     ctab[1]+=({ 0 });
     ctab=order_alist(ctab);
  }
  if(!chk_existing(TPRNAME)) {
     write(assoc(this_player()->query_real_name(),ctab,666));
     write("Error on opening an account! Please contact a wizard.\n");
     return 1;
  }
/* End of changes */
 
  this_player()->save_me(0);
  save_bank();

  write("You now have opened an account at the Money Brokers Assoc.\n"
      + "One of the filthy old clerks stand up and gives an advertising,\n"
      + "saying: 'Service is our success' !\n"); 
  log_file("BROKER","New Account: "+TPRNAME+" "+ctime(time())+"\n"); 
  return 1;

} 

do_statement() {

  if (chk_existing(TPRNAME) && !id_present) 
     get_and_save_id

  if (!id_present) { 
     write("The clerk says: But you don't have an account.\n");
     return 1;
  }

  write("Your statement reads: "+amount+" gold coins.\n");
  say(TPNAME+" reads "+TPPOSSE+" statement.\n");
  return 1;

}

do_deposit(str) {
int i,to_depose;

   if (chk_existing(TPRNAME) && !id_present)
      get_and_save_id

   if (!id_present) {
      write("The clerk  says: Sorry, I can't find any entry for your name.\n");
      return 1;
   }

   if (!str) return; 
   if (sscanf(str,"%d coins",to_depose)!=1 || to_depose < 1) {
     write("The clerk says: Uh ? Could you please repeat that ?\n");
     return 1;
  }

   if (to_depose > this_player()->query_money()) {
      write("The clerk grins like a jerk.\n");
      write("The clerk says: You don't have that much money.\n");
      return 1; 
   }

   if(idx < 0)
   {
     write("Clerk says: Your name is not on our list. If you think this is\n"+
           "an error, please leave a message on the player bug board, in\n"+
           "the Adventurers guild.\n");
     log_file("BROKER","Deposit: "+TPRNAME+" "+to_depose+" coin(s)."+
               ">> Stand: "+amount+" coin(s). "+ctime(time())+" IDX = "+idx+
               "\n");
     return 1;
   }
   ctab[1][idx]+=to_depose;
   this_player()->add_money(-to_depose);
   this_player()->save_me(0);	
   save_bank();	
   write("You gave your money to the clerk.\n"); 
   log_file("BROKER","Deposit: "+TPRNAME+" "+to_depose+" coin(s). Stand: "+amount+" coin(s). "+ctime(time())+"\n");
        return 1;
}
   
do_withdraw(str) {
int i,to_withdraw;

   if (chk_existing(TPRNAME) && !id_present) 
       get_and_save_id

   if (!id_present) {
       write("The clerk says: You don't have an account, and want to get cash ??\n");
       write("The clerk grins ironically.\n");
       return 1; 
   }

   if (!str) return;
   if (sscanf(str,"%d coins",to_withdraw)!=1 || to_withdraw < 1) {
      write("The clerk looks utterly confused.\n");
      return 1;
   }

   if (amount < to_withdraw) {
      write("The clerk say: You don't have that much money on your account.\n");
      write("The clerk yawns: We don't give any credits, good bye !\n");
      return 1;
   }

   if(idx < 0)
   {
     write("Clerk says: Your name is not on our list. If you think this is\n"+ 
           "is a error, please leave a message on the player bug board, in\n"+
           "the Adventurers guild.\n");
     log_file("BROKER","Withdraw: "+TPRNAME+" "+to_withdraw+" coin(s)."+
               ">> Stand: "+amount+" coin(s). "+ctime(time())+" IDX = "+idx+
               "\n");
     return 1;
   }
   ctab[1][idx]-=to_withdraw;
   this_player()->add_money(to_withdraw);
   this_player()->save_me(0);
   save_bank();
   write("The clerk gives you your money.\n");
   log_file("BROKER","Withdraw: "+TPRNAME+" "+to_withdraw+" coin(s). Stand: "+amount+" coin(s). "+ctime(time())+"\n");	
   return 1;

}

do_set(str) {
string who,c;
int i,ct;

  if (!TPWIZARD || !str) return;

  ct=sscanf(str,"%s %d",who,c);
  if (ct!=2) ct=sscanf(str,"%s",who);
  if (ct!=1 && ct!=2) return;

  if (!chk_existing(who)) {
     write(capitalize(who)+" doesn't have an account here.\n");
     return 1;
  }

  switch(ct) {
  case 2:
    if (TPLEVEL<50) {
       write("Only gods can do this.\n");
       return 1;
    }
    ctab[1][idx]=c;
    save_bank();
    log_file("BROKER","Setbank: ("+TPRNAME+") "+who+" Stand: "+c+" coin(s). "+ctime(time())+"\n");
    write("Ok.\n");
    say(TPNAME+" adjusts the statment of "+cus_name+" to "+c+" coins.\n");
    return 1;
  case 1:
    write(capitalize(cus_name)+" has "+amount+" gold coins on his account.\n");
    say(TPNAME+" checks the statement of "+cus_name+".\n");
    return 1;
  }
}

static int list_line;

do_list() {
int c;

  if (!TPWIZARD) return;

  write("Number of customers: "+sizeof(ctab[0])+".\n\n");
  list_line=0;
  do_more_list();
  if (list_line) {
     write("<q> to abort, enter to continue.\n");
     input_to("do_list_now");
  }
  return 1;
}

do_list_now(str) {
  if (str=="q") return 1;
  do_more_list();
  if (list_line) {
     write("<q> to abort, enter to continue.\n");
     input_to("do_list_now");
  }
  return 1;
}

do_more_list() {
int i,c;

  for (i=list_line;i<list_line+20 && i<sizeof(ctab[0]);i++)
    write(capitalize(ctab[0][i])+" has "+ctab[1][i]+" coins.\n");
  if (i<sizeof(ctab[0])) list_line=i;
  else list_line=0;
}

chk_existing(name) {

  idx=assoc(name,ctab[0]);
#if 0
  write("Debug! idx = "+idx+"\n");
#endif
  if (idx==-1) return 0;
  cus_name=name;
  amount=ctab[1][idx];
  return 1;
}


help_bank(str) {
  if (str=="bank") {
     cat("/doc/helpdir/broker");
     return 1;
  }
}

reload_bank() {
  if (this_player()->query_level()<25) return; 
  if (!restore_object(BANKFILE)) {
     write("Failed to restore bank, 'restore_object'.\n");
     return 1;
  }
  save_object(BANKFILE);
  write("Reloaded ...\n");
  return 1;
} 

save_bank() { 
  save_object(BANKFILE);
  return 1;
}

show_bank() {
int i;
  if (this_player()->query_level()<25) return; 
  for (i=0; i<sizeof(ctab[0]); i++)
      write(ctab[0][i]+"\n");
  return 1;
}
