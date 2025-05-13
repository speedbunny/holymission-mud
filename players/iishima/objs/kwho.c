id(str)    
{
 return str=="kiwi who";
}
 
short() { return "A Kiwi Who"; }
long() { return write("This is Iishima's Kiwi Who.\n"),1; }
query_weight() { return 0; }
drop() { return 1; }
get() { return 1; }

xxx(){ }
query_auto_load() { return "/players/iishima/objs/kwho.c:"; } 

string *kwho = ({ });
int loaded;

reset()
{
}

init()
{
 if (loaded != 10) kload();
 add_action("kadd","kadd");
 add_action("ksub","ksub");
 add_action("kwho","kwho");
 add_action("klist","klist");
 add_action("kload","kload");
}
 
kload()
{
 restore_object("/players/iishima/objs/kwho");
 loaded = 10;
 return 1;
}

kadd(string str)
{
 if (!str) notify_fail("Kadd who?");
 if (member_array(str, kwho) == -1)
  {
   write("Added "+str+".\n");
   kwho = kwho + ({ str });
   save_object("/players/iishima/objs/kwho");   
   return 1;
 }
 write("Name already in use.\n");
 return 1;
}  

ksub(string str)
{
 if (!str) notify_fail("Ksub who?");
 if (member_array(str, kwho) == -1) notify_fail("That name is not in your list.");
 
 kwho = kwho - ({ str });
 save_object("/players/iishima/objs/kwho");
 return write("Name removed.\n"),1;
}

kwho()
{
 int x,y;
 object test;

 y = sizeof(kwho);

 printf("Iishima's Kiwi Who List\n");
 printf("------------------------------------------------------------\n");
 for (x = 0; x < y; x++)
  {
   test = find_player(kwho[x]);
   if (test) printf("%s %s\n",capitalize(test->query_real_name()),test->query_title());
  }
 return 1;
}

klist()
{
 int x, y;

 y = sizeof(kwho);
 printf("People in your kiwi who list\n");
 printf("----------------------------\n");
 for (x = 0; x < y; x++)
 {
  printf("%s\n",kwho[x]);
 }
 return 1;
}


